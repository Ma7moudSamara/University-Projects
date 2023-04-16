import time
from socket import *

print("\n\t\t\t\t\t\t\t{Welcome to our program}")
print("\n\t\t(Note that : you can enter an infinite websites names)")
while True:

  url = input("\nPlease Enter the url like this formula (www.WebsiteName.com) :")
  NameOFServer = url
  PortOfServer = 80

  clinetSoket = socket(AF_INET, SOCK_STREAM) # Create a socket object

  clinetSoket.connect((NameOFServer,PortOfServer)) # Connect the client
  StartTime = time.time() #Time when send requst

  clinetSoket.send("HEAD / HTTP/1.1 \r\n".encode()) # Send some data
  clinetSoket.send(("Hostname:"+url+" \r\n\r\n").encode())

  modifiedSentence = clinetSoket.recv(1024) # receive some data

  EndTime = time.time() #Time when recive response

  print("From server:", modifiedSentence.decode()) #Display the response

  ElapsedTime = EndTime - StartTime  #Response time
  print(f"Elapsed time = { ElapsedTime * 1000  } ms ") #Display the response time

  clinetSoket.close()
