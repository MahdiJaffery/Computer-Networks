import socket

attendance = []

def main():
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    server_address = ('127.0.0.1', 2000)
    sock.bind(server_address)

    print("Socket created and bound")
    print("Listening for messages...\n")

    while True:
        try:
            client_message, client_address = sock.recvfrom(2000)
            print(f"Received message from IP: {client_address[0]} and Port No: {client_address[1]}")
            print(f"Client Message: {client_message.decode()}")


            if client_message.decode() not in attendance:
                attendance.append(client_message.decode())
                print(f"Attendance: {attendance}\n")

                client_message = f"Welcome Student {client_message.decode()}"
            else:
                client_message = f"Student {client_message.decode()} is already present"

            sock.sendto(client_message.encode(), client_address)
        except Exception as e:
            print(f"An error occurred: {e}")
            break
    
    sock.close()

if __name__ == "__main__":
    main()