#include <stdio.h>
#include "Sequence_Stack.h"

void ADT_Stack::InitStack(){
    rear++;
    
}
void ADT_Stack::DestoryStack(){
    rear = -1;
}
void ADT_Stack::ClearStack(){
    rear = 0;
}
bool ADT_Stack::StackEmpty(){
    return rear == 0 ? true : false;
}
int ADT_Stack::StackLength(){
    return rear;
}
Pos ADT_Stack::GetTop(){
    return Stack[rear];
}
void ADT_Stack::StackTraverse(){
    for (int i = 1; i <= rear; i++)
        printf("%d %d\n", Stack[i].x, Stack[i].y);
}
void ADT_Stack::Push(Pos point){
    Stack[++rear] = point;
}
Pos ADT_Stack::Pop(){
    return Stack[rear--];
}
Pos ADT_Stack::operator [] (int index) {
    return Stack[index];
}
// int ADT_Stack::LocateElem(int num){
//     for (int i = 1; i <= rear; i++)
//         if (Stack[i] == num)
//             return i;
//     return -1;
// }
// int ADT_Stack::PriorElem(int cur_num){
//     int pre;
//     for (int i = 1; i <= rear; i++){
//         if (Stack[i] == cur_num){
//             return i - 1;
//         }
//     }
//     return -1;
// }
// int ADT_Stack::NextElem(int cur_num){
//     for (int i = 0; i < rear; i++){
//         if (Stack[i] == cur_num && i != rear){
//             return i + 1;
//         }
//     }
//     return -1;
// }
// int ADT_Stack::SetElem(int index, int num){
//     Stack[index] = num;
//     return num = Stack[index];
// }
// void ADT_Stack::InsertElem(int index, int num){
//     rear++;
//     for (int i = rear; i > index; i--){
//         Stack[i] = Stack[i - 1];
//     }
//     Stack[index - 1] = num;
// }
// void ADT_Stack::DeleteElem(int index){
//     for (int i = index - 1; i < rear; i++){
//         Stack[i] = Stack[i + 1];
//     }
//     rear--;
// }
// void ADT_Stack::Remove(){
//     int use[999];
//     for (int i = 0; i < rear; i++){
//         if (use[Stack[i]]){
//             DeleteElem(i + 1);
//             i--;
//             continue;
//         }
//         use[Stack[i]] = 1;
//         i++;
//     }
// }
// void ADT_Stack::Bubble_Sort(){
//     for(int i = 0; i < rear; i++)
//     for(int j = 0; j < rear - i - 1; j++)
//         if (Stack[j] > Stack[j + 1]){
//             int temp = Stack[j];
//             Stack[j] = Stack[j + 1];
//             Stack[j + 1] = temp;
//         }
// }
// void ADT_Stack::Select_sort(){
//     for(int i = 0; i < rear; i++){
//         int minn = 0x3f3f3f3f;
//         for (int j = i; j < rear; j++){
//             minn = Stack[j] < minn ? Stack[j] : minn;
//         }
//         SetElem(LocateElem(minn), Stack[i]);
//         SetElem(i, minn);
//     }
// }
// ADT_Stack ADT_Stack::Union(ADT_Stack B){
//     ADT_Stack C;
//     C.InitStack();
//     int index = 0;
//     for (int i = 0; i < rear; i++){
//         if (B.LocateElem(Stack[i]) >= 0){
//             C.InsertElem(++index, Stack[i]);
//         }
//     }
//     return C;
// }
// void ADT_Stack::Josephus(int m){
//     int index = 0;
//     while(rear){
//         index = (index + m - 1) % rear;
//         printf("%d ", Stack[index]);
//         DeleteElem(index + 1);
//     }
// }
