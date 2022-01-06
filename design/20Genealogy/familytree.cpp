#include "familytree.h"

Person::Person(){}

Person::Person(string& nameIn, bool genderIn, bool marriedIn, bool aliveIn, string& dateIn, string& addressIn)
			  :name(nameIn), gender(genderIn), married(marriedIn), alive(aliveIn), date(dateIn), address(addressIn)
{

}

Couple::Couple(){}

Couple::Couple(Person husbandIn, Person wifeIn, int geIn)
			  : husband(husbandIn), wife(wifeIn), generation(geIn)
{

}

familyTree::familyTree(const string& fileName)
{
	personCnt = 0;
	fstream dataFile(fileName, ios::in);

	string name1, name2, date, address, tmp1, tmp2, tmp3;
	bool gender, married, alive;
	char x;
	while (dataFile.get(x))
	{
		if (personCnt != 0)
			dataFile >> name1;

		dataFile >> name2 >> tmp1 >> tmp2 >> tmp3 >> date >> address;
		dataFile.ignore();//读掉换行符

		if (tmp1 == "男")				gender = true;
		else if (tmp1 == "女")			gender = false;
		if (tmp2 == "已婚")				married = true;
		else if (tmp2 == "未婚")		married = false;
		if (tmp3 == "健在")				alive = true;
		else if (tmp3 == "已故")		alive = false;
		Person person(name2, gender, married, alive, date, address);

		if (x == '5')//添加孩子
		{
			if (gender)
				addChild(name1, Couple(person, Person()));
			else
				addChild(name1, Couple(Person(), person));
		}
		else if (x == '6')//添加配偶
		{
			addCouple(name1, person);
		}
	}

	dataFile.close();
}

familyTree::~familyTree(){}

//显示所有人信息（层序遍历）
void familyTree::show()
{
	cout << "以下是家谱中所有人的信息：" << endl;

	queue<Couple*> Queue;
	Queue.push(&ancestor);

	while (!Queue.empty())
	{
		Couple* cpl = Queue.front();
		Queue.pop();

		//输出夫妇信息
		show(cpl->husband);
		show(cpl->wife);

		for (int i = 0; i < cpl->offspring.size(); i++)
			Queue.push(&cpl->offspring.at(i));
	}
}

//显示第n代所有人信息 （层序遍历）
void familyTree::show(int generation)
{
	cout << "以下是第 " << generation << " 代所有人的信息：" << endl;

	queue<Couple*> Queue;
	Queue.push(&ancestor);
//	Couple* lastPtr = Queue.front();//指向每层最后一个结点
//	int level = 1;

	while (!Queue.empty())
	{
		Couple* cpl = Queue.front();
		Queue.pop();

		//输出夫妇信息
		if (cpl->generation == generation)
		{
			show(cpl->husband);
			show(cpl->wife);
		}
		else if (cpl->generation > generation)
			return;

		for (int i = 0; i < cpl->offspring.size(); i++)
			Queue.push(&cpl->offspring.at(i));

//		if (cpl == lastPtr)
//		{
//			lastPtr = Queue.back();
//			level++;
//		}
	}
}

//显示此人信息
void familyTree::show(const Person& person, bool familyMember)
{
	if (person.name.empty())
		return;
//	cout << "here4" << endl;//debug

	cout << "以下为 " << person.name << " 的全部信息：" << endl
		 << person.name << " ";
	if (person.gender)		cout << "男 ";
	else				cout << "女 ";
	if (person.married)		cout << "已婚 ";
	else				cout << "未婚 ";
	if (person.alive)		cout << "健在 ";
	else				cout << "已故 ";
	cout << person.date << " " << person.address << endl << endl;

	if (familyMember)
	{
		Couple* cpl = findParents(person.name);//找到其双亲
		if (cpl != NULL)
		{
			cout << "以下为 " << person.name << " 双亲的全部信息：" << endl << endl;
			show(cpl->husband);
			show(cpl->wife);
		}
		else
			cout << "未找到 " << person.name << " 的双亲。" << endl << endl;

		cpl = find(person.name);//找到其本人
		if (cpl == NULL)
			cout << "未找到 " << person.name << "，请检查输入是否合法。" << endl << endl;
		else if (cpl->offspring.size() == 0)
			cout << person.name << " 无子女。" << endl << endl;
		else
		{
			cout << "以下为 " << person.name << " 子女的全部信息：" << endl << endl;
			for (int i = 0; i < cpl->offspring.size(); i++)
			{
				show(cpl->offspring[i].husband);
				show(cpl->offspring[i].wife);
			}
		}
	}
}

