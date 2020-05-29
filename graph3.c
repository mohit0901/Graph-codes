#include <stdio.h>
#include <malloc.h>
#define MAX 1000
int graph[MAX][MAX];
void createGraph(int graph[][MAX],int n);
void bfs(int graph[][MAX],int n);
void printAdj(int graph[][MAX],int n);
void main()
{
    int n;
    printf("Enter number of vertices : ");
    scanf("%d",&n);
    printf("Enter the adjancy matrix for the graph: \n");
    createGraph(graph,n);
    printf("The adjancy matrix is: \n");
    printAdj(graph,n);
    printf("The BFS graph is: \n");
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
        for(j=0;j<n;j++)
        {
            if(graph[co][j]==1 && visited[j]==0)
            {
                rear++;
                q[rear]=(char)(65+j);
                visited[j]=1;
            }
        }
    }
    printf("\b\b ");
    printf("\n");

}
void printAdj(int graph[][MAX],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",graph[i][j]);
        printf("\n");
    }
}
