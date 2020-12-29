/* ------------------------- 19BCP101 -----------------------*/
/* ----------------------- Rajan Gautam ---------------------*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int vertex;
};
struct node *G[20];
int visited[20];
int n;

void read_graph();
void insert(int, int);
void dfs(int);

int main()
{
    int i;
    read_graph();

    for(i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    dfs(0);
    return 0;
}
void dfs(int i)
{
    struct node *p;

	printf("%d --> ",i);
    p=G[i];
    visited[i]=1;
    while(p!=NULL)
    {
       i=p->vertex;

	   if(!visited[i])
       {
            dfs(i);
       }
        p=p->next;
    }
}

void read_graph()
{
    int i,vi,vj,no_of_edges;
    printf("Enter number of vertices: ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
    {
        G[i]=NULL;

		printf("Enter number of edges: ");
       	scanf("%d",&no_of_edges);

       	for(i=0;i<no_of_edges;i++)
        {
        	printf("Enter an edge(u,v): ");
			scanf("%d%d",&vi,&vj);
			insert(vi,vj);
        }
    }
}

void insert(int vi,int vj)
{
    struct node *p,*q;

	q=(struct node*)malloc(sizeof(struct node));
    q->vertex=vj;
    q->next=NULL;

    if(G[vi]==NULL)
        G[vi]=q;
    else
    {
        p=G[vi];

		while(p->next!=NULL)
        	p=p->next;
        p->next=q;
    }
}
