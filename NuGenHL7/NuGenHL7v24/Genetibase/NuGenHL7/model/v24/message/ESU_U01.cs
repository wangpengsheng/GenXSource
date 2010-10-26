using System;
using Genetibase.NuGenHL7.model.v24.group;
using Genetibase.NuGenHL7.model.v24.segment;
using HL7Exception = Genetibase.NuGenHL7.NuGenHL7Exception;
using ModelClassFactory = Genetibase.NuGenHL7.parser.NuGenModelClassFactory;
using DefaultModelClassFactory = Genetibase.NuGenHL7.parser.NuGenDefaultModelClassFactory;
using AbstractMessage = Genetibase.NuGenHL7.model.AbstractMessage;
namespace Genetibase.NuGenHL7.model.v24.message
{
	
	/// <summary> <p>Represents a ESU_U01 message structure (see chapter 13). This structure contains the 
	/// following elements: </p>
	/// 0: MSH (Message Header) <b></b><br>
	/// 1: EQU (Equipment Detail) <b></b><br>
	/// 2: ISD (Interaction Status Detail) <b>optional repeating</b><br>
	/// 3: ROL (Role) <b>optional </b><br>
	/// </summary>
	[Serializable]
	public class ESU_U01:AbstractMessage
	{
		/// <summary> Returns MSH (Message Header) - creates it if necessary</summary>
		virtual public MSH MSH
		{
			get
			{
				MSH ret = null;
				try
				{
					ret = (MSH) this.get_Renamed("MSH");
				}
				catch (NuGenHL7Exception)
				{
					throw new Exception();
				}
				return ret;
			}
			
		}
		/// <summary> Returns EQU (Equipment Detail) - creates it if necessary</summary>
		virtual public EQU EQU
		{
			get
			{
				EQU ret = null;
				try
				{
					ret = (EQU) this.get_Renamed("EQU");
				}
				catch (NuGenHL7Exception)
				{
					throw new Exception();
				}
				return ret;
			}
			
		}
		/// <summary> Returns the number of existing repetitions of ISD </summary>
		virtual public int ISDReps
		{
			get
			{
				int reps = - 1;
				try
				{
					reps = this.getAll("ISD").Length;
				}
				catch (NuGenHL7Exception)
				{
					System.String message = "Unexpected error accessing data - this is probably a bug in the source code generator.";
					throw new System.SystemException(message);
				}
				return reps;
			}
			
		}
		/// <summary> Returns ROL (Role) - creates it if necessary</summary>
		virtual public ROL ROL
		{
			get
			{
				ROL ret = null;
				try
				{
					ret = (ROL) this.get_Renamed("ROL");
				}
				catch (NuGenHL7Exception)
				{
					throw new Exception();
				}
				return ret;
			}
			
		}
		
		/// <summary> Creates a new ESU_U01 Group with custom ModelClassFactory.</summary>
		public ESU_U01(ModelClassFactory factory):base(factory)
		{
			init(factory);
		}
		
		/// <summary> Creates a new ESU_U01 Group with DefaultModelClassFactory. </summary>
		public ESU_U01():base(new DefaultModelClassFactory())
		{
			init(new DefaultModelClassFactory());
		}
		
		private void  init(ModelClassFactory factory)
		{
			try
			{
				this.add(typeof(MSH), true, false);
				this.add(typeof(EQU), true, false);
				this.add(typeof(ISD), false, true);
				this.add(typeof(ROL), false, false);
			}
			catch (NuGenHL7Exception)
			{
			}
		}
		
		/// <summary> Returns  first repetition of ISD (Interaction Status Detail) - creates it if necessary</summary>
		public virtual ISD getISD()
		{
			ISD ret = null;
			try
			{
				ret = (ISD) this.get_Renamed("ISD");
			}
			catch (NuGenHL7Exception)
			{
				throw new Exception();
			}
			return ret;
		}
		
		/// <summary> Returns a specific repetition of ISD
		/// (Interaction Status Detail) - creates it if necessary
		/// throws HL7Exception if the repetition requested is more than one 
		/// greater than the number of existing repetitions.
		/// </summary>
		public virtual ISD getISD(int rep)
		{
			return (ISD) this.get_Renamed("ISD", rep);
		}
	}
}