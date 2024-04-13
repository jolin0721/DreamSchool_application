# Function to check if parentheses in a string are balanced
# Parameters:
#   string: The input string to be checked for balanced parentheses
# Method:
#   Traverse the string from the end.
#   When encountering '(', find the corresponding ')' ahead.
#   Mark '(' as 1 and ')' as -1 in the array.
#   If a ')' is found, mark the corresponding '(' as 0.
#   Print 'x' for unmatched '(' and '?' for unmatched ')'.
#   Print ' ' for characters other than parentheses.
def checkBrackets(string):
    length = len(string)
    a = [0] * length  # List to store the result

    for i in range(length - 1, -1, -1):
        find = 0

        # Ignore alphabets
        if string[i].isalpha():
            continue
        elif string[i] == ')':
            a[i] = -1
        elif string[i] == '(':
            for j in range(i, length):
                if a[j] == -1:
                    a[j] = 0
                    find = 1
                    break
            if find == 0:
                a[i] = 1

    for i in range(length):
        if a[i] == 1:
            print("x", end="")
        elif a[i] == -1:
            print("?", end="")
        elif a[i] == 0:
            print(" ", end="")

    print()

def main():
    while True:
        try:
            string = input()
            checkBrackets(string)
        except EOFError:
            break

if __name__ == "__main__":
    main()
