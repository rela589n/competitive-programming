using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace SD_LB_17_3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        double start = 0, end = 30, step = 1;

        private bool validateValues(double start, double end, double step)
        {
            return (start < end) && (end - start > step);
        }

        private void textBoxStep_TextChanged(object sender, EventArgs e)
        {
            if (textBoxStep.Text.Length == 0)
            {
                this.step = 0.1;
                return;
            }

            double new_step;
            bool isNumeric = double.TryParse(textBoxStep.Text, out new_step);

            if (isNumeric && validateValues(start, end, new_step))
            {
                if (new_step > 0) {
                    this.step = new_step;
                    drawChart();
                }
                else
                {
                    textBoxStep.Text = "0,";
                }
                
            }
            else
            {
                textBoxStep.Text = step.ToString();
            }

            
        }

        private void textBoxEnd_TextChanged(object sender, EventArgs e)
        {
            if (textBoxEnd.Text.Length == 0)
            {
                this.end = 0;
                return;
            }

            double new_end;
            bool isNumeric = double.TryParse(textBoxEnd.Text, out new_end);

            if (isNumeric && validateValues(start, new_end, step))
            {
                this.end = new_end;
                drawChart();
            }
            else
            {
                textBoxEnd.Text = end.ToString();
            }

            
        }

        private void textBoxStart_TextChanged(object sender, EventArgs e)
        {
            if (textBoxStart.Text.Length == 0)
            {
                this.start = 0;
                return;
            }

            double new_start;
            bool isNumeric = double.TryParse(textBoxStart.Text, out new_start);

            if (isNumeric && validateValues(new_start, end, step))
            {
                this.start = new_start;
                drawChart();
            }
            else
            {
                textBoxStart.Text = start.ToString();
            }

           
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            drawChart();
        }

        private void drawChart()
        {
            chart1.Series[0].Points.Clear();

            // масштабування 
            //область діаграми - Вісь Х - Масштабування - Масштабування

            chart1.ChartAreas[0].AxisX.Minimum = start;
            chart1.ChartAreas[0].AxisX.Maximum = end;


            chart1.ChartAreas[0].AxisY.Minimum = -1;
            chart1.ChartAreas[0].AxisY.Maximum = 1;
            chart1.ChartAreas[0].AxisY.Interval = 0.5;


            //chart1.ChartAreas[0].AxisX.ScaleView.Zoom(start, end + 0.5);
            chart1.ChartAreas[0].CursorX.IsUserEnabled = true;

            chart1.ChartAreas[0].CursorX.IsUserSelectionEnabled = true;
            chart1.ChartAreas[0].AxisX.ScaleView.Zoomable = true;

            // для Y
            //chart1.ChartAreas[0].AxisY.ScaleView.Zoom(-1, 1);
            chart1.ChartAreas[0].CursorY.IsUserEnabled = true;

            chart1.ChartAreas[0].CursorY.IsUserSelectionEnabled = true;
            chart1.ChartAreas[0].AxisY.ScaleView.Zoomable = true;


            for (double i = start; i < end; i += step)
            {
                chart1.Series[0].Points.AddXY(i, Math.Sin(i));
            }
        }
    }
}
