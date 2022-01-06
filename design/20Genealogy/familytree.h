#ifndef FAMILYTREE_H
#define FAMILYTREE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <algorithm>
#define NONE -1
using namespace std;

struct Person{
	string name;//姓名
	bool gender;//性别
	bool married;//婚否
	bool alive;//健在否
	string date;//出生/死亡日期
	string address;//住址

	Person();
	Person(string& nameIn, bool genderIn, bool marriedIn, bool aliveIn, string& dateIn, string& addressIn);
};

struct Couple{
//	bool which;//若真，husband为子，若假，wife为女
	Person husband;
	Person wife;
	int generation;//第几代人

	vector<Couple> offspring;//后代

	Couple();
	Couple(Person husbandIn, Person wifeIn, int geIn = NONE);
};

class familyTree{
	public:
		familyTree(const string& fileName);//读取数据并建树
		~familyTree();//销毁树

		void show();//显示所有人信息
		void show(int generation);//显示第n代所有人信息
		void show(const Person& person, bool familyMember = false);//显示此人信息
		void show(bool alive, const string& date);//按出生/死亡日期显示信息
		void showRelation(const string& name1, const string& name2);//显示两人关系

		Couple* find(const string& name);//按姓名查找
		Couple* findParents(const string& name);//返回其双亲

		void addCouple(const string& name, const Person person);//添加配偶
		void addChild(const string& name, Couple couple);//添加孩子
		void deletePerson(const string& name);//删除成员
		void modify(const string& name, Person person);//修改成员信息

//	private:
		Couple ancestor;//根结点

		int personCnt;//总人数
};

void Operation(int x, familyTree& family);
void operation0();//退出程序
void operation1(familyTree& family);//显示家谱所有人信息
void operation2(familyTree& family);//显示第n 代所有人的信息
void operation3(familyTree& family);//显示某人的信息
void operation4(familyTree& family);//查询两人之间关系
void operation5(familyTree& family);//为某夫妇添加孩子
void operation6(familyTree& family);//为某人添加配偶
void operation7(familyTree& family);//删除某成员
void operation8(familyTree& family);//修改某成员信息
void operation9(familyTree& family);//按照出生/死亡日期查询成员信息

#endif