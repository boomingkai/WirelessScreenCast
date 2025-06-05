using System;
using System.Configuration;
using System.Data;
using System.Windows;

namespace WirelessScreenCastApplication
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
        [STAThread]
        public static void Main()
        {
            var app = new App(); // 实例化 WPF Application
            app.InitializeComponent();
            app.Run();
        }
    }

}
