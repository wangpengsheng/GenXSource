/* -----------------------------------------------
 * NuGenPageFileBytesPeakMeter.cs
 * Author: Alex Nesterov
 * --------------------------------------------- */

using en  = Genetibase.PerformanceCounters.NuGenProcessCounter;
using cat = Genetibase.PerformanceCounters.Process;

using System;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.Windows.Forms;

namespace Genetibase.UI.NuGenMeters.Process
{
	/// <summary>
	/// Process -> Page File Bytes Peak
	/// </summary>
	[ToolboxItem(true)]
	public class NuGenPageFileBytesPeakMeter : Genetibase.UI.NuGenMeters.NuGenByteMeterBase
	{
		#region Declarations
		
		private IContainer components = null;

		#endregion

		#region Properties.Overriden

		private PerformanceCounter counter = cat.GetCounter(en.PageFileBytesPeak);

		/// <summary>
		/// Gets the <c>System.Diagnostics.PerformanceCounter</c> object with the specified parameters set.
		/// </summary>
		/// <value></value>
		protected override PerformanceCounter CounterType
		{
			get
			{
				return this.counter;
			}
		}

		/// <summary>
		/// Gets or sets the format for the counter.
		/// </summary>
		/// <value></value>
		public override string CounterFormat
		{
			get
			{
				return "Bytes";
			}
			set
			{
			}
		}

		#endregion

		#region Constructors

		/// <summary>
		/// Initializes a new instance of the <see cref="NuGenPageFileBytesPeakMeter"/> class.
		/// </summary>
		public NuGenPageFileBytesPeakMeter()
		{
			InitializeComponent();
		}
		
		#endregion

		#region Dispose

		/// <summary> 
		/// Clean up any resources being used.
		/// </summary>
		protected override void Dispose(bool disposing)
		{
			if (disposing)
			{
				if (components != null) components.Dispose();
			}
			
			base.Dispose(disposing);
		}
		
		#endregion

		#region Designer generated code
		
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			components = new System.ComponentModel.Container();
		}
		
		#endregion
	}
}