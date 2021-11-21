#ifndef LINKED_LIST_H
#define LINKED_LIST_H
class ADT_list{
public:
    typedef struct node
    {
        int x1, y1, x2, y2;
        node *next;
    } node;
    node *head;
    int length = -1;

    void InitLIst();
    void DestoryList();
    void ClearList();
    bool ListEmpty();
    int ListLength();
    node* GetElem(int);
    int LocateElem(int);
    int PriorElem(int);
    int NextElem(int);
    void ListTraverse();
    int SetElem(int index, int num);
    void InsertElem(int , int ,int ,int ,int);
    void DeleteElem(int index);
    void Remove();
    void Reverse();
    void Bubble_Sort();
    void Select_sort();
    ADT_list Union(ADT_list B);
    void Josephus(int);
};
#endif