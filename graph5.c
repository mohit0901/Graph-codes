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
    char ch;
    int visited[n];
    int i,j;
    for(i=0;i<n;i++)
        visited[i]=0;
    char q[n];
    int front=-1,rear=-1;
    char origin[n];
    int oc=0;
    rear++;
    front++;
    int co=0;
    q[rear]=(char)(co+65);
    origin[oc]='\0';
    oc++;
    visited[co]=1;
    while(visited[n-1]!=1)
    {
        ch=q[front];
        front++;
        co=(int)ch-65;
        ptr=graph[co];
        while(ptr!=NULL)
        {
            if(visited[(int)(ptr->data)-65]==0)
            {
                rear++;
                q[rear]=ptr->data;
                visited[(int)(ptr->data)-65]=1;
                origin[oc]=ch;
                oc++;
            }
            ptr=ptr->next;
        }
    }
    char shortPath[n];
    int spco=0;
    //shortest path
    /*for(i=0;i<=rear;i++)
        printf("%c ",q[i]);
    printf("\n");
    for(i=0;i<oc;i++)
        printf("%c ",origin[i]);*/
    int x;
    x=rear;
    char ch1;
    do
    {
        ch=q[x];
        shortPath[spco]=ch;
        spco++;
        ch1=origin[x];
        if(ch1=='\0')
            break;
        for(j=0;j<=rear;j++)
        {
            if(q[j]==ch1)
            {
                x=j;
                break;
            }
        }

    }while(1);
    for(i=spco-1;i>=0;i--)
        printf("%c ",shortPath[i]);
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
