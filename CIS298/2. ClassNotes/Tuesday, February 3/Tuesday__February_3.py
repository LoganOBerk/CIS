#Regular Expressions
import re

#checks if an expression exists in line and will print the line with it in it
with open('mbox-short.txt', 'r') as file:
    for line in file:
        line = line.strip()
        if re.search('From:', line):
            print(line)

# ^ character says startwith, searching for expression in start of string
with open('mbox-short.txt', 'r') as file:
    for line in file:
        line = line.strip()
        if re.search('^From:', line):
            print(line)

# . character will be a placeholder for any character
with open('mbox-short.txt', 'r') as file:
    for line in file:
        line = line.strip()
        if re.search('F..m:', line):
            print(line)

# .+ means one or more characters between, .* means 0 or more characters in between, the preceeding . can be any character you want
with open('mbox-short.txt', 'r') as file:
    for line in file:
        line = line.strip()
        if re.search('F.+m:', line):
            print(line)

#*,+ are greedy characters it will try to go further trying to find another occurance and will consider the last occurance of the character we defined
#? after will ensure it will match the very first instance

#the finall() method will extract all of the substrings which match the regular expression, returning a list of all strings
#r tells python not to consider the special programming characters like \
#\S tells python any character not whitespace
#\s is any whitespace

#[a-zA-Z0-9] explicitly identifies which types of characters are allowed
#[^a-zA-Z0-9] inside the brackets means any character not in brackets ^ inside brackets is exclusionary

#[0-9.]+ this looks for floats
#() specifies that that is the value that needs to be extracted
#$ specifies that we want this specifically to be at the end of the line or string
#\$ identifies $ as an actual character instead of a specifier

# \b matches empty string only at start or end of word
# \B matches the empty string but not at start or end
# \d matches any decimal digit
# \D matches any non digit character




