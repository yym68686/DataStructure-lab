#include <stdio.h>
#include "Linked_list.h"
char str[100];
int num, check;
int main(){
    ADT_list list;
    list.InitLIst();
    freopen("insertnode", "r", stdin);
    while (scanf("%s", &str) != EOF) list.InsertElem(str);
    list.ListTraverse();
    list.ClearList();
    freopen("CheckBlockChain", "r", stdin);
    while (scanf("%s%d", &str, &check) != EOF) list.CreateList(str, check);
    list.ListTraverse();
    (num = list.CheckList()) < 100 ? puts("Accept!") : printf("The %dth node Error!", num - 100);
    
}