#ifndef CHARTABLE_H
#define CHARTABLE_H

#include <string>
#include <map>

using namespace std;

class CharTable{
	public:
		//计算文件中所有出现字符的词频
		void calculateFreq(const string& filename);

	private:
		//存放词频
		map<char, int> table;

	friend class HuffmanTree;
};

#endif