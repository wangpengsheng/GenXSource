using System;
using Genetibase.NuGenHL7.model;
using Genetibase.NuGenHL7.model.v21.datatype;
using ModelClassFactory = Genetibase.NuGenHL7.parser.NuGenModelClassFactory;
using HL7Exception = Genetibase.NuGenHL7.NuGenHL7Exception;
namespace Genetibase.NuGenHL7.model.v21.segment
{
	
	/// <summary> <p>Represents an HL7 URD message segment. 
	/// This segment has the following fields:</p><p>
	/// URD-1: R/U DATE/TIME (TS)<br> 
	/// URD-2: REPORT PRIORITY (ID)<br> 
	/// URD-3: R/U WHO SUBJECT DEFINITION (ST)<br> 
	/// URD-4: R/U WHAT SUBJECT DEFINITION (ID)<br> 
	/// URD-5: R/U WHAT DEPARTMENT CODE (ST)<br> 
	/// URD-6: R/U DISPLAY/PRINT LOCATIONS (ST)<br> 
	/// URD-7: R/U RESULTS LEVEL (ID)<br> 
	/// </p><p>The get...() methods return data from individual fields.  These methods 
	/// do not throw exceptions and may therefore have to handle exceptions internally.  
	/// If an exception is handled internally, it is logged and null is returned.  
	/// This is not expected to happen - if it does happen this indicates not so much 
	/// an exceptional circumstance as a bug in the code for this class.</p>    
	/// </summary>
	[Serializable]
	public class URD:AbstractSegment
	{
		/// <summary> Returns R/U DATE/TIME (URD-1).</summary>
		virtual public TS RUDATETIME
		{
			get
			{
				TS ret = null;
				try
				{
					Type t = this.getField(1, 0);
					ret = (TS) t;
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
		/// <summary> Returns REPORT PRIORITY (URD-2).</summary>
		virtual public ID REPORTPRIORITY
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
		/// <summary> Returns R/U RESULTS LEVEL (URD-7).</summary>
		virtual public ID RURESULTSLEVEL
		{
			get
			{
				ID ret = null;
				try
				{
					Type t = this.getField(7, 0);
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
		
		/// <summary> Creates a URD (RESULTS/UPDATE DEFINITION) segment object that belongs to the given 
		/// message.  
		/// </summary>
		public URD(Group parent, ModelClassFactory factory):base(parent, factory)
		{
			Message message = Message;
			try
			{
				this.add(typeof(TS), false, 1, 19, new System.Object[]{message});
				this.add(typeof(ID), false, 1, 1, new System.Object[]{message, 109});
				this.add(typeof(ST), true, 0, 20, new System.Object[]{message});
				this.add(typeof(ID), false, 0, 3, new System.Object[]{message, 48});
				this.add(typeof(ST), false, 0, 20, new System.Object[]{message});
				this.add(typeof(ST), false, 0, 20, new System.Object[]{message});
				this.add(typeof(ID), false, 1, 1, new System.Object[]{message, 108});
			}
			catch (NuGenHL7Exception)
			{
			}
		}
		
		/// <summary> Returns a single repetition of R/U WHO SUBJECT DEFINITION (URD-3).</summary>
		/// <param name="rep">the repetition number (this is a repeating field)
		/// </param>
		/// <throws>  HL7Exception if the repetition number is invalid. </throws>
		public virtual ST getRUWHOSUBJECTDEFINITION(int rep)
		{
			ST ret = null;
			try
			{
				Type t = this.getField(3, rep);
				ret = (ST) t;
			}
			catch (System.InvalidCastException )
			{
				throw new Exception();
			}
			return ret;
		}
		
		/// <summary> Returns all repetitions of R/U WHO SUBJECT DEFINITION (URD-3).</summary>
		public virtual ST[] getRUWHOSUBJECTDEFINITION()
		{
			ST[] ret = null;
			try
			{
				Type[] t = this.getField(3);
				ret = new ST[t.Length];
				for (int i = 0; i < ret.Length; i++)
				{
					ret[i] = (ST) t[i];
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
		
		/// <summary> Returns a single repetition of R/U WHAT SUBJECT DEFINITION (URD-4).</summary>
		/// <param name="rep">the repetition number (this is a repeating field)
		/// </param>
		/// <throws>  HL7Exception if the repetition number is invalid. </throws>
		public virtual ID getRUWHATSUBJECTDEFINITION(int rep)
		{
			ID ret = null;
			try
			{
				Type t = this.getField(4, rep);
				ret = (ID) t;
			}
			catch (System.InvalidCastException )
			{
				throw new Exception();
			}
			return ret;
		}
		
		/// <summary> Returns all repetitions of R/U WHAT SUBJECT DEFINITION (URD-4).</summary>
		public virtual ID[] getRUWHATSUBJECTDEFINITION()
		{
			ID[] ret = null;
			try
			{
				Type[] t = this.getField(4);
				ret = new ID[t.Length];
				for (int i = 0; i < ret.Length; i++)
				{
					ret[i] = (ID) t[i];
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
		
		/// <summary> Returns a single repetition of R/U WHAT DEPARTMENT CODE (URD-5).</summary>
		/// <param name="rep">the repetition number (this is a repeating field)
		/// </param>
		/// <throws>  HL7Exception if the repetition number is invalid. </throws>
		public virtual ST getRUWHATDEPARTMENTCODE(int rep)
		{
			ST ret = null;
			try
			{
				Type t = this.getField(5, rep);
				ret = (ST) t;
			}
			catch (System.InvalidCastException )
			{
				throw new Exception();
			}
			return ret;
		}
		
		/// <summary> Returns all repetitions of R/U WHAT DEPARTMENT CODE (URD-5).</summary>
		public virtual ST[] getRUWHATDEPARTMENTCODE()
		{
			ST[] ret = null;
			try
			{
				Type[] t = this.getField(5);
				ret = new ST[t.Length];
				for (int i = 0; i < ret.Length; i++)
				{
					ret[i] = (ST) t[i];
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
		
		/// <summary> Returns a single repetition of R/U DISPLAY/PRINT LOCATIONS (URD-6).</summary>
		/// <param name="rep">the repetition number (this is a repeating field)
		/// </param>
		/// <throws>  HL7Exception if the repetition number is invalid. </throws>
		public virtual ST getRUDISPLAYPRINTLOCATIONS(int rep)
		{
			ST ret = null;
			try
			{
				Type t = this.getField(6, rep);
				ret = (ST) t;
			}
			catch (System.InvalidCastException )
			{
				throw new Exception();
			}
			return ret;
		}
		
		/// <summary> Returns all repetitions of R/U DISPLAY/PRINT LOCATIONS (URD-6).</summary>
		public virtual ST[] getRUDISPLAYPRINTLOCATIONS()
		{
			ST[] ret = null;
			try
			{
				Type[] t = this.getField(6);
				ret = new ST[t.Length];
				for (int i = 0; i < ret.Length; i++)
				{
					ret[i] = (ST) t[i];
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