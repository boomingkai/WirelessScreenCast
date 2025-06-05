using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace WirelessScreenCastApplication
{
    internal class NativeCastSenderCore
    {
        [DllImport("CASTSENDERCORE.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern bool Init();

        [DllImport("CASTSENDERCORE.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern bool UnInit();
    }
}
