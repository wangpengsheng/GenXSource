/* -----------------------------------------------
 * NuGenTabControlActionList.cs
 * Copyright � 2006 Alex Nesterov
 * mailto:a.nesterov@genetibase.com
 * --------------------------------------------- */

using Genetibase.Shared.Collections;
using Genetibase.Shared.Controls.Properties;

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.ComponentModel.Design;
using System.Windows.Forms;

namespace Genetibase.Shared.Controls.Design
{
	/// <summary>
	/// </summary>
	public class NuGenTabControlActionList : DesignerActionList
	{
		#region Declarations.Fields

		private NuGenTabControl _tabControl = null;

		#endregion

		#region Methods.Public.Overridden

		/*
		 * GetSortedActionItems
		 */

		/// <summary>
		/// Returns the collection of <see cref="T:System.ComponentModel.Design.DesignerActionItem"></see> objects contained in the list.
		/// </summary>
		/// <returns>
		/// A <see cref="T:System.ComponentModel.Design.DesignerActionItem"></see> array that contains the items in this list.
		/// </returns>
		public override DesignerActionItemCollection GetSortedActionItems()
		{
			DesignerActionItemCollection actionItems = new DesignerActionItemCollection();

			actionItems.Add(
				new DesignerActionMethodItem(
					this,
					"AddTabPage",
					Resources.ActionList_TabControl_AddTabPage
				)
			);
			actionItems.Add(
				new DesignerActionMethodItem(
					this,
					"RemoveTabPage",
					Resources.ActionList_TabControl_RemoveTabPage
				)
			);

			return actionItems;
		}

		#endregion

		#region Methods.Public

		/*
		 * AddTabPage
		 */

		/// <summary>
		/// </summary>
		public virtual void AddTabPage()
		{
			this.CreateTabPage<NuGenTabPage>();
		}

		/*
		 * RemoveTabPage
		 */

		/// <summary>
		/// </summary>
		public virtual void RemoveTabPage()
		{
			if (_tabControl.SelectedTab != null)
			{
				this.DestroyTabPage(_tabControl.SelectedTab);
			}
		}

		#endregion

		#region Methods.Protected

		/// <summary>
		/// </summary>
		protected void CreateTabPage<TPage>() where TPage : NuGenTabPage
		{
			IDesignerHost host = (IDesignerHost)this.GetService(typeof(IDesignerHost));

			if (host != null)
			{
				DesignerTransaction transaction = null;

				try
				{
					try
					{
						transaction = host.CreateTransaction("NuGenTabControl.AddTabPage");
					}
					catch (CheckoutException e)
					{
						if (e != CheckoutException.Canceled)
						{
							throw e;
						}

						return;
					}

					TPage tabPage = (TPage)host.CreateComponent(typeof(TPage));
					_tabControl.TabPages.Add(tabPage);

					PropertyDescriptor textDescriptor = TypeDescriptor.GetProperties(tabPage)["Text"];

					if (textDescriptor != null)
					{
						textDescriptor.SetValue(tabPage, Resources.BlankText);
					}
				}
				finally
				{
					if (transaction != null)
					{
						transaction.Commit();
					}
				}
			}
		}

		/// <summary>
		/// </summary>
		/// <param name="tabPageToDestroy"></param>
		/// <exception cref="ArgumentNullException">
		/// <para>
		///		<paramref name="tabPageToDestroy"/> is <see langword="null"/>.
		/// </para>
		/// </exception>
		protected void DestroyTabPage(NuGenTabPage tabPageToDestroy)
		{
			if (tabPageToDestroy == null)
			{
				throw new ArgumentNullException("tabPageToDestroy");
			}

			IDesignerHost host = (IDesignerHost)this.GetService(typeof(IDesignerHost));

			if (host != null)
			{
				DesignerTransaction transaction = null;

				try
				{
					try
					{
						transaction = host.CreateTransaction("NuGenTabControl.RemoveTabPage");
					}
					catch (CheckoutException e)
					{
						if (e != CheckoutException.Canceled)
						{
							throw e;
						}

						return;
					}

					_tabControl.TabPages.Remove(tabPageToDestroy);
					host.DestroyComponent(tabPageToDestroy);
				}
				finally
				{
					if (transaction != null)
					{
						transaction.Commit();
					}
				}
			}
		}

		#endregion

		#region EventHandlers

		private void _tabControl_TabPageRemoved(object sender, NuGenCollectionEventArgs<NuGenTabPage> e)
		{
			if (e.Item != null)
			{
				this.DestroyTabPage(e.Item);
			}
		}

		#endregion

		#region Constructors

		/// <summary>
		/// Initializes a new instance of the <see cref="NuGenTabControlActionList"/> class.
		/// </summary>
		/// <exception cref="ArgumentNullException">
		///	<para>
		///		<paramref name="tabControl"/> is <see langword="null"/>.
		/// </para>
		/// </exception>
		public NuGenTabControlActionList(NuGenTabControl tabControl)
			: base(tabControl)
		{
			if (tabControl == null)
			{
				throw new ArgumentNullException("tabControl");
			}

			_tabControl = tabControl;
			_tabControl.TabPageRemoved += _tabControl_TabPageRemoved;
		}

		#endregion
	}
}
