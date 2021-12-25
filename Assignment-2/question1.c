#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct stack
{
    int top;
    int size;
    char *arr;
};

struct stack *createStack(int size)
{
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));
    st -> top = -1;
    st ->size = size;
    st -> arr = (char *)malloc(size*sizeof(int));
    return st;
}
bool isEmpty(struct stack *st)
{
    if(st->top == -1)
        return true;
    else
        return false;
}
bool isFull(struct stack *st)
{
    if(st->top == st->size)
        return true;
    else
        return false;
}
char stackTop(struct stack *st)
{
    if(!isEmpty(st))
        return st->arr[st->top];
    else
        return '0';
}

void push(struct stack *st, char x)
{
    if(!isFull(st))
        {
            st->arr[++st->top] = x;
            //printf("%c\n",stackTop(st));
        }
    else
        printf("Stack Full!!");
}
void pop(struct stack *st)
{
    if(!isEmpty(st))
        st->arr[st->top--];
}
void main()
{
    int i;
    bool result = true;
    char str[1000];
    printf("Enter the input string\n");
    scanf("%s",str);
    if(strlen(str)<2)                   //base case
        result = false;
    else
    {
    struct stack *st = createStack(strlen(str));
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i] == '(')
            push(st,'(');
        else if(str[i] == '{')
            push(st, '{');
        else if(str[i] == '[')
            push(st,'[');
        else if(str[i] == ')')
        {
            if(stackTop(st) != '(')
            {
                result = false;
                break;
            }
            pop(st);
        }
        else if(str[i] == '}')
        {
            if(stackTop(st)!= '{')
            {
                result = false;
                break;
            }
            pop(st);
        }
        else if(str[i] == ']')
        {
            if(stackTop(st) != '[')
            {
                result = false;
                break;
            }
            pop(st);
        }
        else
        {
            printf("Invalid Expression\n");
            result = false;
            break;
        }
    }
    if(!isEmpty(st) && str[i]=='\0')
        result = false;
  }

    printf(result ? "true":"false");
    printf("\n");
}
