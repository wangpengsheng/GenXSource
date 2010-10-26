using System;
using Genetibase.NuGenHL7.model.v22.group;
using Genetibase.NuGenHL7.model.v22.segment;
using HL7Exception = Genetibase.NuGenHL7.NuGenHL7Exception;
using ModelClassFactory = Genetibase.NuGenHL7.parser.NuGenModelClassFactory;
using DefaultModelClassFactory = Genetibase.NuGenHL7.parser.NuGenDefaultModelClassFactory;
using AbstractMessage = Genetibase.NuGenHL7.model.AbstractMessage;
namespace Genetibase.NuGenHL7.model.v22.message
{
	
	/// <summary> <p>Represents a NMR_N02 message structure (see chapter ?). This structure contains the 
	/// following elements: </p>
	/// 0: MSH (MESSAGE HEADER) <b></b><br>
	/// 1: MSA (MESSAGE ACKNOWLEDGMENT) <b></b><br>
	/// 2: ERR (ERROR) <b>optional </b><br>
	/// 3: QRD (QUERY DEFINITION) <b>optional </b><br>
	/// 4: NMR_N02_CLOCK_AND_STATS_WITH_NOTES_ALT (a Group object) <b>repeating</b><br>
	/// </summary>
	[Serializable]
	public class NMR_N02:AbstractMessage
	{
		/// <summary> Returns MSH (MESSAGE HEADER) - creates it if necessary</summary>
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
		/// <summary> Returns MSA (MESSAGE ACKNOWLEDGMENT) - creates it if necessary</summary>
		virtual public MSA MSA
		{
			get
			{
				MSA ret = null;
				try
				{
					ret = (MSA) this.get_Renamed("MSA");
				}
				catch (NuGenHL7Exception)
				{
					throw new Exception();
				}
				return ret;
			}
			
		}
		/// <summary> Returns ERR (ERROR) - creates it if necessary</summary>
		virtual public ERR ERR
		{
			get
			{
				ERR ret = null;
				try
				{
					ret = (ERR) this.get_Renamed("ERR");
				}
				catch (NuGenHL7Exception)
				{
					throw new Exception();
				}
				return ret;
			}
			
		}
		/// <summary> Returns QRD (QUERY DEFINITION) - creates it if necessary</summary>
		virtual public QRD QRD
		{
			get
			{
				QRD ret = null;
				try
				{
					ret = (QRD) this.get_Renamed("QRD");
				}
				catch (NuGenHL7Exception)
				{
					throw new Exception();
				}
				return ret;
			}
			
		}
		/// <summary> Returns the number of existing repetitions of NMR_N02_CLOCK_AND_STATS_WITH_NOTES_ALT </summary>
		virtual public int CLOCK_AND_STATS_WITH_NOTES_ALTReps
		{
			get
			{
				int reps = - 1;
				try
				{
					reps = this.getAll("CLOCK_AND_STATS_WITH_NOTES_ALT").Length;
				}
				catch (NuGenHL7Exception)
				{
					System.String message = "Unexpected error accessing data - this is probably a bug in the source code generator.";
					throw new System.SystemException(message);
				}
				return reps;
			}
			
		}
		
		/// <summary> Creates a new NMR_N02 Group with custom ModelClassFactory.</summary>
		public NMR_N02(ModelClassFactory factory):base(factory)
		{
			init(factory);
		}
		
		/// <summary> Creates a new NMR_N02 Group with DefaultModelClassFactory. </summary>
		public NMR_N02():base(new DefaultModelClassFactory())
		{
			init(new DefaultModelClassFactory());
		}
		
		private void  init(ModelClassFactory factory)
		{
			try
			{
				this.add(typeof(MSH), true, false);
				this.add(typeof(MSA), true, false);
				this.add(typeof(ERR), false, false);
				this.add(typeof(QRD), false, false);
				this.add(typeof(NMR_N02_CLOCK_AND_STATS_WITH_NOTES_ALT), true, true);
			}
			catch (NuGenHL7Exception)
			{
			}
		}
		
		/// <summary> Returns  first repetition of NMR_N02_CLOCK_AND_STATS_WITH_NOTES_ALT (a Group object) - creates it if necessary</summary>
		public virtual NMR_N02_CLOCK_AND_STATS_WITH_NOTES_ALT getCLOCK_AND_STATS_WITH_NOTES_ALT()
		{
			NMR_N02_CLOCK_AND_STATS_WITH_NOTES_ALT ret = null;
			try
			{
				ret = (NMR_N02_CLOCK_AND_STATS_WITH_NOTES_ALT) this.get_Renamed("CLOCK_AND_STATS_WITH_NOTES_ALT");
			}
			catch (NuGenHL7Exception)
			{
				throw new Exception();
			}
			return ret;
		}
		
		/// <summary> Returns a specific repetition of NMR_N02_CLOCK_AND_STATS_WITH_NOTES_ALT
		/// (a Group object) - creates it if necessary
		/// throws HL7Exception if the repetition requested is more than one 
		/// greater than the number of existing repetitions.
		/// </summary>
		public virtual NMR_N02_CLOCK_AND_STATS_WITH_NOTES_ALT getCLOCK_AND_STATS_WITH_NOTES_ALT(int rep)
		{
			return (NMR_N02_CLOCK_AND_STATS_WITH_NOTES_ALT) this.get_Renamed("CLOCK_AND_STATS_WITH_NOTES_ALT", rep);
		}
	}
}