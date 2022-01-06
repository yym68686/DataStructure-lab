#include <iostream>
#include "familytree.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	const string fileName("data.txt");//原始数据文件
//	const string fileName("test.txt");

	familyTree family(fileName);

	int x;
	while(1)
	{
//		system("cls");

		cout << "请输入数字实现相应功能噢。" << endl
			 << "若想显示家谱所有人信息，请按1" << endl
			 << "若想显示第n 代所有人的信息，请按2" << endl
			 << "若想显示某人的信息，请按3" << endl
			 << "若想查询两人之间关系，请按4" << endl
			 << "若想为某夫妇添加孩子，请按5" << endl
			 << "若想为某人添加配偶，请按6" << endl
			 << "若想删除某成员，请按7" << endl
			 << "若想修改某成员信息，请按8" << endl
			 << "若想按照出生/死亡日期查询成员信息，请按9" << endl
			 << "若想退出程序，请按0" << endl << endl
			 << "请输入：";
		cin >> x;
		cout << endl;
		Operation(x, family);//执行相应操作

		system("pause");
	}
}