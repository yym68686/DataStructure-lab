#ifndef LINKED_LIST_H
#define LINKED_LIST_H
class ADT_list{
public:
    typedef struct node
    {
        int value;
        struct node *next;
    } node;
    node *head;
    int length = -1;

    void InitLIst();
    void DestoryList();
    void ClearList();
    bool ListEmpty();
    int ListLength();
    int GetElem(int);
    int LocateElem(int);
    int PriorElem(int);
    int NextElem(int);
    void ListTraverse();
    int SetElem(int index, int num);
    void InsertElem(int index, int num);
    void DeleteElem(int index);
    void Remove();
    void Reverse();
    void Bubble_Sort();
    void Select_sort();
};
#endif