#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
};

struct Queue
{
    struct treeNode *add;
    struct Queue *next;
};

struct Queue *front;
struct Queue *rear;

void enqueue(struct treeNode *t)
{
    struct Queue *temp;
    temp = (struct Queue*)malloc(sizeof(struct Queue));
    if(!temp)
        printf("Queue Full!!\n");
    else
    {     
        temp->add = t;
        temp->next = NULL;
        if(front == NULL)
            front = rear = temp;
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }
}

struct treeNode *dequeue()
{
    struct Queue *temp;
        temp = front;
        front = front->next;
        return temp->add;
}

bool isEmpty()
{
    return front == NULL;
}

struct treeNode *createTreeNode(int data)
{
    struct treeNode *t = (struct treeNode *)malloc(sizeof(struct treeNode));
    t->data = data;
    t->left = NULL;
    t->right = NULL;
    return t;
}

struct treeNode *createTree(int arr[], int n)
{
    int i =1,left,right;
    struct treeNode *root = createTreeNode(arr[i]);
    enqueue(root);
    while(!isEmpty())
    {
        struct treeNode *t = dequeue();
        left = i*2;
        right = left+1;
        if(left<=n)
        {
            t->left = createTreeNode(arr[left]);
            enqueue(t->left);
        }
        else
            t->left = NULL;
        if(right <= n)
        {
            t->right = createTreeNode(arr[right]);
            enqueue(t->right);
        }
        else
            t->right = NULL;
        i++;
    }
    return root;
}

void inorder(struct treeNode *ptr)
{
    if(ptr)
    {
        inorder(ptr->left);
        printf(" %d ",ptr->data);
        inorder(ptr->right);
    }
}
void preorder(struct treeNode *ptr)
{
    if(ptr)
    {
        printf(" %d ",ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}
void postorder(struct treeNode *ptr)
{
    if(ptr)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf(" %d ",ptr->data);
    }
}

int height(struct treeNode *ptr)
{
    int x=0,y=0;
    if(!ptr)
        return 0;
    x = height(ptr->left);
    y = height(ptr->right);
    if(x>y)
        return x+1;
    else
        return y+1;
}

void printTree(int arr[],int height, int n)
{
    int currHeight, currNode=1,count = 1, countSpaces, countArrow = 1, i = 1;
    currHeight = height+1;
    countSpaces = currHeight-1;
    while(height)
    {
        while(currHeight)
            {
                printf(" ");
                currHeight--;
            }
        while(count >= 1 && i < n)
        {
            printf("%d ", arr[i]);
            count--;
            i++;
        }
        printf("\n");
        while(countSpaces)
        {
            printf(" ");
            countSpaces--;
        }
        while(countArrow && i < n)
        { 
            printf("/\\ ");
            countArrow--;
        }
        count = 2 * currNode;
        currNode = count;
        countArrow = count;
        printf("\n");
        height--;
        currHeight = height+1;
        countSpaces = currHeight-1;
    }
}

void main()
{
    int n;
    printf("Enter number of values\n");
    scanf("%d",&n);
    int arr[n+1];
    for(int i=1; i<=n; i++)
        scanf("%d",&arr[i]);
    struct treeNode *t = createTree(arr,n);
    printf("\nHeight of tree is: %d\n",height(t));
    printf("Inorder of the tree is:");
    inorder(t);
    printf("\nPreorder of the tree is:");
    preorder(t);
    printf("\nPostOrder of th tree is:");
    postorder(t);
    printf("\n");
    printTree(arr,height(t),n+1);
    
}