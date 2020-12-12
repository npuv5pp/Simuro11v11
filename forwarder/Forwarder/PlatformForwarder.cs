using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.NetworkInformation;
using System.Net.Sockets;
using System.Text;
using System.Threading;

namespace forwarder
{
    public class PlatformForwarder : Forwarder
    {
        public PlatformForwarder(string localAddrString, string remoteAddrString) : base(localAddrString,
            remoteAddrString)
        {
            remoteClient = new UdpClient(remoteEndPoint);
            localClient = new UdpClient();
            byte[] msg;
            do
            {
                msg = remoteClient.Receive(ref remoteEndPoint);
            } while (!Encoding.ASCII.GetString(msg).Equals("Client Online"));

            Console.WriteLine("Client Online");
            msg = Encoding.ASCII.GetBytes("Platform Reply");
            remoteClient.Send(msg, msg.Length, remoteEndPoint);
            waitToBeActivated();
        }

        public void waitToBeActivated()
        {
            byte[] msg;
            do
            {
                msg = remoteClient.Receive(ref remoteEndPoint);
            } while (!Encoding.ASCII.GetString(msg).Equals("Activate Platform"));

            activatePlatform();

            msg = Encoding.ASCII.GetBytes($"Activate Successed{this.side}");
            remoteClient.Send(msg, msg.Length, remoteEndPoint);
        }

        public void activatePlatform()
        {
            // string msgString = "(init\x20"+"AgentTeam(version4.00))";
            string msgString = "(init AgentClient (version 4.00))";
            var msg = Encoding.ASCII.GetBytes(msgString);
            localClient.Send(msg, msg.Length, localEndPoint);
            var returnMsg = localClient.Receive(ref localEndPoint);
            var returnMsgString = Encoding.ASCII.GetString(returnMsg);
            if (returnMsgString[6] == 'r' || returnMsgString[6] == 'l')
            {
                this.side = returnMsgString[6];
            }
        }
    }
}