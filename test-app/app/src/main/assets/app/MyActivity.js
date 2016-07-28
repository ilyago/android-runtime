/* 
	// demonstrates how to extend class in TypeScript with prebuilt Java proxy
	
	declare module android {
		export module app {
			export class Activity {
				onCreate(bundle: android.os.Bundle);			
			}
		}
		export module os {
			export class Bundle {}
		}
	}
	
	@JavaProxy("com.tns.NativeScriptActivity")
	class MyActivity extends android.app.Activity
	{
		onCreate(bundle: android.os.Bundle) 
		{
			super.onCreate(bundle);
		}
	}
*/
var MyActivity = (function (_super) {
    __extends(MyActivity, _super);
    function MyActivity() {
        _super.apply(this, arguments);
    }
    MyActivity.prototype.onCreate = function (bundle) {
        _super.prototype.onCreate.call(this, bundle);

//    	require("./tests/testsWithContext").run(this);
//    	execute(); //run jasmine

//        var a = Worker("./myFile.js"); // not called as constructor
//        var a = new Worker(1); //not string
//        var a = new Worker(); //not not one parameter\

        var a = new Worker("./myFile.js");

//        a.postMessage("I POST A MESSAGE TO THE WORKER!");
//
        a.onmessage = function(msg) {
            android.util.Log.d("TNS.JAVASCRIPT.LOG", "I RECEIVED A MESSAGE FROM THE WORKER!");
        }

        a.onmessage("asdasdasd");
////
//    	var layout = new android.widget.LinearLayout(this);
//    	layout.setOrientation(1);
//    	this.setContentView(layout);
//
//    	var textView = new android.widget.TextView(this);
//    	textView.setText("It's a button!");
//    	layout.addView(textView);
//
//    	var button = new android.widget.Button(this);
//    	button.setText("Hit me");
//    	layout.addView(button);
//    	var counter = 0;
//
//    	var Color = android.graphics.Color;
//    	var colors = [Color.BLUE, Color.RED, Color.MAGENTA, Color.YELLOW, Color.parseColor("#FF7F50")];
//    	var taps = 0;
//
//    	var dum = com.tns.tests.DummyClass.null;
//
//    	button.setOnClickListener(new android.view.View.OnClickListener("AppClickListener", {
//    		onClick:  function() {
//    			button.setBackgroundColor(colors[taps % colors.length]);
//
////                android.util.Log.d("AAAAAALA", "AAAAAAAAAAAAAAAAAAAALA BAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAALA");
//                __log("Main thread Logging");
//
//    			taps++;
//    		}}));
    };
    MyActivity = __decorate([
        JavaProxy("com.tns.NativeScriptActivity")
    ], MyActivity);
    return MyActivity;
})(android.app.Activity);