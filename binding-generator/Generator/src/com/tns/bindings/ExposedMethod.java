package com.tns.bindings;

import java.lang.reflect.Modifier;
import java.util.ArrayList;

public class ExposedMethod implements MethodDescriptor
{
	private final String desc;
	private final AnnotationDescriptor[] annotations;
	private String name;
	private Class<?>[] paramTypes;
	private Class<?> retType;
	private int idx;
	
	public ExposedMethod(String desc, AnnotationDescriptor[] annotations)
	{
		this.desc = desc;
		this.annotations = annotations;
		parse();
	}

	public String getName()
	{
		return this.name;
	}

	public Class<?>[] getParameterTypes()
	{
		return this.paramTypes;
	}

	public Class<?> getReturnType()
	{
		return this.retType;
	}

	public int getModifiers()
	{
		return Modifier.PUBLIC;
	}

	public boolean isSynthetic()
	{
		return false;
	}
	
	public AnnotationDescriptor[] getAnnotations()
	{
		return this.annotations;
	}
	
	private void parse()
	{
		int startingParenthesesIdx = this.desc.indexOf('(');
		this.name = this.desc.substring(0, startingParenthesesIdx);
		idx = startingParenthesesIdx + 1;
		int endingParenthesesIdx = this.desc.indexOf(')');
		
		ArrayList<Class<?>> params = new ArrayList<Class<?>>();
		
		while (idx < endingParenthesesIdx)
		{
			String className = readType();
			
			Class<?> c = findClass(className);
			
			params.add(c);
		}
		++idx;
		
		String retType = readType();
		
		this.paramTypes = params.toArray(new Class<?>[params.size()]);
		this.retType = findClass(retType);
	}
	
	private String readType()
	{
		int startPos = idx;
		
		char c = this.desc.charAt(idx);
		
		boolean isArray = c == '[';
		while (c == '[')
		{
			c = this.desc.charAt(++idx);
		}

		boolean foundRefType = c == 'L'; 
		if (foundRefType)
		{
			while (c != ';')
			{
				c = this.desc.charAt(++idx);
			}
		}
		++idx;
		
		String type;
		if (isArray)
		{
			type = this.desc.substring(startPos, idx).replace('/', '.'); 
		}
		else if (foundRefType)
		{
			type = this.desc.substring(startPos + 1, idx - 1).replace('/', '.');
		}
		else
		{
			type = this.desc.substring(startPos, idx);
		}
		 
		return type;
	}
	
	private Class<?> findClass(String className)
	{
		Class<?> c = null;
		
		try
		{
			switch (className)
			{
				case "B":
					c = byte.class;
					break;
				case "S":
					c = short.class;
					break;
				case "I":
					c = int.class;
					break;
				case "J":
					c = long.class;
					break;
				case "F":
					c = float.class;
					break;
				case "D":
					c = double.class;
					break;
				case "C":
					c = char.class;
					break;
				case "Z":
					c = boolean.class;
					break;
				case "V":
					c = void.class;
					break;
				default:
					c = Class.forName(className);
					break;
			}
		}
		catch (ClassNotFoundException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		return c;
	}
}
