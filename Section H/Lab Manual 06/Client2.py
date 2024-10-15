import socket
import sys


def reverseNonVowels(sen):
    vowels = 'aeiouAEIOU'

    count = 0

    for word in sen:
        count = 0 
        for letter in word:
            if letter in vowels:
                count += 1
        if not count:
            sen[sen.index(word)] = word[::-1]
    print(sen)


sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server_address = ('localhost', 10001)

print('connecting to %s port %s' % server_address)

sock.connect(server_address)

try:
    message = "Hello World! My name is Mahdi Jaffri"
    print('sending "%s"' % message)
    sock.sendall(message.encode())

    amount_received = 0
    amount_expected = len(message)

    data = sock.recv(4096)

    data = data.decode().split()
    reverseNonVowels(data)
    data = ' '.join(data)

    print('received "%s"' % data)
    
finally:
    print('closing socket')
    sock.close()
