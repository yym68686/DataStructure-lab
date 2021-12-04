#include "1BinaryTree.h"
#include <stdio.h>
int main(){
    BinaryTree Tree;
    Tree.InitBiTree();
    freopen("tree", "r", stdin);
    Tree.root = Tree.CreateBiTree();
    Tree.PreOrderTreaverse(Tree.root);
    puts("");
    Tree.Nonrecursive_PreOrderTreaverse(Tree.root);
    puts("");
    Tree.InOrderTreaverse(Tree.root);
    puts("");
    Tree.Nonrecursive_InOrderTreaverse(Tree.root);
    puts("");
    Tree.PostOrderTreaverse(Tree.root);
    puts("");
    Tree.Nonrecursive_PostOrderTreaverse(Tree.root);
    puts("");
    Tree.LevelOrderTreaverse();
}