#Lists and Tuples

#lists in python are denoted by []

cars = ['ford', 'bmw', 'toyota', 'fiat', 'kia', 'subaru']
print(type(cars)) #type is a list

print(len(cars)) #prints num items in list

#accessed the same as C arrays, but you are allowed to access with negative values to start from back of list, 
# 0, 1, 2, 3, 4, 5
# -6, -5, -4, -3 ,-2, -1


#lists are mutable, strings act as immutible lists
#values can be reassigned directly

#adding to end of list, .append()
#adding to any location of list .insert(position, item to add)

#del is used if you know position of item you want to delete
#pop() removes last item from list and returns its value
#pop() can also be specified by position
#.remove() removes an item by value, deletes first occurance

#example
del[cars[0]] #remove first item
print(cars)
deleted_item = cars.pop(); #saves and removes last item
print(cars)

#sort() method permanently sorts a list alphabetically
#sort(reverse = True) will sort in reverse order
#sorted() function will return a copy of your list and sort it
#reverse will just reverse the order of a list

books = ['The Linux Command Line', 'Python Crash Course', 'Think Python']

#prints each book in list 
for book in books:
    print(book)

#can also be written as
for i in range(len(books)):
    print (books[i])

#OR
for i in range(0, len(books)):
    print (books[i])


#Lists of numbers
numbers = list(range(1, 6)) #1,2,3,4,5  AKA(6-1)
print(numbers)


#Example
squares = []
for value in range(1, 11):
    square = value**2
    square.append(square)
print(squares)

#OR
squares = [value**2 for value in range(1,11)]

#min(listname), gives min in list
#max(listname), gives max in list
#sum(listname), gives sum of list

#copy an entire list 
fav_books = books[:]

#fav_books = books will pass by refrence changing original if fav_books is changed

#tuple similar to list but they are immutable
#Example
motorcycles = ('honda', 'yamaha', 'suzuki')

#creating a tuple with one item requires a comma
myTup = ('item',)

#can use in to check if element is in the list
motorcycle = 'honda'
if motorcycle in motorcycles:
    print('its there')

#slicing is a possibility in lists, reverse slice [-3:] will go from -3 index to the front of list