#include "Linked_list.h"
ADT_list ADTlist;
int main(){
    ADTlist.InitLIst();
    ADTlist.InsertElem(1, 1);
    ADTlist.InsertElem(2, 1);
    ADTlist.InsertElem(3, 3);
    ADTlist.InsertElem(4, 3);
    ADTlist.InsertElem(5, 3);
    ADTlist.InsertElem(6, 4);
    ADTlist.InsertElem(7, 4);
    ADTlist.ListTraverse();
    ADTlist.Remove();
    ADTlist.ListTraverse();
    ADTlist.DestoryList();
}