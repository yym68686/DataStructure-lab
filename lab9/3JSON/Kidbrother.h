#ifndef Kidbrother_H
#define Kidbrother_H
class BinaryTree{
public:
    typedef struct BiTNode
    {
        char data;
        struct BiTNode *kid, *borther;
    } BiTNode;
    BiTNode *root;
    int Nodenum = 0, flags[999];
    void InitBiTree();
    void DestoryBiTree(BiTNode *p);
    BiTNode* CreateBiTree();
    void ClearBiTree();
    bool BiTreeEmpty();
    int BiTreeDepth(BiTNode *p);
    char Root();
    char Value(BiTNode *p);
    BiTNode* Parent(BiTNode *p, BiTNode *target);
    BiTNode* kidChild(BiTNode *p);
    BiTNode* bortherChild(BiTNode *p);
    BiTNode* kidBrother(BiTNode *p);
    BiTNode* bortherBrother(BiTNode *p);
    BiTNode* FindtargetandDelete(BiTNode *p, char ch);
    void PreOrderTreaverse(BiTNode *p);
    void InOrderTreaverse(BiTNode *p);
    void PostOrderTreaverse(BiTNode *p);
    void LevelOrderTreaverse();
    void Nonrecursive_PreOrderTreaverse(BiTNode *p);
    void Nonrecursive_InOrderTreaverse(BiTNode *p);
    void Nonrecursive_PostOrderTreaverse(BiTNode *p);
    void Nonrecursive_LevelOrderTreaverse(BiTNode *p);
    void Assign(BiTNode *p, char value);
    void InsertChild(BiTNode *p, BiTNode *c, int LR);
    void DeleteChild(BiTNode *p, int LR);
    int Complete_binary_tree(BiTNode *p);
    int getwidth(BiTNode *p);
    void printtree(BiTNode *node, int tab, int flag);
    void printTabs(int);
    void Output_layer_elements(int index);
};
#endif