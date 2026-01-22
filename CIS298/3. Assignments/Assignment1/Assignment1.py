import math

#Exercise 1
print("Breaking Bad")


#Exercise 2
x, y, z = 23, 49, 3

print (x + z) #26
print (x / z) #7.666...7
print (x**z ) #12,167
print (y//z ) #16
print (y % z) #1


#Exercise 3

#first message prints then second message prints if you want to use seperate vars then make names unique
#such as message1 and message2
message = "Did you ever hear the tragedy of Darth Plagueis The Wise?"
print(message)
message = "I thought not. It's not a story the Jedi would tell you."
print(message)


#Exercise 4

#1 : valid
#2 : invalid
#3 : invalid
#4 : invalid
#5 : invalid
#6 : valid


#Exercise 5

#1 : error is missing )
#FIX : print("Hello there.")
#2 : error is typo in print(respose)
#FIX : print(response)
#3 : error string multiplication with a floating point
#FIX : laugh = "HA" * 5
#4 : error concatination with string and int is invalid
#FIX : movie = "Toy Story 3" or movie = "Toy Story" + str(3)
#5 : error total = 100.00 + cost, cost is a string as input returns a string
#FIX : total = 100.00 + float(cost), this is a tenative fix but doesnt handle illegal inputs


#Exercise 6

#Replace I've with I/'ve


#Exercise 7

print("Hello User") #welcome message
userNameInit = input("Please enter name:") #user prompt and input retrieval and storage
userName = userNameInit.strip() #whitespace strip

print(userName.title()) #printing username with first letter in words captial
print(userName.upper()) #printing full capital username
print(userName.lower()) #printing full lowercase username
print(userNameInit) #printing original username


#Excercise 8

    #Q1 : The main difference is a for loop is primarily used when number of itterations is known
        # whereas a while loop is used when number of itterations may not be known, they are also
        # differing in syntax structure with the for loop itterating through a list of nums,
        # whereas while loop just accepts a boolean value as its condition

    #Q2 : A break statement immediately exits the loop when executed
    #Q3 : A continue statement jumps to the next loop itteration skipping code below the continue
    #Q4.1 : The print result is 8 and on a new line 20 below 8
    #Q4.2 : x = 8, y = 0


#Excercise 9

#1

for i in range(1, 10, 1) :
    if(i == 9):
        print(i)
        break;
    print(i, end = ", ")

#2
for i in range(13, 47, 5) :
    if(i == 43):
        print(i)
        break;
    print(i, end = ", ")

#3
for i in range(20, -1, -1) :
    if(i == 0):
        print(i)
        break;
    print(i, end = ", ")

#4
for i in range(5, -7, -2) :
    if(i == -5):
        print(i)
        break;
    print(i, end = ", ")

#5
for i in range(2, 12, 2) :
    if(i == 10):
        print(i)
        break;
    print(i, end = ", ")


#Excercise 10

#1: the while loop has an infinite loop
#FIX : add num_attempts++ after or before the print statement inside the loop so that the loop exits
#2 : range() function requires at least one arg
#FIX : I would add a number inside the range depending on how many times I want to loop




