#include "1BinaryTree.h"
#include <stdio.h>
int main(){
    BinaryTree Tree;
    Tree.InitBiTree();
    freopen("tree", "r", stdin);
    Tree.root = Tree.CreateBiTree();
    Tree.PreOrderTreaverse(Tree.root);
    puts("");
    Tree.FindtargetandDelete(Tree.root, 'D');
    Tree.PreOrderTreaverse(Tree.root);
}