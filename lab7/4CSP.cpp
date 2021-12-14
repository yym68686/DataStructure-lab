#include <algorithm>
#include <cstdio>
using namespace std;
int n, m, x[222222], y[222222], z[222222], f[5555], sum, line;
int root(int x){
    return f[x] == x ? x : f[x] = root(f[x]);
}
struct tree{
    int x, y, z;
} t[222222];

bool cmp(tree x, tree y){
    return x.z < y.z;
}
int main(){
    freopen("4CSP", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &t[i].x, &t[i].y, &t[i].z);
    for (int i = 1; i <= n; i++)
        f[i] = i;
    sort(t + 1, t + m + 1, cmp);
    for (int i = 1; i <= m; i++){
        int x = t[i].x;
        int y = t[i].y;
        if (root(x) == root(y))
            continue;
        f[root(x)] = root(y);
        sum += t[i].z;
        line++;
    }
    if (line == n - 1)
        printf("%d", sum);
    else
        printf("orz");
}