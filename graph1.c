#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};
void createGraph(struct node *arr[],int);
void main()
{
    int n;
    printf("Enter the number of nodes of graph: ");
    scanf("%d",&n);
    struct node *arr[n];
    int i;
    for(i=0;i<n;i++)
        arr[i]=NULL;
    createGraph(arr,n);
    printf("which node neighbours you want: ");
    int q;
    scanf("%d",&q);
    if(arr[q]==NULL)
        printf("no neighbours");
    else
    {
        struct node *ptr;
        ptr=arr[q];
        while(ptr!=NULL)
        {
            printf("%d - ",ptr->data);
            ptr=ptr->next;
        }
    }
}
void createGraph(struct node *arr[],int n)
{
    struct node *t;
    int i;
    int nn,d;
    for(i=0;i<n;i++)
    {
        t=NULL;
        printf("Enter neighbours of node %d: ",i);
        scanf("%d",&nn);
        for(int j=1;j<=nn;j++)
        {
            printf("Enter neighbour %d of %d ",j,i);
            scanf("%d",&d);
            struct node *newnode=(struct node *)malloc(sizeof(struct node));
            newnode->next=NULL;
            newnode->data=d;
            if(arr[i]==NULL)
            {
                arr[i]=newnode;
                t=newnode;
            }
            else
            {
                t->next=newnode;
            }
        }
    }
}
