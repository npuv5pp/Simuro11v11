using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;

namespace forwarder
{
    public abstract class Forwarder
    {
        protected IPEndPoint localEndPoint;
        protected IPEndPoint remoteEndPoint;
        protected UdpClient remoteClient;
        protected UdpClient localClient;
        protected char side;

        public void forward()
        {
            Thread localToRemoteThread = new Thread(new ThreadStart(localToRemote));
            Thread remoteToLocalThread = new Thread(new ThreadStart(RemoteTolocal));
            localToRemoteThread.Start();
            remoteToLocalThread.Start();
            localToRemoteThread.Join();
            remoteToLocalThread.Join();
        }

        public Forwarder(string localAddrString, string remoteAddrString)
        { 
            try
            {
                this.localEndPoint = new IPEndPoint(IPAddress.Parse(localAddrString.Split(':')[0]), 
                    Int32.Parse(localAddrString.Split(':')[1]));
                this.remoteEndPoint = new IPEndPoint(IPAddress.Parse(remoteAddrString.Split(':')[0]), 
                    Int32.Parse(remoteAddrString.Split(':')[1]));
            }
            catch(Exception e)
            {
                Console.Error.WriteLine(e);
            }
        }
        
        protected void localToRemote()
        {
            try
            {
                while (true)
                {
                    byte[] msg = localClient.Receive(ref localEndPoint);
                    remoteClient.Send(msg, msg.Length, remoteEndPoint);
                    Console.WriteLine($"local to remote length:{msg.Length}");
                }
            }
            catch (ThreadInterruptedException e)
            {
                Console.Error.WriteLine(e);
            }
            finally
            {
                localClient.Dispose();
                remoteClient.Dispose();
            }
        }

        protected void RemoteTolocal()
        {
            try
            {
                while (true)
                {
                    byte[] msg = remoteClient.Receive(ref remoteEndPoint);
                    localClient.Send(msg, msg.Length, localEndPoint);
                    Console.WriteLine($"remote to local length:{msg.Length}");
                }
            }
            catch (ThreadInterruptedException e)
            {
                Console.Error.WriteLine(e);
            }
            finally
            {
                localClient.Dispose();
                remoteClient.Dispose();
            }
        }
    }
}