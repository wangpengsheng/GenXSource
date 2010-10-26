using System;
using Composite = Genetibase.NuGenHL7.model.Composite;
using DataTypeException = Genetibase.NuGenHL7.model.DataTypeException;
using Message = Genetibase.NuGenHL7.model.Message;
using Type = Genetibase.NuGenHL7.model.Type;
using AbstractType = Genetibase.NuGenHL7.model.AbstractType;
namespace Genetibase.NuGenHL7.model.v22.datatype
{
	
	/// <summary> <p>The HL7 CM_NDL (observing practitioner) data type.  Consists of the following components: </p><ol>
	/// <li>interpreter / technician (CN)</li>
	/// <li>start date/time (TS)</li>
	/// <li>end date/time (TS)</li>
	/// <li>location (CM_INTERNAL_LOCATION)</li>
	/// </ol>
	/// </summary>
	[Serializable]
	public class CM_NDL:AbstractType, Composite
	{
		/// <summary> Returns an array containing the data elements.</summary>
		virtual public Type[] Components
		{
			get
			{
				return this.data;
			}
			
		}
		/// <summary> Returns interpreter / technician (component #0).  This is a convenience method that saves you from 
		/// casting and handling an exception.
		/// </summary>
		virtual public CN InterpreterTechnician
		{
			get
			{
				CN ret = null;
				try
				{
					ret = (CN) getComponent(0);
				}
				catch (DataTypeException)
				{
					throw new Exception();
				}
				return ret;
			}
			
		}
		/// <summary> Returns start date/time (component #1).  This is a convenience method that saves you from 
		/// casting and handling an exception.
		/// </summary>
		virtual public TS StartDateTime
		{
			get
			{
				TS ret = null;
				try
				{
					ret = (TS) getComponent(1);
				}
				catch (DataTypeException)
				{
					throw new Exception();
				}
				return ret;
			}
			
		}
		/// <summary> Returns end date/time (component #2).  This is a convenience method that saves you from 
		/// casting and handling an exception.
		/// </summary>
		virtual public TS EndDateTime
		{
			get
			{
				TS ret = null;
				try
				{
					ret = (TS) getComponent(2);
				}
				catch (DataTypeException)
				{
					throw new Exception();
				}
				return ret;
			}
			
		}
		/// <summary> Returns location (component #3).  This is a convenience method that saves you from 
		/// casting and handling an exception.
		/// </summary>
		virtual public CM_INTERNAL_LOCATION Location
		{
			get
			{
				CM_INTERNAL_LOCATION ret = null;
				try
				{
					ret = (CM_INTERNAL_LOCATION) getComponent(3);
				}
				catch (DataTypeException)
				{
					throw new Exception();
				}
				return ret;
			}
			
		}
		
		private Type[] data;
		
		/// <summary> Creates a CM_NDL.</summary>
		/// <param name="message">the Message to which this Type belongs
		/// </param>
		public CM_NDL(Message message):base(message)
		{
			data = new Type[4];
			data[0] = new CN(message);
			data[1] = new TS(message);
			data[2] = new TS(message);
			data[3] = new CM_INTERNAL_LOCATION(message);
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
				throw new DataTypeException("Element " + number + " doesn't exist in 4 element CM_NDL composite");
			}
		}
	}
}