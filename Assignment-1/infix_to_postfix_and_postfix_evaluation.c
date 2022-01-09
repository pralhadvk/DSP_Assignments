#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h> 
#include<string.h>

struct Stack
{
    int top;
    int size;
    char *arr;
};

struct Stack *createStack(int size)
{
    struct Stack *st = (struct Stack *)malloc(sizeof(struct Stack));
    st->top = -1;
    st->size = size;
    st->arr = (char *)malloc(size*sizeof(char));
    return st;
}

bool isEmpty(struct Stack *st)
    {return st->top == -1;}

bool isFull(struct Stack *st)
    {return st->top == st->size-1;}

bool isOperator(char c)
    {return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
}

bool isOperand(char c)
    {return (c>='1' && c<= '9');}

int operatorValue(char c)
{
    if(c == '^')
        return 3;
    else if(c =='*' || c=='/')
            return 2;
    else if(c=='+' || c=='-')
            return 1;
        else
            return -1;
}

void push(struct Stack *st,char operator)
{
    st->arr[++st->top] = operator;
}

char pop(struct Stack *st)
{
    if(!isEmpty(st))
        return st->arr[st->top--];
    else
        return '$';
}

char lookup(struct Stack *st)
{
    return st->arr[st->top];
}

int main()
{
    char str[100];
    int i,j,x;
    char temp,char1,char2,value1,value2;
    printf("Enter a string of expression\n");
    scanf("%s",str);
    struct Stack *st = createStack(strlen(str));
    for(i=0, j=-1;str[i]!='\0';i++)
        {
            if(isOperand(str[i]))               //if operator it is added in the original string
                str[++j] = str[i];
            
            else if(str[i]=='(')
                push(st,'(');

            else if(str[i] == ')')
                {
                while(!isEmpty(st) && lookup(st)!='(')
                    str[++j] = pop(st);
                if(!isEmpty(st) && lookup(st)!='(')         //if any char other than ( is found
                    {
                        printf("Invalid Expression!!");
                        break;
                    }
                else
                    pop(st);  
                }                         //pops value of last "(" in stack
                
            else
            {
                while(!isEmpty(st) && operatorValue(str[i]) <= operatorValue(lookup(st)))  //till a condition wherein the top of stack has less value than 
                    str[++j] = pop(st);
                
                push(st,str[i]);                         //insert operator in stack
            }


        }
    while(!isEmpty(st))
    {
        str[++j] = pop(st);
    }

    str[++j] ='\0';
    printf("Postfix Expression is:\n%s\n",str);


// postfix evaluation starts  here

    for(i=0; str[i]!= '\0'; i++)
    {
        if(isOperand(str[i]))
            push(st,str[i]);
        else
        {
            if(str[i]=='^')
            {
                char1 = pop(st);
                char2 = pop(st);
                x = pow((char1-'0'),(char2-'0'));
                push(st,x+'0');
            }
            if(str[i]=='*')
            {
                char1 = pop(st);
                char2 = pop(st);
                x = (char1-'0')*(char2-'0');
                push(st,x+'0');
            }
            if(str[i]=='/')
            {
                char1 = pop(st);
                char2 = pop(st);
                x = (char2-'0')/(char1-'0');
                push(st,x+'0');
            }
            if(str[i]=='+')
            {
                char1 = pop(st);
                char2 = pop(st);
                x = (char1-'0')+(char2-'0');
                push(st,x+'0');
            }
            if(str[i]=='-')
            {
                char1 = pop(st);
                char2 = pop(st);
                x = (char2-'0')-(char1-'0');
                push(st,x+'0');
            }
        }
    }
    char1 = pop(st);
    x = char1-'0';
    printf("Evaluated Postfix value is: %d\n", x);

}
