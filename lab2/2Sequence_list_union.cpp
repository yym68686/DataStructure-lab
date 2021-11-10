#include "Sequence_list.h"
ADT_list A, B, C;
int main(){
    A.InitLIst();
    A.InsertElem(1, 7);
    A.InsertElem(2, 6);
    A.InsertElem(3, 5);
    A.InsertElem(4, 4);
    A.InsertElem(5, 3);
    A.InsertElem(6, 2);
    A.InsertElem(7, 0);
    A.ListTraverse();

    B.InitLIst();
    B.InsertElem(1, 9);
    B.InsertElem(2, 8);
    B.InsertElem(3, 7);
    B.InsertElem(4, 6);
    B.InsertElem(5, 3);
    B.InsertElem(6, 2);
    B.InsertElem(7, 1);
    B.ListTraverse();

    C = A.Union(B);
    C.ListTraverse();

    A.DestoryList();
    B.DestoryList();
    C.DestoryList();
}