package com.tns.bindings;

import java.util.ArrayList;

public class AnnotationDescriptor
{
	public static class Parameter
	{
		private final String name;
		private final Object value;
		
		public Parameter(String name, Object value)
		{
			this.name = name;
			this.value = value;
		}
		
		public String getName()
		{
			return this.name;
		}
		
		public Object getValue()
		{
			return this.value;
		}
	}
	
	public AnnotationDescriptor(String classname)
	{
		this.classname = classname;
		this.params = new ArrayList<Parameter>();
	}
	
	public String getAnnotationClassname()
	{
		return this.classname;
	}
	
	public boolean isRuntimeVisible()
	{
		return true;
	}
	
	public Parameter[] getParams()
	{
		Parameter[] p = new Parameter[this.params.size()];
		this.params.toArray(p);
		return p;
	}
	
	private final String classname;
	private final ArrayList<Parameter> params;
}
