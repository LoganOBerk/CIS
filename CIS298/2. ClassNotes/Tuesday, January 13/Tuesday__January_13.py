import random

def main():

    #in python inside the input function you can have argument which can be a prompt for the input
    name = input("please write your name: ")
    print(name)
    print()
    message = "hello world"
    print(message) #printing var
    print("message") #printing string
    print()
    #can assign values to more than one variable in one line
    x, y, z = 1, 2, 3;

    #No specific const identifier standard is ALL CAPS

    #Variables can be overritten in python easily and they are not type specific
    message = "Welcome to CIS"
    print(message)
    print()

    #Conditionals
    print(type(True)) #will show <class 'bool'> in console
    #type function is comparible itself
    print()
    a = "I am a"
    b = a
    c = "I am a"
    print(a is b) # 'is' identifies if value is the same and has the same memory allocation "only working with strings"
    print(a is not c) #'is not' identifies if the value has different memory allocation or different values "only working with strings"
    print()
    # 'and' is same as &&, 'or' is same as ||, 'not' is same as !

    # a block of code otherwise called a clause is usually seperated between conditional blocks such as if statements

    troy_aval = True
    abed_aval = True
    show = troy_aval and abed_aval

    if (troy_aval and abed_aval):
        print ("Troy and Aved are aval")

    #indentation dictates scope in python

    #in python 'else if' is elif

    #Program for score between 0.0 and 1.0

    score = round(random.random(), 1)
    if(score >= 0.9):
        print("A")
    elif(score >= 0.8):
        print("B")
    elif(score >= 0.7):
        print("C")
    elif(score >= 0.6):
        print("D")
    else:
        print("F")
    print("Score: " + str(score))
    return 0

if (__name__ == "__main__"):
    main()
