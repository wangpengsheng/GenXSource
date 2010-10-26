/* -----------------------------------------------
 * INuGenToolTipRenderer.cs
 * Copyright � 2007 Anthony Nystrom
 * mailto:a.nystrom@genetibase.com
 * --------------------------------------------- */

using System;
using System.Collections.Generic;
using System.Diagnostics;

namespace Genetibase.Shared.Controls.ToolTipInternals
{
	/// <summary>
	/// </summary>
	public interface INuGenToolTipRenderer
	{
		/// <summary>
		/// </summary>
		void DrawBackground(NuGenPaintParams paintParams);

		/// <summary>
		/// </summary>
		void DrawBevel(NuGenPaintParams paintParams);

		/// <summary>
		/// </summary>
		void DrawBorder(NuGenPaintParams paintParams);

		/// <summary>
		/// </summary>
		void DrawImage(NuGenImagePaintParams paintParams);

		/// <summary>
		/// </summary>
		void DrawShadow(NuGenPaintParams paintParams);

		/// <summary>
		/// </summary>
		void DrawHeaderText(NuGenTextPaintParams paintParams);

		/// <summary>
		/// </summary>
		void DrawText(NuGenTextPaintParams paintParams);
	}
}