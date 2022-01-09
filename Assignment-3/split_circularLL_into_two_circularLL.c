#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node * head = NULL;
int count;

void insert(int value)
{   
        count++;
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = value;
        temp->next = NULL;

        if(!head)                           //check for initail head node for empty LL
        {
            head = temp;
        }
        else
        {
            struct Node *ptr = head;
            while(ptr->next)
                ptr = ptr->next;

            ptr->next = temp;
        }

}

void display(struct Node *ptr)
{
    struct Node *itr = ptr;
    while(itr->next!= ptr)
    {
        printf(" %d ->",itr->data);
        itr = itr->next;
    }
    printf(" %d \n",itr->data);
}

void breakList()
{   
    int half1,half2;                      //half1,half2 stores number of elements in first circular LL and second Circular LLrespectively
    if(count%2)
        half1 = (count/2)+1;
    else
        half1 = count/2;

    half2 = count-half1;
    struct Node *ptr1 = head;
    struct Node *ptr2;
    struct Node *head2;
    half1--;                    //since ptr already points to one value in LL half1 and half are decremented by 1
    half2--;

    while(half1)
    {
        ptr1 = ptr1->next;
        half1--;
    }
    
    head2 = ptr1->next;         //head2 contains value of second Circular LL
    ptr1->next = head;          //last element made to point to first element

    ptr2 = head2;
    
    while(half2)
        {
            ptr2 = ptr2->next;
            half2--;
        }

    ptr2->next = head2;         //last element made to point to first element

    printf("first Circular LL is: \n");
    display(head);
    printf("Second Circular LL is: \n");
    display(head2);   
}

void main()
{
    int value,inputValue;
    while(1)
    {
        printf("Enter value to insert in LL and -1 to break\n"); 
        if(!scanf("%d",&value))
            {
                printf("Program exit ddue to non-numeric value!!\n");
                break;
            }
        if(-1 == value)
        {   
            if(1 >= count)
            {
                printf("Node number shuld be greater than 1!!\n");
                continue;
            }
            else
            {
                struct Node *ptr = head;
                while(ptr->next)                //connect last node to head forming circulat LL
                    ptr = ptr->next;
                ptr->next = head;
                breakList();
                break;
            }
        }
        else
        {
            insert(value);
        }
    }
}
