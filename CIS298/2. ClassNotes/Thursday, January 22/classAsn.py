total = 0
numG = 0
with open('grades.txt') as grades:
    for grade in grades:
        print(grade.strip())
        total += float(grade)
        numG += 1
print( "Class Average: "+ str(round(total/numG, 2)))
