#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)
#define MAX_LEN 100


// Function to check if parentheses in a string are balanced
// Parameters:
//   str: The input string to be checked for balanced parentheses
// Method:
//   Traverse the string from the end.
//   When encountering '(', find the corresponding ')' ahead.
//   Mark '(' as 1 and ')' as -1 in the array.
//   If a ')' is found, mark the corresponding '(' as 0.
//   Print 'x' for unmatched '(' and '?' for unmatched ')'.
//   Print ' ' for characters other than parentheses.
void checkBrackets(char str[]) 
{
    int len = strlen(str);
    int a[100] = { 0 }; //array to store the result
    for (int i = len-1; i >=0; i--) 
    {
        int find = 0;

        //ignoring alphabet
        if(str[i] <='z' && str[i] >= 'a' || str[i]>='A' && str[i]<='Z')
        {
            continue;
        }
        else if (str[i] == ')')
        {
            a[i] = -1;
        }
        else if (str[i] == '(') 
        {
            for (int j = i; j < len; j++)
            {
                if (a[j] == -1)
                {
                    a[j] = 0;
                    find = 1;
                    break;
                }
            }
            if (find == 0)
            {
                a[i] = 1;
            }       
        }
    }
    for (int i = 0; i < len; i++)
    {
        if (a[i] == 1)
        {
            printf("x");
        }
        else if (a[i] == -1)
        {
            printf("?");
        }
        else if (a[i] == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    char str[100];

    while (scanf("%s", str) != EOF) {
        checkBrackets(str);
    }
    return 0;
}