//显示两人关系
void familyTree::showRelation(const string& name1, const string& name2)
{
	if (name1 == name2)
	{
		cout << "这是同一人。" << endl;
		return;
	}

	Couple* cpl1 = find(name1);
	Couple* cpl2 = find(name2);
	if (cpl1 == cpl2)
	{
		cout << name1 << "与 "  << name2 << " 是夫妻关系。" << endl;
		return;
	}

	int ge1 = cpl1->generation;
	int ge2 = cpl2->generation;
	int minG = min(ge1, ge2);
	Couple* cpl;

	if (ge1 > minG)
	{
		string tmp = name1;

		cout << name1 << " ";
		while (ge1-- > minG)
		{
			cout << "的父亲";
			cpl = findParents(tmp);
			tmp = cpl->husband.name;
		}

		if (cpl->husband.name == name2)
			cout << "是 " << name2 << endl;
		else if (cpl->wife.name == name2)
			cout << "的妻子是 " << name2 << endl;
		else
			cout << "与 "  << name2 << " 是兄弟姐妹关系。" << endl;
	}
	else if (ge2 > minG)
	{
		string tmp = name2;
		cout << name2 << " ";
		while (ge2-- > minG)
		{
			cout << "的父亲";
			cpl = findParents(tmp);
			tmp = cpl->husband.name;
		}

		if (cpl->husband.name == name1)
			cout << "是 " << name1 << endl;
		else if (cpl->wife.name == name1)
			cout << "的妻子是 " << name1 << endl;
		else
			cout << "与 "  << name1 << " 是兄弟姐妹关系。" << endl;
	}
	else
		cout << name1 << "与 "  << name2 << " 是兄弟姐妹关系。" << endl;
}

//按姓名查找（层序遍历）
Couple* familyTree::find(const string& name)
{
	queue<Couple*> Queue;
	Queue.push(&ancestor);

	while (!Queue.empty())
	{
		Couple* cpl = Queue.front();
		Queue.pop();

		if ((cpl->husband.name == name) || (cpl->wife.name == name))//找到
			return cpl;

		for (int i = 0; i < cpl->offspring.size(); i++)
			Queue.push(&cpl->offspring.at(i));
	}
	//未找到
	return NULL;
}

//返回其双亲（层序遍历）
Couple* familyTree::findParents(const string& name)
{
	queue<Couple*> Queue;
	Queue.push(&ancestor);

	while (!Queue.empty())
	{
		Couple* cpl = Queue.front();
		Queue.pop();

		for (int i = 0; i < cpl->offspring.size(); i++)
			if ((cpl->offspring[i].husband.name == name) || (cpl->offspring[i].wife.name == name))//找到
				return cpl;

		for (int i = 0; i < cpl->offspring.size(); i++)
			Queue.push(&cpl->offspring.at(i));
	}
	//未找到
	return NULL;
}

//按出生/死亡日期查找（层序遍历）
void familyTree::show(bool alive, const string& date)
{
	cout << "以下为符合要求的所有成员信息：" << endl;
	queue<Couple*> Queue;
	Queue.push(&ancestor);

	while (!Queue.empty())
	{
		Couple* cpl = Queue.front();
		Queue.pop();

		if ((cpl->husband.alive == alive) && (cpl->husband.date == date))
			show(cpl->husband);
		if ((cpl->wife.alive == alive) && (cpl->wife.date == date))
			show(cpl->wife);

		for (int i = 0; i < cpl->offspring.size(); i++)
			Queue.push(&cpl->offspring.at(i));
	}
}

//添加孩子
void familyTree::addChild(const string& name, Couple couple)
{
	if (personCnt == 0)
	{
		ancestor = couple;
		ancestor.generation = 1;
	}
	else
	{
		Couple* cpl = find(name);
		if (cpl == NULL)
		{
			cout << "未找到 " << name << "，请检查输入是否合法。" << endl << endl;
			return;
		}
		couple.generation = cpl->generation+1;
		cpl->offspring.push_back(couple);
	}
	personCnt++;
}

//添加配偶
void familyTree::addCouple(const string& name, const Person person)
{
//	cout << "here5" << endl;//debug
	Couple* cpl = find(name);
	if (cpl->husband.name == name)
		cpl->wife = person;
	else
		cpl->husband = person;
	personCnt++;
}

//删除成员
void familyTree::deletePerson(const string& name)
{
	if ((ancestor.husband.name == name) || (ancestor.wife.name == name))
		ancestor.~Couple();
	else
	{
		Couple* cpl = findParents(name);
		if (cpl == NULL)
		{
			cout << "未找到 " << name << "，请检查输入是否合法。" << endl << endl;
			return;
		}
		auto iter = cpl->offspring.begin();
		for (; iter != cpl->offspring.end(); )
			if ((iter->husband.name == name) || (iter->wife.name == name))
			{
				iter = cpl->offspring.erase(iter);
			}
			else
				iter++;
	}
}

