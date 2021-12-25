#include <malloc.h>
#include <stdio.h>
#include <string.h>
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
    head->next = NULL;
}

bool ADT_list::ListEmpty(){
    if (length < 1) return true;
    return false;
}

int ADT_list::ListLength(){
    return length;
}

ADT_list::node* ADT_list::GetElem(int index){
    node *p;
    int i = 0;
    p = head->next;
    while (p != NULL){
        if (index == ++i)
            return p;
        p = p->next;
    }
    return NULL;
}

int ADT_list::LocateElem(int num){
    node *p;
    p = head->next;
    int index = 0;
    while (p != NULL){
        if (p->number == num)
            return index;
        p = p->next;
        index++;
    }
    return -1;
}

int ADT_list::PriorElem(int cur_num){
    node *p, *temp;
    p = head->next;
    while (p != NULL){
        temp = p;
        p = p->next;
        if (p != NULL && p->number == cur_num)
            return temp->number;
    }
    return 0;
}

int ADT_list::NextElem(int cur_num){
    node *p, *temp;
    p = head->next;
    while (p != NULL){
        temp = p;
        p = p->next;
        if (p != NULL && temp->number == cur_num)
            return p->number;
    }
    return 0;
}

void ADT_list::ListTraverse(){
    node *p;
    p = head->next;
    puts("Block Chain Output:");
    while (p != NULL){
        printf("%d %s %d\n", p->number, p->information, p->Checkcode);
        p = p->next;
    }
    printf("\n");
}

void ADT_list::CreateList(char* str, int check){
    node *p = head;
    while (p->next != NULL) p = p->next;
    node *tmp = (node *)malloc(sizeof(node));
    p->next = tmp;
    tmp->next = NULL;
    tmp->number = length;
    strcpy(tmp->information, str);
    length++;
    tmp->Checkcode = check;
}

int ADT_list::CheckList(){
    node* p = head->next, *tmp = p;
    if (!p) return 1;
    while(p) {
        int sum = 0;
        for (int i = 0; i < strlen(p->information); i++)
            sum += p->information[i];
        if (p->number) {
            node *temp = head;
            sum += p->number;
            while (temp->next != p) temp = temp->next;
            sum += temp->Checkcode;
        }
        // printf("%d %d %d\n", sum % 113, p->Checkcode, p->number);
        if (sum % 113 != p->Checkcode) return p->number + 100;
        p = p->next;
    }
    return 1;
}

void ADT_list::SetStr(int index, const char* str){
    node *p;
    int i = 0;
    p = head->next;
    while (p && index != i++) p = p->next;
    strcpy(p->information, str);
    while(p) {
        int sum = 0;
        for (int i = 0; i < strlen(p->information); i++)
            sum += p->information[i];
        if (p->number) {
            node *temp = head;
            sum += p->number;
            while (temp->next != p) temp = temp->next;
            sum += temp->Checkcode;
        }
        // printf("%d %d %d\n", sum % 113, p->Checkcode, p->number);
        // if (sum % 113 != p->Checkcode) return p->number + 100;
        p->Checkcode = sum % 113;
        p = p->next;
    }
}

void ADT_list::InsertElem(char* str){
    node *p = head;
    while (p->next != NULL) p = p->next;
    node *tmp = (node *)malloc(sizeof(node));
    p->next = tmp;
    tmp->next = NULL;
    tmp->number = length;
    strcpy(tmp->information, str);
    length++;
    tmp->Checkcode = GetCheckcode();
}
int ADT_list::GetCheckcode(){
    node* p = head;
    while (p->next != NULL) p = p->next;
    int sum = 0;
    for (int i = 0; i < strlen(p->information); i++)
        sum += p->information[i];
    if (length > 1) {
        sum += p->number;
        p = head;
        while (p->next->next) p = p->next;
        sum += p->Checkcode;
    }
    return sum % 113;
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