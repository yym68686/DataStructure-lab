#include <iostream>
using namespace std;
#define INF 2147483647
#define maxn 20000

struct Edge{
    int v;
    int len;
    int next;
} edge[1111111];
int head[maxn], cnt = 0, m, from, to, len;
bool visit[maxn];
long long dis[maxn];

void addedge(int from, int to, int len){
    edge[++cnt].v = to;
    edge[cnt].len = len;
    edge[cnt].next = head[from];
    head[from] = cnt;
}

void DFS(int temp){
    printf("%d ", temp);
    for (int j = head[temp]; j; j = edge[j].next)
        DFS(edge[j].v);
}


int main(){
    freopen("1DFS", "r", stdin);
    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> from >> to >> len;
        addedge(from, to, len);
    }
    DFS(1);
    return 0;
}
