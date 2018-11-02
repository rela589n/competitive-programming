namespace SD_LB_17_2
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
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.ABText = new System.Windows.Forms.TextBox();
            this.BCText = new System.Windows.Forms.TextBox();
            this.ACText = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.squareText = new System.Windows.Forms.TextBox();
            this.perimeterText = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pictureBox1.Location = new System.Drawing.Point(0, 0);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(1082, 553);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // ABText
            // 
            this.ABText.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F);
            this.ABText.Location = new System.Drawing.Point(808, 58);
            this.ABText.Name = "ABText";
            this.ABText.Size = new System.Drawing.Size(200, 36);
            this.ABText.TabIndex = 1;
            this.ABText.TextChanged += new System.EventHandler(this.ABText_TextChanged);
            // 
            // BCText
            // 
            this.BCText.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F);
            this.BCText.Location = new System.Drawing.Point(808, 136);
            this.BCText.Name = "BCText";
            this.BCText.Size = new System.Drawing.Size(200, 36);
            this.BCText.TabIndex = 2;
            this.BCText.TextChanged += new System.EventHandler(this.BCText_TextChanged);
            // 
            // ACText
            // 
            this.ACText.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F);
            this.ACText.Location = new System.Drawing.Point(808, 211);
            this.ACText.Name = "ACText";
            this.ACText.Size = new System.Drawing.Size(200, 36);
            this.ACText.TabIndex = 3;
            this.ACText.TextChanged += new System.EventHandler(this.ACTextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 17F);
            this.label1.Location = new System.Drawing.Point(848, 300);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(116, 33);
            this.label1.TabIndex = 4;
            this.label1.Text = "Square:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 17F);
            this.label2.Location = new System.Drawing.Point(877, 22);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(53, 33);
            this.label2.TabIndex = 5;
            this.label2.Text = "AB";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 17F);
            this.label3.Location = new System.Drawing.Point(877, 100);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(55, 33);
            this.label3.TabIndex = 6;
            this.label3.Text = "BC";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 17F);
            this.label4.Location = new System.Drawing.Point(877, 175);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(55, 33);
            this.label4.TabIndex = 7;
            this.label4.Text = "AC";
            // 
            // squareText
            // 
            this.squareText.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F);
            this.squareText.Location = new System.Drawing.Point(808, 336);
            this.squareText.Name = "squareText";
            this.squareText.ReadOnly = true;
            this.squareText.Size = new System.Drawing.Size(200, 36);
            this.squareText.TabIndex = 8;
            this.squareText.Text = "0";
            // 
            // perimeterText
            // 
            this.perimeterText.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F);
            this.perimeterText.Location = new System.Drawing.Point(808, 435);
            this.perimeterText.Name = "perimeterText";
            this.perimeterText.ReadOnly = true;
            this.perimeterText.Size = new System.Drawing.Size(200, 36);
            this.perimeterText.TabIndex = 10;
            this.perimeterText.Text = "0";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 17F);
            this.label5.Location = new System.Drawing.Point(836, 399);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(150, 33);
            this.label5.TabIndex = 9;
            this.label5.Text = "Perimeter:";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1082, 553);
            this.Controls.Add(this.perimeterText);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.squareText);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.ACText);
            this.Controls.Add(this.BCText);
            this.Controls.Add(this.ABText);
            this.Controls.Add(this.pictureBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.TextBox ABText;
        private System.Windows.Forms.TextBox BCText;
        private System.Windows.Forms.TextBox ACText;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox squareText;
        private System.Windows.Forms.TextBox perimeterText;
        private System.Windows.Forms.Label label5;
    }
}

