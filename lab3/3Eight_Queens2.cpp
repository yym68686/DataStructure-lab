#include <stdio.h>
#include "Sequence_Stack.h"
int N = 8;
bool conflict(ADT_Stack solution, Pos point) {
	for (int i = 1; i <= solution.StackLength(); i++){
   if (point.x == 5 && point.y == 7) printf("%d %d %d %d %d\n", point.x, point.y, solution.StackLength(), solution[i].x, solution[i].y);
      if (point.y == solution[i].y || (point.x + point.y) == (solution[i].x + solution[i].y) || (point.x - point.y) == (solution[i].x - solution[i].y) || point.x >= N || point.y >= N){
         return true;

      }

   }
	return false;
}
void find(ADT_Stack solution, Pos pos) {
   printf("%d %d\n", pos.x, pos.y);
   if (solution.StackLength() >= N || (pos.y >= N && pos.x == N)){
      for (int i = 1; i <= solution.StackLength(); i++)
         printf("%d ", solution[i].y);
      printf("\n");
      return;
   }
   if(!conflict(solution, pos)){
      solution.Push(pos);
      if (pos.x < N){
         pos.x++;
         pos.y = 0;
      }
   }
   else{
      if (pos.x == 5 && pos.y == 7) printf("//\n");
      if (pos.y >= N)
         pos = solution.Pop();
      pos.y++;

   }
   printf("*%d %d*", pos.x, pos.y);
   find(solution, pos);
}
int main(){
   Pos pos;
   ADT_Stack solution;
   solution.InitStack();
   pos.x = 0, pos.y = 0;
   find(solution, pos);
}