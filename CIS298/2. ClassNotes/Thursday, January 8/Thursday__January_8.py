
def main():
    

    #Integers, Floats, and Strings operate similar to C++ can use "" or  '' quotes
    integer_number = 100
    print(integer_number)
    print("Of Type: ")
    print(type(integer_number))
    print()

    pi = 3.14
    print(pi)
    print("Of Type: ")
    print(type(pi))
    print()

    intro = "Hello World"
    print(intro)
    print("Of Type: ")
    print(type(intro))
    print()

    #naming conventions similar, types dont need to be specified

    # '//' is floor division rounding down to nearest whole number
    # '**' is exponent 5**2 is 5^2
    # other operators work as other programing languages

    #statements dont produce outputs to console
    #expressions produce a console output

    #string concatenation is the same as in C++


    #Asking for user input
    print("Please Provide Name")
    a = input()
    print("Your Name is " + a)


    return 0

if __name__ == "__main__":
    main()