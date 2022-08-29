using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Media.Animation;
using System.Threading;

namespace WPFGlobalization
{
    /// <summary>
    /// Interaction logic for ucMain.xaml
    /// </summary>
    public partial class ucMain : UserControl
    {
        public ucMain()
        {
            InitializeComponent();
        }

        public bool IsSuccess { get; set; }
        private void UserControl_Loaded(object sender, RoutedEventArgs e)
        {
            this.SetLanguageDictionary();
            tbStatus.Text = IsSuccess ? this.Resources["successkey"].ToString() : this.Resources["unsuccesskey"].ToString();
            Storyboard sizeAnimation = (Storyboard)this.FindResource("sbdUserControlAnimation");
            sizeAnimation.Begin(this);
        }
        private void SetLanguageDictionary()
        {
            ResourceDictionary dict = new ResourceDictionary();
            switch (Thread.CurrentThread.CurrentCulture.ToString())
            {
                case "ru-RU":
                    dict.Source = new Uri("..\\Resources\\StringResources.ru-RU.xaml", UriKind.Relative);
                    break;
                case "en-US":
                    dict.Source = new Uri("..\\Resources\\StringResources.xaml", UriKind.Relative);
                    break;
                case "fr-CA":
                    dict.Source = new Uri("..\\Resources\\StringResources.fr-CA.xaml", UriKind.Relative);
                    break;
            }
            this.Resources.MergedDictionaries.Add(dict);

        }
    }
}
