#include <stdio.h>
#include "Sequence_Stack.h"
ADT_Stack solution;
int N = 8;
bool conflict(Pos point) {
	for (int i = 1; i <= solution.StackLength(); i++)
      if (point.y == solution[i].y || (point.x + point.y) == (solution[i].x + solution[i].y) || (point.x - point.y) == (solution[i].x - solution[i].y) || point.x >= N || point.y >= N)
         return true;
	return false;
}
void find(Pos pos) {
   if (solution.StackLength() >= N || (pos.y >= N && pos.x == N)){
      for (int i = 1; i <= solution.StackLength(); i++)
         printf("%d ", solution[i].y);
      printf("\n");
      return;
   }
   if(!conflict(pos)){
      solution.Push(pos);
      if (pos.x < N){
         pos.x++;
         pos.y = 0;
      }
   }
   else {
      if (pos.y >= N)
         pos = solution.Pop();
      pos.y++;
   }
   find(pos);
}
int main(){
   Pos pos;
   solution.InitStack();
   pos.x = 0, pos.y = 0;
   find(pos);
}