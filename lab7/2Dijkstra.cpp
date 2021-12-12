#include <iostream>
using namespace std;
#define INF 2147483647
#define maxn 20000

struct Edge{
    int v;
    int len;
    int next;
} edge[1111111];
int head[maxn], cnt = 0;
int n, m, s, from, to, len;
bool visit[maxn];
long long dis[maxn];

void addedge(int from, int to, int len){
    edge[++cnt].v = to;
    edge[cnt].len = len;
    edge[cnt].next = head[from];
    head[from] = cnt;
}

void dijkstra(){
    for (int i = 1; i <= n; i++)
        dis[i] = INF;
    int temp = s;
    dis[temp] = 0;
    long long minn;
    while (!visit[temp])
    {
        visit[temp] = true;
        for (int j = head[temp]; j; j = edge[j].next)
            if (!visit[edge[j].v] && dis[edge[j].v] > dis[temp] + edge[j].len)
                dis[edge[j].v] = dis[temp] + edge[j].len;
        minn = INF;
        for (int j = 1; j <= n; j++)
            if (!visit[j] && minn > dis[j])
                minn = dis[j], temp = j;
    }
}

int main(){
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++){
        cin >> from >> to >> len;
        addedge(from, to, len);
    }
    dijkstra();
    for (int i = 1; i <= n; i++){
        cout << dis[i] << " ";
    }
    return 0;
}
