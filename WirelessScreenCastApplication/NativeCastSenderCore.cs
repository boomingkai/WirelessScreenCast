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
        public static extern void Init();

        [DllImport("CASTSENDERCORE.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void StartCast();

        [DllImport("CASTSENDERCORE.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void ShutDownCast();
    }
}
