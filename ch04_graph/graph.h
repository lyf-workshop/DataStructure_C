#ifndef GRAPH_H
#define GRAPH_H

#include "utils.h"

#define MAX_VERTEX 20

/* 邻接矩阵表示的图 */
typedef struct {
    int vexs[MAX_VERTEX];        /* 顶点表 */
    int arc[MAX_VERTEX][MAX_VERTEX];  /* 邻接矩阵 */
    int vexnum;                  /* 顶点数 */
    int arcnum;                  /* 边数 */
} Graph;

void Graph_Init(Graph *G, int vexnum);
void Graph_AddEdge(Graph *G, int u, int v);    /* 无向图加边 */
void Graph_BFS(Graph *G, int start);           /* 广度优先搜索 */
void Graph_DFS(Graph *G, int start);           /* 深度优先搜索 */
void Graph_Print(Graph *G);

#endif
