#Dictionaries
#Store key value pairs, keys can be different immutable types, only standard types they need to be hashable
customer = {'name': 'John', 'age' : 30, 'is_verified' : True}

#Dictionary is accessed by key
#len(customer) will give amount of key value pairs

#Dictionaries are mutable

len(customer) #expected, 3
customer['birthdate'] = 'January 1 1996' #will add this as a new key value pair, will modify if already exists

#printing a dict print(customer), will print the list as initalized
#can create empty dict by initializing {}

#del customer['birthdate'], deletes both key and value
#del customer, deletes whole dictionary

print(customer.get('birthdate', 'January 1 1980')) #gets and prints value in key, second arg is only used if a current value doesnt exist

#itterates through key value pairs, defaults to customer.keys(), can use customer.values()
for key,value in customer.items():
    print(key, value)


#Sets

#Sets dont accept repetitive values
favorite_books = {'The Linux Command Line', 'Python Crash Course', 'Think Python'}
favorite_books.add('New Book')
favorite_books.remove('New Book')

#List of dictionaries
customer1 = {}
customer2 = {}
customer3 = {}

customers = [customer1, customer2, customer3]

customers[1]['key']

#can also have a dictionary with a key : list pair with list as our value
#can also have dictionaries of dictionaries

#lists of lists, dicts of dicts, tuple of tuples etc can be created and accessed similar to multidimentional arrays
#a tuple of lists allows the lists to be changed but not the tuple

#lists can be concatenated with +
#lists can also be multiplied

#can assign multiple items to list
movies = ['movie1', 'movie2', 'movie3']
x,y,z = movies

#enumeration
#replaces the i in range(len(myList))
for position, movie in enumerate(movies):
    print("Position " + str(position) + ": " + movie)

#random.choice() will choose a random item from a list
#random.shuffle() will randomly shuffle the list
#.index('val') will give index of value in list
#tuple(myList) will convert a list to a tuple

