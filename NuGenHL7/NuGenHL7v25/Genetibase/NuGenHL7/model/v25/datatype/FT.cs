using System;
using Primitive = Genetibase.NuGenHL7.model.Primitive;
using DataTypeException = Genetibase.NuGenHL7.model.DataTypeException;
using Message = Genetibase.NuGenHL7.model.Message;
using Type = Genetibase.NuGenHL7.model.Type;
using AbstractPrimitive = Genetibase.NuGenHL7.model.AbstractPrimitive;
namespace Genetibase.NuGenHL7.model.v25.datatype
{
	
	/// <summary> <p>Represents the HL7 FT (Formatted Text Data) datatype.  A FT contains a single String value.</summary>
	[Serializable]
	public class FT:AbstractPrimitive
	{
		/// <returns> "2.5"
		/// </returns>
		virtual public System.String Version
		{
			get
			{
				return "2.5";
			}
			
		}
		
		/// <summary> Constructs an uninitialized FT.</summary>
		/// <param name="message">the Message to which this Type belongs
		/// </param>
		public FT(Message message):base(message)
		{
		}
	}
}