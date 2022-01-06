#include "avl_tree.h"

BiNode::BiNode(ElemType dataIn): data(dataIn)
{
	left = right = NULL;
}

AVL_Tree::AVL_Tree()
{
	root = NULL;
}

AVL_Tree::~AVL_Tree()
{
	Delete(root);
}

bool AVL_Tree::Create(const string fileName)
{
	fstream dataFile(fileName, ios::in);
	if (!dataFile){
		cout << "打开文件" << fileName << "失败！" << endl;
		return false;
	}

	int data;
	while (!dataFile.eof())
	{
		dataFile >> data;
//		cout << data << " ";//debug
		root = Insert(root, data);
	}

	dataFile.close();
	return true;
}

Position AVL_Tree::Find(ElemType data)
{
	Position pos = root;
	while (pos != NULL)
	{
		if (data < pos->data)
			pos = pos->left;
		else if (data > pos->data)
			pos = pos->right;
		else
			return pos;
	}
	return NULL;
}

Position AVL_Tree::FindMax(BiTree root)
{
	BiNode* p = root;
	if (p == NULL)
		return NULL;
	else
	{
		while (p->right != NULL)
		{
			p = p->right;
		}
	}
	return p;
}

Position AVL_Tree::FindMin(BiTree root)
{
	BiNode* p = root;
	if (p == NULL)
		return NULL;
	else
	{
		while (p->left != NULL)
		{
			p = p->left;
		}
	}
	return p;
}

Position AVL_Tree::Insert(BiTree root, ElemType data)
{
	if(root == NULL)
	{
		root = new BiNode(data);
	}
	else
	{
		if(data < root->data)
		{
			//插入到左子树
			root->left = Insert(root->left, data);
			//计算平衡因子，再判断如何旋转
			if(height(root->left) - height(root->right) == 2)
			{
				if(data < root->left->data)
					root = LL_rotation(root);
				else if(data > root->left->data)
					root = LR_rotation(root);
			}
		}
		else if(data > root->data)
		{
			//插入到右子树
			root->right = Insert(root->right, data);
			//计算平衡因子，再判断如何旋转
			if(height(root->right) - height(root->left) == 2)
			{
				if(data > root->right->data)
					root = RR_rotation(root);
				else if(data < root->right->data)
					root = RL_rotation(root);
			}
		}
	}
	return root;
}

Position AVL_Tree::Delete(BiTree root)
{
	if (root != NULL){
		root->left = Delete(root->left);
		root->right = Delete(root->right);
		delete root;
		return NULL;
	}
}

Position AVL_Tree::Delete(BiTree root, ElemType data)
{
	//思路：
	//1.找到结点（若不为叶结点，转化为叶结点）
	//2.删除
	//3.平衡调整
	if (root == NULL)
		return NULL;
	else
	{
		if (data < root->data) //1.找到结点
		{
			root->left = Delete(root->left, data);
		}
		else if (data > root->data) //1.找到结点
		{
			root->right = Delete(root->right, data);
		}
		else
		{
			//2.删除
			if ((root->left == NULL) && (root->right == NULL))
			{
				delete root;
				if (root == this->root)//特殊情况
					this->root = NULL;
				return NULL;
			}
			else//1.（若不为叶结点，转化为叶结点）
			{
				Position pos;
				if (height(root->left) > height(root->right))
				{
					pos = FindMax(root->left);
					//交换data与左子树最大值
					root->data = pos->data;
					pos->data = data;
					root->left = Delete(root->left, data);
				}
				else
				{
					pos = FindMin(root->right);
					//交换data与右子树最小值
					root->data = pos->data;
					pos->data = data;
					root->right = Delete(root->right, data);
				}
			}
		}
	}

	//3.平衡调整
//	if (height(root->left) - height(root->right) == 2)
//	{
//		if (height(root->left->left) >= height(root->left->right))
//			root = LL_rotation(root);
//		else
//			root = LR_rotation(root);
//	}
//	else if (height(root->left) - height(root->right) == -2)
//	{
//		if (height(root->right->right) >= height(root->right->left))
//			root = RR_rotation(root);
//		else
//			root = RL_rotation(root);
//	}

	return root;
}

int AVL_Tree::height(BiNode* root)
{
	if (root == NULL)
		return 0;
	else
		return 1 + max(height(root->left), height(root->right));
}

Position AVL_Tree::LL_rotation(BiTree root)
{
	BiNode* p1 = root->left;
	BiNode* p2 = p1->right;
	root->left = p2;
	p1->right = root;
	return p1;
}

Position AVL_Tree::LR_rotation(BiTree root)
{
	BiNode* p1 = root->left;
	BiNode* p2 = p1->right;
	root->left = p2->right;
	p2->right = root;
	p1->right = p2->left;
	p2->left = p1;
	return p2;
}

Position AVL_Tree::RL_rotation(BiTree root)
{
	BiNode* p1 = root->right;
	BiNode* p2 = p1->left;
	root->right = p2->left;
	p2->left = root;
	p1->left = p2->right;
	p2->right = p1;
	return p2;
}

Position AVL_Tree::RR_rotation(BiTree root)
{
	BiNode* p1 = root->right;
	BiNode* p2 = p1->left;
	root->right = p2;
	p1->left = root;
	return p1;
}

void AVL_Tree::print(BiTree root)
{
	if (root == this->root)
		cout << endl << "平衡二叉树的中序遍历如下：" << endl;
	if (root == NULL)
		return;
	else if (root != NULL){
		print(root->left);
		cout << root->data << " ";
		print(root->right);
	}

//	queue<BiNode*> queue;
//	queue.push(root);
//	BiNode* p;
//	while (!queue.empty())
//	{
//		p = queue.front();
//		queue.pop();
//
//		if (p->left != NULL)
//			queue.push(p->left);
//		if (p->right != NULL)
//			queue.push(p->right);
//
//		cout << p->data << " 对应结点树高为：" << height(p) << endl;
//	}
}

//选做题 9.32
void find_a_b(AVL_Tree& avl_tree, BiTree root, ElemType x, ElemType* a, ElemType* b)
{
	if (root == NULL)
		return;
	else
	{
		if (root->data < x)
		{
			*a = root->data;
			find_a_b(avl_tree, root->right, x, a, b);
		}
		else if (root->data > x)
		{
			*b = root->data;
			find_a_b(avl_tree, root->left, x, a, b);
		}
		else
		{
			Position pos1 = avl_tree.FindMax(root->left);
			Position pos2 = avl_tree.FindMin(root->right);

			if (pos1 != NULL)
				*a = pos1->data;
			if (pos2 != NULL)
				*b = pos2->data;
		}
	}
}