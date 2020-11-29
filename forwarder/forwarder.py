from socket import socket, AF_INET, SOCK_DGRAM
from threading import Thread
from typing import Tuple


def init_connect(listen_addr: tuple, dest_addr: tuple):
    listen_sock = socket(AF_INET, SOCK_DGRAM)
    listen_sock.bind(listen_addr)
    msg, first_addr = listen_sock.recvfrom(8192)
    print(msg)

    dest_sock = socket(AF_INET, SOCK_DGRAM)
    dest_sock.sendto(msg, dest_addr)

    msg, second_addr = dest_sock.recvfrom(8192)
    print(msg)

    listen_sock.close()
    del listen_sock
    send_sock = socket(AF_INET, SOCK_DGRAM)
    send_sock.sendto(msg, first_addr)
    return (send_sock, first_addr), (dest_sock, second_addr)


def one_way_forward(listen: socket, send: Tuple[socket, any]):
    while True:
        msg, addr = listen.recvfrom(8192)
        print(msg)
        send[0].sendto(msg, send[1])


def forward(*args, first: Tuple[socket, any], second: Tuple[socket, any]):
    th1 = Thread(target=one_way_forward, args=(first[0], second))
    th2 = Thread(target=one_way_forward, args=(second[0], first))
    if len(args) >= 2:
        th3 = Thread(target=one_way_forward, args=(args[0][0], args[1]))
        th4 = Thread(target=one_way_forward, args=(args[1][0], args[0]))
        th1.start()
        th2.start()
        th3.start()
        th4.start()
    else:
        th1.start()
        th2.start()
