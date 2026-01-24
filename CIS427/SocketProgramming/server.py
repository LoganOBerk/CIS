#Developer: Logan Berk
#How to run: Install python interpreter
#            >navigate to file directory with server.py in terminal,
#            >type 'python server.py' in the terminal 

from socket import *
import threading

serverPort = 12000
serverSocket = socket(AF_INET,SOCK_STREAM)
serverSocket.bind(('',serverPort))

#Server backlog queue for clients is at most 5
serverSocket.listen(5)
print('[LISTENING] Server is waiting for connections on port ' + str(serverPort) + '...')

#Server number
s = 10

def clientProcess(connectionSocket, addr):
    sSum = 0
    while True:
        data = connectionSocket.recv(1024).decode() #Server expects to receive an object and decodes it 
        if (data == ''):
            break
        name, n = data.split('|') #Object data is expected to come in a pair seperated by '|'
        n = int(n)

        if (n > 100 or n < 1) :
            connectionSocket.send('|OUT_OF_RANGE|||'.encode()) # OUT_OF_RANGE is sent with four '|' because client expects to recieve 5 objects 
            connectionSocket.close()
            break

        print('Data recieved from client: ' + str(addr))
      
        sSum += n #Update the client running total

        #All server side data is sent to client
        connectionSocket.send((name + '|' + str(n) + '|' + str(s) + '|' + str(s+n) + '|' + str(sSum)).encode())

        #Server Logs
        print('Client Name:', name)
        print('Client Number:', n)
        print('Server Number:', s)
        print('Transaction Sum:', s + n)
        print("Session Sum: ", sSum)
        print()

    #On loop exit the connection is terminated
    connectionSocket.close()
    print('Connection terminated with client' + str(addr))
    print()
    

while True:
     #Server is accepting socket connections
     connectionSocket, addr = serverSocket.accept()
     print('Connection established with client ' + str(addr))

     #Create new thread that calls clientProcess function with client socket and address
     threading.Thread(target = clientProcess, args = (connectionSocket, addr)).start()
     


 
