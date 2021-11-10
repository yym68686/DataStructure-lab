#include <stdio.h>
#include "Sequence_list.h"

void ADT_list::InitLIst(){
    rear++;
}
void ADT_list::DestoryList(){
    rear = -1;
}
void ADT_list::ClearList(){
    for(int i = 0; i <= rear; i++){
        list[i] = 0;
    }
}
bool ADT_list::ListEmpty(){
    if (rear == 0 && list[rear] == 0){
        return true;
    }
    return false;
}
int ADT_list::ListLength(){
    return rear;
}
int ADT_list::GetElem(int num){
    return *(list + num);
}
int ADT_list::LocateElem(int num){
    for (int i = 0; i <= rear; i++){
        if (list[i] == num){
            return i;
        }
    }
    return -1;
}
int ADT_list::PriorElem(int cur_num){
    int pre;
    for (int i = 0; i <= rear; i++){
        if (list[i] == cur_num){
            return i - 1;
        }
    }
    return -1;
}
int ADT_list::NextElem(int cur_num){
    for (int i = 0; i <= rear; i++){
        if (list[i] == cur_num && i != rear){
            return i + 1;
        }
    }
    return -1;
}
void ADT_list::ListTraverse(){
    for (int i = 0; i < rear; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
}
int ADT_list::SetElem(int index, int num){
    list[index] = num;
    return num = list[index];
}
void ADT_list::InsertElem(int index, int num){
    rear++;
    for (int i = rear; i > index - 1; i--){
        list[i] = list[i - 1];
    }
    list[index - 1] = num;
}
void ADT_list::DeleteElem(int index){
    for (int i = index - 1; i < rear; i++){
        list[i] = list[i + 1];
    }
    rear--;
}
void ADT_list::Remove(){
    int use[999];
    for (int i = 0; i < rear; i++){
        if (use[list[i]]){
            DeleteElem(i + 1);
            i--;
            continue;
        }
        use[list[i]] = 1;
        i++;
    }
}
void ADT_list::Bubble_Sort(){
    for(int i = 0; i < rear; i++)
    for(int j = 0; j < rear - i - 1; j++)
        if (list[j] > list[j + 1]){
            int temp = list[j];
            list[j] = list[j + 1];
            list[j + 1] = temp;
        }
}
void ADT_list::Select_sort(){
    for(int i = 0; i < rear; i++){
        int minn = 0x3f3f3f3f;
        for (int j = i; j < rear; j++){
            minn = list[j] < minn ? list[j] : minn;
        }
        SetElem(LocateElem(minn), list[i]);
        SetElem(i, minn);
    }
}