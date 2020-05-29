#include <stdio.h>
#include <malloc.h>
#define MAX 1000
int graph[MAX][MAX];
void createGraph(int graph[][MAX],int n);
void bfs(int graph[][MAX],int n);
void main()
{
    int n;
    printf("Enter the number of vertices in graph : ");
    scanf("%d",&n);
    printf("Enter the adjancy matrix:\n");
    createGraph(graph,n);
    printf("Shortest path is: ");
    printf("\n");
    bfs(graph,n);
}
void createGraph(int graph[][MAX],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&graph[i][j]);
    }
}
void bfs(int graph[][MAX],int n)
{
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
        for(j=0;j<n;j++)
        {
            if(graph[co][j]==1 && visited[j]==0)
            {
                rear++;
                q[rear]=(char)(65+j);
                visited[j]=1;
                origin[oc]=ch;
                oc++;
            }
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
