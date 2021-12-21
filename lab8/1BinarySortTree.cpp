#include <stdio.h>
#include <malloc.h>
class BinarySortTree{
public:
    typedef struct treenode{
        int value;
        struct treenode *left;
        struct treenode *right;
    }* node, binode;
    node root = NULL;
    int flags[99];
    int search(int data, node point, node *father){
        if (point == NULL) return 0;
        else if (point->value == data) return 1;
        else if (data < point->value) {
            *father = point;
            return search(data, point->left, father);
        }
        else {
            *father = point;
            return search(data, point->right, father);
        }
    }
    void insert(int data){
        node father = root;
        if (!search(data, root, &father)) {
            node q = (binode *)malloc(sizeof(binode));
            q->value = data;
            q->left = q->right = NULL;
            if (root == NULL) root = q;
            else if (data < father->value) father->left = q, printf("left: %d\n", father->left->value);
            else father->right = q, printf("right: %d\n", father->right->value);
        }
    }
    void deletenode(int data){
        node father = root;
        if (search(data, root, &father)){
            node target;
            if (data < father->value) target = father->left;
            else target = father->right;
            if (!target->left && !target->right) {
                if (data < father->value) father->left = NULL;
                else father->right = NULL;
            }
            else if ((target->left && !target->right) || (!target->left && target->right)) {
                node son = target->left ? target->left : target->right;
                if (data < father->value) father->left = son;
                else father->right = son;
            }
            else {
                node lefttree = target->left;
                if (!lefttree->right) {
                    father->left = lefttree;
                    lefttree->right = target->right;
                }
                else {
                    node maxnode = lefttree, maxnodefather = lefttree;
                    while (maxnode->right) {
                        maxnodefather = maxnode;
                        maxnode = maxnode->right;
                    }
                    maxnodefather->right = maxnode->left;
                    maxnode->left = maxnodefather;
                    maxnode->right = target->right;
                    father->left = maxnode;
                }
            }
            // delete target;
            free(target);
        }
    }
    void printtree(node root, int tab, int flag){
        int nextTab = tab;
        flags[tab] = 1;
        printTabs(tab);
        if (root->value){
            if (flag == 2) {
                printf("\\--> %d", root->value);
                // printf("%d\n", root->left == NULL);
                flags[tab] = 0;
            }
            else{
                printf("|--> %d", root->value);
            }
        }
        printf("\n");
        if (root->left) {
            printtree(root->left, nextTab + 1, 1);
        }
        if (root->right) {
            flags[tab + 1] = 0;
            printtree(root->right, tab + 1, 2);
        }
    }
    void printTabs(int numOfTabs) {
        int i;
        for (i = 0; i < numOfTabs; i++) {
            if (flags[i] == 0)
                printf("  ");
            else
                printf("| ");
        }
    }
};
int main(){
    BinarySortTree Tree;
    int x[] = {62, 58, 88, 47, 73, 99, 35, 51, 93, 29, 37, 49, 56, 36, 48, 50};
    for (int i = 0; i < sizeof(x) / sizeof(x[0]); i++)
        Tree.insert(x[i]);
    Tree.printtree(Tree.root, 0, 2);
}