#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

struct LLnode               //queue used to store leaf nodes in decreasing order
{
    char name[1000];
    int freq;
    struct LLnode *next;
};

struct LLnode *ptr = NULL;

struct node                 //node structure used for tree
{
    char name[1000];
    struct node *child[100];
    bool isLeaf;
    int freq;
};

struct node *root = NULL;

void insertLL(struct node *t)
{   
    struct LLnode *temp = (struct LLnode *)malloc(sizeof(struct LLnode));
    struct LLnode *pt = ptr;        //ptr is head node whereas pt is used to hold address of it 
    struct LLnode *tempp;           //used for holding address used during new node insert
    strcpy(temp->name,t->name);     //new queue LL node created with name passed
    temp->freq = t->freq;           
    temp->next = NULL;
    if(!ptr)
        ptr = temp;
    else
    {
        if(temp->freq > ptr->freq)  //the head nodes freq is greatest and if new node freq is found greater than head node freq then it is made head node
            {
                temp->next = ptr;
                ptr = temp;
            }
        else
        {
            while(pt->next && pt->next->freq >= temp->freq )    //location for new node 
            {
                pt = pt->next;
            }
            tempp = pt->next; //stores address where the new nodes needs to be added
            pt->next = temp;
            temp->next = tempp;
        }

    }

}

void displayDecFreqLeaf()
{
    struct LLnode *temp = ptr;
    if(!temp)
        printf("No leaf!!\n");
    else
    {
        while(temp)
        {
            printf(" %s ", temp->name);
            temp = temp->next;
        }
    }
}

struct node *createNode(char name[],bool isLeaf) //create node based on node structure and if leaf set the leaf
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    for(int i=0;i<100; i++)
        temp->child[i] = NULL;
    strcpy(temp->name,name);
    if(isLeaf)
        temp->freq = 1;
    else
        temp->freq = -1;

    return temp;
}

void initialize()
{
    root = createNode("words",0);           //since root is given as "word"
}

struct node *insertCategory(char category[])
{
    struct node *temp = createNode(category, 0);    //create category node with leaf as 0
    int i = 0;
    while(root->child[i])                           //used to verify is category is already present
        {
            if(strcmp(root->child[i]->name,category) == 0)
                {
                    printf("Category already present!!\n");
                    return root->child[i];
                }
            i++;
        }
    root->child[i] = temp;                  //new category node is created as assigned to next child pointer of root which is NULL
    return root->child[i];
}

void insertLeaf(char category[],char leaf[])
{
    struct node *temp = createNode(leaf, 1);    //leaf node created with leaf set to 1
    struct node *ct;
    int i=0;
    bool foundCategory = false, foundChild = false;
    while(root->child[i])
    {
        if(strcmp(category,root->child[i]->name)== 0)
            {   
                foundCategory = true;
                ct = root->child[i];            //if category present it's address is stored in ct
                break;
            }
        i++;
    }
    if(foundCategory)
    {
        int j=0;
        while(ct->child[j])
            {
                if(strcmp(leaf,ct->child[j]->name)== 0)
                {
                    ct->child[j]->freq++;       //leaf node for the category is checked and if already present its freq iss incremented
                    foundChild = true;
                    break;
                }
                j++;
            }
        if(!foundChild)
        {
            ct->child[j] = temp;        //if leaf node is not found in child nodes then newly created leaf node is assigned to the next child pointer address
        }
    }
    else
    {
        ct = insertCategory(category);  //if category itself is not present it is created and its first child address is assigned with the leaf node
        ct->child[0] = temp;
    }

}

void displayLeaf()
{   
    for(int i=0; root->child[i] != NULL; i++) //all category nodes are traversed
    {
        struct node *ct = root->child[i];
        for(int j=0; ct->child[j]!= NULL; j++)  // for every category nodes all its child nodes are printed
            printf(" %s ",ct->child[j]->name);
    }
}


//search  function required for depth and degree 
bool isNodePresent(char name[])
{
    if(name == "words")
    {
        printf("%s node is at level 0\n",name);
        return true;
    }
    else
    {
        for(int i=0; root->child[i] != NULL; i++)   //all category nodes are traversed
        {   
            struct node *ct = root->child[i];
            if(strcmp(root->child[i]->name,name) == 0)  //category nodes names are checked for the given name
                return true;

            for(int j=0; ct->child[j] != NULL; j++)
            {
                if(strcmp(ct->child[j]->name,name) == 0)    // all child nodes of the category node are traversed and checked with the given name
                    return true;
            }
        }
    }
    return false;
}

