com.tns.tests.ClassExtendingClassAndInterfaces.extend("com.tns.generated.ComplicatedClass", {
    method2OfInterfaceExtendingSimpleInterface: function(input) {
        console.log("method2 Of Interface that extends another interface called");

        return true;
    },
    method1OfSimpleInterface: function() {
        console.log("method1 Of SimpleInterface called");
    },
    method1OfSimpleClass: function(input) {
        console.log("method1 of SimpleClass called");

        return true;
    }
});

com.tns.tests.SimpleClass.extend("com.tns.generated.SimpleClassWithInterfaces", {
    interfaces: [com.tns.tests.MyPublicInterface, com.tns.tests.SimpleInterface],
    method1OfSimpleInterface: function() {
        console.log("method1 Of SimpleInterface called");
    }
})