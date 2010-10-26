using System;
using Genetibase.NuGenHL7.model;
using Genetibase.NuGenHL7.model.v231.datatype;
using ModelClassFactory = Genetibase.NuGenHL7.parser.NuGenModelClassFactory;
using HL7Exception = Genetibase.NuGenHL7.NuGenHL7Exception;
namespace Genetibase.NuGenHL7.model.v231.segment
{
	
	/// <summary> <p>Represents an HL7 Hxx message segment. 
	/// This segment has the following fields:</p><p>
	/// </p><p>The get...() methods return data from individual fields.  These methods 
	/// do not throw exceptions and may therefore have to handle exceptions internally.  
	/// If an exception is handled internally, it is logged and null is returned.  
	/// This is not expected to happen - if it does happen this indicates not so much 
	/// an exceptional circumstance as a bug in the code for this class.</p>    
	/// </summary>
	[Serializable]
	public class Hxx:AbstractSegment
	{
		
		/// <summary> Creates a Hxx (null) segment object that belongs to the given 
		/// message.  
		/// </summary>
		public Hxx(Group parent, ModelClassFactory factory):base(parent, factory)
		{
			Message message = Message;
		}
	}
}