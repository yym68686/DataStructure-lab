#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <iomanip>
#include <string.h>
#include <bitset>
#include "chartable.h"

using namespace std;

struct BiNode{
	char data;//英文字符
	int weight;//字符权值，即其词频
	BiNode* left;
	BiNode* right;
	string codes;//编码结果

	BiNode(char c, int w);
	BiNode(int w);
	~BiNode();

	void show();//打印词频及编码
};

//重写仿函数以建立最小堆
struct cmp{
	bool operator()(BiNode* n1, BiNode* n2);
};

class HuffmanTree{
	public:
		HuffmanTree(CharTable& charTable);//建树
		~HuffmanTree();//销毁Huffman tree（递归）

		void encode(const string& filename1, const string& filename2);//编码
		void decode(const string& filename1, const string& filename2);//解码

		void show(const string& filename);//打印词频及编码，并写入文件

	private:
		BiNode* root;//树根
		map<char, string> codeTable;//编码表
};

#endif