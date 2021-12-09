#ifndef Graph_H
#define Graph_H
class Graph{
public:
    typedef struct MGrape
    {
        int edges[999][999];
        int n, e;
        char v[999];
    } MGrape;
    MGrape G;
    int visited[999];
    int CreateGraph();
    void DestoryGraph();
    char GetVex(int);
    int FirstAdjVex(int);
    int NextAdjVex(int, int);
    void DFSTraverse();
    void DFS(int);
    void BFSTraverse();
    void BFS(int);
    void InsertVex(char);
    void InsertArc(int, int);
    void DeleteVex(int);
    void DeleteArc(int, int);
};
#endif