struct node *depthOfNode(char name[])
{   
    if(name == "words")
    {
        printf("%s node is at level 0\n",name);
        return root;
    }
    else
    {
        for(int i=0; root->child[i] != NULL; i++)   //all category nodes are traversed
        {   
            struct node *ct = root->child[i];
            if(strcmp(root->child[i]->name,name) == 0)  //category nodes names are checked for the given name
                {
                    printf("%s node is at level 1\n",root->child[i]->name);
                    return root->child[i];
                }
            for(int j=0; ct->child[j] != NULL; j++)
            {
                if(strcmp(ct->child[j]->name,name) == 0)    // all child nodes of the category node are traversed and checked with the given name
                {
                    printf("%s node is at level 2\n",ct->child[j]->name);
                    return ct->child[j];
                }
            }
        }
        return NULL;
    }
}

void displayDegree(char name[])
{
    struct node *temp = NULL;
    if(strcmp("words",name) == 0)       //name passed is checked with the root name
        temp = root;
    else                                //name passed is checked with category as well as child and that node address stored in temp
        for(int i=0; root->child[i] != NULL; i++)
        {   
            struct node *ct = root->child[i];
            if(strcmp(root->child[i]->name,name) == 0)
                temp = root->child[i];
            for(int j=0; ct->child[j] != NULL; j++)
                if(strcmp(ct->child[j]->name,name) == 0)
                    temp = ct->child[j];
        }
    if(temp)
    {
        int i=0;
        // printf("%d %d",temp->isLeaf,temp->freq);
        if(temp->freq > 1)             //temp is leaf node which has degree 1
            printf("Degree of node %s is 1",name);
        else
        {
            while(temp->child[i])       //calculate all the child nodes which are non NULL and the count indicates the degree of that node
            i++;
            printf("Degree of node %s is: %d",name,i);
        }
    }
    else                                //if name does not match with any name in the tree
    {
        printf("No Node found!!\n");
    }
}

void main()
{
    int choice,len;
    char name1[100],name2[100], name3[100];
    bool exit= false;
    initialize();                           //creates root node as "word"

    while(!exit)
    {
        printf("\n Select choice\n1.insert\n2.Display Leaf\n3.node depth\n4.node degree\n5.Display freq desc node\n6.Quit\n");
        scanf("%d",&choice);
        if(1 == choice)
            {
                printf("Enter 1 to insert category 2 for word(All words used are case sensitive)\n");
                scanf("%d", &choice);
                if(1 == choice)
                {
                    printf("Enter Category name\n");
                    scanf("%s",name1);
                    // for(int i=0; name1[i]; i++)
                    //     name1[i] = tolower(name1[i]);
                    insertCategory(name1);
                }
                else
                {
                    printf("Enter Category name\n");
                    scanf("%s",name1);
                    // for(int i=0; name1[i]; i++)
                    //     name1[i] = tolower(name1[i]);
                    printf("Enter word name\n");
                    scanf("%s", name2);
                    // for(int i=0; name2[i]; i++)
                    //     name2[i] = tolower(name2[i]);
                    len = strlen(name2);
                    if(name2[len-2]== '-') //used to extract count from the leaf node name 
                        {
                            len = name2[len-1]-'0';
                            int i=0;
                            while(name2[i] != '-')
                                {
                                    name3[i] = name2[i];
                                    i++;
                                }
                            name3[i] = '\0';
                            // printf("%s",name3);
                            while(len)      //based on the extracted count of leaf node insertLeaf function is called
                            {
                                insertLeaf(name1,name3);
                                len--;
                            }
                        }
                    else
                    {
                        insertLeaf(name1,name2);
                    }
                    
                }
            }
        else if(2 == choice)
        {
            displayLeaf();
        }
        else if(3 == choice)
        {
            printf("Enter node name to find its depth\n");
            scanf("%s", name1);
            if(isNodePresent(name1))
                depthOfNode(name1);
            else
                printf("%s node is not present!\n",name1);
        }
        else if(4 == choice)
        {
            printf("Enter node name to find its degree\n");
            scanf("%s",name1);
            if(isNodePresent(name1))
                displayDegree(name1);
            else
                printf("%s node is not present!\n",name1);
        }
        else if(5 == choice)
        {
            printf("desc node are:\n");
            for(int i=0; root->child[i] != NULL; i++)
            {
                struct node *ct = root->child[i];
                for(int j=0; ct->child[j]!= NULL; j++)
                    insertLL(ct->child[j]);             //used to order nodes based on descending order into a LL
            }
            displayDecFreqLeaf();
            ptr = NULL;
        }
        else if(6 == choice)
        {
            exit = true;
        }
        else
        {
            printf("Invalid Input!!\n");
            continue;
        }

    }
}
