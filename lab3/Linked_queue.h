#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H
class ADT_queue{
public:
    typedef struct node
    {
        int value;
        struct node *next;
    } node;
    node *head;
    int length = -1;

    void Initqueue();
    void Destoryqueue();
    void Clearqueue();
    bool queueEmpty();
    int queueLength();
    int GetHead();
    void queueTraverse();
    void EnQueue(int num);
    void DeQueue();
    // int GetElem(int);
    // int LocateElem(int);
    // int PriorElem(int);
    // int NextElem(int);
    // int SetElem(int index, int num);
    // void InsertElem(int index, int num);
    // void DeleteElem(int index);
    // void Remove();
    // void Reverse();
    // void Bubble_Sort();
    // void Select_sort();
    // ADT_queue Union(ADT_queue B);
    // void Josephus(int);
};
#endif