#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;

typedef int ElemType;
typedef struct BiNode* Position;
typedef Position BiTree;

struct BiNode{
	ElemType data;//关键字
	BiTree left;//左子树
	BiTree right;//右子树

	BiNode(ElemType dataIn);
};

class AVL_Tree{
	public:
		AVL_Tree();
		~AVL_Tree();//销毁树

		bool Create(const string fileName);//建树
		Position Find(ElemType data);//查找值为data的结点
		Position FindMax(BiTree root);//查找以root为根的子树中，最大值结点
		Position FindMin(BiTree root);//查找以root为根的子树中，最小值结点

		Position Insert(BiTree root, ElemType data);//插入结点
		Position Delete(BiTree root);//删除子树
		Position Delete(BiTree root, ElemType data);//删除值为data的结点

		int height(BiTree root);//返回以root为根结点的树高
		Position LL_rotation(BiTree root);
		Position LR_rotation(BiTree root);
		Position RL_rotation(BiTree root);
		Position RR_rotation(BiTree root);

		void print(BiTree root);//以中序遍历方式输出结果

//	private:
		BiTree root;//树根
};

//选做题 9.32
void find_a_b(AVL_Tree& avl_tree, BiTree root, ElemType x, ElemType* a, ElemType* b);

#endif