import sys
from client_forwarder import client_forward
from platform_forwarder import platform_forward


def print_usage():
    print("usage: " + sys.argv[0] + " <-p/-c> [-r/-l] <ip> <port>")
    print("-p     platform")
    print("-c     client")
    print("-r     right side( no need for platform )")
    print("-l     left  side( no need for platform )")
    print("ip     ip of strategy or platform")
    print("port   listen port of platform forwarder")


def get_argv():
    argv = [sys.argv[0], input("platform or client(-p/-c):")]
    if argv[1] == "-c":
        argv.append(input("right or left(-r/-l):"))
    elif argv[1] == "-p":
        pass
    else:
        exit(0)
    argv.append(input("ip:"))
    argv.append(input("port:"))
    return argv


if __name__ == "__main__":
    if len(sys.argv) == 1:
        print_usage()
        sys.argv = get_argv()
        print("arguments are: ", sys.argv)

    if len(sys.argv) < 4 or (sys.argv[1] == "-c" and len(sys.argv) != 5) or (sys.argv[1] == "-p" and len(sys.argv) != 4):
        print_usage()
    elif sys.argv[1] == "-c":
        client_forward(dest_addr=(sys.argv[3], int(sys.argv[4])), side=sys.argv[2][1])
    elif sys.argv[1] == "-p":
        platform_forward(listen_addr=(sys.argv[2], int(sys.argv[3])))
    else:
        print_usage()
