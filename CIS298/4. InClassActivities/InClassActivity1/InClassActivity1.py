
numsToWords = {
    0 : ("Zero"),
    1 : ("One"), 
    2 : ("Two"), 
    3 : ("Three"), 
    4 : ("Four"), 
    5 : ("Five"), 
    6 : ("Six"), 
    7 : ("Seven"), 
    8 : ("Eight"), 
    9 : ("Nine")
}

#handles phone numbers displays them back as numbers in words one, two, three etc..
#basic input handling for invalid numbers and will accept "-" in any input as a valid delimeter
while(True):
    ui = input("Enter Phone Number: ")
    formatNum = ui.strip().replace(" ", "").replace("-","")
    fini = "-";
    if(formatNum.isdigit()):
        for i, num in enumerate(formatNum):
            if(i == len(formatNum) - 1) : fini = "\n" 
            print(numsToWords[int(num)], end = fini)
        break;
    else:
        print("Not a valid numerical type or phone number format try again")
        print("EXAMPLE FORMATS INCLUDE (X-X-X-...) or (XXXXXXXXXX)")