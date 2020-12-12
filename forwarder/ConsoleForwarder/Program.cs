using System;
using System.Text;
using forwarder;

namespace ConsoleForwarder
{
    class Program
    {
        
        static void Main(string[] args)
        {
            Forwarder myforwarder;
            if (args.Length < 2)
            {
                Console.Error.WriteLine("Usage: ConsoleForwarder -p/-c <local address> <remote address>");
                System.Environment.Exit(-1);
            }
            else if (args[0].Equals("-p"))
            {
                if (args.Length == 2)
                {
                    myforwarder = new PlatformForwarder("127.0.0.1:6000", args[1]);
                }
                else
                {
                    myforwarder = new PlatformForwarder(args[1], args[2]);
                }
                myforwarder.forward();
            }
            else if(args[0].Equals("-c"))
            {
                if (args.Length == 2)
                {
                    myforwarder = new ClientForwarder("127.0.0.1:6000", args[1]);
                }
                else
                {
                    myforwarder = new ClientForwarder(args[1], args[2]);
                }
                myforwarder.forward();
            }
            else
            {
                Console.Error.WriteLine("Usage: ConsoleForwarder -p/-c <local address> <remote address>");
                System.Environment.Exit(-1);
            }
        }
    }
}