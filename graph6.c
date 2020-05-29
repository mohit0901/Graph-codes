//creating graph using adjancy list
#include <malloc.h>
#include <stdio.h>
#define MAX 1000
struct node
{
    char data;
    struct node *next;
};
struct node *graph[MAX];
void createGraph(struct node *graph[],int n);
void bfs(struct node *graph[],int n);
void printGraph(struct node *graph[],int n);
void main()
{
    int n;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    char x;
    scanf("%c",&x);
    int i;
    for(i=0;i<n;i++)
        graph[i]=NULL;
    printf("Enter the adjancy list:\n");
    createGraph(graph,n);
    printf("The graph is:\n");
    printGraph(graph,n);
    printf("Shortest path is:\n");
    bfs(graph,n);
}
void createGraph(struct node *graph[],int n)
{
    char x;
    int nn;
    struct node *newnode;
    struct node *tail;
    int i,j;
    char ch;
    for(i=0;i<n;i++)
    {
        printf("Enter the number of neighbours of %c : ",(char)(i+65));
        scanf("%d",&nn);
        scanf("%c",&x);
        for(j=1;j<=nn;j++)
        {
            printf("Enter neighbour %d of %c: ",j,(char)(i+65));

            scanf("%c",&ch);
            scanf("%c",&x);
            newnode=(struct node *)malloc(sizeof(struct node));
            newnode->next=NULL;
            newnode->data=ch;
            if(graph[i]==NULL)
            {
                graph[i]=newnode;
            }
            else
                tail->next=newnode;
            tail=newnode;
        }

    }
}
void bfs(struct node *graph[],int n)
{
    struct node *ptr;
    int visited[n];
    int i,j,co;
    for(i=0;i<n;i++)
        visited[i]=0;
    //queue
    co=0;
    char q[n];
    char ch;
    int front=-1,rear=-1;
    rear++;
    front++;
    q[rear]=(char)(65+co);
    visited[0]=1;
    while(front<=rear)
    {
        ch=q[front];
        front++;
        printf("%c - ",ch);
        co=(int)ch-65;
        ptr=graph[co];
        while(ptr!=NULL)
        {
            if(visited[(int)(ptr->data)-65]==0)
            {
                rear++;
                q[rear]=ptr->data;
                visited[(int)(ptr->data)-65]=1;
            }
            ptr=ptr->next;
        }
    }
    printf("\b\b ");
    printf("\n");

}
void printGraph(struct node *graph[],int n)
{
    int i;
    struct node *ptr;
    for(i=0;i<n;i++)
    {
        ptr=graph[i];
        printf("%c = ",(char)(i+65));
        while(ptr!=NULL)
        {
            printf("%c ",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
}

