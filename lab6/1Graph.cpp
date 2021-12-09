#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include "1Graph.h"
int Graph::CreateGraph(){
    scanf("%d%d", &G.n, &G.e);
    memset(G.edges, 0, sizeof(G.edges));
    for (int i = 0; i < G.n; i++)
        scanf("%c", &G.v[i]);
    int x, y;
    for (int i = 0; i < G.e; i++){
        scanf("%d%d", &x, &y);
        G.edges[x][y] = 1;
        G.edges[y][x] = 1;
    }
}
void Graph::DestoryGraph(){
    memset(G.edges, 0, sizeof(G.edges));
    G.n = 0;
    G.e = 0;
}
char Graph::GetVex(int index){
    return G.v[index];
}
int Graph::FirstAdjVex(int start){
    for (int i = 0; i < G.n; i++){
        if (G.edges[start][i]) return i;
    }
    return NULL;
}
int Graph::NextAdjVex(int start, int now){
    int flag = 0;
    for (int i = 0; i < G.n; i++){
        if (flag && G.edges[start][i]) return i;
        if (i == now && G.edges[start][i] && !flag) flag = 1;
    }
    return NULL;
}
void Graph::DFSTraverse(){
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < G.n; i++)
        if (!visited[i])
            DFS(i);
}
void Graph::DFS(int index){
    printf("%c", G.v[index]);
    visited[index] = 1;
    for (int i = 0; i < G.n; i++)
        if (!visited[i] && G.edges[index][i])
            DFS(i);
}
void Graph::BFSTraverse(){
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < G.n; i++){
        if (!visited[i])
            BFS(i);
    }
}
void Graph::BFS(int index){
    int queue[999], rear = 0, front = 0;
    queue[++rear] = index;
    visited[index] = 1;
    while (front != rear){
        int first = queue[front++];
        printf("%d ", first);
        for (int i = 0; i < G.n; i++){
            if (!visited[i] && G.edges[index][i]){
                visited[i] = 1;
                queue[++rear] = i;
            }
        }

    }
}
void Graph::InsertVex(char ch){
    G.v[G.n++] = ch;
}
void Graph::InsertArc(int start, int end){
    G.edges[start][end] = 1;
    G.edges[end][start] = 1;
}
void Graph::DeleteVex(int index){
    for (int i = index; i < G.n - 1; i++){
        G.v[i] = G.v[i + 1];
    }
    G.n--;
}
void Graph::DeleteArc(int start, int end){
    G.edges[start][end] = 0;
    G.edges[end][start] = 0;
}