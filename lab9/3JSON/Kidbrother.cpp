#include <malloc.h>
#include <stdio.h>
#include "Kidbrother.h"

void BinaryTree::InitBiTree(){
    BiTNode *tmp = (BiTNode *)malloc(sizeof(BiTNode));
    root = tmp;
    root->data = NULL;
    root->kid = NULL;
    root->borther = NULL;
}
void BinaryTree::DestoryBiTree(BiTNode *p){
    if (p){
        if (p->kid) DestoryBiTree(p->kid), p->kid = NULL;
        if (p->borther) DestoryBiTree(p->borther), p->borther = NULL;
        free(p);
    }
}
BinaryTree::BiTNode* BinaryTree::CreateBiTree(){
    BiTNode *tmp = NULL;
    char ch;
    scanf("%c", &ch);
    if (ch != '#') {
        tmp = (BiTNode *)malloc(sizeof(BiTNode));
        tmp->data = ch;
        Nodenum++;
        tmp->kid = CreateBiTree();
        tmp->borther = CreateBiTree();
    }
    return tmp;
}
void BinaryTree::ClearBiTree(){
    if (root){
        DestoryBiTree(root->kid);
        DestoryBiTree(root->borther);
    }
}
bool BinaryTree::BiTreeEmpty(){
    if(!root->kid && !root->borther) return true;
    return false;

}
int BinaryTree::BiTreeDepth(BiTNode *p){
    if (!p) return 0;
    int kid = BiTreeDepth(p->kid);
    int borther = BiTreeDepth(p->borther);
    return kid >= borther ? kid + 1 : borther + 1;
}
char BinaryTree::Root(){
    return root->data;
}
char BinaryTree::Value(BiTNode *p){
    return p->data;
}
BinaryTree::BiTNode* BinaryTree::Parent(BiTNode *p, BiTNode *target){
    if (!p) return NULL;
    if (p == target)
        return p;
    if (Parent(p->kid, target))
        return Parent(p->kid, target);
    if (Parent(p->borther, target))
        return Parent(p->borther, target);
    return p;
}
BinaryTree::BiTNode* BinaryTree::kidChild(BiTNode *p){
    return p->kid;
}
BinaryTree::BiTNode* BinaryTree::bortherChild(BiTNode *p){
    return p->borther;
}
BinaryTree::BiTNode* BinaryTree::kidBrother(BiTNode *p){
    return Parent(root, p)->kid == p ? NULL : Parent(root, p)->kid;
}
BinaryTree::BiTNode* BinaryTree::bortherBrother(BiTNode *p){
    return Parent(root, p)->borther == p ? NULL : Parent(root, p)->borther;
}
BinaryTree::BiTNode* BinaryTree::FindtargetandDelete(BiTNode *p, char ch){
    if (p->kid && p->kid->data == ch) DestoryBiTree(p->kid), p->kid = NULL;
    if (p->borther && p->borther->data == ch) DestoryBiTree(p->borther), p->borther = NULL;
    if (p->kid) return FindtargetandDelete(p->kid, ch);
    if (p->borther) return FindtargetandDelete(p->borther, ch);
    return NULL;
}
void BinaryTree::PreOrderTreaverse(BiTNode *p){
    if (!p) return;
    printf("%c", p->data);
    PreOrderTreaverse(p->kid);
    PreOrderTreaverse(p->borther);
}
void BinaryTree::InOrderTreaverse(BiTNode *p){
    if (!p) return;
    InOrderTreaverse(p->kid);
    printf("%c", p->data);
    InOrderTreaverse(p->borther);
}
void BinaryTree::PostOrderTreaverse(BiTNode *p){
    if (!p) return;
    PostOrderTreaverse(p->kid);
    PostOrderTreaverse(p->borther);
    printf("%c", p->data);
}
void BinaryTree::LevelOrderTreaverse(){
    BiTNode *queue[999];
    int head = 0, rear = 0;
    queue[rear++] = root;
    while(head < rear){
        printf("%c", queue[head]->data);
        if (queue[head]->kid) queue[rear++] = queue[head]->kid;
        if (queue[head]->borther) queue[rear++] = queue[head]->borther;
        head++;
    }
    return;
}

