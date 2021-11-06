#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

void push(struct node**head_ref, int new_data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void reverse(node *head){
    node *q, *p=head->next;
    head->next=NULL;
    while(p){
        q = p;
        p = p->next;
        q->next = head->next;
        head->next = q;
    }
}

bool isPresent(struct node *head, int data){
    struct node *t = head;
    while(t != NULL){
        if( t->data == data )
            return 1;
        t = t->next;
    }
    return 0;
}

void printList(struct node *node){
    node = node->next;
    while( node != NULL ){
        printf("%d ", node->data);
        node = node->next;
    }
}

int main(){
    struct node* head1 = NULL;

    push(&head1, 20), push(&head1, 4), push(&head1, 15), push(&head1, 10), push(&head1, 0);

    printf("A: ");
    printList(head1);
    reverse(head1);
    printf("\nB: ");
    printList(head1);

    return 0;
}