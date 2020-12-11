from socket import socket, AF_INET, SOCK_DGRAM
from threading import Thread
from typing import Tuple
from time import sleep


def init_connect(listen_addr: tuple, dest_addr: tuple, side='r'):
    listen_sock = socket(AF_INET, SOCK_DGRAM)
    listen_sock.bind(listen_addr)
    msg, first_addr = listen_sock.recvfrom(8192)
    listen_sock.close()
    del listen_sock
    print(msg)

    dest_sock = socket(AF_INET, SOCK_DGRAM)
    dest_sock.sendto(msg, dest_addr)

    msg, second_addr = dest_sock.recvfrom(8192)
    if len(msg) > 25 and len(side) > 0:
        msg = b'(init r before_kick_off)\n'
        pass
    print(msg)
    send_sock = socket(AF_INET, SOCK_DGRAM)
    send_sock.sendto(msg, first_addr)
    sleep(10)
    return (send_sock, first_addr), (dest_sock, second_addr)


def one_way_forward(listen: socket, send: Tuple[socket, any]):
    while True:
        msg, addr = listen.recvfrom(8192)
        print(msg)
        send[0].sendto(msg, send[1])


def forward(first: Tuple[socket, any], second: Tuple[socket, any]):
    th1 = Thread(target=one_way_forward, args=(first[0], second))
    th2 = Thread(target=one_way_forward, args=(second[0], first))
    th1.start()
    th2.start()
