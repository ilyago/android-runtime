__disableVerboseLogging();
__log("starting tests");
require("./tests/testWeakRef"); 
require("./tests/tests");
require("./tests/testMethodResolution");
require("./tests/testArrays");
require("./tests/testsForRuntimeBindingGenerator");
require("./tests/testPrimitiveTypeConversion");
require("./tests/numericConversionTests"); 
require("./tests/inheritanceChainResolutionTest"); 
require("./tests/exceptionHandlingTests");
require("./tests/dispatchCallbacksOnUiThreadTests");
require("./tests/stringConversionTests");
require("./tests/testsForTypescript"); 
require("./tests/testGC");
require("./tests/testsMemoryManagement");
require("./tests/testIfAbleToRunExternalFile");
require("./tests/testFieldGetSet");
require("./tests/extendedClassesTests");
require("./tests/extendClassNameTests");
require("./tests/testJniReferenceLeak");

var MainActivity = {
    onCreate: function (bundle) {
    	__log("-----------> onCreate from js");
    	var k = this.toString();
    	__log("this.toString " + k);
    	this.super.onCreate(bundle);

    	require("./tests/testsWithContext").run(this);
    	execute(); //run jasmine
    	
    	var O = this.getExtendedClassInTypeScript();
    	//var O = this.getExtendedClassInJavaScript();
    	
        var webview = new android.webkit.WebView(this);
        webview.getSettings().setJavaScriptEnabled(true);
        var obj = new O();
        webview.addJavascriptInterface(obj, "NativeScript");
        var htmlFile = new java.io.File(__dirname, "webViewTest.html")
        var url = htmlFile.toURL().toString();
        webview.loadUrl(url);
        this.setContentView(webview);
    },
    
    getExtendedClassInJavaScript: function() {
    	var jsiAnnotation = { "className":"Landroid/webkit/JavascriptInterface;", "props":[] };
    	var O = java.lang.Object.extend("WebViewInterOp", {
    		sayHello: function() {
    			return "Hello NativeScript (extended in JavaScript)!";
    		}
    	}, {
    		"annotations": [ /* list class annotations */ ],
    		"exposedMethods": [ { "signature": "sayHello()Ljava/lang/String;", "annotations": [ jsiAnnotation ] } ]
    	});
    	return O;
    },
    
    getExtendedClassInTypeScript: function() {
    	/*
    	declare namespace java {
    		export namespace lang {
    			export class Object {}
    		}
    	}

    	function ExposeWithSignature(sig: string, annotations: any[] ) {
    		return function(target, key, value): void {
    			if (!target.__exposedMethods) {
    				target.__exposedMethods = [];
    			}
    			target.__exposedMethods.push({"signature": sig, "annotations": annotations});
    		}
    	}

    	function __native(o: any): any{}

    	class O extends java.lang.Object {
    		constructor() {
    			super();
    			return __native(this);
    		}
    		@ExposeWithSignature("sayHello()Ljava/lang/String;", [ { "className": "Landroid/webkit/JavascriptInterface;", "props": [] }])
    	    sayHello(): string {
    	        return "Hello NativeScript (extended in TypeScript)!"
    	    }
    	}
		*/
    	var O = (function (_super) {
    	    __extends(O, _super);
    	    function O() {
    	        _super.call(this);
    	        return __native(this);
    	    }
    	    O.prototype.sayHello = function () {
    	        return "Hello NativeScript (extended in TypeScript)!"
    	    };
    	    Object.defineProperty(O.prototype, "sayHello",
    	        __decorate([
    	            ExposeWithSignature("sayHello()Ljava/lang/String;", [{ "className": "Landroid/webkit/JavascriptInterface;", "props": [] }])
    	        ], O.prototype, "sayHello", Object.getOwnPropertyDescriptor(O.prototype, "sayHello")));
    	    return O;
    	})(java.lang.Object);
    	return O;
    }
}; 

app.init({
	
	getActivity: function(activity) {
		var intent = activity.getIntent();
		__log("intent=" + intent)
		var action = intent.getAction();
		__log("action=" + action)
		return MainActivity;
	},
	
	
	onCreate: function() {
		__log("Application on create called");
	} 
});