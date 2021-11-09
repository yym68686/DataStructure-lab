#include "Linked_list.h"
ADT_list ADTlist;
int main(){
    ADTlist.InitLIst();
    ADTlist.InsertElem(1, 3);
    ADTlist.InsertElem(2, 5);
    ADTlist.InsertElem(3, 1);
    ADTlist.InsertElem(4, 2);
    ADTlist.InsertElem(5, 6);
    ADTlist.InsertElem(6, 7);
    ADTlist.InsertElem(7, 0);
    ADTlist.ListTraverse();
    ADTlist.Bubble_Sort();
    ADTlist.ListTraverse();
    ADTlist.DestoryList();
}