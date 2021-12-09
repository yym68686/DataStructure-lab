#include <malloc.h>
#include <stdio.h>
#include "3BinaryTree.h"

void BinaryTree::InitBiTree(){
    BiTNode *tmp = (BiTNode *)malloc(sizeof(BiTNode));
    root = tmp;
    root->data = NULL;
    root->left = NULL;
    root->right = NULL;
}
void BinaryTree::DestoryBiTree(BiTNode *p){
    if (p){
        if (p->left) DestoryBiTree(p->left), p->left = NULL;
        if (p->right) DestoryBiTree(p->right), p->right = NULL;
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
        tmp->left = CreateBiTree();
        tmp->right = CreateBiTree();
    }
    return tmp;
}
void BinaryTree::ClearBiTree(){
    if (root){
        DestoryBiTree(root->left);
        DestoryBiTree(root->right);
    }
}
bool BinaryTree::BiTreeEmpty(){
    if(!root->left && !root->right) return true;
    return false;

}
int BinaryTree::BiTreeDepth(BiTNode *p){
    if (!p) return 0;
    int left = BiTreeDepth(p->left);
    int right = BiTreeDepth(p->right);
    return left >= right ? left + 1 : right + 1;
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
    if (Parent(p->left, target))
        return Parent(p->left, target);
    if (Parent(p->right, target))
        return Parent(p->right, target);
    return p;
}
BinaryTree::BiTNode* BinaryTree::LeftChild(BiTNode *p){
    return p->left;
}
BinaryTree::BiTNode* BinaryTree::RightChild(BiTNode *p){
    return p->right;
}
BinaryTree::BiTNode* BinaryTree::LeftBrother(BiTNode *p){
    return Parent(root, p)->left == p ? NULL : Parent(root, p)->left;
}
BinaryTree::BiTNode* BinaryTree::RightBrother(BiTNode *p){
    return Parent(root, p)->right == p ? NULL : Parent(root, p)->right;
}
BinaryTree::BiTNode* BinaryTree::FindtargetandDelete(BiTNode *p, char ch){
    if (p->left && p->left->data == ch) DestoryBiTree(p->left), p->left = NULL;
    if (p->right && p->right->data == ch) DestoryBiTree(p->right), p->right = NULL;
    if (p->left) return FindtargetandDelete(p->left, ch);
    if (p->right) return FindtargetandDelete(p->right, ch);
    return NULL;
}
void BinaryTree::PreOrderTreaverse(BiTNode *p){
    if (!p) return;
    printf("%c", p->data);
    PreOrderTreaverse(p->left);
    PreOrderTreaverse(p->right);
}
void BinaryTree::InOrderTreaverse(BiTNode *p){
    if (!p) return;
    InOrderTreaverse(p->left);
    printf("%c", p->data);
    InOrderTreaverse(p->right);
}
void BinaryTree::PostOrderTreaverse(BiTNode *p){
    if (!p) return;
    PostOrderTreaverse(p->left);
    PostOrderTreaverse(p->right);
    printf("%c", p->data);
}
void BinaryTree::LevelOrderTreaverse(){
    BiTNode *queue[999];
    int head = 0, rear = 0;
    queue[rear++] = root;
    while(head < rear){
        printf("%c", queue[head]->data);
        if (queue[head]->left) queue[rear++] = queue[head]->left;
        if (queue[head]->right) queue[rear++] = queue[head]->right;
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
        if (tmp->right) stack[++top] = tmp->right;
        if (tmp->left) stack[++top] = tmp->left;
    }
}
void BinaryTree::Nonrecursive_InOrderTreaverse(BiTNode *p){
    BiTNode *stack[999], *node = p;
    int top = 0;
    while (top || node){
        if (node){
            stack[++top] = node;
            node = node->left;
        }
        else {
            node = stack[top--];
            printf("%c", node->data);
            node = node->right;
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
        if(node->left) stack1[++top1] = node->left;
        if(node->right) stack1[++top1] = node->right;
    }
    while (top2)
        printf("%c", stack2[top2--]->data);
}

void BinaryTree::Assign(BiTNode *p, char value){
    p->data = value;
}
void BinaryTree::InsertChild(BiTNode *p, BiTNode *c, int LR){
    BiTNode *tmp = LR ? p->right : p->left;
    if (LR)
        p->right = c;
    else
        p->left = c;
    c->right = tmp;
}
void BinaryTree::DeleteChild(BiTNode *p, int LR){
    if (LR)
        DestoryBiTree(p->right);
    else
        DestoryBiTree(p->left);
}
int BinaryTree::Complete_binary_tree(BiTNode *p){
    BiTNode *queue[999];
    int head = 0, rear = 0, num = 1;
    queue[rear++] = root;
    while(head < rear){
        if (queue[head]->left) queue[rear++] = queue[head]->left, num++;
        else if (num != Nodenum) return 0;
        if (queue[head]->right) queue[rear++] = queue[head]->right, num++;
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
            if (stack[i]->left) stack[++top] = stack[i]->left, nownum++;
            if (stack[i]->right) stack[++top] = stack[i]->right, nownum++;
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
    if (node->left) {
        printtree(node->left, nextTab + 1, 1);
    }
    if (node->right) {
        flags[tab + 1] = 0;
        printtree(node->right, tab + 1, 2);
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