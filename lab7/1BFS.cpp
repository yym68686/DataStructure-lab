#include <iostream>
using namespace std;
#define INF 2147483647
#define maxn 20000

struct Edge{
    int v;
    int len;
    int next;
} edge[1111111];
int head[maxn], cnt = 0, m, from, to, len, queue[1111111], front, rear;
bool visit[maxn];
long long dis[maxn];

void addedge(int from, int to, int len){
    edge[++cnt].v = to;
    edge[cnt].len = len;
    edge[cnt].next = head[from];
    head[from] = cnt;
}

void BFS(int temp){
    queue[++rear] = temp;
    front = rear;
    while (front <= rear){
        int tmp = queue[front++];
        printf("%d ", tmp);
        for (int j = head[tmp]; j; j = edge[j].next)
            queue[++rear] = edge[j].v;
    }
}


int main(){
    freopen("1BFS", "r", stdin);
    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> from >> to >> len;
        addedge(from, to, len);
    }
    BFS(1);
    return 0;
}
