#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include "Kidbrother.h"
using namespace std;
int n, m;
string str[99];
bool IsJsonData(string strData)
{
	if (strData[0] != '{') return false;
	int num = 1;
	for (int i=1; i<strData.length(); ++i){
		if (strData[i] == '{') ++num;
		else if (strData[i] == '}') --num;
		if (num == 0) return true;
	}
	return false;
}
struct point{
    int x, y;
} t[111];
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


    freopen("input", "r", stdin);
    scanf("%d%d\n", &n, &m);
    for (int i = 0; i < n; i++)
        getline(cin, str[i]), cout << str[i] << endl;

}