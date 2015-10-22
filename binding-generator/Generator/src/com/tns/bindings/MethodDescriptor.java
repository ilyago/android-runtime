package com.tns.bindings;

public interface MethodDescriptor
{
	String getName();
	
	Class<?>[] getParameterTypes();
	
	Class<?> getReturnType();
	
	int getModifiers();
	
	boolean isSynthetic(); 
	
	AnnotationDescriptor[] getAnnotations();
}
