#ifndef SEQUENCE_Stack_H
#define SEQUENCE_Stack_H
class ADT_Stack{
public:
    int Stack[999];
    int rear = -1;
    void InitStack();
    void DestoryStack();
    void ClearStack();
    bool StackEmpty();
    int StackLength();
    int GetTop();
    void StackTraverse();
    void Push(int);
    void Pop();
    // int LocateElem(int num);
    // int PriorElem(int cur_num);
    // int NextElem(int cur_num);
    // int SetElem(int index, int num);
    // void InsertElem(int index, int num);
    // void DeleteElem(int index);
    // void Remove();
    // void Bubble_Sort();
    // void Select_sort();
    // ADT_Stack Union(ADT_Stack);
    // void Josephus(int);
};
#endif
