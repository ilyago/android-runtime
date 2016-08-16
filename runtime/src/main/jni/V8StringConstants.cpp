#include "V8StringConstants.h"
#include "NativeScriptAssert.h"

using namespace v8;
using namespace std;

namespace tns
{
	Local<String> V8StringConstants::GetClassImplementationObject(Isolate *isolate)
	{
		if (CLASS_IMPLEMENTATION_OBJECT_PERSISTENT == nullptr)
		{
			auto str = String::NewFromUtf8(isolate, CLASS_IMPLEMENTATION_OBJECT.c_str());
			CLASS_IMPLEMENTATION_OBJECT_PERSISTENT = new Persistent<String>(isolate, str);
		}

		return Local<String>::New(isolate, *CLASS_IMPLEMENTATION_OBJECT_PERSISTENT);
	}

	Local<String> V8StringConstants::GetExtend(Isolate *isolate)
	{
		// TODO: Pete: Find a way to make these constants persistent for each new thread
//		if (EXTEND_PERSISTENT == nullptr)
//		{
			auto str = String::NewFromUtf8(isolate, EXTEND.c_str());
			EXTEND_PERSISTENT = new Persistent<String>(isolate, str);
//		}

		return Local<String>::New(isolate, *EXTEND_PERSISTENT);
	}

	Local<String> V8StringConstants::GetNullObject(Isolate *isolate)
	{
		// TODO: Pete: Find a way to make these constants persistent for each new thread
//		if (NULL_OBJECT_PERSISTENT == nullptr)
//		{
			auto str = String::NewFromUtf8(isolate, NULL_OBJECT.c_str());
			NULL_OBJECT_PERSISTENT = new Persistent<String>(isolate, str);
//		}

		return Local<String>::New(isolate, *NULL_OBJECT_PERSISTENT);
	}

	Local<String> V8StringConstants::GetNullNodeName(Isolate *isolate)
	{
		if (NULL_NODE_NAME_PERSISTENT == nullptr)
		{
			auto str = String::NewFromUtf8(isolate, NULL_NODE_NAME.c_str());
			NULL_NODE_NAME_PERSISTENT = new Persistent<String>(isolate, str);
		}

		return Local<String>::New(isolate, *NULL_NODE_NAME_PERSISTENT);
	}

	Local<String> V8StringConstants::GetIsPrototypeImplementationObject(Isolate *isolate)
	{
		if (IS_PROTOTYPE_IMPLEMENTATION_OBJECT_PERSISTENT == nullptr)
		{
			auto str = String::NewFromUtf8(isolate, IS_PROTOTYPE_IMPLEMENTATION_OBJECT.c_str());
			IS_PROTOTYPE_IMPLEMENTATION_OBJECT_PERSISTENT = new Persistent<String>(isolate, str);
		}

		return Local<String>::New(isolate, *IS_PROTOTYPE_IMPLEMENTATION_OBJECT_PERSISTENT);
	}

	Local<String> V8StringConstants::GetNativeException(Isolate *isolate)
	{
		if (NATIVE_EXCEPTION_PERSISTENT == nullptr)
		{
			auto str = String::NewFromUtf8(isolate, NATIVE_EXCEPTION.c_str());
			NATIVE_EXCEPTION_PERSISTENT = new Persistent<String>(isolate, str);
		}

		return Local<String>::New(isolate, *NATIVE_EXCEPTION_PERSISTENT);
	}

	Local<String> V8StringConstants::GetStackTrace(Isolate *isolate)
	{
		if (STACK_TRACE_PERSISTENT == nullptr)
		{
			auto str = String::NewFromUtf8(isolate, STACK_TRACE.c_str());
			STACK_TRACE_PERSISTENT = new Persistent<String>(isolate, str);
		}

		return Local<String>::New(isolate, *STACK_TRACE_PERSISTENT);
	}

	Local<String> V8StringConstants::GetLongNumber(Isolate *isolate)
	{
		if (LONG_NUMBER_PERSISTENT == nullptr)
		{
			auto str = String::NewFromUtf8(isolate, LONG_NUMBER.c_str());
			LONG_NUMBER_PERSISTENT = new Persistent<String>(isolate, str);
		}

		return Local<String>::New(isolate, *LONG_NUMBER_PERSISTENT);
	}

