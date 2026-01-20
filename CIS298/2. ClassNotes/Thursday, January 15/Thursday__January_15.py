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

#'continue' keyword will jump to beginning of loop

#range(start, end, step) func

range(12, 16) #12, 13, 14, 15, default step is 1
range(5) #end is 5, this is because range start = 0 and step = 1 are defaulted 
range(5, -1, -1)  #accepts backward steps, returns list of items

#for loops, useful for predefined itteration segments
for i in range(5) :
    print ("I would like to buy a puppy.")
print()

total = 0
for itervar in {3, 41, 12, 9, 74, 15} :
    total += itervar
print(str(total) + '\n')