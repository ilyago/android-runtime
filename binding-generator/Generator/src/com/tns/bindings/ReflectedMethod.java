package com.tns.bindings;

import java.lang.reflect.Method;

public class ReflectedMethod implements MethodDescriptor
{
	private final Method m;
	
	public ReflectedMethod(Method m)
	{
		this.m = m;
	}

	public String getName()
	{
		return m.getName();
	}

	public Class<?>[] getParameterTypes()
	{
		return m.getParameterTypes();
	}

	public Class<?> getReturnType()
	{
		return m.getReturnType();
	}

	public int getModifiers()
	{
		return m.getModifiers();
	}

	public boolean isSynthetic()
	{
		return m.isSynthetic();
	}

	public AnnotationDescriptor[] getAnnotations()
	{
		return null;
	}
}
