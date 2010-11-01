/* -----------------------------------------------
 * NuGenLog.cs
 * Copyright � 2006 Alex Nesterov
 * mailto:a.nesterov@genetibase.com
 * --------------------------------------------- */

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Reflection;
using System.Text;

namespace Genetibase.Shared.Diagnostics
{
	/// <summary>
	/// Provides functionality to write logs.
	/// </summary>
	public static class NuGenLog
	{
		private static int _lineCount = 0;

		/// <summary>
		/// Pushes the specified message into the log.
		/// </summary>
		/// <param name="message">Specifies the message to log.</param>
		public static void Log(string message)
		{
			StackTrace stackTrace = new StackTrace(0);
			
			Debug.WriteLine(
				string.Format(
					"<{0}> <{1}> {2}",
					(++_lineCount).ToString("00000"),
					stackTrace.GetFrame(1).GetMethod().Name,
					message
				)
			);
		}
	}
}
