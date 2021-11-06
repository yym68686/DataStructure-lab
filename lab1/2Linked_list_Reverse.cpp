#include<stdio.h>
#include <malloc.h>

class ADT_list{
public:
    typedef struct node
    {
        int value;
        struct node *next;
    } node;

    node *head;
    int length = -1;

    void InitLIst(){
        node *tmp = (node *)malloc(sizeof(node));
        length = 0;
        head = tmp;
        tmp->next = NULL;
    }
    void DestoryList(){
        node *p, *temp;
        p = head;
        while (p != NULL){
            temp = p;
            p = p->next;
            free(temp);
        }
        length = -1;
    }
    void ClearList(){
        node *p, *temp;
        p = head->next;
        while (p != NULL){
            temp = p;
            p = p->next;
            free(temp);
        }
        length = 0;
    }
    bool ListEmpty(){
        if (length < 1) return true;
        return false;
    }
    int ListLength(){
        return length;
    }
    int GetElem(int index){
        node *p;
        int i = 0;
        p = head->next;
        while (p != NULL){
            if (index == ++i)
                return p->value;
            p = p->next;
        }
        return 0;
    }
    int LocateElem(int num){
        node *p;
        p = head->next;
        int index = 0;
        while (p != NULL){
            if (p->value == num)
                return ++index;
            p = p->next;
        }
        return 0;
    }
    int PriorElem(int cur_num){
        node *p, *temp;
        p = head->next;
        while (p != NULL){
            temp = p;
            p = p->next;
            if (p != NULL && p->value == cur_num)
                return temp->value;
        }
        return 0;
    }
    int NextElem(int cur_num){
        node *p, *temp;
        p = head->next;
        while (p != NULL){
            temp = p;
            p = p->next;
            if (p != NULL && temp->value == cur_num)
                return p->value;
        }
        return 0;
    }
    void ListTraverse(){
        node *p;
        p = head->next;
        while (p != NULL){
            printf("%d ", p->value);
            p = p->next;
        }
        printf("\n");
    }
    int SetElem(int index, int num){
        node *p;
        int i = 0;
        p = head->next;
        while (p != NULL){
            if (index != ++i) {
                p = p->next;
                continue;
            }
            int old = p->value;
            p->value = num;
            return old;
        }
        return 0;
    }
    void InsertElem(int index, int num){
        node *p, *temp;
        int i = 0;
        p = head;
        length++;
        while (p != NULL){
            if (index != ++i) {
                temp = p;
                p = p->next;
                continue;
            }
            temp = p->next;
            node *tmp = (node *)malloc(sizeof(node));
            p->next = tmp;
            tmp->next = temp;
            tmp->value = num;
            return;
        }
        node *tmp = (node *)malloc(sizeof(node));
        temp->next = tmp;
        tmp->value = num;
        tmp->next = NULL;
    }
    void DeleteElem(int index){
        node *p, *temp;
        int i = 0;
        temp = head;
        p = head->next;
        length--;
        while (p != NULL){
            if (index != ++i) {
                temp = p;
                p = p->next;
                continue;
            }
            temp->next = p->next;
            free(p);
        }
    }
    void Reverse(){
        if (length < 1) return;
        node *p, *temp, *tmp = NULL;
        temp = p = head->next;
        while(temp != NULL){
            temp = p->next;
            p->next = tmp;
            tmp = p;
            p = temp;
        }
        head->next = tmp;
    }
} ADTlist;

int main(){
    ADTlist.InitLIst();
    ADTlist.InsertElem(1, 1);
    ADTlist.InsertElem(2, 2);
    ADTlist.InsertElem(3, 3);
    ADTlist.InsertElem(4, 4);
    ADTlist.ListTraverse();
    ADTlist.Reverse();
    ADTlist.ListTraverse();
    ADTlist.DestoryList();
}