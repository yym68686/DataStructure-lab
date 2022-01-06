#include <iostream>
#include <string>
#include "avl_tree.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	AVL_Tree avl_tree;
	const string fileName("test1.txt");
	fstream dataFile(fileName, ios::in);
	avl_tree.Create(fileName);

	//1.插入操作
	avl_tree.Insert(avl_tree.root, 9999);
	avl_tree.Insert(avl_tree.root, -9999);
	avl_tree.Insert(avl_tree.root, 2);
	avl_tree.print(avl_tree.root);
	cout << endl;

	//2.查找操作
	if (avl_tree.Find(2))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	if (avl_tree.Find(80))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	if (avl_tree.Find(0))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	avl_tree.print(avl_tree.root);
	cout << endl;

	//3.删除操作
	avl_tree.Delete(avl_tree.root, 5);
	avl_tree.Delete(avl_tree.root, 0);
	avl_tree.Delete(avl_tree.root, 9999);
	avl_tree.Delete(avl_tree.root, 91);
	avl_tree.Delete(avl_tree.root, 5);
	avl_tree.Delete(avl_tree.root, 30);
	avl_tree.print(avl_tree.root);
	cout << endl;
	return 0;
}