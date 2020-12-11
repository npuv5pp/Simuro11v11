from forwarder import *
import sys


def client_forward(listen_addr=('0.0.0.0', 6000), dest_addr=('127.0.0.1', 23010), side="r"):
    client, nps = init_connect(listen_addr, dest_addr, side)
    forward(first=client, second=nps)


if __name__ == '__main__':
    if len(sys.argv) == 3:
        client_forward(dest_addr=(sys.argv[1], int(sys.argv[2])))
    else:
        client_forward()
