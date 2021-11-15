#include <stdio.h>
#include <algorithm>
using namespace std;
int m, result[111111], y[111111], num = 1, maxx = 0, ans = 0, onenum, indexx, error, temp;
typedef struct Test
{
       int y;
       int result;
       int state;
}person;
person list[111111];
bool Compare(const person &a, const person &b)
{
    return a.y < b.y ? true : (a.y == b.y ? a.result < b.result : false);
}
int main(){
    freopen("4CSP2", "r", stdin);
    scanf("%d", &m);
    while (scanf("%d%d", &list[num].y, &list[num].result) != EOF) num++;
    sort(list + 1, list + m + 1, Compare);
    while (++indexx != num)  list[indexx].state = list[indexx - 1].state + list[indexx].result, onenum += list[indexx].result;
    for(int i = 1; i <= m; i++){
        error = list[i].state - list[i].result + m - i + 1 - (onenum - (list[i].state - list[i].result)) + (temp = list[i].y == list[i - 1].y && i != 1 ? 0x3f3f : 0);
        maxx <= m - error ? maxx = m - error, ans = list[i].y : maxx = maxx;
    }
    printf("%d", ans);
}