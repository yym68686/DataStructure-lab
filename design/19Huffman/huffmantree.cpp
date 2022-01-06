#include "huffmantree.h"

const int width = 25;//设置输出域宽

bool cmp::operator()(BiNode* n1, BiNode* n2)
{
	return n1->weight > n2->weight;
}

BiNode::BiNode(char c, int w): data(c), weight(w)
{
	left = right = NULL;
}

BiNode::BiNode(int w): weight(w)
{
	left = right = NULL;
}

BiNode::~BiNode()
{
	if (left != NULL)
	{
		delete left;
		left = NULL;
	}
	if (right != NULL)
	{
		delete right;
		right = NULL;
	}
}

void BiNode::show()
{
	cout << "char: " << data
		 << setw(width) << "frequency: " << weight
		 << setw(width) << "codes: " << codes
		 << endl;
}

HuffmanTree::HuffmanTree(CharTable& charTable)
{
	//建立最小堆
	priority_queue<BiNode*, vector<BiNode*>, cmp> minHeap;

	auto iter = charTable.table.begin();
	for (; iter != charTable.table.end(); iter++)
	{
		BiNode* p = new BiNode(iter->first, iter->second);
		minHeap.push(p);
	}

	//建树
	BiNode* min1;
	BiNode* min2;
	while (minHeap.size() != 1)
	{
		min1 = minHeap.top();
		minHeap.pop();
		min2 = minHeap.top();
		minHeap.pop();

		BiNode* root = new BiNode(min1->weight + min2->weight);
		root->left = min1;
		root->right = min2;

		minHeap.push(root);
	}

	//记录树根
	root = minHeap.top();

	//给每个结点编码（基于层序遍历）
	queue<BiNode*> queue;
	BiNode* p = root;

	if (p == NULL)
		return;

	queue.push(p);
	while (!queue.empty())
	{
		p = queue.front();
		queue.pop();

		if (p->left != NULL){
			p->left->codes = p->codes + "0";
			queue.push(p->left);
		}
		if (p->right != NULL){
			p->right->codes = p->codes + "1";
			queue.push(p->right);
		}

		//将叶结点加入编码表
		if ((p->left == NULL) && (p->right == NULL))
		{
			codeTable.insert(pair<char, string>(p->data, p->codes));
		}
	}
}

HuffmanTree::~HuffmanTree()
{
	if (root != NULL)
	{
		delete root;//递归实现
		root = NULL;
	}
}

void HuffmanTree::show(const string& filename)
{
	fstream file(filename.data(), ios::out);
	if (file.bad()){
		cout << "cann't open " << filename << endl;
		return;
	}

	queue<BiNode*> queue;
	BiNode* p = root;

	if (p == NULL)
		return;

	cout << "字符： "
		 << setw(width) << "词频：     "
		 << setw(width) << "编码："
		 << endl;
	file << "字符： "
		 << setw(width) << "词频：     "
		 << setw(width) << "编码："
		 << endl;

	queue.push(p);
	while (!queue.empty())
	{
		p = queue.front();
		queue.pop();

		if (p->left != NULL){
			queue.push(p->left);
		}
		if (p->right != NULL){
			queue.push(p->right);
		}

		//只对叶结点进行输出
		if ((p->left == NULL) && (p->right == NULL))
		{
			//打印
			p->show();
			//写入文件
			file << "char: " << p->data
				 << setw(width) << "frequency: " << p->weight
				 << setw(width) << "codes: " << p->codes
				 << endl;
		}
	}

	file.close();
}

void HuffmanTree::encode(const string& filename1, const string& filename2)
{
	fstream sourceFile(filename1.data(), ios::in);//打开原文本文件
	if (sourceFile.bad()){
		cout << "cann't open " << filename1 << endl;
		return;
	}
	fstream desFile(filename2.data(), ios::out | ios::binary);//创建目标二进制文件
	if (desFile.bad()){
		cout << "cann't open " << filename2 << endl;
		return;
	}

	string codes;//所有编码
	//每次读入一个字符，将其编码追加入codes
	char c1;
	while (sourceFile.get(c1))//每次读入一字符
	{
		auto iter = codeTable.find(c1);
		if (iter == codeTable.end())//c1不在编码表中，报错
		{
			cout << "ERROR!!!";
			return;
		}
		else//c1在编码表中
			codes.append(iter->second);
	}

//	cout << "codes: " << codes << endl;//debug

	//二进制文件前四个字节存放数据的有效位数
	int bitSize = codes.size();
	desFile.write((const char*)(&bitSize), sizeof(bitSize));

	//第五个字节开始存放数据
	int byteSize = codes.size()/8 + 1;

	for (int i = 0; i < byteSize; i++)
	{
		bitset<8> byte(codes.substr(i*8, 8));//直接用string初始化byte

		//将一字节编码写入文件
		desFile.write((const char*)&byte, byte.size()/8);
	}

	sourceFile.close();
	desFile.close();
}

void HuffmanTree::decode(const string& filename1, const string& filename2)
{
	fstream sourceFile(filename1.data(), ios::in | ios::binary);//打开原二进制文件
	if (sourceFile.bad()){
		cout << "cann't open " << filename1 << endl;
		return;
	}
	fstream desFile(filename2.data(), ios::out);//创建目标文本文件
	if (desFile.bad()){
		cout << "cann't open " << filename2 << endl;
		return;
	}

	//先读入前四字节
	int bitSize;
	sourceFile.read((char*)(&bitSize), sizeof(bitSize));
	int byteSize = bitSize/8 + 1;

	string codes;
	for (int i = 0; i < byteSize; i++)
	{
		//读入一字节
		bitset<8> byte;
		sourceFile.read((char*)&byte, byte.size()/8);
		//将这一字节编码转为string
		codes.append(byte.to_string());
	}

	//先将最后八位全部读入，再删去冗余部分
	int n = byteSize*8 - bitSize;
	cout << "n: " << n << endl;//debug
	codes.erase((byteSize-1)*8, n);

//	cout << "codes: " << codes << endl;//debug
//	return;

	string curCodes;
	char c;
	BiNode* p;
	int i = 0;
	while (i < codes.size())
	{
		curCodes.clear();//先清空上次的编码

		while (1)//一次循环解码一字符
		{
			if (i >= codes.size())//表明编码结束
				break;

			curCodes += codes.at(i++);
			p = root;
			int pos = 0;

			//寻找curCodes对应的叶结点
			while ((p != NULL) && (pos < curCodes.size()))
			{
				if (curCodes.at(pos) == '0')
					p = p->left;
				else if (curCodes.at(pos) == '1')
					p = p->right;
				pos++;
			}

			//若p指向叶结点且pos指向curCodes末尾，则可解码一个字符
			if ((p->left == NULL) && (p->right == NULL) &&
				(pos == curCodes.size()))
			{
				break;
			}
			//反之，需要继续读入二进制码
		}

		desFile << p->data;//成功解码一个字符
	}

	sourceFile.close();
	desFile.close();
}