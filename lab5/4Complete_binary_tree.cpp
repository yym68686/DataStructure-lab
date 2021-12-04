#include "1BinaryTree.h"
#include <stdio.h>
int main(){
    BinaryTree Tree;
    Tree.InitBiTree();
    freopen("tree2", "r", stdin);
    Tree.root = Tree.CreateBiTree();
    printf("%d", Tree.Complete_binary_tree(Tree.root));
}