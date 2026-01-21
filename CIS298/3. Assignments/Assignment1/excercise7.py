print("Hello User") #welcome message
userNameInit = input("Please enter name:") #user prompt and input retrieval and storage
userName = userNameInit.strip() #whitespace strip

print(userName.title()) #printing username with first letter in words captial
print(userName.upper()) #printing full capital username
print(userName.lower()) #printing full lowercase username
print(userNameInit) #printing original username