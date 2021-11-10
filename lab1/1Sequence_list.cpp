#include <stdio.h>
class ADT_list{
public:
    int list[999];
    int rear = -1;
    void InitLIst(){
        rear++;
    }
    void DestoryList(){
        rear = -1;
    }
    void ClearList(){
        for(int i = 0; i <= rear; i++){
            list[i] = 0;
        }
    }
    bool ListEmpty(){
        if (rear == 0 && list[rear] == 0){
            return true;
        }
        return false;
    }
    int ListLength(){
        return rear;
    }
    int GetElem(int num){
        return *(list + num);
    }
    int LocateElem(int num){
        for (int i = 0; i < rear; i++){
            if (list[i] == num){
                return i;
            }
        }
        return -1;
    }
    int PriorElem(int cur_num){
        int pre;
        for (int i = 0; i < rear; i++){
            if (list[i] == cur_num){
                return i - 1;
            }
        }
        return -1;
    }
    int NextElem(int cur_num){
        for (int i = 0; i < rear; i++){
            if (list[i] == cur_num && i != rear){
                return i + 1;
            }
        }
        return -1;
    }
    void ListTraverse(){
        for (int i = 0; i < rear; i++){
            printf("%d ", list[i]);
        }
        printf("\n");
    }
    int SetElem(int index, int num){
        list[index] = num;
        return num = list[index];
    }
    void InsertElem(int index, int num){
        rear++;
        for (int i = rear; i > index - 1; i--){
            list[i] = list[i - 1];
        }
        list[index - 1] = num;
    }
    void DeleteElem(int index){
        for (int i = index - 1; i < rear; i++){
            list[i] = list[i + 1];
        }
        rear--;
    }
} ADTlist;