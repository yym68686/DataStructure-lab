#include <stdio.h>
#include <algorithm>
using namespace std;
int n, m, num = 1, maxx = 0, ans = 0, onenum, indexx, error, temp;
typedef struct Win
{
       int x1, y1, x2, y2;
}Windows;
Windows list[999];
typedef struct Click
{
       int x, y;
}ClickList;
ClickList Clicks[999];
int main(){
    freopen("4CSP2", "r", stdin);
    scanf("%d%d", &n, &m);
    while (num++ != n) scanf("%d%d%d%d", &list[num].x1, &list[num].y1, &list[num].x2, &list[num].y2);
    num = 0;
    while (scanf("%d%d", &Clicks[num].x, &Clicks[num].y) != EOF) num++;
}