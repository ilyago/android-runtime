package com.tns.tests;

public class ClassImplementingInterface extends SimpleClass implements InterfaceExtendingSimpleInterface {
    @Override
    public boolean method2OfInterfaceExtendingSimpleInterface(boolean in) {
        return false;
    }

    @Override
    public void method1OfSimpleInterface() {

    }
}
