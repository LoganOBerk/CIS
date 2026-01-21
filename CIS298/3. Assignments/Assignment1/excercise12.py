import math #import math util for math.inf

#Excercise 12
maximum = -math.inf #maximum is nothing therefore the lowest possible
minimum = math.inf #minimum is nothing therefore highest possible
while True:
    i = input("Enter Integer, and 'done' when done: ") #input reciever
    i = i.strip() #strip whitespace L & R
    
    #check if user entered done
    if (i == 'done'):
        print(f"Maximum: {maximum}") #print max
        print(f"Minimum: {minimum}") #print min
        break;

    #check if i can be changed to a digit
    if (i.isdigit() == False) :
        print("Not a number try again") #error msg, executes when i cannot become a digit
        continue

    i = int(i) #convert i to a digit

    #check if i is larger than max if so update max
    if (i > maximum) :
        maximum = i
    #check if i is less than min if so update min
    if (i < minimum) :
        minimum = i