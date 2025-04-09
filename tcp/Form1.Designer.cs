namespace tcp
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            textBoxIP = new TextBox();
            textBoxPORT = new TextBox();
            textBoxmessage = new TextBox();
            button1 = new Button();
            label1 = new Label();
            label2 = new Label();
            label3 = new Label();
            label4 = new Label();
            textBoxINFO = new TextBox();
            buttonstart = new Button();
            SuspendLayout();
            // 
            // textBoxIP
            // 
            textBoxIP.Location = new Point(654, 478);
            textBoxIP.Name = "textBoxIP";
            textBoxIP.Size = new Size(208, 38);
            textBoxIP.TabIndex = 1;
            // 
            // textBoxPORT
            // 
            textBoxPORT.Location = new Point(1027, 481);
            textBoxPORT.Name = "textBoxPORT";
            textBoxPORT.Size = new Size(124, 38);
            textBoxPORT.TabIndex = 2;
            // 
            // textBoxmessage
            // 
            textBoxmessage.Location = new Point(627, 387);
            textBoxmessage.Name = "textBoxmessage";
            textBoxmessage.Size = new Size(524, 38);
            textBoxmessage.TabIndex = 3;
            // 
            // button1
            // 
            button1.Location = new Point(1206, 387);
            button1.Name = "button1";
            button1.Size = new Size(150, 46);
            button1.TabIndex = 4;
            button1.Text = "发送";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(535, 390);
            label1.Name = "label1";
            label1.Size = new Size(86, 31);
            label1.TabIndex = 5;
            label1.Text = "输入框";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(535, 481);
            label2.Name = "label2";
            label2.Size = new Size(41, 31);
            label2.TabIndex = 6;
            label2.Text = "ip:";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(939, 486);
            label3.Name = "label3";
            label3.Size = new Size(68, 31);
            label3.TabIndex = 7;
            label3.Text = "port:";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(533, 79);
            label4.Name = "label4";
            label4.Size = new Size(114, 31);
            label4.TabIndex = 8;
            label4.Text = "message";
            // 
            // textBoxINFO
            // 
            textBoxINFO.Location = new Point(535, 167);
            textBoxINFO.Multiline = true;
            textBoxINFO.Name = "textBoxINFO";
            textBoxINFO.Size = new Size(821, 172);
            textBoxINFO.TabIndex = 9;
            // 
            // buttonstart
            // 
            buttonstart.Location = new Point(1206, 470);
            buttonstart.Name = "buttonstart";
            buttonstart.Size = new Size(150, 46);
            buttonstart.TabIndex = 10;
            buttonstart.Text = "start";
            buttonstart.UseVisualStyleBackColor = true;
            buttonstart.Click += buttonstart_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(14F, 31F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1906, 639);
            Controls.Add(buttonstart);
            Controls.Add(textBoxINFO);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(button1);
            Controls.Add(textBoxmessage);
            Controls.Add(textBoxPORT);
            Controls.Add(textBoxIP);
            Name = "Form1";
            Text = "Form1";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion
        private TextBox textBoxIP;
        private TextBox textBoxPORT;
        private TextBox textBoxmessage;
        private Button button1;
        private Label label1;
        private Label label2;
        private Label label3;
        private Label label4;
        private TextBox textBoxINFO;
        private Button buttonstart;
    }
}
