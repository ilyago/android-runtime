var global = this;

global.myFunction = this.myFunction || (function(){
	var myVariable = 0;
	return function() {
		return ++myVariable;
	};
}());

global.__warmup = function() {
	myFunction();
	myFunction();
}