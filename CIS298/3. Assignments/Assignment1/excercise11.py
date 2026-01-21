#Excercise 11

#Gross Pay calculator, does not handle illegal inputs
def grossPay():
    h = input("Enter Hours:") #recieve user input for hours
    r = input("Enter Hourly rate:") #recieve user input for rate
    h = float(h) #convert hours to float
    r = float(r) #convert rate to float
    gross = 0

    
    if(h >= 0 and h <= 40):
       gross = h * r       #if h is between 0 and 40 compute regular pay
    elif(h > 40) :
        gross = (40 * r) + (h - 40) * 1.5 * r #if h is above 40 compute adjusted pay
    else:
        gross = - 1 #if h is less than 0 set gross to a junk value

    return round(gross, 2)  #return gross rounded to 2 decimals


print(grossPay)  #example function run to print gross output