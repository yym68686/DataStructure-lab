#include <stdio.h>
#include <stdlib.h>
#include "Sequence_Stack.h"
#include <fstream>
using namespace std;
int maze[100][100], n, visited[100][100];
int xx[] = {-1, 1, 0, 0};
int yy[] = {0, 0, -1, 1};
int endx, endy, flag;
ADT_Stack Stack;
string temp;
int main(){
    ifstream ReadFile("maze");
    while(getline(ReadFile, temp)) n++;

    Stack.InitStack();
    freopen("maze", "r", stdin);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        scanf("%d", &maze[i][j]);
    for (int i = n; i >= 1; i--)
        if (!maze[i][n]) endx = i, endy = n;

    Pos *point = new Pos;
    point->x = 2;
    point->y = 1;
    point->last = NULL;
    Stack.Push(*point);
    visited[point->x][point->y] = 1;
    while (Stack.rear) {
        Pos pp = Stack.Pop();
        Pos *p = new Pos;
        p->x = pp.x;
        p->y = pp.y;
        p->last = pp.last;
        visited[p->x][p->y] = 1;
        if (p->x == endx && p->y == endy) {
            point = p;
            while (point)
                maze[point->x][point->y] = 2, point = point->last;

            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {
                    if (maze[i][j] == 0)
                        printf("  ");
                    else if (maze[i][j] == 2)
                        printf("██");
                    else
                        printf("░░");
                }
                printf("\n");
            }
            return 0;
        }
        for (int i = 0; i < 4; i++)
            if (!maze[p->x + xx[i]][p->y + yy[i]] && !visited[p->x + xx[i]][p->y + yy[i]]) {
                point = new Pos;
                point->x = p->x + xx[i];
                point->y = p->y + yy[i];
                point->last = p;
                Stack.Push(*point);
            }
    }
}