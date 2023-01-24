#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50
typedef struct Graph_t {
    int V;
    bool adj[MAX_VERTICES][MAX_VERTICES];
} Graph;
Graph* Graph_create(int V)
{
    Graph* g = malloc(sizeof(Graph));
    g->V = V;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            g->adj[i][j] = false;
        }
    }

    return g;
}
void Graph_destroy(Graph* g) { free(g); }
void Graph_addEdge(Graph* g, int v, int w)
{
    g->adj[v][w] = true;
}
void Graph_BFS(Graph* g, int s)
{
    bool visited[MAX_VERTICES+1];
    for (int i = 0; i <= g->V; i++) {
        visited[i] = false;
    }
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    visited[s] = true;
    queue[rear++] = s;

    while (front != rear) {
        s = queue[front++];
        printf("%d ", s);
        for (int adjecent = 0; adjecent <= g->V;
             adjecent++) {
            if (g->adj[s][adjecent] && !visited[adjecent]) {
                visited[adjecent] = true;
                queue[rear++] = adjecent;
            }
        }
    }
}
int time=0,visit[MAX_VERTICES+1],Finishing[MAX_VERTICES+1];
void Dfs_visit(Graph *g,int s){
time++;
         printf("%d ",s);
         for (int adjecent = 0; adjecent <= g->V;adjecent++) {
             if (g->adj[s][adjecent] && !visit[adjecent] && adjecent!=s) {
                         Dfs_visit(g,adjecent);
                 }
         }
         visit[s]=true;
         time++;
         Finishing[s]=time;
  }

void Graph_DFS(Graph* g,int s){
    for (int i = 0; i <= g->V; i++) {
        visit[i] = false;
    }
        for (int adjecent = 1; adjecent <= g->V;adjecent++) {
            if (!visit[adjecent]) {
                        Dfs_visit(g,adjecent);
                }
        }
}

void Find_largest(int n){
        int largest=-1,lindex=-1;
        for(int i=0;i<=n;i++)
        {
                if (largest < Finishing[i]){
                        lindex=i;
                        largest = Finishing[i];
                }
        }
        printf("%d ",lindex);
        Finishing[lindex]=-1;
}
void Graph_Topological_Sort(Graph* g,int n,int s){

        Graph_DFS(g,1);
        for (int i=1;i<=n;i++){
                printf("%d ",Finishing[i]);
        }
printf("Topological sort is:");
        for(int i=1;i<=n;i++){
                Find_largest(n);
        }
        printf("\n");
}
int main()
{
int no_of_vertices;
printf("Enter the no. of vertices in graph");
scanf("%d",&no_of_vertices);
Graph* g = Graph_create(no_of_vertices);
int choice,sv,dv;
while(choice!=-1){
printf("Enter choice \n1.Add Edge\n2.BFS\n3.DFS\n4.Topological sort\n-1.Exit\n");
scanf("%d",&choice);
switch(choice){
case 1:printf("Enter the source vertex:");
        scanf("%d",&sv);
        printf("Enter the destination vertex:");
        scanf("%d",&dv);
        Graph_addEdge(g,sv,dv);
        break;
case 2:printf("Enter the source vertex");
        scanf("%d",&sv);
        printf("Following is Breadth First Traversal "
           "(starting from vertex %d) \n",sv);
        Graph_BFS(g, sv);
        printf("\n");
        break;
case 3:printf("Enter the source vertex");
        scanf("%d",&sv);
        printf("Following is Depth First Traversal "
           "(starting from vertex %d) \n",sv);
        Graph_DFS(g, sv);
        printf("\n");
        break;
case 4:printf("Enter the source vertex");
         scanf("%d",&sv);
        Graph_Topological_Sort(g,no_of_vertices,sv);
        break;
default:printf("Exiting\n");
  Graph_destroy(g);
        break;
}
}
       return 0;
}
