#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node                 //node structure for AVL tree 
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

int count;                  //used for sum of leftsubtree nodes
struct node *root = NULL;

struct Queue               //queue strcture for level order traversal
{
    struct node *nodee;
    struct Queue *next;
};

struct Queue *front;
struct Queue *rear;

bool isEmpty()
{
    if(front == NULL)
        return true;
    return false;
}

void enqueue(struct node *ptr)
{
    struct Queue *temp = (struct Queue *)malloc(sizeof(struct Queue));
    temp->nodee = ptr;
    temp->next = NULL;

    if(front == NULL)
        front = rear = temp;
    else
    {
        rear->next = temp;
        rear = temp;       
    }
}

struct node *dequeue()
{
    if(front == NULL)
        return NULL;
    else
    {
        struct Queue *ptr = front;
        front = front->next;
        return ptr->nodee;
    }
}

void inorder(struct node *ptr)
{
    if(ptr)
    {
        inorder(ptr->left);
        printf(" %d ",ptr->data);
        inorder(ptr->right);
    }
}

void preorder(struct node *ptr)
{
    if(ptr)
    {
        printf(" %d ",ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(struct node *ptr)
{
    if(ptr)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf(" %d ",ptr->data);
    }
}

void levelOrder(struct node *ptr)
{
    if(!ptr)
        printf("tree Empty!!\n");
    else
    {   
        struct node *t;
        printf(" %d ",ptr->data);
        enqueue(ptr);
        while(!isEmpty())
        {
            t = dequeue();
            if(t->left)
            {
                printf(" %d ", t->left->data);
                enqueue(t->left);
            }
            if(t->right)
            {
                printf(" %d ", t->right->data);
                enqueue(t->right);
            }
        }
        printf("\n");
    }    
}

int height(struct node *ptr)
{   
    int x,y;
    if(ptr == NULL)
        return 0;
    x = height(ptr->left);
    y = height(ptr->right);
    return x>y ? x+1: y+1;
}

struct node *inPredecessor(struct node *p)
{
    while(p && p->right != NULL)
        p = p->right;
    return p;
}

struct node *inSuccessor(struct node *p)
{
    while(p && p->left != NULL)
        p = p->left;
    return p;
}

int heightOfNode(struct node *temp)
{
    int heightOfLC, heightOfRC;
    if(temp && temp->left)
        heightOfLC = temp->left->height;
    else
        heightOfLC = 0;
    if(temp && temp->right)
        heightOfRC = temp->right->height;
    else
        heightOfRC = 0;
    return heightOfLC>heightOfRC ? heightOfLC+1 : heightOfRC+1;
}

int balanceFactor(struct node *temp)
{
    int heightOfLC, heightOfRC;
    if(temp && temp->left)
        heightOfLC = temp->left->height;
    else
        heightOfLC = 0;
    if(temp && temp->right)
        heightOfRC = temp->right->height;
    else
        heightOfRC = 0;

    return heightOfLC-heightOfRC;
}

struct node *LLrotation(struct node *p)
{
    struct node *pl;
    struct node *plr;
    struct node *temp;
    
    // printf("p: %d\n",p->data);

    temp = p;
    pl = p->left;
    plr = p->left->right;
    pl->right = p;
    p->left = plr;

    p->height = heightOfNode(p);            //as node position changes its height is recalculated
    pl->height = heightOfNode(pl);

    if(root == temp)                        //if node passed is root it is now changed to new root
        root = pl;

    return pl;
}

struct node *LRrotation(struct node *p)
{
    struct node *pl;
    struct node *plr;
    struct node *temp;

    temp = p;
    pl = p->left;
    plr = p->left->right;

    pl->right = plr->left;
    p->left = plr->right;
    plr->left = pl;
    plr->right = p;

    p->height = heightOfNode(p);                    //as node position changes its height is recalculated
    plr->height = heightOfNode(plr);
    pl->height = heightOfNode(pl);

    if(root == temp)                                //if node passed is root it is now changed to new root
        root = plr;

    return plr;
}

struct node *RRrotation(struct node *p)
{
    struct node *pr;
    struct node *prr;
    struct node *temp;
    
    temp = p;
    pr = p->right;
    prr = p->right->right;
    p->right = pr->left;
    pr->left = p;

    p->height = heightOfNode(p);                        //as node position changes its height is recalculated
    pr->height = heightOfNode(pr);
    prr->height = heightOfNode(prr);

    if(root == temp)                                    //if node passed is root it is now changed to new root
        root = pr;
    
    return pr;
}

struct node *RLrotation(struct node *p)
{
    struct node *pr;
    struct node *prl;
    struct node *temp;

    temp = p;
    pr = p->right;
    prl = p->right->left;
    p->right = prl->left;
    pr->left = prl->right;
    prl->left = p;
    prl->right = pr;

    p->height = heightOfNode(p);                        //as node position changes its height is recalculated
    pr->height = heightOfNode(pr);
    prl->height = heightOfNode(prl);

    if(root == temp)                                    //if node passed is root it is now changed to new root
        root = prl;
    
    return prl;
}
struct node *delete(struct node *p, int value)
{   
    struct node *q;
    if(!p)
        {
            return NULL;
        }
    
    if(p->left == NULL && p->right == NULL)
    {
        if(p == root)
            root = NULL;

        free(p);
        return NULL;
    }

    if(value < p->data)
        p->left = delete(p->left, value);
    else if(value >p->data)
        p->right = delete(p->right, value);
    else
    {
        if(height(p->left) > height(p->right))
        {
            q = inPredecessor(p->left);
            p->data = q->data;
            p->left = delete(p->left,q->data);
        }
        else
        {
            q = inSuccessor(p->right);
            p->data = q->data;
            p->right = delete(p->right,q->data);
        }
    }

    p->height = heightOfNode(p);

    if(balanceFactor(p) == 2 && balanceFactor(p->left)==1)
       return LLrotation(p);
    else if(balanceFactor(p) == 2 && balanceFactor(p->left)==-1)
       return LRrotation(p);
    else if(balanceFactor(p) == -2 && balanceFactor(p->right)==-1)
       return RRrotation(p);
    else if(balanceFactor(p) == -2 && balanceFactor(p->right)==1)
       return RLrotation(p);

    return p;
    
}

struct node *insertNode(struct node *p, int value)
{
    if(p == NULL)
        {
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp->data = value;
            temp->height = 1;
            temp->left = NULL;
            temp->right = NULL;
            return temp;
        }

    if(value < p->data)
        p->left = insertNode(p->left, value);
    else if(value > p->data)
        p->right = insertNode(p->right, value);
    
    p->height = heightOfNode(p);

    if(balanceFactor(p) == 2 && balanceFactor(p->left)==1)
        {
            printf("LL\n");
           return LLrotation(p);
        }
    else if(balanceFactor(p) == 2 && balanceFactor(p->left)==-1)
        {
            printf("LR\n");
            return LRrotation(p);
        }
    else if(balanceFactor(p) == -2 && balanceFactor(p->right)==-1)
        {
            printf("RR\n");
            return RRrotation(p);
        }
    else if(balanceFactor(p) == -2 && balanceFactor(p->right)==1)
        {
            printf("RL\n");
            return RLrotation(p);
        }

    return p;

}

void leftSubtreeSum(struct node *ptr)
{
    if(ptr)
    {
        leftSubtreeSum(ptr->left);
        count += ptr->data;
        leftSubtreeSum(ptr->right);
    }
}

struct node *search(struct node *ptr,int value)        //used to serach for value in tree before its deletion
{
    if(ptr == NULL)
        {
            return NULL;
        }
    else if(value < ptr->data)
        search(ptr->left,value);
    else if(value > ptr->data)
        search(ptr->right, value);
    else
        return ptr;
    
}
void main()
{
    int choice,x,n;
    struct node *temproot;
    while(1)
    {
        printf("Select the choice\n1.Insert\n2.Delete\n3.Print LevelOrder,Inorder,Preorder,Postorder,\n4.left subtree Sum\n5.Exit\n");
        scanf("%d", &choice);
        if(1 == choice)
        {
            printf("Enter number to insert\n");
            scanf("%d",&x);
            if(root == NULL)
                root = insertNode(root,x);
            else
                insertNode(root,x);
            // printf("Enter %d numbers\n", n);
            // scanf("%d", &x);
            // root = insertNode(root,x);
            // n = n-1;
            // while(n)
            // {   
            //     scanf("%d", &x);
            //     insertNode(root,x);
            //     n--;
            // }
            printf("root is: %d\n",root->data);
            // printf("%d",root->left->left->data);
            // printf("%d",root->left->right->data);
            temproot = root;
        }
        else if(2 == choice)
        {
            printf("\n Enter number to delete\n");
            scanf("%d",&x);
            if(search(temproot,x))
                delete(root,x);
            else
                printf("Node not found!!\n");

        }
        else if(3 == choice)
        {
            printf("LevelOrder is:\n");
            levelOrder(temproot);
            printf("\n");

            temproot = root;
            printf("PreOrder is:\n");
            preorder(temproot);
            printf("\n");

            temproot = root;
            printf("InOrder is:\n");
            inorder(temproot);
            printf("\n");

            temproot = root;
            printf("PostOrder is:\n");
            postorder(temproot);
            printf("\n");
        }
        else if(4 == choice)
        {
            leftSubtreeSum(temproot->left);
            printf("\nSum of left Subtree nodes: %d\n",count);
        }
        else if(5 == choice)
            break;
        else
        {
            printf("Invalid Choice!!\n");
            continue;
        }
    }
}
