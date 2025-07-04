﻿using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WirelessScreenCastApplication
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            NativeCastSenderCore.Init();
        }

        private async void Start_Button_Click(object sender, RoutedEventArgs e)
        {
            NativeCastSenderCore.StartCast();
        }
        private void Stop_Button_Click(object sender, RoutedEventArgs e)
        {
            NativeCastSenderCore.ShutDownCast();
        }
    }
}