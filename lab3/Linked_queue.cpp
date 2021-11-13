#include <malloc.h>
#include <stdio.h>
#include "Linked_queue.h"

void ADT_queue::Initqueue(){
    node *tmp = (node *)malloc(sizeof(node));
    length = 0;
    head = tmp;
    tmp->next = NULL;
}

void ADT_queue::Destoryqueue(){
    node *p, *temp;
    p = head;
    while (p != NULL){
        temp = p;
        p = p->next;
        free(temp);
    }
    length = -1;
}

void ADT_queue::Clearqueue(){
    node *p, *temp;
    p = head->next;
    while (p != NULL){
        temp = p;
        p = p->next;
        free(temp);
    }
    length = 0;
}

bool ADT_queue::queueEmpty(){
    return length < 1 ? true : false;
}

int ADT_queue::queueLength(){
    return length;
}
int ADT_queue::GetHead(){
    return head->next->value;
}
void ADT_queue::queueTraverse(){
    node *p = head->next;
    while (p){
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}
void ADT_queue::EnQueue(int num){
    node *p = head->next;
    while (p) p = p->next;
    node *tmp = (node *)malloc(sizeof(node));
    p->next = tmp;
    tmp->value = num;
    tmp->next = NULL;
}
void ADT_queue::DeQueue(){
    node *p = head->next;
    head->next = p->next;
    free(p);
}

// int ADT_queue::GetElem(int index){
//     node *p;
//     int i = 0;
//     p = head->next;
//     while (p != NULL){
//         if (index == ++i)
//             return p->value;
//         p = p->next;
//     }
//     return 0;
// }

// int ADT_queue::LocateElem(int num){
//     node *p;
//     p = head->next;
//     int index = 0;
//     while (p != NULL){
//         if (p->value == num)
//             return index;
//         p = p->next;
//         index++;
//     }
//     return -1;
// }

// int ADT_queue::PriorElem(int cur_num){
//     node *p, *temp;
//     p = head->next;
//     while (p != NULL){
//         temp = p;
//         p = p->next;
//         if (p != NULL && p->value == cur_num)
//             return temp->value;
//     }
//     return 0;
// }

// int ADT_queue::NextElem(int cur_num){
//     node *p, *temp;
//     p = head->next;
//     while (p != NULL){
//         temp = p;
//         p = p->next;
//         if (p != NULL && temp->value == cur_num)
//             return p->value;
//     }
//     return 0;
// }


// int ADT_queue::SetElem(int index, int num){
//     node *p;
//     int i = 0;
//     p = head->next;
//     while (p != NULL){
//         if (index != i++) {
//             p = p->next;
//             continue;
//         }
//         int old = p->value;
//         p->value = num;
//         return old;
//     }
//     return 0;
// }

// void ADT_queue::InsertElem(int index, int num){
//     node *p, *temp;
//     int i = 0;
//     p = head;
//     length++;
//     while (p != NULL){
//         if (index != ++i) {
//             temp = p;
//             p = p->next;
//             continue;
//         }
//         temp = p->next;
//         node *tmp = (node *)malloc(sizeof(node));
//         p->next = tmp;
//         tmp->next = temp;
//         tmp->value = num;
//         return;
//     }
//     node *tmp = (node *)malloc(sizeof(node));
//     temp->next = tmp;
//     tmp->value = num;
//     tmp->next = NULL;
// }

// void ADT_queue::DeleteElem(int index){
//     node *p, *temp;
//     int i = 0;
//     temp = head;
//     p = head->next;
//     length--;
//     while (p != NULL){
//         if (index != ++i) {
//             temp = p;
//             p = p->next;
//             continue;
//         }
//         temp->next = p->next;
//         free(p);
//     }
// }

// void ADT_queue::Remove(){
//     node *p = head->next, *temp = head;
//     int use[999] = {0};
//     while (p != NULL){
//         if (use[p->value]) {
//             temp->next = p->next;
//             free(p);
//             length--;
//             p = temp->next;
//             continue;
//         }
//         use[p->value] = 1;
//         temp = p;
//         p = p->next;
//     }
// }

// void ADT_queue::Reverse(){
//     if (length < 1) return;
//     node *p, *temp, *tmp = NULL;
//     temp = p = head->next;
//     while(temp != NULL){
//         temp = p->next;
//         p->next = tmp;
//         tmp = p;
//         p = temp;
//     }
//     head->next = tmp;
// }

// void ADT_queue::Bubble_Sort(){
//     for (int i = 1; i <= length ; i++){
//         node *p = head, *temp = p->next, *tmp = temp->next;
//         int times = length - i;
//         while (times--){
//             if (temp->value > tmp->value){
//                 p->next = temp->next;
//                 temp->next = tmp->next;
//                 tmp->next = temp;
//             }
//             p = p->next;
//             temp = p->next;
//             tmp = temp->next;
//         }
//     }
// }

// void ADT_queue::Select_sort(){
//     node *p = head->next, *temp = p->next;
//     for (int i = 0; i < length - 1; i++){
//         int minn = 0x3f3f3f3f;
//         while(temp){
//             minn = temp->value < minn ? temp->value : minn;
//             temp = temp->next;
//         }
//         SetElem(LocateElem(minn), p->value);
//         SetElem(i, minn);
//         p = p->next;
//         temp = p->next;
//     }
// }

// ADT_queue ADT_queue::Union(ADT_queue B){
//     ADT_queue C;
//     C.Initqueue();
//     int index = 0;
//     node *p = head->next;
//     while(p){
//         if (B.LocateElem(p->value) >= 0){
//             C.InsertElem(++index, p->value);
//         }
//         p = p->next;
//     }
//     // queueTraverse();
//     // B.queueTraverse();
//     return C;
// }

// void ADT_queue::Josephus(int m){
//     node *p = head->next, *last = p, *tmp = head;
//     while(last->next)
//         last = last->next;
//     last->next = head->next;
//     while(length--){
//         int temp = m;
//         while(--temp){
//             p = p->next;
//             tmp = tmp->next;
//         }
//         printf("%d ", p->value);
//         tmp->next = p->next;
//         last = p;
//         p = p->next;
//         free(last);
//     }
// }
