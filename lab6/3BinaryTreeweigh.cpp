#include "3BinaryTree.h"
#include <stdio.h>
int main(){
    BinaryTree Tree;
    Tree.InitBiTree();
    freopen("tree", "r", stdin);
    Tree.root = Tree.CreateBiTree();
    // Tree.PreOrderTreaverse(Tree.root);
    // puts("");
    Tree.printtree(Tree.root, 0, 2);
    printf("%d", Tree.getwidth(Tree.root));
}