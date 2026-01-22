#Excercise 13
s = 'X-DSPAM-Confidence: 0.8475'

# Takes string finds the index of the colon moves
# one index forward and takes the slice from the 
# index to the far right then strips the slice and converts it to a float
s = float((s[s.find(':') + 1:]).strip())
print(s)