	Local<String> V8StringConstants::GetPrototype(Isolate *isolate)
	{
		if (PROTOTYPE_PERSISTENT == nullptr)
		{
			auto str = String::NewFromUtf8(isolate, PROTOTYPE.c_str());
			PROTOTYPE_PERSISTENT = new Persistent<String>(isolate, str);
		}

		return Local<String>::New(isolate, *PROTOTYPE_PERSISTENT);
	}

	Local<String> V8StringConstants::GetSuper(Isolate *isolate)
	{
		if (SUPER_PERSISTENT == nullptr)
		{
			auto str = String::NewFromUtf8(isolate, SUPER.c_str());
			SUPER_PERSISTENT = new Persistent<String>(isolate, str);
		}

		return Local<String>::New(isolate, *SUPER_PERSISTENT);
	}

	Local<String> V8StringConstants::GetTSuper(Isolate *isolate)
	{
		if (T_SUPER_PERSISTENT == nullptr)
		{
			auto str = String::NewFromUtf8(isolate, T_SUPER.c_str());
			T_SUPER_PERSISTENT = new Persistent<String>(isolate, str);
		}

		return Local<String>::New(isolate, *T_SUPER_PERSISTENT);
	}

	Local<String> V8StringConstants::GetTarget(Isolate *isolate)
	{
		if (TARGET_PERSISTENT == nullptr)
		{
			auto str = String::NewFromUtf8(isolate, TARGET.c_str());
			TARGET_PERSISTENT = new Persistent<String>(isolate, str);
		}

		return Local<String>::New(isolate, *TARGET_PERSISTENT);
	}

	Local<String> V8StringConstants::GetToString(Isolate *isolate)
	{
		if (TO_STRING_PERSISTENT == nullptr)
		{
			auto str = String::NewFromUtf8(isolate, TO_STRING.c_str());
			TO_STRING_PERSISTENT = new Persistent<String>(isolate, str);
		}

		return Local<String>::New(isolate, *TO_STRING_PERSISTENT);
	}

	Local<String> V8StringConstants::GetHiddenJSInstance(Isolate *isolate)
	{
		if (HIDDEN_JS_INSTANCE_PERSISTENT == nullptr)
		{
			auto str = String::NewFromUtf8(isolate, HIDDEN_JS_INSTANCE.c_str());
			HIDDEN_JS_INSTANCE_PERSISTENT = new Persistent<String>(isolate, str);
		}

		return Local<String>::New(isolate, *HIDDEN_JS_INSTANCE_PERSISTENT);
	}

	Local<String> V8StringConstants::GetJavaLong(Isolate *isolate)
	{
		if (JAVA_LONG_PERSISTENT == nullptr)
		{
			auto str = String::NewFromUtf8(isolate, JAVA_LONG.c_str());
			JAVA_LONG_PERSISTENT = new Persistent<String>(isolate, str);
		}

		return Local<String>::New(isolate, *JAVA_LONG_PERSISTENT);
	}

	Local<String> V8StringConstants::GetValue(Isolate *isolate)
	{
		if (VALUE_PERSISTENT == nullptr)
		{
			auto str = String::NewFromUtf8(isolate, VALUE.c_str());
			VALUE_PERSISTENT = new Persistent<String>(isolate, str);
		}

		return Local<String>::New(isolate, *VALUE_PERSISTENT);
	}

	Local<String> V8StringConstants::GetValueOf(Isolate *isolate)
	{
		if (VALUE_OF_PERSISTENT == nullptr)
		{
			auto str = String::NewFromUtf8(isolate, VALUE_OF.c_str());
			VALUE_OF_PERSISTENT = new Persistent<String>(isolate, str);
		}

		return Local<String>::New(isolate, *VALUE_OF_PERSISTENT);
	}

