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

name = input('Input Name:')
while (running):
    #input receiver
    n = int(input('Input Integer between 1 and 100 :'))
        
    clientSocket.send((name + ',' + str(n)).encode()) #Send pair of objects seperated by ','       
    data = clientSocket.recv(1024)

    #Validate n was determined in range by server
    if(data.decode() == 'OUT_OF_RANGE'): 
        print(data) 
        break
    name, n, s, tSum, sSum = data.decode().split(',') #Expects to recieve five objects seperated by ',' and assigns them

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
