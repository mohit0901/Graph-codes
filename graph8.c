/*applications of breadth first search:
finding connected components
finding all nodes within connected components
finding shortest path between two nodes u and v

applications of depth first search:
checking whether graph is connected or not
finding a path between two nodes
computing the spanning tree of a connected graph
*/
#include <stdio.h>
#include <malloc.h>
#define MAX 1000
int graph[MAX][MAX];
void createGraph(int graph[][MAX],int n);
void dfs(int graph[][MAX],int n);
void main()
{
    int n;
    printf("Enter the number of vertices in graph : ");
    scanf("%d",&n);
    printf("Enter the adjancy matrix:\n");
    createGraph(graph,n);
    printf("Nodes possible from A is: ");
    printf("\n");
    dfs(graph,n);
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
void dfs(int graph[][MAX],int n)
{
    int visited[n];
    for(int x=0;x<n;x++)
        visited[x]=0;
    char stk[n];
    int top=-1;
    top++;
    stk[top]='A';
    char ch;
    int co;
    int i;
    visited[0]=1;
    while(top!=-1)
    {
        ch=stk[top];
        top--;
        printf("%c - ",ch);
        co=(int)ch-65;
        for(i=0;i<n;i++)
        {
            if(graph[co][i]==1 && visited[i]==0)
            {
                top++;
                stk[top]=(char)(i+65);
                visited[i]=1;
            }
        }
    }
}

