#ifndef SEQUENCE_LIST_H
#define SEQUENCE_LIST_H
class ADT_list{
public:
    int list[999];
    int rear = -1;
    void InitLIst();
    void DestoryList();
    void ClearList();
    bool ListEmpty();
    int ListLength();
    int GetElem(int num);
    int LocateElem(int num);
    int PriorElem(int cur_num);
    int NextElem(int cur_num);
    void ListTraverse();
    int SetElem(int index, int num);
    void InsertElem(int index, int num);
    void DeleteElem(int index);
    void Remove();
    void Bubble_Sort();
    void Select_sort();
};
#endif
