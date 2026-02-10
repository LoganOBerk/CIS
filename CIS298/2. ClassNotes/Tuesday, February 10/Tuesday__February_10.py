#Network Programming

#HTTP language used by browsers to communicate

#HTTP GET

#GET /index.html HTTP/1.0
#Host: example.com
#blank line

#response

#HTTP/1.1 200 OK
#Content-Type: text/html
#Content-Length:...
#
#<!doctype html>
#<html>
#...

#command line
#curl website

#Sockets in python 
#two way communication link between programs

#------
#Steps
#------
#Connect
#Send
#Recv

import socket
import time

mysock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
mysock.connect(('data.pr4e.org', 80))
cmd = 'GET http://data.pr4e.org/romeo.txt HTTP/1.0\r\n\r\n'.encode()
mysock.send(cmd)

while True:
    data = mysock.recv(512) #512bytes is the maximum per packet size
    if len(data) < 1:
        break
    print(data.decode(), end = '')


mysock.close()

#b before a string will encode to bytes

#Retreiving an Image HTTP

HOST = 'data.pr4e.org'
PORT = 80
mysock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
mysock.connect((HOST, PORT))
mysock.sendall( 'GET http://data.pr4e.org/cover.jpg HTTP/1.0\r\n\r\n'.encode()) #ensures all bytes are sent or an exception is raised

count = 0

picture = b''

while True:
    data = mysock.recv(5120) #less chunks can be recieved due to internet traffic or other factors
    if len(data) < 1 : break
    time.sleep(0.25) #ensures server has time to send the chunks in full
    count = count + len(data)
    print(len(data), count)
    picture = picture + data
mysock.close()

#look for end of header

pos = picture.find(b'\r\n\r\n')
print('Header Length', pos)
print(picture[:pos].decode())

#skip past the header and save picture data
picture = picture[pos + 4:]
fhand = open('stuff.jpg', 'wb')
fhand.write(picture)
fhand.close()

#retrieving web pages with urllib

import urllib.request, urllib.parse, urllib.error
fhand = urllib.request.urlopen('http://data.pr4e.org/romeo.txt')
for line in fhand:
    print(line.decode().strip())

img = urllib.request.urlopen('http://data.pr4e.org/cover3.jpg').read()
fhand = open('cover3.jpg', 'wb')
fhand.write(img)
fhand.close()


img = urllib.request.urlopen('http://data.pr4e.org/cover3.jpg')
fhand = open('cover3.jpg', 'wb')
size = 0

while True:
    info = img.read(100000)
    if len(info) < 1: break
    size = size + len(info)
    fhand.write(info)
    print(size, 'characters copied.')

fhand.close()





