using System;
using Composite = Genetibase.NuGenHL7.model.Composite;
using DataTypeException = Genetibase.NuGenHL7.model.DataTypeException;
using Message = Genetibase.NuGenHL7.model.Message;
using Type = Genetibase.NuGenHL7.model.Type;
using AbstractType = Genetibase.NuGenHL7.model.AbstractType;
namespace Genetibase.NuGenHL7.model.v21.datatype
{
	
	/// <summary> <p>The HL7 CQ (composite quantity with units) data type.  Consists of the following components: </p><ol>
	/// <li>quantity (NM)</li>
	/// <li>units (ST)</li>
	/// </ol>
	/// </summary>
	[Serializable]
	public class CQ:AbstractType, Composite
	{
		/// <summary> Returns an array containing the data elements.</summary>
		virtual public Type[] Components
		{
			get
			{
				return this.data;
			}
			
		}
		/// <summary> Returns quantity (component #0).  This is a convenience method that saves you from 
		/// casting and handling an exception.
		/// </summary>
		virtual public NM Quantity
		{
			get
			{
				NM ret = null;
				try
				{
					ret = (NM) getComponent(0);
				}
				catch (DataTypeException)
				{
					throw new Exception();
				}
				return ret;
			}
			
		}
		/// <summary> Returns units (component #1).  This is a convenience method that saves you from 
		/// casting and handling an exception.
		/// </summary>
		virtual public ST Units
		{
			get
			{
				ST ret = null;
				try
				{
					ret = (ST) getComponent(1);
				}
				catch (DataTypeException)
				{
					throw new Exception();
				}
				return ret;
			}
			
		}
		
		private Type[] data;
		
		/// <summary> Creates a CQ.</summary>
		/// <param name="message">the Message to which this Type belongs
		/// </param>
		public CQ(Message message):base(message)
		{
			data = new Type[2];
			data[0] = new NM(message);
			data[1] = new ST(message);
		}
		
		/// <summary> Returns an individual data component.</summary>
		/// <throws>  DataTypeException if the given element number is out of range. </throws>
		public virtual Type getComponent(int number)
		{
			
			try
			{
				return this.data[number];
			}
			catch (IndexOutOfRangeException)
			{
				throw new DataTypeException("Element " + number + " doesn't exist in 2 element CQ composite");
			}
		}
	}
}