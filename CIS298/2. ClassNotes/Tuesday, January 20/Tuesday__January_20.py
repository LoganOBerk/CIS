#Strings

fruit = 'banana'
letter = fruit[1] #strings are useable as char arrays

len(fruit) #returns number of items in a string

#strings that want quotes within them need specification
myString1 = 'This is a string with "quotes"'
myString2 = "This is also a string with \"quotes\"" #backslash ensures character is seen as an actual character
print(myString1)
print(myString2)

#If we want to capitalize all the first letters of each word we can use .title() func
print(myString1.title()) #.title() returns a modified copy of the object not mutating the original
#.upper(), .lower() capitalizes and lowercases full string respectively
#.find() will return the index of character you want to find, will return -1 if it cant find, it will return first index of a substring if your searching

#string format
first_name = 'Logan'
last_name = 'Berk'
age = 24
full_name = first_name + ' ' + last_name
print(f'my name is {first_name} and my last name is {last_name}, and my age is {age}')
print('my name is {} and my last name is {}, and my age is {}'.format(first_name, last_name, age)) #alternative method, ALSO C method is allowed

#adding whitespace \t; tab, \n; newline
#rstrip() method will remove all whitespace from right
#lstrip() method will remove all whitespace from left
#sstrip() method will remove from both sides

#strings allow for multiplication and it will duplicate the string multiple times only by ints
# 'in' keyword checks if string contains word

#strings can be sliced with EX: fruit[:3] gets first 3 chars, fruit[2:] will give all characrers past to end of string
#strings are immutable, may need to get creative with slicing, strings can be compared with < being alphabetical
