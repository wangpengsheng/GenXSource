using System;
using ModelClassFactory = Genetibase.NuGenHL7.parser.NuGenModelClassFactory;
using HL7Exception = Genetibase.NuGenHL7.NuGenHL7Exception;
using Genetibase.NuGenHL7.model.v24.segment;
using Genetibase.NuGenHL7.model;
namespace Genetibase.NuGenHL7.model.v24.group
{
	/// <summary> <p>Represents the RRG_O16_ORDER Group.  A Group is an ordered collection of message 
	/// segments that can repeat together or be optionally in/excluded together.
	/// This Group contains the following elements: </p>
	/// 0: ORC (Common Order) <b></b><br>
	/// 1: RRG_O16_GIVE (a Group object) <b>optional </b><br>
	/// </summary>
	[Serializable]
	public class RRG_O16_ORDER:AbstractGroup
	{
		/// <summary> Returns ORC (Common Order) - creates it if necessary</summary>
		virtual public ORC ORC
		{
			get
			{
				ORC ret = null;
				try
				{
					ret = (ORC) this.get_Renamed("ORC");
				}
				catch (NuGenHL7Exception)
				{
					throw new Exception();
				}
				return ret;
			}
			
		}
		/// <summary> Returns RRG_O16_GIVE (a Group object) - creates it if necessary</summary>
		virtual public RRG_O16_GIVE GIVE
		{
			get
			{
				RRG_O16_GIVE ret = null;
				try
				{
					ret = (RRG_O16_GIVE) this.get_Renamed("GIVE");
				}
				catch (NuGenHL7Exception)
				{
					throw new Exception();
				}
				return ret;
			}
			
		}
		
		/// <summary> Creates a new RRG_O16_ORDER Group.</summary>
		public RRG_O16_ORDER(Group parent, ModelClassFactory factory):base(parent, factory)
		{
			try
			{
				this.add(typeof(ORC), true, false);
				this.add(typeof(RRG_O16_GIVE), false, false);
			}
			catch (NuGenHL7Exception)
			{
			}
		}
	}
}