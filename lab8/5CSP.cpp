#include <algorithm>
#include <cstdio>
using namespace std;
int n, map[111111][111], score[5];
struct point{
    int x, y;
} t[111];
int main(){
    freopen("5CSP3", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &t[i].x, &t[i].y), map[t[i].x + 100000][t[i].y]++;
    for (int i = 0; i < n; i++)
        if (map[t[i].x + 100000][t[i].y] && map[t[i].x - 1 + 100000][t[i].y] && map[t[i].x + 1 + 100000][t[i].y] && map[t[i].x + 100000][t[i].y - 1] && map[t[i].x + 100000][t[i].y + 1])
            score[map[t[i].x - 1 + 100000][t[i].y - 1] + map[t[i].x - 1 + 100000][t[i].y + 1] + map[t[i].x + 1 + 100000][t[i].y - 1] + map[t[i].x + 1 + 100000][t[i].y + 1]]++;
    for (int i = 0; i <= 4; i++)
        printf("%d %d\n", i, score[i]);
}