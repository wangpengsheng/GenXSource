using System;
using Composite = Genetibase.NuGenHL7.model.Composite;
using DataTypeException = Genetibase.NuGenHL7.model.DataTypeException;
using Message = Genetibase.NuGenHL7.model.Message;
using Type = Genetibase.NuGenHL7.model.Type;
using AbstractType = Genetibase.NuGenHL7.model.AbstractType;
namespace Genetibase.NuGenHL7.model.v25.datatype
{
	
	/// <summary> <p>The HL7 CCP (Channel Calibration Parameters) data type.  Consists of the following components: </p><ol>
	/// <li>Channel Calibration Sensitivity Correction Factor (NM)</li>
	/// <li>Channel Calibration Baseline (NM)</li>
	/// <li>Channel Calibration Time Skew (NM)</li>
	/// </ol>
	/// </summary>
	[Serializable]
	public class CCP:AbstractType, Composite
	{
		/// <summary> Returns an array containing the data elements.</summary>
		virtual public Type[] Components
		{
			get
			{
				return this.data;
			}
			
		}
		/// <summary> Returns Channel Calibration Sensitivity Correction Factor (component #0).  This is a convenience method that saves you from 
		/// casting and handling an exception.
		/// </summary>
		virtual public NM ChannelCalibrationSensitivityCorrectionFactor
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
		/// <summary> Returns Channel Calibration Baseline (component #1).  This is a convenience method that saves you from 
		/// casting and handling an exception.
		/// </summary>
		virtual public NM ChannelCalibrationBaseline
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
		/// <summary> Returns Channel Calibration Time Skew (component #2).  This is a convenience method that saves you from 
		/// casting and handling an exception.
		/// </summary>
		virtual public NM ChannelCalibrationTimeSkew
		{
			get
			{
				NM ret = null;
				try
				{
					ret = (NM) getComponent(2);
				}
				catch (DataTypeException)
				{
					throw new Exception();
				}
				return ret;
			}
			
		}
		
		private Type[] data;
		
		/// <summary> Creates a CCP.</summary>
		/// <param name="message">the Message to which this Type belongs
		/// </param>
		public CCP(Message message):base(message)
		{
			data = new Type[3];
			data[0] = new NM(message);
			data[1] = new NM(message);
			data[2] = new NM(message);
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
				throw new DataTypeException("Element " + number + " doesn't exist in 3 element CCP composite");
			}
		}
	}
}