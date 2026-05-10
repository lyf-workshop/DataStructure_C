#include "graph.h"

void Graph_Init(Graph *G, int vexnum) {
    G->vexnum = vexnum;
    G->arcnum = 0;
    for (int i = 0; i < vexnum; i++) {
        G->vexs[i] = i;
        for (int j = 0; j < vexnum; j++)
            G->arc[i][j] = 0;
    }
}

void Graph_AddEdge(Graph *G, int u, int v) {
    G->arc[u][v] = 1;
    G->arc[v][u] = 1;
    G->arcnum++;
}

void Graph_BFS(Graph *G, int start) {
    bool visited[MAX_VERTEX] = {false};
    int  queue[MAX_VERTEX];
    int  front = 0, rear = 0;

    visited[start] = true;
    queue[rear++]  = start;
    printf("BFS: ");
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        for (int i = 0; i < G->vexnum; i++) {
            if (G->arc[v][i] && !visited[i]) {
                visited[i]    = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

static bool dfs_visited[MAX_VERTEX];

static void dfs(Graph *G, int v) {
    dfs_visited[v] = true;
    printf("%d ", v);
    for (int i = 0; i < G->vexnum; i++)
        if (G->arc[v][i] && !dfs_visited[i])
            dfs(G, i);
}

void Graph_DFS(Graph *G, int start) {
    memset(dfs_visited, false, sizeof(dfs_visited));
    printf("DFS: ");
    dfs(G, start);
    printf("\n");
}

void Graph_Print(Graph *G) {
    printf("邻接矩阵 (%d顶点, %d边):\n", G->vexnum, G->arcnum);
    for (int i = 0; i < G->vexnum; i++) {
        for (int j = 0; j < G->vexnum; j++)
            printf("%d ", G->arc[i][j]);
        printf("\n");
    }
}
