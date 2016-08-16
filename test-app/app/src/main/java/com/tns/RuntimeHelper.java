package com.tns;

import java.io.File;

import android.app.Application;
import android.content.pm.PackageManager.NameNotFoundException;
import android.os.Build;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;

import java.io.IOException;

public final class RuntimeHelper {
    private RuntimeHelper() {
    }

    // hasErrorIntent tells you if there was an event (with an uncaught
    // exception) raised from ErrorReport
    private static boolean hasErrorIntent(Application app) {
        boolean hasErrorIntent = false;

        try {
            // empty file just to check if there was a raised uncaught error by
            // ErrorReport
            File errFile = new File(app.getFilesDir(), ErrorReport.ERROR_FILE_NAME);

            if (errFile.exists()) {
                errFile.delete();
                hasErrorIntent = true;
            }
        } catch (Exception e) {
            Log.d(logTag, e.getMessage());
        }

        return hasErrorIntent;
    }

    public static Runtime initRuntime(Application app) {
        if (Runtime.isInitialized()) {
            return Runtime.getCurrentRuntime();
        }

        System.loadLibrary("NativeScript");

        Logger logger = new LogcatLogger(app);
        logger.setEnabled(true);
        Debugger debugger = AndroidJsDebugger.isDebuggableApp(app) ? new AndroidJsDebugger(app, logger) : null;

        Runtime runtime = null;
        boolean showErrorIntent = hasErrorIntent(app);
        if (!showErrorIntent) {
            NativeScriptUncaughtExceptionHandler exHandler = new NativeScriptUncaughtExceptionHandler(logger, app);

            Thread.setDefaultUncaughtExceptionHandler(exHandler);

            DefaultExtractPolicy extractPolicy = new DefaultExtractPolicy(logger);
            boolean skipAssetExtraction = Util.runPlugin(logger, app);

            String appName = app.getPackageName();
            File rootDir = new File(app.getApplicationInfo().dataDir);
            File appDir = app.getFilesDir();

            try {
                appDir = appDir.getCanonicalFile();
            } catch (IOException e1) {
            }

            if (!skipAssetExtraction) {
                if (logger.isEnabled()) {
                    logger.write("Extracting assets...");
                }

                AssetExtractor aE = new AssetExtractor(null, logger);

                String outputDir = app.getFilesDir().getPath() + File.separator;

                aE.extractAssets(app, "app", outputDir, extractPolicy);
                aE.extractAssets(app, "internal", outputDir, extractPolicy);
                aE.extractAssets(app, "metadata", outputDir, extractPolicy);

                // enable with flags?
                boolean shouldExtractSnapshots = true;

                // will extract snapshot of the device appropriate architecture
                if (shouldExtractSnapshots) {
                    if (logger.isEnabled()) {
                        logger.write("Extracting snapshot blob");
                    }

                    aE.extractAssets(app, "snapshots/" + Build.CPU_ABI, outputDir, extractPolicy);
                }

                extractPolicy.setAssetsThumb(app);
            }

            Object[] v8Config = V8Config.fromPackageJSON(appDir);

            ClassLoader classLoader = app.getClassLoader();
            File dexDir = new File(rootDir, "code_cache/secondary-dexes");
            String dexThumb = null;
            try {
                dexThumb = Util.getDexThumb(app);
            } catch (NameNotFoundException e) {
                if (logger.isEnabled())
                    logger.write("Error while getting current proxy thumb");
                e.printStackTrace();
            }
            ThreadScheduler workThreadScheduler = new WorkThreadScheduler(new Handler(Looper.getMainLooper()));
            Configuration config = new Configuration(workThreadScheduler, logger, debugger, appName, null, rootDir,
                    appDir, classLoader, dexDir, dexThumb, v8Config);
            runtime = new Runtime(config);

            exHandler.setRuntime(runtime);

            if (NativeScriptSyncService.isSyncEnabled(app)) {
                NativeScriptSyncService syncService = new NativeScriptSyncService(runtime, logger, app);

                syncService.sync();
                syncService.startServer();

                // preserve this instance as strong reference
                // do not preserve in NativeScriptApplication field inorder to
                // make the code more portable
                // @@@
                // Runtime.getOrCreateJavaObjectID(syncService);
            } else {
                if (logger.isEnabled()) {
                    logger.write("NativeScript LiveSync is not enabled.");
                }
            }

            runtime.init();
            runtime.runScript(new File(appDir, "internal/ts_helpers.js"));

            File javaClassesModule = new File(appDir, "app/tns-java-classes.js");
            if (javaClassesModule.exists()) {
                runtime.runModule(javaClassesModule);
            }

            try {
                // put this call in a try/catch block because with the latest changes in the modules it is not granted that NativeScriptApplication is extended through JavaScript.
                Runtime.initInstance(app);
            } catch (Exception e) {

            }
        }
        return runtime;
    }

    @RuntimeCallable
    public static void initRuntimeOnNewThread(final String appName, final String appDir, final String filePath) {
        Thread runtimeThread = new Thread(new Runnable() {
            @Override
            public void run() {
                String name = "Worker-\'" + filePath + "\'";
                Thread.currentThread().setName(name);
                init(appName, appDir, filePath);
            }
        });

        runtimeThread.start();
    }

    public static Runtime init(String appName, String appDir, String filePath) {
        if (Runtime.isInitialized()) {
            return Runtime.getCurrentRuntime();
        }

        Runtime runtime = null;

        Object[] v8Config = new Object[1];//V8Config.fromPackageJSON(appDir);

        String dexThumb = null;

        Logger logger = new LogcatLogger();
        Configuration config = new Configuration(null, null, null, appName, null, null, new File(appDir), null, null, null, null);
        runtime = new Runtime(config);

        runtime.simplisticInit(logger);

        // TODO: Pete: RESOLVE FULL PATH to file on device
//        filePath = "/data/data/com.tns.android_runtime_testapp/files/app/myFile.js";
        runtime.runGivenScript(filePath);
//			runtime.runScript(new File(appDir, "internal/ts_helpers.js"));

//			File javaClassesModule = new File(appDir, "app/tns-java-classes.js");
//			if (javaClassesModule.exists()) {
//				runtime.runModule(javaClassesModule);
//			}

//			try {
        // put this call in a try/catch block because with the latest changes in the modules it is not granted that NativeScriptApplication is extended through JavaScript.
//				Runtime.initInstance(app);
//			}
//			catch (Exception e) {
//			}
//		}
        return runtime;
    }

    private static final String logTag = "MyApp";
}
