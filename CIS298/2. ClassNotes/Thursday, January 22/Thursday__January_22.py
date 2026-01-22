#Try Except Blocks

try:

    print(5/0)

except ZeroDivisionError:
    print ("Don't divide by zero")
else:
    print ("Numbers divided successfully")


#File I/O

#EX: input file, suppose you have a grades.txt file
file = open('grades.txt') #method 1, doesnt automatically close
file.close()

with open('grades.txt') as myFileObjectName: #method 2, automatically closes at end
    #block for file operations
    grades = myFileObjectName.read() #returns entire file and its format as one large string, adds a newline after all content
    print(grades)

    grades = myFileObjectName.readlines() #will string each value in file as a list
    print(grades) 

#Filepaths ex: with open ('text_files/grades.txt') as fileObject, relative path
#Absolute filepath, EX: C:\\Users\\Jane\\PythonProjects\\textfiles\\books.txt

#line by line file reading
#open() has two args, open(filename, (read(default), write, append))
with open('books.txt') as books:
    #prints line by line and adds a newline after each line read
    for book in books:
        if(book.startswith("L")): #conditional for when a string startswith a character
            print(book)
        print(book.strip()) #removes the newline character so that data is more closely arranged

book = "Python Crash Course"
print(book.split()) #can split string based on delimiters


#writing to file
with open('books.txt', 'w') as books:
    books.write("James and The Giant Peach") #will override content of file and write the new content

with open('books.txt', 'a') as books:
    books.write("\nJames and The Giant Peach\n") #will append content to end of file back to back no newline so you must add a newline

#FileNotFoundError Exception
fname = input('Enter file name: ')
try:
    fhand = open(fname)
except:
    print('File connot be opened:', fname)
    exit() #exits program

