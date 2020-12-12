using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;

namespace forwarder
{
    public class ClientForwarder : Forwarder
    {
        public ClientForwarder(string localAddrString, string remoteAddrString) : base(localAddrString,
            remoteAddrString)
        {
            remoteClient = new UdpClient();
            localClient = new UdpClient(this.localEndPoint);
            var msg = Encoding.ASCII.GetBytes("Client Online");
            do
            {
                remoteClient.Send(msg, msg.Length, remoteEndPoint);
            } while (!Encoding.ASCII.GetString(
                remoteClient.Receive(ref remoteEndPoint)).Equals("Platform Reply"));

            Console.WriteLine("Platform Connected");

            listenToClient();
        }

        public void listenToClient()
        {
            byte[] msg;
            string msgString;
            do
            {
                msg = localClient.Receive(ref localEndPoint);
                msgString = Encoding.ASCII.GetString(msg);
            } while (!msgString.Substring(0, 5).Equals("(init"));

            activatePlatform();
        }

        public void activatePlatform()
        {
            var msg = Encoding.ASCII.GetBytes("Activate Platform");
            string returnMagString;
            do
            {
                remoteClient.Send(msg, msg.Length, remoteEndPoint);
                returnMagString = Encoding.ASCII.GetString(remoteClient.Receive(ref remoteEndPoint));
            } while (!returnMagString.Substring(0, returnMagString.Length-1).Equals("Activate Successed"));

            this.side = returnMagString[returnMagString.Length - 1];
            string initMsgString = $"(init {this.side} before_kick_off)\n";
            var initMsg = Encoding.ASCII.GetBytes(initMsgString);
            localClient.Send(initMsg, initMsg.Length, localEndPoint);
        }
    }
}