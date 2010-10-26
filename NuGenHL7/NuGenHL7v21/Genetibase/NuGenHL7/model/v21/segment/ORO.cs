using System;
using Genetibase.NuGenHL7.model;
using Genetibase.NuGenHL7.model.v21.datatype;
using ModelClassFactory = Genetibase.NuGenHL7.parser.NuGenModelClassFactory;
using HL7Exception = Genetibase.NuGenHL7.NuGenHL7Exception;
namespace Genetibase.NuGenHL7.model.v21.segment
{
	
	/// <summary> <p>Represents an HL7 ORO message segment. 
	/// This segment has the following fields:</p><p>
	/// ORO-1: ORDER ITEM ID (CE)<br> 
	/// ORO-2: SUBSTITUTE ALLOWED (ID)<br> 
	/// ORO-3: RESULTS COPIES TO (CN)<br> 
	/// ORO-4: STOCK LOCATION (ID)<br> 
	/// </p><p>The get...() methods return data from individual fields.  These methods 
	/// do not throw exceptions and may therefore have to handle exceptions internally.  
	/// If an exception is handled internally, it is logged and null is returned.  
	/// This is not expected to happen - if it does happen this indicates not so much 
	/// an exceptional circumstance as a bug in the code for this class.</p>    
	/// </summary>
	[Serializable]
	public class ORO:AbstractSegment
	{
		/// <summary> Returns ORDER ITEM ID (ORO-1).</summary>
		virtual public CE ORDERITEMID
		{
			get
			{
				CE ret = null;
				try
				{
					Type t = this.getField(1, 0);
					ret = (CE) t;
				}
				catch (System.InvalidCastException )
				{
					throw new Exception();
				}
				catch (NuGenHL7Exception)
				{
					throw new Exception();
				}
				return ret;
			}
			
		}
		/// <summary> Returns SUBSTITUTE ALLOWED (ORO-2).</summary>
		virtual public ID SUBSTITUTEALLOWED
		{
			get
			{
				ID ret = null;
				try
				{
					Type t = this.getField(2, 0);
					ret = (ID) t;
				}
				catch (System.InvalidCastException )
				{
					throw new Exception();
				}
				catch (NuGenHL7Exception)
				{
					throw new Exception();
				}
				return ret;
			}
			
		}
		/// <summary> Returns STOCK LOCATION (ORO-4).</summary>
		virtual public ID STOCKLOCATION
		{
			get
			{
				ID ret = null;
				try
				{
					Type t = this.getField(4, 0);
					ret = (ID) t;
				}
				catch (System.InvalidCastException )
				{
					throw new Exception();
				}
				catch (NuGenHL7Exception)
				{
					throw new Exception();
				}
				return ret;
			}
			
		}
		
		/// <summary> Creates a ORO (ORDER OTHER) segment object that belongs to the given 
		/// message.  
		/// </summary>
		public ORO(Group parent, ModelClassFactory factory):base(parent, factory)
		{
			Message message = Message;
			try
			{
				this.add(typeof(CE), false, 1, 200, new System.Object[]{message});
				this.add(typeof(ID), false, 1, 1, new System.Object[]{message, 0});
				this.add(typeof(CN), false, 0, 80, new System.Object[]{message});
				this.add(typeof(ID), false, 1, 2, new System.Object[]{message, 12});
			}
			catch (NuGenHL7Exception)
			{
			}
		}
		
		/// <summary> Returns a single repetition of RESULTS COPIES TO (ORO-3).</summary>
		/// <param name="rep">the repetition number (this is a repeating field)
		/// </param>
		/// <throws>  HL7Exception if the repetition number is invalid. </throws>
		public virtual CN getRESULTSCOPIESTO(int rep)
		{
			CN ret = null;
			try
			{
				Type t = this.getField(3, rep);
				ret = (CN) t;
			}
			catch (System.InvalidCastException )
			{
				throw new Exception();
			}
			return ret;
		}
		
		/// <summary> Returns all repetitions of RESULTS COPIES TO (ORO-3).</summary>
		public virtual CN[] getRESULTSCOPIESTO()
		{
			CN[] ret = null;
			try
			{
				Type[] t = this.getField(3);
				ret = new CN[t.Length];
				for (int i = 0; i < ret.Length; i++)
				{
					ret[i] = (CN) t[i];
				}
			}
			catch (System.InvalidCastException )
			{
				throw new Exception();
			}
			catch (NuGenHL7Exception)
			{
				throw new Exception();
			}
			return ret;
		}
	}
}