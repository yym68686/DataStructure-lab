#include <malloc.h>
#include <stdio.h>
#include "Linked_list.h"

void ADT_list::InitLIst(){
    node *tmp = (node *)malloc(sizeof(node));
    length = 0;
    head = tmp;
    tmp->next = NULL;
}

void ADT_list::DestoryList(){
    node *p, *temp;
    p = head;
    while (p != NULL){
        temp = p;
        p = p->next;
        free(temp);
    }
    length = -1;
}

void ADT_list::ClearList(){
    node *p, *temp;
    p = head->next;
    while (p != NULL){
        temp = p;
        p = p->next;
        free(temp);
    }
    length = 0;
}

bool ADT_list::ListEmpty(){
    if (length < 1) return true;
    return false;
}

int ADT_list::ListLength(){
    return length;
}

int ADT_list::GetElem(int index){
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

int ADT_list::LocateElem(int num){
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

int ADT_list::PriorElem(int cur_num){
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

int ADT_list::NextElem(int cur_num){
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

void ADT_list::ListTraverse(){
    node *p;
    p = head->next;
    while (p != NULL){
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}

int ADT_list::SetElem(int index, int num){
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

void ADT_list::InsertElem(int index, int num){
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

void ADT_list::DeleteElem(int index){
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

void ADT_list::Remove(){
    node *p = head->next, *temp = head;
    int use[999] = {0};
    while (p != NULL){
        if (use[p->value]) {
            temp->next = p->next;
            free(p);
            length--;
            p = temp->next;
            continue;
        }
        use[p->value] = 1;
        temp = p;
        p = p->next;
    }
}

void ADT_list::Reverse(){
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

void ADT_list::Bubble_Sort(){
    for (int i = 0; i < length - 1; i++){
        node *p = head, *temp = p->next, *tmp = temp->next;
        while (tmp != NULL){
            if (temp->value > tmp->value){
                p->next = temp->next;
                temp->next = tmp->next;
                tmp->next = temp;
            }
            p = p->next;
            temp = p->next;
            tmp = temp->next;
        }
    }
}

void ADT_list::Select_sort(){

}