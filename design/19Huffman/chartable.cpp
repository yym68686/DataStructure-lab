#include "chartable.h"

#include <iostream>
#include <fstream>

void CharTable::calculateFreq(const string& filename)
{
	fstream file(filename.data());
	if (file.bad()){
		cout << "cann't open " << filename << endl;
		return;
	}

	//每次读入一个字符
	//若不在表中，将其插入表中
	//若在表中，其词频加1
	char c1;
	while (file.get(c1))//每次读入一字符
	{
		auto iter = table.find(c1);
		if (iter == table.end())//c1不在表中
		{
			table.insert(pair<char, int>(c1, 1));
		}
		else//c1在表中
		{
			iter->second++;
		}
	}

	file.close();
}