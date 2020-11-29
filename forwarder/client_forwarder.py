from forwarder import *
import sys


def client_forward(*addrs, listen_addr=('0.0.0.0', 6000), dest_addr=('127.0.0.1', 23010)):
    if len(addrs) >= 2:
        client1, nps1 = init_connect(listen_addr, dest_addr)
        client2, nps2 = init_connect(addrs[0], addrs[1])
        forward(client1, nps1, client2, nps2)
    else:
        client, nps = init_connect(listen_addr, dest_addr)
        forward(first=client, second=nps)


if __name__ == '__main__':
    if len(sys.argv) == 3:
        client_forward(dest_addr=(sys.argv[1], int(sys.argv[2])))
    elif len(sys.argv) == 5:
        client_forward(('0.0.0.0', 6000), (sys.argv[3], int(sys.argv[4])),
                       listen_addr=('0.0.0.0', 6000), dest_addr=(sys.argv[1], int(sys.argv[2])))
    else:
        client_forward()
