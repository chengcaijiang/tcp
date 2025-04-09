using System.Net;
using System.Net.Sockets;

namespace tcp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        IPAddress ip;
        TcpListener server;

        private void button1_Click(object sender, EventArgs e)
        {
            String Message = textBoxmessage.Text;
            byte[] data = System.Text.Encoding.UTF8.GetBytes(Message);
            TcpClient client = new TcpClient();
            client.Connect(ip, int.Parse(textBoxPORT.Text));
            NetworkStream stream = client.GetStream();
            stream.Write(data, 0, data.Length);
            textBoxINFO.Text = "发送数据成功";
            stream.Close();
            client.Close();
        }

        private void buttonstart_Click(object sender, EventArgs e)
        {
            ip = IPAddress.Parse(textBoxIP.Text);
            server = new TcpListener(ip, int.Parse(textBoxPORT.Text));
            server.Start();
            textBoxINFO.Text = "监听服务启动";

        }
    }
}