void BinaryTree::Nonrecursive_PreOrderTreaverse(BiTNode *p){
    BiTNode *stack[999];
    int top = 0;
    stack[++top] = root;
    while (top){
        printf("%c", stack[top]->data);
        BiTNode* tmp = stack[top--];
        if (tmp->borther) stack[++top] = tmp->borther;
        if (tmp->kid) stack[++top] = tmp->kid;
    }
}
void BinaryTree::Nonrecursive_InOrderTreaverse(BiTNode *p){
    BiTNode *stack[999], *node = p;
    int top = 0;
    while (top || node){
        if (node){
            stack[++top] = node;
            node = node->kid;
        }
        else {
            node = stack[top--];
            printf("%c", node->data);
            node = node->borther;
        }
    }
}
void BinaryTree::Nonrecursive_PostOrderTreaverse(BiTNode *p){
    BiTNode *stack1[999], *stack2[999], *node;
    int top1 = 0, top2 = 0;
    stack1[++top1] = p;
    while (top1){
        node = stack1[top1--];
        stack2[++top2] = node;
        if(node->kid) stack1[++top1] = node->kid;
        if(node->borther) stack1[++top1] = node->borther;
    }
    while (top2)
        printf("%c", stack2[top2--]->data);
}

void BinaryTree::Assign(BiTNode *p, char value){
    p->data = value;
}
void BinaryTree::InsertChild(BiTNode *p, BiTNode *c, int LR){
    BiTNode *tmp = LR ? p->borther : p->kid;
    if (LR)
        p->borther = c;
    else
        p->kid = c;
    c->borther = tmp;
}
void BinaryTree::DeleteChild(BiTNode *p, int LR){
    if (LR)
        DestoryBiTree(p->borther);
    else
        DestoryBiTree(p->kid);
}
int BinaryTree::Complete_binary_tree(BiTNode *p){
    BiTNode *queue[999];
    int head = 0, rear = 0, num = 1;
    queue[rear++] = root;
    while(head < rear){
        if (queue[head]->kid) queue[rear++] = queue[head]->kid, num++;
        else if (num != Nodenum) return 0;
        if (queue[head]->borther) queue[rear++] = queue[head]->borther, num++;
        else if (num != Nodenum) return 0;
        head++;
    }
    return 1;
}
int BinaryTree::getwidth(BiTNode *p){
    BiTNode *stack[999];
    int top = 0, maxx = -1, nownum = 1, start = 1, end = 1;
    stack[++top] = p;
    while (nownum){
        nownum = 0;
        for (int i = start;i <= end; i++){
            if (stack[i]->kid) stack[++top] = stack[i]->kid, nownum++;
            if (stack[i]->borther) stack[++top] = stack[i]->borther, nownum++;
        }
        start = end + 1;
        end = end + nownum;
        maxx = maxx < nownum ? nownum : maxx;
    }
    return maxx;
}

void BinaryTree::printtree(BiTNode *node, int tab, int flag){
    int nextTab = tab;
    flags[tab] = 1;
    printTabs(tab);
    if (node){
        if (flag == 2) {
            printf ("\\--> %c", node->data);
            flags[tab] = 0;
        }
        else{
            printf ("|--> %c", node->data);
        }
    }
    printf("\n");
    if (node->kid) {
        printtree(node->kid, nextTab + 1, 1);
    }
    if (node->borther) {
        flags[tab + 1] = 0;
        printtree(node->borther, tab + 1, 2);
    }
}
void BinaryTree::printTabs(int numOfTabs) {
    int i;
    for (i = 0; i < numOfTabs; i++) {
        if (flags[i] == 0)
            printf("  ");
        else
            printf("| ");
    }
}
void BinaryTree::Output_layer_elements(int index){
    BiTNode *node = root, *stack[999];
    int top = 0;
    while (node){
        stack[++top] = node;
        node = node->borther;
    }
    int k = 0;
    while (k++ != top){
        int times = index;
        while (--times){
            if (stack[k]->kid) stack[k] = stack[k]->kid;
            else {
                for (int j = k; j < top - 1; j++){
                    stack[j] = stack[j + 1];
                }
                k--,top--;
                break;
            };
        }
    }
    int set[333];
    for (int i = 1; i <= top; i++){
        while (stack[i]){
            if (!set[(int)stack[i]->data])
                printf("%c ", stack[i]->data), set[(int)stack[i]->data]++;
            if (stack[i]->borther) stack[i] = stack[i]->borther;
            else break;
        }
    }
}
