namespace Genetibase.NuGenMediImage
{
    using System;
    using System.Collections;
    using System.ComponentModel;
    using System.ComponentModel.Design.Serialization;
    using System.Globalization;

    /// <summary>Provides a type converter to convert <see cref="T:System.Windows.Forms.TabBar"></see> values to and from various other representations.</summary>
    public class TabBarConverter : TypeConverter
    {
        /// <summary>Returns whether this converter can convert an object of one type to the type of this converter.</summary>
        /// <returns>true if this object can perform the conversion; otherwise, false.</returns>
        /// <param name="context">An <see cref="T:System.ComponentModel.ITypeDescriptorContext"></see> that provides a format context.</param>
        /// <param name="sourceType">A <see cref="T:System.Type"></see> that represents the type you wish to convert from.</param>
        public override bool CanConvertFrom(ITypeDescriptorContext context, Type sourceType)
        {
            if (sourceType == typeof(string))
            {
                return true;
            }
            return base.CanConvertFrom(context, sourceType);
        }

        public override bool CanConvertTo(ITypeDescriptorContext context, Type destinationType)
        {
            if (destinationType == typeof(InstanceDescriptor))
            {
                return true;
            }
            return base.CanConvertTo(context, destinationType);
        }

        public override object ConvertFrom(ITypeDescriptorContext context, CultureInfo culture, object value)
        {
            string text1 = value as string;            
            TabBar viewer1 = (TabBar)context.PropertyDescriptor.GetValue(context.Instance);

            if (text1 != null)
            {
                text1 = text1.Trim();
                if (text1.Length != 0)
                {
                    if (culture == null)
                    {
                        culture = CultureInfo.CurrentCulture;
                    }
                    char ch1 = culture.TextInfo.ListSeparator[0];
                    string[] textArray1 = text1.Split(new char[] { ch1 });

                    viewer1.Collapsed = Boolean.Parse(textArray1[0]);
                    viewer1.Visible = Boolean.Parse(textArray1[1]);
                    viewer1.ShowStartTab = Boolean.Parse(textArray1[2]);
                }
                return viewer1;
            }
            return base.ConvertFrom(context, culture, value);
        }

        public override object ConvertTo(ITypeDescriptorContext context, CultureInfo culture, object value, Type destinationType)
        {
            if (destinationType == null)
            {
                throw new ArgumentNullException("destinationType");
            }
            if (value is TabBar)
            {
                if (destinationType == typeof(string))
                {
                    TabBar TabBar1 = (TabBar)value;
                    if (culture == null)
                    {
                        culture = CultureInfo.CurrentCulture;
                    }
                    string text1 = culture.TextInfo.ListSeparator + " ";
                    TypeConverter converter1 = TypeDescriptor.GetConverter(typeof(Boolean));
                    string[] textArray1 = new string[4];
                    int num1 = 0;
                    textArray1[num1++] = converter1.ConvertToString(context, culture, TabBar1.Visible);
                    textArray1[num1++] = converter1.ConvertToString(context, culture, TabBar1.Collapsed);
                    textArray1[num1++] = converter1.ConvertToString(context, culture, TabBar1.ShowStartTab);
                    return string.Join(text1, textArray1);
                }
                if (destinationType == typeof(InstanceDescriptor))
                {
                    TabBar TabBar2 = (TabBar)value;
                    return new InstanceDescriptor(typeof(TabBar).GetConstructor(new Type[] { typeof(bool), typeof(bool), typeof(bool) }), new object[] { TabBar2.Visible, TabBar2.Collapsed, TabBar2.ShowStartTab });
                }
            }
            return base.ConvertTo(context, culture, value, destinationType);
        }

        public override object CreateInstance(ITypeDescriptorContext context, IDictionary propertyValues)
        {
            if (context == null)
            {
                throw new ArgumentNullException("context");
            }
            if (propertyValues == null)
            {
                throw new ArgumentNullException("propertyValues");
            }
            TabBar TabBar1 = (TabBar)context.PropertyDescriptor.GetValue(context.Instance);

            TabBar1.Visible = (bool)propertyValues["Visible"];
            TabBar1.Collapsed =(bool)propertyValues["Collapsed"];
            TabBar1.ShowStartTab = (bool)propertyValues["ShowStartTab"];

            return TabBar1;
        }

        public override bool GetCreateInstanceSupported(ITypeDescriptorContext context)
        {
            return true;
        }

        public override PropertyDescriptorCollection GetProperties(ITypeDescriptorContext context, object value, Attribute[] attributes)
        {
            return TypeDescriptor.GetProperties(typeof(TabBar), attributes).Sort(new string[] { "All", "Left", "Top", "Right", "Visible" });
        }

        public override bool GetPropertiesSupported(ITypeDescriptorContext context)
        {
            return true;
        }

    }
}

