#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
    char *first;
    char *mid;
    char *last;
    struct Node *next;
};
struct Node *head=NULL;
struct Node *createNode(char *first, char *mid, char *last)
{   
    int i=0,j=0,k=0;
    struct Node *st = (struct Node *)malloc(sizeof(struct Node));
    st->first = (char*)malloc(20*sizeof(char));
    while(st->first[i]=first[i])
        ++i;
    st->mid = (char*)malloc(20*sizeof(char));
    while(st->mid[j]=mid[j])
        ++j;
    st->last = (char*)malloc(20*sizeof(char));
    while(st->last[k]=last[k])
        ++k;
    st->next = NULL;
    return st;
}

// void linkNode(struct Node *st)
// {

//         struct Node *temp;
//         temp = head;
//         while(temp->next)
//             temp = temp->next;
//         temp->next = st;
//         curr = st;
// }

void displayAll()
{
    int count = 1;
    struct Node *st = head;
    while(count<=5)
    {
        printf("%d.%s  %s  %s\n",count,st->first,st->mid,st->last);
        st = st->next;
        count++;
    }
    printf("\n");
}
void displayMidString()
{
    int count = 1;
    struct Node *st = head;
    while(count<=5)
    {
        printf(" %s ",st->mid);
        st = st->next;
        count++;
    }
    printf("\n");
}

void verify()
{   
    int count = 5;
    struct Node *ptr = head;
    struct Node *ptr_prev = head;
    ptr = ptr->next;
    while(count)
    {
        if(strcmp(ptr_prev->last,ptr->first))
        {
            printf("String not matching\n");
            break;
        }
        ptr_prev = ptr;
        ptr = ptr->next;
        count--;
    }
    if(!count)
        printf("Valid String\n");
}
void main()
{   
    int i=0,count=1;
    char first[20], mid[20], last[20];
    struct Node *temp;
    struct Node *p;
    
    while(count<=5)
    {
        printf("Enter 3 strings\n");
        scanf("%s",first);
        scanf("%s",mid);
        scanf("%s",last);
        temp = createNode(first,mid,last);
        if(!head)
            {
                head = temp;
                p = head;
            }
        else
        {   
            p->next = temp;
            p = p->next;
            // struct Node *p;
            // p = head;
            // while(p->next)
            //     p = p->next;
            // p->next = temp;
        }
        count++;
    }
    p->next = head;

    displayAll();
    //displayMidString();
    verify();
}
