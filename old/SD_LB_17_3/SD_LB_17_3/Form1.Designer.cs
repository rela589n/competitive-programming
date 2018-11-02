namespace SD_LB_17_3
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea15 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend15 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series15 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Title title15 = new System.Windows.Forms.DataVisualization.Charting.Title();
            this.chart1 = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.textBoxStart = new System.Windows.Forms.TextBox();
            this.textBoxEnd = new System.Windows.Forms.TextBox();
            this.labelStart = new System.Windows.Forms.Label();
            this.labelEnd = new System.Windows.Forms.Label();
            this.labelStep = new System.Windows.Forms.Label();
            this.textBoxStep = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.chart1)).BeginInit();
            this.SuspendLayout();
            // 
            // chart1
            // 
            chartArea15.Name = "ChartArea1";
            this.chart1.ChartAreas.Add(chartArea15);
            legend15.Name = "Legend1";
            this.chart1.Legends.Add(legend15);
            this.chart1.Location = new System.Drawing.Point(12, 12);
            this.chart1.Name = "chart1";
            series15.ChartArea = "ChartArea1";
            series15.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Spline;
            series15.Legend = "Legend1";
            series15.LegendText = "Sin x";
            series15.Name = "Series1";
            this.chart1.Series.Add(series15);
            this.chart1.Size = new System.Drawing.Size(776, 382);
            this.chart1.TabIndex = 0;
            this.chart1.Text = "chart1";
            title15.Name = "Title1";
            title15.Text = "Функція синуса";
            this.chart1.Titles.Add(title15);
            // 
            // textBoxStart
            // 
            this.textBoxStart.Location = new System.Drawing.Point(675, 138);
            this.textBoxStart.Name = "textBoxStart";
            this.textBoxStart.Size = new System.Drawing.Size(100, 22);
            this.textBoxStart.TabIndex = 1;
            this.textBoxStart.Text = "0";
            this.textBoxStart.TextChanged += new System.EventHandler(this.textBoxStart_TextChanged);
            // 
            // textBoxEnd
            // 
            this.textBoxEnd.Location = new System.Drawing.Point(675, 205);
            this.textBoxEnd.Name = "textBoxEnd";
            this.textBoxEnd.Size = new System.Drawing.Size(100, 22);
            this.textBoxEnd.TabIndex = 2;
            this.textBoxEnd.Text = "30";
            this.textBoxEnd.TextChanged += new System.EventHandler(this.textBoxEnd_TextChanged);
            // 
            // labelStart
            // 
            this.labelStart.AutoSize = true;
            this.labelStart.Location = new System.Drawing.Point(672, 104);
            this.labelStart.Name = "labelStart";
            this.labelStart.Size = new System.Drawing.Size(64, 17);
            this.labelStart.TabIndex = 3;
            this.labelStart.Text = "Початок";
            // 
            // labelEnd
            // 
            this.labelEnd.AutoSize = true;
            this.labelEnd.Location = new System.Drawing.Point(672, 174);
            this.labelEnd.Name = "labelEnd";
            this.labelEnd.Size = new System.Drawing.Size(51, 17);
            this.labelEnd.TabIndex = 4;
            this.labelEnd.Text = "Кінець";
            // 
            // labelStep
            // 
            this.labelStep.AutoSize = true;
            this.labelStep.Location = new System.Drawing.Point(672, 250);
            this.labelStep.Name = "labelStep";
            this.labelStep.Size = new System.Drawing.Size(40, 17);
            this.labelStep.TabIndex = 6;
            this.labelStep.Text = "Крок";
            // 
            // textBoxStep
            // 
            this.textBoxStep.Location = new System.Drawing.Point(675, 281);
            this.textBoxStep.Name = "textBoxStep";
            this.textBoxStep.Size = new System.Drawing.Size(100, 22);
            this.textBoxStep.TabIndex = 5;
            this.textBoxStep.Text = "1";
            this.textBoxStep.TextChanged += new System.EventHandler(this.textBoxStep_TextChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.labelStep);
            this.Controls.Add(this.textBoxStep);
            this.Controls.Add(this.labelEnd);
            this.Controls.Add(this.labelStart);
            this.Controls.Add(this.textBoxEnd);
            this.Controls.Add(this.textBoxStart);
            this.Controls.Add(this.chart1);
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = " ";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.chart1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataVisualization.Charting.Chart chart1;
        private System.Windows.Forms.TextBox textBoxStart;
        private System.Windows.Forms.TextBox textBoxEnd;
        private System.Windows.Forms.Label labelStart;
        private System.Windows.Forms.Label labelEnd;
        private System.Windows.Forms.Label labelStep;
        private System.Windows.Forms.TextBox textBoxStep;
    }
}

