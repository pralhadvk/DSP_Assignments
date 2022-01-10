#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define SIZE 10

int count;
int hashTable[SIZE];
int R = 7;              //first prime number less than hash table size

void initializeHash()
{
    for(int i=0; i<SIZE; i++)
        hashTable[i] = INT_MAX;
}

void displayHashTable()
{   
    printf("Below is the hashTable\n");
    for(int i=0; i<SIZE; i++)
        {   
            if(hashTable[i] == INT_MAX || hashTable[i] == INT_MIN)
                printf(" %s ","_");
            else
                printf(" %d ", hashTable[i]);
        }
    printf("\n");
}

void insertKey(int key)
{
    int index = key%SIZE;
    int i=0, j=1, k=0;
    if(hashTable[index] != INT_MAX)
    {
        int h2 = R-(key%R);

        while(hashTable[(index + i*h2)%SIZE] != INT_MIN && hashTable[(index + i*h2)%SIZE] != INT_MAX && j <= SIZE)
        {
            i++;
            j++;
        }

         if(j > SIZE)
        {
            printf("insufficient space for double probing!\n");
            return;
        }
        printf("location: %d\n", (index + i*h2)%SIZE);
        hashTable[(index + i*h2)%SIZE] = key;
        count++;
    }
    else
    {   
        printf("Location: %d\n",index);
        hashTable[index] = key;
        count++;
    }
    // displayHashTable();
}

bool isKeyPresent(int key)
{
    int index = key%SIZE;
    if(hashTable[index] == key)
        return true;
    else
    {
        int i=0, j=1;
        int h2 = R-(key%R);
        while(hashTable[(index + i*h2)%SIZE]!= key && j<SIZE)
        {
            i++;
            j++;
        }
        if(j == SIZE)
            return false;
        else
            return true;
    }
}

void deleteKey(int key)
{
    int index = key%SIZE;
    if(hashTable[index] == key)
    {
        hashTable[index] = INT_MIN;
        count--;
    }
    else
    {
        int i=0, j=1;
        int h2 = R-(key%R);
        while(hashTable[(index + i*h2)%SIZE] == INT_MIN || (hashTable[(index + i*h2)%SIZE]!= key && j<SIZE))
        {
            i++;
            j++;
        }
        if(j == SIZE)
        {
            printf("Element not Found!\n");
        }
        else
        {
            hashTable[(index + i*h2)%SIZE] = INT_MIN;
            count--;
        }
    }
}

void loadFactor()
{
    float lf;
    lf = (float)count/SIZE;
    printf("Load Factor is:%f\n",lf);
}

void main()
{
    int n, choice;
    bool exit = false;
    initializeHash();
    while(!exit)
    {
        displayHashTable();
        printf("Select below choice(hash size is: %d)\n1.Insert\n2.Search\n3.Delete\n4.LoadFactor\n5.Exit\n",SIZE);
        scanf("%d",&choice);
        if(choice == 1)
        {
            printf("Enter key to insert\n");
            scanf("%d",&n);
            if(count < SIZE)
                {
                    if(!isKeyPresent(n))
                        insertKey(n);
                    else
                        printf("Key present in hashTable\n");
                }
            else
                printf("Hash Full\n");
        }
        else if(choice == 2)
        {
            printf("Enter key to Search\n");
            scanf("%d", &n);
            isKeyPresent(n);
        }
        else if(choice == 3)
        {
            printf("Enter key to delete\n");
            scanf("%d",&n);
            deleteKey(n);
        }
        else if(choice == 4)
        {
            loadFactor();
        }
        else if(choice == 5)
            exit = true;
        else
            {
                printf("Enter valid choice\n");
                continue;
            }
    }
}