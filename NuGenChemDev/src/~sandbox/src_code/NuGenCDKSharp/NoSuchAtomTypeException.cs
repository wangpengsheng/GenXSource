/* $RCSfile$   
* $Author: egonw $   
* $Date: 2006-05-02 11:17:35 +0200 (Tue, 02 May 2006) $   
* $Revision: 6123 $
*
*  Copyright (C) 1997-2006  The Chemistry Development Kit (CDK) project
*
*  Contact: cdk-devel@lists.sourceforge.net
*
*  This program is free software; you can redistribute it and/or
*  modify it under the terms of the GNU Lesser General Public License
*  as published by the Free Software Foundation; either version 2.1
*  of the License, or (at your option) any later version.
*  All we ask is that proper credit is given for our work, which includes
*  - but is not limited to - adding the above copyright notice to the beginning
*  of your source code files, and to any copyright notice that you may distribute
*  with programs based on this work.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU Lesser General Public License for more details.
*
*  You should have received a copy of the GNU Lesser General Public License
*  along with this program; if not, write to the Free Software
*  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
*
*/
using System;

namespace Org.OpenScience.CDK.Exception
{
    /// <summary> Exception that may be thrown when an atom type is looked up or perceived
    /// but no such atom type was found.
    /// 
    /// </summary>
    /// <cdk.module>  core </cdk.module>
    [Serializable]
    public class NoSuchAtomTypeException : CDKException
    {

        private const long serialVersionUID = 2689048410917221667L;

        /// <summary> Constructs a new NoSuchAtomTypeException.
        /// 
        /// </summary>
        /// <param name="message">Message explaining why the atom type could not be found
        /// </param>
        public NoSuchAtomTypeException(System.String message)
            : base(message)
        {
        }
    }
}