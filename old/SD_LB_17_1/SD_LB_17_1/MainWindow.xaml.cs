using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
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

namespace SD_LB_17_1
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        int lastLostFocus = 1;
        private void Calculate_Click(object sender, RoutedEventArgs e)
        {
            if (lastLostFocus == 1)
            {

                string str_inches = inchesBox.Text.Trim();

                double inches;
                bool isNumeric = double.TryParse(str_inches, out inches);

                if (isNumeric)
                {
                    santimetresBox.Text = (Math.Round(inches * 2.54, 8)).ToString();
                }

                else
                {
                    santimetresBox.Text = "Помилка виконання!";
                }
                
            }
            else
            {

                string str_santimetres = santimetresBox.Text.Trim();
                double santimetres;


                bool isNumeric = double.TryParse(str_santimetres, out santimetres);

                if (isNumeric)
                {
                    inchesBox.Text = (Math.Round(santimetres / 2.54, 8)).ToString();
                }
                else
                {
                    inchesBox.Text = "Помилка виконання!";
                }

                
            }
            
        }

        private void SantimetresBox_LostFocus(object sender, RoutedEventArgs e)
        {
            lastLostFocus = 2;
        }

        private void InchesBox_LostFocus(object sender, RoutedEventArgs e)
        {
            lastLostFocus = 1;
        }
    }
}
