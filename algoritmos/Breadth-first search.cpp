#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXV 1005
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define NIL -1
#define myInfinite 2147483647

struct edge
{
    int vertex;
/*    int weight; */
    struct edge *next;
};

struct graph
{
    int NumberVertex;
    int NumberEdges;
    struct edge *Adj[MAXV];
};

struct graph *ReadGraph(int vertexes, int edges)
{
    int indexVertex, indexEdge, v, u;
    struct graph *Graph;
    struct edge *tempEdge;

    Graph = (struct graph *)malloc(sizeof(struct graph));

    Graph->NumberVertex = vertexes;
    Graph->NumberEdges = edges;

    for(indexVertex = 0; indexVertex <= (Graph->NumberVertex); indexVertex++)
    {
        Graph->Adj[indexVertex] = NULL;
    }

    for(indexEdge = 1; indexEdge <= (Graph->NumberEdges); indexEdge++)
    {
        scanf("%d %d", &v, &u);

        tempEdge = (struct edge *)malloc(sizeof(struct edge));
        tempEdge->vertex = u;
        tempEdge->next = Graph->Adj[v];
        Graph->Adj[v] = tempEdge;

        if(v != u)
        {
            tempEdge = (struct edge *)malloc(sizeof(struct edge));
            tempEdge->vertex = v;
            tempEdge->next = Graph->Adj[u];
            Graph->Adj[u] = tempEdge;
        }
    }
    return Graph;
}

void PrintGraph(struct graph *Graph)
{
    int indexVertex;
    struct edge *tempEdge;
    if(Graph != NULL)
    {
        printf("Representation for graph'source adjacent lists: \n");
        for(indexVertex = 1; indexVertex <= Graph->NumberVertex; indexVertex++)
        {
            printf("[%d]: ",indexVertex);
            tempEdge = Graph->Adj[indexVertex];
            while(tempEdge != NULL)
            {
                printf(" -> %d", tempEdge->vertex);
                tempEdge = tempEdge->next;
            }
            printf(" -> NULL\n");
        }
    }
    else
        printf("Empty Graph.\n");
}

struct graph *DeleteGraph(struct graph *Graph)
{
    int indexVertex;
    struct edge *ActualEdge, *NextEdge;

    for(indexVertex = 1; indexVertex <= (Graph->NumberVertex); indexVertex++)
    {
        ActualEdge = Graph->Adj[indexVertex];
        while(ActualEdge != NULL)
        {
            NextEdge = ActualEdge->next;
            free(ActualEdge);
            ActualEdge = NextEdge;
        }
    }
    free(Graph);
    Graph = NULL;
    return Graph;
}


void BFS(struct graph *Graph, int source, int color[], int distance[], int ParentIndex[])
{
    struct edge *tempEdge;
    int indexVertex, u, v, Queue[MAXV], head = 1, tail = 1;

    for(indexVertex = 1; indexVertex <= (Graph->NumberVertex); indexVertex++)
    {
        color[indexVertex] = WHITE;
        distance[indexVertex] = myInfinite;
        ParentIndex[indexVertex] = NIL;
    }

    color[source] = GRAY;
    distance[source] = 0;
    Queue[tail] = source;
    tail++;

    while(head < tail)
    {
        u = Queue[head];
        head++;
        tempEdge = Graph->Adj[u];
        while(tempEdge != NULL)
        {
            v = tempEdge->vertex;
            if(color[v] == WHITE)
            {
                color[v] = GRAY;
                distance[v] = distance[u] + 1;
                ParentIndex[v] = u;
                Queue[tail] = v;
                tail++;
            }
            tempEdge = tempEdge->next;
        }
        color[u] = BLACK;
    }
}


void Path(int u, int ParentIndex[])
{
    if(ParentIndex[u] == NIL)
        printf("%d", u);
    else
    {
        Path(ParentIndex[u], ParentIndex);
        printf(" -> %d", u);
    }
}

void Solver(struct graph *Graph, int source)
{
    int color[MAXV], distance[MAXV], ParentIndex[MAXV],indexVertex;
    BFS(Graph, source, color, distance, ParentIndex);

    for(indexVertex = 1; indexVertex <= (Graph->NumberVertex); indexVertex++)
        printf("d[%d]: %d\n",indexVertex, distance[indexVertex]);

    for(indexVertex = 1; indexVertex <= (Graph->NumberVertex); indexVertex++)
        printf("ParentIndex[%d]: %d\n",indexVertex, ParentIndex[indexVertex]);

    for(indexVertex = 1; indexVertex <= (Graph->NumberVertex); indexVertex++)
    {
        if(color[indexVertex] == WHITE)
            printf("color[%d]: WHITE\n",indexVertex);
        if(color[indexVertex] == GRAY)
            printf("color[%d]: GRAY\n",indexVertex);
        if(color[indexVertex] == BLACK)
            printf("color[%d]: BLACK\n",indexVertex);
    }

    printf("\n");
    for(indexVertex = 1;indexVertex <= (Graph->NumberVertex); indexVertex++)
    {
        Path(indexVertex, ParentIndex);
        printf("\n");
    }
}


int main()
{
    int vertexes, edges,indexVertex, indexEdge, v, u, source;
    struct graph *Graph;
    struct edge *tempEdge;

    while(scanf("%d %d %d", &vertexes, &edges, &source) != EOF)
    {
        Graph = ReadGraph(vertexes, edges);
        PrintGraph(Graph);
        Solver(Graph, source);
        Graph = DeleteGraph(Graph);
        PrintGraph(Graph);
    }
    return 0;
}
