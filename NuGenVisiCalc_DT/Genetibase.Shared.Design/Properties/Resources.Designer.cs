﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:2.0.50727.1378
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace Genetibase.Shared.Design.Properties {
    using System;
    
    
    /// <summary>
    ///   A strongly-typed resource class, for looking up localized strings, etc.
    /// </summary>
    // This class was auto-generated by the StronglyTypedResourceBuilder
    // class via a tool like ResGen or Visual Studio.
    // To add or remove a member, edit your .ResX file then rerun ResGen
    // with the /str option, or rebuild your VS project.
    [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Resources.Tools.StronglyTypedResourceBuilder", "2.0.0.0")]
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
    [global::System.Runtime.CompilerServices.CompilerGeneratedAttribute()]
    internal class Resources {
        
        private static global::System.Resources.ResourceManager resourceMan;
        
        private static global::System.Globalization.CultureInfo resourceCulture;
        
        [global::System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1811:AvoidUncalledPrivateCode")]
        internal Resources() {
        }
        
        /// <summary>
        ///   Returns the cached ResourceManager instance used by this class.
        /// </summary>
        [global::System.ComponentModel.EditorBrowsableAttribute(global::System.ComponentModel.EditorBrowsableState.Advanced)]
        internal static global::System.Resources.ResourceManager ResourceManager {
            get {
                if (object.ReferenceEquals(resourceMan, null)) {
                    global::System.Resources.ResourceManager temp = new global::System.Resources.ResourceManager("Genetibase.Shared.Design.Properties.Resources", typeof(Resources).Assembly);
                    resourceMan = temp;
                }
                return resourceMan;
            }
        }
        
        /// <summary>
        ///   Overrides the current thread's CurrentUICulture property for all
        ///   resource lookups using this strongly typed resource class.
        /// </summary>
        [global::System.ComponentModel.EditorBrowsableAttribute(global::System.ComponentModel.EditorBrowsableState.Advanced)]
        internal static global::System.Globalization.CultureInfo Culture {
            get {
                return resourceCulture;
            }
            set {
                resourceCulture = value;
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to The transparency level should be between 0 and 100..
        /// </summary>
        internal static string Argument_InvalidTransparencyLevel {
            get {
                return ResourceManager.GetString("Argument_InvalidTransparencyLevel", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to Alert.
        /// </summary>
        internal static string Caption_Alert {
            get {
                return ResourceManager.GetString("Caption_Alert", resourceCulture);
            }
        }
        
        internal static System.Drawing.Bitmap Down {
            get {
                object obj = ResourceManager.GetObject("Down", resourceCulture);
                return ((System.Drawing.Bitmap)(obj));
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to The value should be an integer between 0 and 100..
        /// </summary>
        internal static string Message_TransparencyConverter_FormatException {
            get {
                return ResourceManager.GetString("Message_TransparencyConverter_FormatException", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to &amp;Cancel.
        /// </summary>
        internal static string Text_CollectionEditor_cancelButton {
            get {
                return ResourceManager.GetString("Text_CollectionEditor_cancelButton", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to &amp;Ok.
        /// </summary>
        internal static string Text_CollectionEditor_okButton {
            get {
                return ResourceManager.GetString("Text_CollectionEditor_okButton", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to &amp;Cancel.
        /// </summary>
        internal static string Text_StringCollectionEditor_cancelButton {
            get {
                return ResourceManager.GetString("Text_StringCollectionEditor_cancelButton", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to Enter the strings in the collection (one per line):.
        /// </summary>
        internal static string Text_StringCollectionEditor_editBoxLabel {
            get {
                return ResourceManager.GetString("Text_StringCollectionEditor_editBoxLabel", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to String Collection Editor.
        /// </summary>
        internal static string Text_StringCollectionEditor_EditorForm {
            get {
                return ResourceManager.GetString("Text_StringCollectionEditor_EditorForm", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to &amp;Ok.
        /// </summary>
        internal static string Text_StringCollectionEditor_okButton {
            get {
                return ResourceManager.GetString("Text_StringCollectionEditor_okButton", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to 0%.
        /// </summary>
        internal static string Text_TransparencyEditor_transparencyLabel {
            get {
                return ResourceManager.GetString("Text_TransparencyEditor_transparencyLabel", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to Ctrl + Enter for new line. Enter to accept changes..
        /// </summary>
        internal static string ToolTip_MultilineUI_EditBox {
            get {
                return ResourceManager.GetString("ToolTip_MultilineUI_EditBox", resourceCulture);
            }
        }
        
        internal static System.Drawing.Bitmap Up {
            get {
                object obj = ResourceManager.GetObject("Up", resourceCulture);
                return ((System.Drawing.Bitmap)(obj));
            }
        }
    }
}