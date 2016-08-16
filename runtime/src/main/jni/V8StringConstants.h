#ifndef V8STRINGCONSTANTS_H_
#define V8STRINGCONSTANTS_H_

#include <string>
#include "v8.h"

//const int V8_STRING_NATIVE_SCRIPT_LONG_NUMBER = 0;
//const int V8_STRING_VALUE_OF = 1;
//const int V8_STRING_VALUE = 2;
//const int V8_STRING_TO_STRING = 3;
//const int V8_STRING_T_JAVA_LONG = 4;
//const int V8_STRING_T_HIDDEN_JS_INSTANCE = 5;
//const int V8_STRING_T_MARKED_AS_LONG = 6;
//const int V8_STRING_T_MARKED_AS_BYTE = 7;
//const int V8_STRING_T_MARKED_AS_SHORT = 8;
//const int V8_STRING_T_MARKED_AS_DOUBLE = 9;
//const int V8_STRING_T_MARKED_AS_FLOAT = 10;
//const int V8_STRING_T_MARKED_AS_CHAR = 11;
//const int V8_STRING_DEBUG_NAME_KEY = 12;
//const int V8_STRING_IS_PROTOTYPE_IMPLEMENTATION_OBJECT_KEY = 13;
//const int V8_STRING_PROTOTYPE = 14;
//const int V8_STRING_SUPER = 15;
//const int V8_STRING_CLASS_IMPLEMENTATION_OBJECT_KEY = 16;
//const int V8_STRING_EXTENDS = 17;
//const int V8_STRING_NATIVE_EXCEPTION = 18;
//const int V8_STRING_TARGET = 19;

namespace tns
{
	class V8StringConstants
	{
		public:
			static v8::Local<v8::String> GetClassImplementationObject(v8::Isolate *isolate);
			static v8::Local<v8::String> GetDebugName(v8::Isolate *isolate);
			static v8::Local<v8::String> GetExtend(v8::Isolate *isolate);
			static v8::Local<v8::String> GetNullObject(v8::Isolate *isolate);
			static v8::Local<v8::String> GetNullNodeName(v8::Isolate *isolate);
			static v8::Local<v8::String> GetIsPrototypeImplementationObject(v8::Isolate *isolate);
			static v8::Local<v8::String> GetNativeException(v8::Isolate *isolate);
			static v8::Local<v8::String> GetStackTrace(v8::Isolate *isolate);
			static v8::Local<v8::String> GetLongNumber(v8::Isolate *isolate);
			static v8::Local<v8::String> GetPrototype(v8::Isolate *isolate);
			static v8::Local<v8::String> GetSuper(v8::Isolate *isolate);
			static v8::Local<v8::String> GetTSuper(v8::Isolate *isolate);
			static v8::Local<v8::String> GetTarget(v8::Isolate *isolate);
			static v8::Local<v8::String> GetToString(v8::Isolate *isolate);
			static v8::Local<v8::String> GetHiddenJSInstance(v8::Isolate *isolate);
			static v8::Local<v8::String> GetJavaLong(v8::Isolate *isolate);
			static v8::Local<v8::String> GetValueOf(v8::Isolate *isolate);
			static v8::Local<v8::String> GetValue(v8::Isolate *isolate);
			static v8::Local<v8::String> GetUncaughtError(v8::Isolate *isolate);

			static const std::string CLASS_IMPLEMENTATION_OBJECT;
			static const std::string DEBUG_NAME;
			static const std::string EXTEND;
			static const std::string NULL_OBJECT;
			static const std::string NULL_NODE_NAME;
			static const std::string IS_PROTOTYPE_IMPLEMENTATION_OBJECT;
			static const std::string NATIVE_EXCEPTION;
			static const std::string STACK_TRACE;
			static const std::string LONG_NUMBER;
			static const std::string PROTOTYPE;
			static const std::string SUPER;
			static const std::string T_SUPER;
			static const std::string TARGET;
			static const std::string TO_STRING;
			static const std::string HIDDEN_JS_INSTANCE;
			static const std::string JAVA_LONG;
			static const std::string MARKED_AS_BYTE;
			static const std::string MARKED_AS_CHAR;
			static const std::string MARKED_AS_DOUBLE;
			static const std::string MARKED_AS_FLOAT;
			static const std::string MARKED_AS_LONG;
			static const std::string MARKED_AS_SHORT;
			static const std::string VALUE_OF;
			static const std::string VALUE;
			static const std::string UNCAUGHT_ERROR;
			private:
			V8StringConstants()
			{
			}
			;

			static v8::Persistent<v8::String> *CLASS_IMPLEMENTATION_OBJECT_PERSISTENT;
			static v8::Persistent<v8::String> *DEBUG_NAME_PERSISTENT;
			static v8::Persistent<v8::String> *EXTEND_PERSISTENT;
			static v8::Persistent<v8::String> *NULL_OBJECT_PERSISTENT;
			static v8::Persistent<v8::String> *NULL_NODE_NAME_PERSISTENT;
			static v8::Persistent<v8::String> *IS_PROTOTYPE_IMPLEMENTATION_OBJECT_PERSISTENT;
			static v8::Persistent<v8::String> *NATIVE_EXCEPTION_PERSISTENT;
			static v8::Persistent<v8::String> *STACK_TRACE_PERSISTENT;
			static v8::Persistent<v8::String> *LONG_NUMBER_PERSISTENT;
			static v8::Persistent<v8::String> *PROTOTYPE_PERSISTENT;
			static v8::Persistent<v8::String> *SUPER_PERSISTENT;
			static v8::Persistent<v8::String> *T_SUPER_PERSISTENT;
			static v8::Persistent<v8::String> *TARGET_PERSISTENT;
			static v8::Persistent<v8::String> *TO_STRING_PERSISTENT;
			static v8::Persistent<v8::String> *HIDDEN_JS_INSTANCE_PERSISTENT;
			static v8::Persistent<v8::String> *JAVA_LONG_PERSISTENT;
			static v8::Persistent<v8::String> *VALUE_OF_PERSISTENT;
			static v8::Persistent<v8::String> *VALUE_PERSISTENT;
			static v8::Persistent<v8::String> *UNCAUGHT_ERROR_PERSISTENT;
	};
}

#endif /* V8STRINGCONSTANTS_H_ */
