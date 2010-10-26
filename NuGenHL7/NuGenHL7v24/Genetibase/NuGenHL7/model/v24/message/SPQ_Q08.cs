using System;
using Genetibase.NuGenHL7.model.v24.group;
using Genetibase.NuGenHL7.model.v24.segment;
using HL7Exception = Genetibase.NuGenHL7.NuGenHL7Exception;
using ModelClassFactory = Genetibase.NuGenHL7.parser.NuGenModelClassFactory;
using DefaultModelClassFactory = Genetibase.NuGenHL7.parser.NuGenDefaultModelClassFactory;
using AbstractMessage = Genetibase.NuGenHL7.model.AbstractMessage;
namespace Genetibase.NuGenHL7.model.v24.message
{
	
	/// <summary> <p>Represents a SPQ_Q08 message structure (see chapter ?). This structure contains the 
	/// following elements: </p>
	/// 0: MSH (Message Header) <b></b><br>
	/// 1: SPR (Stored Procedure Request Definition) <b></b><br>
	/// 2: RDF (Table Row Definition) <b>optional </b><br>
	/// 3: DSC (Continuation Pointer) <b>optional </b><br>
	/// </summary>
	[Serializable]
	public class SPQ_Q08:AbstractMessage
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
		/// <summary> Returns SPR (Stored Procedure Request Definition) - creates it if necessary</summary>
		virtual public SPR SPR
		{
			get
			{
				SPR ret = null;
				try
				{
					ret = (SPR) this.get_Renamed("SPR");
				}
				catch (NuGenHL7Exception)
				{
					throw new Exception();
				}
				return ret;
			}
			
		}
		/// <summary> Returns RDF (Table Row Definition) - creates it if necessary</summary>
		virtual public RDF RDF
		{
			get
			{
				RDF ret = null;
				try
				{
					ret = (RDF) this.get_Renamed("RDF");
				}
				catch (NuGenHL7Exception)
				{
					throw new Exception();
				}
				return ret;
			}
			
		}
		/// <summary> Returns DSC (Continuation Pointer) - creates it if necessary</summary>
		virtual public DSC DSC
		{
			get
			{
				DSC ret = null;
				try
				{
					ret = (DSC) this.get_Renamed("DSC");
				}
				catch (NuGenHL7Exception)
				{
					throw new Exception();
				}
				return ret;
			}
			
		}
		
		/// <summary> Creates a new SPQ_Q08 Group with custom ModelClassFactory.</summary>
		public SPQ_Q08(ModelClassFactory factory):base(factory)
		{
			init(factory);
		}
		
		/// <summary> Creates a new SPQ_Q08 Group with DefaultModelClassFactory. </summary>
		public SPQ_Q08():base(new DefaultModelClassFactory())
		{
			init(new DefaultModelClassFactory());
		}
		
		private void  init(ModelClassFactory factory)
		{
			try
			{
				this.add(typeof(MSH), true, false);
				this.add(typeof(SPR), true, false);
				this.add(typeof(RDF), false, false);
				this.add(typeof(DSC), false, false);
			}
			catch (NuGenHL7Exception)
			{
			}
		}
	}
}