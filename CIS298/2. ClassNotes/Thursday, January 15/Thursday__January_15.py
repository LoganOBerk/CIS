#functions and iterations

#clarification on 'is'
#'is' will change based on IDE your using, generally speaking 'is' is meant to determine if memory and value is the same

#python has built in functions, print(), input(), int(), float(), etc...

int('32') #expliciity turns a value into an int if it can, will chop fraction off of floating point

float(32) #expliciity turns a value into a float if it can

str(32) #expliciity turns a value into a string if it can

#python functions require forward definitions
#function parameter order matters in python
#no function overloading
#python allows for default parameter values
#functions default to void 


#function EX
def greet_user_():
    #Display simple greeting
    print('Hello there.')


def greet_user(name) :
    print ('Welcome to CIS 298', name)

    
def fav_books(book, num_books):
    print ('I want ' + str(num_books) + ' ' + book)

#keyword arguments, allows you to define which parameter names are mapped to which variables, essentially negating the order
fav_books(book = 'Think Python', num_books = 5)

#calling function for exectution
greet_user_()


#iterations

num_cats = 0
while(num_cats <= 5):
    print("I would like to buy a cat.")
    num_cats = num_cats + 1

