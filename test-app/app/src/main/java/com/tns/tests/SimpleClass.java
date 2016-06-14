package com.tns.tests;

public class SimpleClass {
    public SimpleClass() {
        System.out.println("Hello, from SimpleClass!");
    }

    public SimpleClass(boolean booleanParam) {
        System.out.println("Hello with: " + String.valueOf(booleanParam) + ", from SimpleClass");
    }

    public boolean method1OfSimpleClass() {
        return true;
    }

    private void privateMethod2OfSimpleClass() {

    }
}