	Local<String> V8StringConstants::GetUncaughtError(Isolate *isolate)
	{
		if (UNCAUGHT_ERROR_PERSISTENT == nullptr)
		{
			auto str = String::NewFromUtf8(isolate, UNCAUGHT_ERROR.c_str());
			UNCAUGHT_ERROR_PERSISTENT = new Persistent<String>(isolate, str);
		}

		return Local<String>::New(isolate, *UNCAUGHT_ERROR_PERSISTENT);
	}

	const string V8StringConstants::CLASS_IMPLEMENTATION_OBJECT = "t::ClassImplementationObject";
	const string V8StringConstants::EXTEND = "extend";
	const string V8StringConstants::NULL_OBJECT = "null";
	const string V8StringConstants::NULL_NODE_NAME = "nullNode";
	const string V8StringConstants::IS_PROTOTYPE_IMPLEMENTATION_OBJECT = "__isPrototypeImplementationObject";
	const string V8StringConstants::NATIVE_EXCEPTION = "nativeException";
	const string V8StringConstants::STACK_TRACE = "stackTrace";
	const string V8StringConstants::LONG_NUMBER = "NativeScriptLongNumber";
	const string V8StringConstants::PROTOTYPE = "prototype";
	const string V8StringConstants::SUPER = "super";
	const string V8StringConstants::T_SUPER = "t:super";
	const string V8StringConstants::TARGET = "target";
	const string V8StringConstants::TO_STRING = "toString";
	const string V8StringConstants::HIDDEN_JS_INSTANCE = "t::HiddenJSInstanceInfo";
	const string V8StringConstants::JAVA_LONG = "t::JavaLong";
	const string V8StringConstants::MARKED_AS_BYTE = "t::MarkedAsByte";
	const string V8StringConstants::MARKED_AS_CHAR = "t::MarkedAsChar";
	const string V8StringConstants::MARKED_AS_DOUBLE = "t::MarkedAsDouble";
	const string V8StringConstants::MARKED_AS_FLOAT = "t::MarkedAsFloat";
	const string V8StringConstants::MARKED_AS_LONG = "t::MarkedAsLong";
	const string V8StringConstants::MARKED_AS_SHORT = "t::MarkedAsShort";
	const string V8StringConstants::VALUE = "value";
	const string V8StringConstants::VALUE_OF = "valueOf";
	const string V8StringConstants::UNCAUGHT_ERROR = "__onUncaughtError";

	// TODO: Release these objects when we implement V8 reset
	// TODO: These are not thread-safe!
	Persistent<String> *V8StringConstants::CLASS_IMPLEMENTATION_OBJECT_PERSISTENT;
	Persistent<String> *V8StringConstants::EXTEND_PERSISTENT;
	Persistent<String> *V8StringConstants::NULL_OBJECT_PERSISTENT;
	Persistent<String> *V8StringConstants::NULL_NODE_NAME_PERSISTENT;
	Persistent<String> *V8StringConstants::IS_PROTOTYPE_IMPLEMENTATION_OBJECT_PERSISTENT;
	Persistent<String> *V8StringConstants::NATIVE_EXCEPTION_PERSISTENT;
	Persistent<String> *V8StringConstants::STACK_TRACE_PERSISTENT;
	Persistent<String> *V8StringConstants::LONG_NUMBER_PERSISTENT;
	Persistent<String> *V8StringConstants::PROTOTYPE_PERSISTENT;
	Persistent<String> *V8StringConstants::SUPER_PERSISTENT;
	Persistent<String> *V8StringConstants::T_SUPER_PERSISTENT;
	Persistent<String> *V8StringConstants::TARGET_PERSISTENT;
	Persistent<String> *V8StringConstants::TO_STRING_PERSISTENT;
	Persistent<String> *V8StringConstants::HIDDEN_JS_INSTANCE_PERSISTENT;
	Persistent<String> *V8StringConstants::JAVA_LONG_PERSISTENT;
	Persistent<String> *V8StringConstants::VALUE_PERSISTENT;
	Persistent<String> *V8StringConstants::VALUE_OF_PERSISTENT;
	Persistent<String> *V8StringConstants::UNCAUGHT_ERROR_PERSISTENT;
}
