#Developer: Logan Berk
#How to run: Install python interpreter
#            >navigate to file directory with client.py in terminal,
#            >type 'python client.py' in the terminal after server is running 

from socket import *
serverName = 'localhost'
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((serverName,serverPort))

running = True
while (running):
    #input receiver
    name = input('Input Name:')
    n = int(input('Input Integer between 1 and 100 :'))
        
    clientSocket.send((name + '|' + str(n)).encode()) #Send pair of objects seperated by '|'       
    data = clientSocket.recv(1024)
    name, n, s, tSum, sSum = data.decode().split('|') #Expects to recieve five objects seperated by '|' and assigns them

    #Validate n was determined in range by server
    if(n == 'OUT_OF_RANGE'):
        print(n)
        break

    #Formatted data
    print('Client Name:', name)
    print('Client Number:', n)
    print('Server Number:', s)
    print('Transaction Sum:', tSum)
    print("Session Sum: ", sSum)

    print('Would you like to try again?')
    response = input('Do you want to send another number? (y/n): ')
    if(response != 'y'):
        break
    
clientSocket.close()
