#include <stdio.h>
class HuffmanTree{
public:
    typedef struct HNode{
        int weight;
        int parent;
        int lchild, rchild;
        char *code;
        HNode() {
            weight = 0;
            parent = lchild = rchild = -1;
        }
    } HNode;
    HNode *Tree;
    int TreeSize, flags[99];
    void CreateTree(int* a, int n){
        TreeSize = 2 * n - 1;
        Tree = new HNode[TreeSize];
        for (int i = 0; i < n ;i++){
            Tree[i].weight = a[i];
        }
        int s1, s2, nextPos = n;
        for (int i = 0; i < n - 1; i++){
            SelectTwoMin(nextPos, s1, s2);
            Tree[nextPos].lchild = s1;
            Tree[nextPos].rchild = s2;
            Tree[nextPos].weight = Tree[s1].weight + Tree[s2].weight;
            Tree[s1].parent = Tree[s2].parent = nextPos++;
        }
    };
    void SelectTwoMin(int nextPos, int &s1, int &s2){
        int index = 0;
        while(Tree[index].parent != -1) index++;
        s1 = index++;
        while(Tree[index].parent != -1) index++;
        s2 = index;
        KeepOrder(s1, s2);
        for (int i = index + 1; i < nextPos; i++){
            if (Tree[i].parent == -1 && Tree[i].weight < Tree[s2].weight){
                s2 = i;
                KeepOrder(s1, s2);
            }
        }
    };
    void KeepOrder(int& n1,int& n2){
        if (Tree[n1].weight > Tree[n2].weight)
        {
            int tmp = n1;
            n1 = n2;
            n2 = tmp;
        }
    };
    void printtree(int index, int tab, int flag){
        int nextTab = tab;
        flags[tab] = 1;
        printTabs(tab);
        if (Tree[index].weight){
            if (flag == 2) {
                printf ("\\--> %d", Tree[index].weight);
                flags[tab] = 0;
            }
            else{
                printf ("|--> %d", Tree[index].weight);
            }
        }
        printf("\n");
        if (Tree[index].lchild != -1) {
            printtree(Tree[index].lchild, nextTab + 1, 1);
        }
        if (Tree[index].rchild != -1) {
            flags[tab + 1] = 0;
            printtree(Tree[index].rchild, tab + 1, 2);
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
    int findroot(){
        int index = 0;
        while (Tree[index].parent != -1) index = Tree[index].parent;
        return index;
    }
};
int main(){
    HuffmanTree hTree;
    int x[] = {5,29,7,8,14,23,3,11};
    hTree.CreateTree(x, sizeof(x) / sizeof(x[0]));
    hTree.printtree(hTree.findroot(), 0, 2);
}