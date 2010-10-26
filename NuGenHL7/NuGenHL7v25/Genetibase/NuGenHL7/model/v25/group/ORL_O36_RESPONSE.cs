using System;
using ModelClassFactory = Genetibase.NuGenHL7.parser.NuGenModelClassFactory;
using HL7Exception = Genetibase.NuGenHL7.NuGenHL7Exception;
using Genetibase.NuGenHL7.model.v25.segment;
using Genetibase.NuGenHL7.model;
namespace Genetibase.NuGenHL7.model.v25.group
{
	/// <summary> <p>Represents the ORL_O36_RESPONSE Group.  A Group is an ordered collection of message 
	/// segments that can repeat together or be optionally in/excluded together.
	/// This Group contains the following elements: </p>
	/// 0: ORL_O36_PATIENT (a Group object) <b>optional </b><br>
	/// </summary>
	[Serializable]
	public class ORL_O36_RESPONSE:AbstractGroup
	{
		/// <summary> Returns ORL_O36_PATIENT (a Group object) - creates it if necessary</summary>
		virtual public ORL_O36_PATIENT PATIENT
		{
			get
			{
				ORL_O36_PATIENT ret = null;
				try
				{
					ret = (ORL_O36_PATIENT) this.get_Renamed("PATIENT");
				}
				catch (NuGenHL7Exception)
				{
					throw new Exception();
				}
				return ret;
			}
			
		}
		
		/// <summary> Creates a new ORL_O36_RESPONSE Group.</summary>
		public ORL_O36_RESPONSE(Group parent, ModelClassFactory factory):base(parent, factory)
		{
			try
			{
				this.add(typeof(ORL_O36_PATIENT), false, false);
			}
			catch (NuGenHL7Exception)
			{
			}
		}
	}
}