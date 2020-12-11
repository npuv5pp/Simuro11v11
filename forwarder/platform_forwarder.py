from forwarder import *
import sys


def platform_forward(*addrs, listen_addr=('0.0.0.0', 23010), dest_addr=('127.0.0.1', 6000), side=""):
    npc, plat = init_connect(listen_addr, dest_addr, side)
    forward(first=npc, second=plat)


if __name__ == '__main__':
    if len(sys.argv) == 3:
        platform_forward(listen_addr=(sys.argv[1], int(sys.argv[2])))
    else:
        platform_forward()
