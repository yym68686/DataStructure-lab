#include "4Kidbrother.h"
#include <stdio.h>
int main(){
    BinaryTree Tree;
    Tree.InitBiTree();
    freopen("tree", "r", stdin);
    Tree.root = Tree.CreateBiTree();
    Tree.PreOrderTreaverse(Tree.root);
    puts("");
    Tree.printtree(Tree.root, 0, 2);
    Tree.Output_layer_elements(1);
    puts("");
    Tree.Output_layer_elements(2);
    puts("");
    Tree.Output_layer_elements(3);
    puts("");
    Tree.Output_layer_elements(4);
}