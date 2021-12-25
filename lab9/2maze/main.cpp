#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;
int maze[100][100], n;
string temp;
int main(){
    ifstream ReadFile("maze");
    while(getline(ReadFile, temp)) n++;

    freopen("maze", "r", stdin);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        scanf("%d", &maze[i][j]);

    

}