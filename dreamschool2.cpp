#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)
#define MAX_LEN 100

void checkBrackets(char str[]) 
{
    int len = strlen(str);
    int a[100] = { 0 };
    for (int i = len-1; i >=0; i--) 
    {
        int find = 0;
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