//修改成员信息
void familyTree::modify(const string& name, Person person)
{
	Couple* cpl = find(name);
	if (cpl->husband.name == name)
		cpl->husband = person;
	else if (cpl->wife.name == name)
		cpl->wife = person;
}

void Operation(int x, familyTree& family)
{
	switch (x)
	{
		case 0: operation0();break;
		case 1: operation1(family);break;
		case 2: operation2(family);break;
		case 3: operation3(family);break;
		case 4: operation4(family);break;
		case 5: operation5(family);break;
		case 6: operation6(family);break;
		case 7: operation7(family);break;
		case 8: operation8(family);break;
		case 9: operation9(family);break;
		default :operation0();break;
	}
}

void operation0()
{
	cout<< "程序已退出。" << endl;
	exit(0);
}

void operation1(familyTree& family)
{
	family.show();
}

void operation2(familyTree& family)
{
	int generation;
	cout << "您想显示第几代人的信息呢？" << endl;
	cin >> generation;
	family.show(generation);
}

void operation3(familyTree& family)
{
	string name;
	cout << "您想显示谁的信息呢？" << endl;
	cin >> name;
	bool familyMember;
	cout << "您想显示 " << name << " 家庭成员的信息吗？若想输入1，反之输入0：" << endl;
	cin >> familyMember;
	Couple* cpl = family.find(name);
	if (cpl == NULL)
	{
		cout << "未找到 " << name << "，请检查输入是否合法。" << endl << endl;
		return;
	}
	else if (cpl->husband.name == name)
		family.show(cpl->husband, familyMember);
	else
		family.show(cpl->wife, familyMember);
}

void operation4(familyTree& family)
{
	string name1, name2;
	cout << "您想查询谁与谁之间的信息呢？" << endl;
	cin >> name1 >> name2;
	family.showRelation(name1, name2);
}

void operation5(familyTree& family)
{
	string name1, name2, date, address, tmp1, tmp2, tmp3;
	bool gender, married, alive;

	cout << "您想为谁添加孩子呢？" << endl;
	cin >> name1;
	cout << "请输入此人所有信息：" << endl;
	cin >> name2 >> tmp1 >> tmp2 >> tmp3 >> date >> address;

	if (tmp1 == "男")				gender = true;
	else if (tmp1 == "女")			gender = false;
	if (tmp2 == "已婚")				married = true;
	else if (tmp2 == "未婚")		married = false;
	if (tmp3 == "健在")				alive = true;
	else if (tmp3 == "已故")		alive = false;
	Person person(name2, gender, married, alive, date, address);

	if (gender)
		family.addChild(name1, Couple(person, Person()));
	else
		family.addChild(name1, Couple(Person(), person));
}

void operation6(familyTree& family)
{
	string name1, name2, date, address, tmp1, tmp2, tmp3;
	bool gender, married, alive;

	cout << "您想为谁添加配偶呢？" << endl;
	cin >> name1;
	cout << "请输入此人所有信息：" << endl;
	cin >> name2 >> tmp1 >> tmp2 >> tmp3 >> date >> address;

	if (tmp1 == "男")				gender = true;
	else if (tmp1 == "女")			gender = false;
	if (tmp2 == "已婚")				married = true;
	else if (tmp2 == "未婚")		married = false;
	if (tmp3 == "健在")				alive = true;
	else if (tmp3 == "已故")		alive = false;
	Person person(name2, gender, married, alive, date, address);

	family.addCouple(name1, person);
}

void operation7(familyTree& family)
{
	string name;
	cout << "您想删除哪位成员呢？" << endl;
	cin >> name;

	family.deletePerson(name);
}

void operation8(familyTree& family)
{
	string name1, name2, date, address, tmp1, tmp2, tmp3;
	bool gender, married, alive;

	cout << "您想修改哪位成员的信息呢？" << endl;
	cin >> name1;
	cout << "请输入此人所有信息：" << endl;
	cin >> name2 >> tmp1 >> tmp2 >> tmp3 >> date >> address;

	if (tmp1 == "男")				gender = true;
	else if (tmp1 == "女")			gender = false;
	if (tmp2 == "已婚")				married = true;
	else if (tmp2 == "未婚")		married = false;
	if (tmp3 == "健在")				alive = true;
	else if (tmp3 == "已故")		alive = false;
	Person person(name2, gender, married, alive, date, address);

	family.modify(name1, person);
}

void operation9(familyTree& family)
{
	bool alive;
	cout << "此人是否健在，若是输入1，反之输入0：" << endl;
	cin >> alive;
	string date;
	cout << "请输入出生/死亡日期：" << endl;
	cin >> date;

	family.show(alive, date);
}