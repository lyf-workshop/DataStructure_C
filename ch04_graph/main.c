#include <stdio.h>
#include "graph.h"

int main(void) {
    printf("=== 图 (邻接矩阵) ===\n");
    Graph G;
    Graph_Init(&G, 6);

    /* 构建如下无向图:
       0-1, 0-2, 1-3, 1-4, 2-4, 3-5, 4-5 */
    Graph_AddEdge(&G, 0, 1);
    Graph_AddEdge(&G, 0, 2);
    Graph_AddEdge(&G, 1, 3);
    Graph_AddEdge(&G, 1, 4);
    Graph_AddEdge(&G, 2, 4);
    Graph_AddEdge(&G, 3, 5);
    Graph_AddEdge(&G, 4, 5);

    Graph_Print(&G);
    printf("\n");
    Graph_BFS(&G, 0);
    Graph_DFS(&G, 0);

    return 0;
}
