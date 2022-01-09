#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SIZE 100

void main()
{
    char str[SIZE], ans[SIZE];
    int startIndex, endIndex;
    printf("Enter string:\n");
    scanf("%s",str);
    int strSize = strlen(str);
    
    int dp[strSize][strSize];
    for(int i=0; i<strSize; i++)
        for(int j=0; j<strSize; j++)
            dp[i][j] = 0;               //initialize the DP table

    for(int i=0; i<strSize; i++)        //a string with 1 char is pallindrome
        dp[i][i] = 1;
    
    for(int i=0; i<strSize-1; i++)      //a check for length of string of 2 chars
    {
        if(str[i] == str[i+1])
        {
            dp[i][i+1] = 1;
            startIndex = i;
            endIndex = i+1;
        }
    }

    for(int j=2; j<strSize; j++)        //iterates diagonally from the right of primary diagonal
    {
        for(int i=0; i<strSize-j; i++)
        {
            if(str[i] == str[i+j] && dp[i+1][i+j-1] == 1)   //a string is pallindrome iff its end chars match and string between end char is already pallindrome
            {
                dp[i][i+j] = 1;
                startIndex = i;
                endIndex = j+i;
            }
        }
    }
    printf("The longest pallindrome string is:\n");
    for(int i = startIndex; i<=endIndex; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}