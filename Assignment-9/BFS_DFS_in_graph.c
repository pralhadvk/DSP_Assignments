#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node                 //node structure used in queue for BFS
{
    int data;
    struct node *next;
};

struct node *front, *rear;
bool isGraphCreated = false;        //used to prevent BFS/DFS being called on uninitialized graph
int vertices;

bool isEmpty()
{
    return NULL == front;
}

void enqueue(int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if(!temp)
        printf("Memory full!!\n");
    else
    {
        temp->data = data;
        temp->next = NULL;
        if(NULL == front)
            front = rear = temp;
        else
        {
            rear->next = temp;
            rear = rear->next;
        }
    }
        
}

int dequeue()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if(NULL == front)
    {
        return -1;
    }
    else
    {
        temp = front;
        front = front->next;
        return temp->data;   
    }
}

bool isValidEdge(int test)          //used to check if entered edge value is either 1 or 0
{
    return 0 == test || 1 == test;
}

void createGraph(int adj[vertices][vertices])
{
    int temp;
    printf("Enter 1 for an edge 0 for no edge\n");
    for(int i=0;i<vertices; i++)
    {
        for(int j=0; j<vertices; j++)
        {
            if(i==j)                        //No self edge for any node
                adj[i][j] = 0;
            else
            {
                printf("From vertex %d to vertex %d: ",i,j);
                scanf("%d",&temp);
                while(!isValidEdge(temp))
                {
                    printf("From vertex %d to vertex %d: ",i,j);
                    scanf("%d",&temp);
                }
                
                adj[i][j] = temp;
            }
        }
    }
    printf("Entered Adj matrix is:\n");
    for(int i=0; i<vertices; i++)
    {
        for(int j=0; j<vertices; j++)
            printf(" %d ", adj[i][j]);
        printf("\n");
    }
    isGraphCreated = true;
}

void BFS(int adj[vertices][vertices], int visited[vertices])
{
    if(!isGraphCreated)
    {
        printf("Graph not created!\n");
        return;
    }
    int startVertex;
    printf("Enter valid start vertex: ");
    scanf("%d", &startVertex);

    while(startVertex > vertices-1 && startVertex < 0)
    {
        printf("Enter valid start vertex: ");
        scanf("%d", &startVertex);
    }

    visited[startVertex] = 1;
    enqueue(startVertex);
    printf("BFS sequence is as follows:\n");
    while(!isEmpty())
    {
        startVertex = dequeue();
        printf(" %d ",startVertex);
        for(int j=0; j < vertices; j++)
        {
            if(adj[startVertex][j] == 1 && visited[j] == 0)
            {
                enqueue(j);
                visited[j] = 1;
            }
        }
    }
    printf("\n");
}

void DFS(int adj[vertices][vertices], int visited[vertices], int startVertex)
{
    if(!isGraphCreated)
    {
        printf("Graph not created!\n");
        return;
    }
    printf(" %d ", startVertex);
    visited[startVertex] = 1;
    for(int i=0; i<vertices; i++)
    {
        if(adj[startVertex][i] == 1 && visited[i] == 0)
        {
            DFS(adj,visited,i);
        }
    }
}

int main()
{
    int choice;
    printf("Enter 2 or more the number of nodes for graph\n");
    scanf("%d", &vertices);
    while(vertices <= 1)
        scanf("%d", &vertices);
    int adj[vertices][vertices],visited[vertices];

    printf("Select below choices:\n1.Create Graph\n2.BFS\n3.DFS\n4.exit\n");
    scanf("%d", &choice);
    while(4 != choice)
    {
        if(1 == choice)
        {
            createGraph(adj);
        }
        else if(2 == choice)
        {   
            for(int i=0; i<vertices; i++)
                visited[i] = 0;
            BFS(adj, visited);
        }
        else if(3 == choice)
        {   
            if(!isGraphCreated)
            {
                printf("Graph not created!\n");
                return 0;
            }
            for(int i=0; i<vertices; i++)
                visited[i] = 0;
            int startVertex;
            printf("Enter valid start vertex: ");
            scanf("%d", &startVertex);
            while(startVertex > vertices-1 && startVertex < 0)
            {
                printf("Enter valid start vertex: ");
                scanf("%d", &startVertex);
            }
            DFS(adj,visited,startVertex);
            printf("\n");
        }
        else
        {
            printf("Invalid choice\n");
        }
        printf("Select below choices:\n1.Create Graph\n2.BFS\n3.DFS\n4.exit\n");
        scanf("%d", &choice);
    }
}