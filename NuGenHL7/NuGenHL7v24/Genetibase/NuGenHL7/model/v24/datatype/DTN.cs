using System;
using Composite = Genetibase.NuGenHL7.model.Composite;
using DataTypeException = Genetibase.NuGenHL7.model.DataTypeException;
using Message = Genetibase.NuGenHL7.model.Message;
using Type = Genetibase.NuGenHL7.model.Type;
using AbstractType = Genetibase.NuGenHL7.model.AbstractType;
namespace Genetibase.NuGenHL7.model.v24.datatype
{
	
	/// <summary> <p>The HL7 DTN (Day Type and Number) data type.  Consists of the following components: </p><ol>
	/// <li>day type (IS)</li>
	/// <li>number of days (NM)</li>
	/// </ol>
	/// </summary>
	[Serializable]
	public class DTN:AbstractType, Composite
	{
		/// <summary> Returns an array containing the data elements.</summary>
		virtual public Type[] Components
		{
			get
			{
				return this.data;
			}
			
		}
		/// <summary> Returns day type (component #0).  This is a convenience method that saves you from 
		/// casting and handling an exception.
		/// </summary>
		virtual public IS DayType
		{
			get
			{
				IS ret = null;
				try
				{
					ret = (IS) getComponent(0);
				}
				catch (DataTypeException)
				{
					throw new Exception();
				}
				return ret;
			}
			
		}
		/// <summary> Returns number of days (component #1).  This is a convenience method that saves you from 
		/// casting and handling an exception.
		/// </summary>
		virtual public NM NumberOfDays
		{
			get
			{
				NM ret = null;
				try
				{
					ret = (NM) getComponent(1);
				}
				catch (DataTypeException)
				{
					throw new Exception();
				}
				return ret;
			}
			
		}
		
		private Type[] data;
		
		/// <summary> Creates a DTN.</summary>
		/// <param name="message">the Message to which this Type belongs
		/// </param>
		public DTN(Message message):base(message)
		{
			data = new Type[2];
			data[0] = new IS(message, 0);
			data[1] = new NM(message);
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
				throw new DataTypeException("Element " + number + " doesn't exist in 2 element DTN composite");
			}
		}
	}
}