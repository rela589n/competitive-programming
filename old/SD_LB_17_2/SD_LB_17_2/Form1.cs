using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SD_LB_17_2
{
    public partial class Form1 : Form
    {
        double AB = -1;
        double BC = -1;
        double AC = -1;

        public Form1()
        {
            InitializeComponent();
            Draw();
            AddLabel("A", new Point(10, 335));
            AddLabel("B", new Point(180, 20));
            AddLabel("C", new Point(500, 280));
            
        }

        private void Draw()
        {
            Bitmap PictureBoxImg = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            Graphics canvas = Graphics.FromImage(PictureBoxImg);

            Pen pen = new Pen(Color.Black);
            canvas.DrawLine(pen, 50, 350, 200, 60); 
            canvas.DrawLine(pen, 200, 60, 500, 300);
            canvas.DrawLine(pen, 500, 300, 50, 350);

            pictureBox1.Image = PictureBoxImg;
        }

        private void AddLabel(string text, Point loc)
        {
            Label lab = new Label();
            lab.Text = text;

            lab.AutoSize = true;
            lab.Font = new Font("Arial", 24, FontStyle.Bold);

            lab.Location = loc;

            this.Controls.Add(lab);
            lab.BringToFront();
        }
         
        private static bool IsTriangle(double a, double b, double c)
        {
            return (a > 0) && (b > 0) && (c > 0) && 
                (a + b > c) && 
                (Math.Abs(a - b) < c);
        }
        private static double square(double a, double b, double c)
        {
            double p = perimeter(a, b, c) / 2.0;

            return Math.Sqrt(p * (p - a) * (p - b) * (p - c));
        }

        private static double perimeter(double a, double b, double c)
        {
            return a + b + c;
        }

        private void CalculateSquare()
        {
            
            if (IsTriangle(AB, BC, AC))
            {
                double sq = Math.Round(square(AB, BC, AC), 11);

                squareText.Text = sq.ToString();
            }
            else
            {
                squareText.Text = "Not Triangle!";
            }

        }

        private void CalculatePerimeter()
        {

            if (IsTriangle(AB, BC, AC))
            {
                double perim = Math.Round(perimeter(AB, BC, AC), 11);

                perimeterText.Text = perim.ToString();
            }
            else
            {
                perimeterText.Text = "Not Triangle!";
            }

        }


        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void ABText_TextChanged(object sender, EventArgs e)
        {

            string str_AB = ABText.Text.Trim();
            double AB;
            bool isNumeric = double.TryParse(str_AB, out AB);

            this.AB = (isNumeric) ? AB : -1;

            CalculateSquare();
            CalculatePerimeter();
        }

        private void BCText_TextChanged(object sender, EventArgs e)
        {
            string str_BC = BCText.Text.Trim();
            double BC;
            bool isNumeric = double.TryParse(str_BC, out BC);

            this.BC = (isNumeric) ? BC : -1;

            CalculateSquare();
            CalculatePerimeter();
        }

        private void ACTextChanged(object sender, EventArgs e)
        {
            string str_AC = ACText.Text.Trim();
            double AC;
            bool isNumeric = double.TryParse(str_AC, out AC);

            this.AC = (isNumeric) ? AC : -1;

            CalculateSquare();
            CalculatePerimeter();
        }
    }
}
