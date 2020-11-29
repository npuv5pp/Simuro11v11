from forwarder import *
import sys


def platform_forward(*addrs, listen_addr=('0.0.0.0', 23010), dest_addr=('127.0.0.1', 6000)):
    if len(addrs) >= 2:
        npc1, plat1 = init_connect(listen_addr, dest_addr)
        npc2, plat2 = init_connect(addrs[0], addrs[1])
        forward(npc1, plat1, npc2, plat2)
    else:
        npc, plat = init_connect(listen_addr, dest_addr)
        forward(first=npc, second=plat)


if __name__ == '__main__':
    if len(sys.argv) == 3:
        platform_forward(listen_addr=(sys.argv[1], int(sys.argv[2])))
    elif len(sys.argv) == 5:
        platform_forward((sys.argv[3], int(sys.argv[4])), ('127.0.0.1', 6000),
                         listen_addr=(sys.argv[1], int(sys.argv[2])), dest_addr=('127.0.0.1', 6000))
    else:
        platform_forward()
