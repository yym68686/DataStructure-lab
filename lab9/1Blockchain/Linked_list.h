#ifndef LINKED_LIST_H
#define LINKED_LIST_H
class ADT_list{
public:
    typedef struct node
    {
        int number;
        char information[100];
        int Checkcode;
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
    void CreateList(char*, int);
    int CheckList();
    void SetStr(int, const char*);
    void InsertElem(char*);
    int GetCheckcode();
    void DeleteElem(int index);
    void Reverse();
};
#endif