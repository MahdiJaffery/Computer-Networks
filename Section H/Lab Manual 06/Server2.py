import socket
import sys


def countVowels(sen):
    vowels = 'aeiouAEIOU'
    print(vowels)
    count = 0
    for word in sen:
        for letter in word:
            if letter in vowels:
                sen[count] = word[::-1]
                break
        
        count += 1
    print(sen)


sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server_address = ('localhost', 10001)

print('starting up on %s port %s' % server_address)

sock.bind(server_address)

sock.listen(1)

while True:
    print('waiting for a connection')
    connection, client_address = sock.accept()
    try:
        print('connection from', client_address)
        while True:
            data = connection.recv(4096)
            print('received "%s"' % data)
            if data:
                print('sending data back to the client')

                data = data.decode().split()
                countVowels(data)
                data = ' '.join(data).encode()
                connection.sendall(data)
            else:
                print('no more data from', client_address)
                break
    finally:
        connection.close()