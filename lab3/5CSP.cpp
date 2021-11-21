#include <stdio.h>
#include "5Linked_list.h"
int n, m, num = 0, maxx = 0, ans = 0, onenum, indexx, error, temp, x1, x2, y1, y2, win[3333][2222];
ADT_list list;
ADT_list::node *point;
typedef struct Click
{
    int x, y;
}ClickList;
ClickList Clicks[11];
int main(){
    list.InitLIst();
    freopen("5CSP1", "r", stdin);
    scanf("%d%d", &n, &m);
    while (num++ != n){
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2), list.InsertElem(1, x1, y1, x2, y2);
        for (int i = x1; i <= x2; i++)
            for (int j = y1; j <= y2; j++)
                win[i][j] = num;
    }
    num = 1;
    while (scanf("%d%d", &Clicks[num].x, &Clicks[num].y) != EOF) {
        int index = win[Clicks[num].x][Clicks[num].y];
        if (index) {
            printf("%d\n", index);
            point = list.GetElem(index);
            for (int i = point->x1; i <= point->x2; i++)
                for (int j = point->y1; j <= point->y2; j++)
                    win[i][j] = index;
        }
        else printf("IGNORED\n");
        num++;
    }
}