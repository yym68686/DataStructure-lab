#include "Linked_list.h"
#include <stdio.h>
ADT_list A, B, C;
int main(){
    A.InitLIst();
    A.InsertElem(1, 1);
    A.InsertElem(2, 2);
    A.InsertElem(3, 3);
    A.InsertElem(4, 4);
    A.InsertElem(5, 5);
    A.InsertElem(6, 6);
    A.InsertElem(7, 7);
    A.Josephus(3);
}