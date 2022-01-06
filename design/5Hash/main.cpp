#include "ChainAddress.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;
Hash_Table HashList;
vector<string> split(const string& str, const string& delim) {
	vector<string> res;
	if("" == str) return res;
	//先将要切割的字符串从string类型转换为char*类型
	char * strs = new char[str.length() + 1];
	strcpy(strs, str.c_str());

	char * d = new char[delim.length() + 1];
	strcpy(d, delim.c_str());

	char *p = strtok(strs, d);
	while(p) {
		string s = p; //分割得到的字符串转换为string类型
		res.push_back(s); //存入结果数组
		p = strtok(NULL, d);
	}
	return res;
}

int main(){
	ifstream inputfile("input");
    if(inputfile.fail()){
        cout<<"Open failed."<<endl;
        inputfile.close();
        return 0;
    }
    string input_line;
    while(!inputfile.eof()){
        getline(inputfile, input_line);
        vector<string> splitarr = split(input_line, ",");
        // for (auto i : splitarr) {
        //     cout << i << endl;
        // }
        // strcpy(HashList[const_cast<char*>(splitarr[0].c_str())]->Identifier, const_cast<char*>(splitarr[0].c_str()));
        // strcpy(HashList[const_cast<char*>(splitarr[0].c_str())]->name, const_cast<char*>(splitarr[1].c_str()));
        // strcpy(HashList[const_cast<char*>(splitarr[0].c_str())]->time, const_cast<char*>(splitarr[3].c_str()));

        HashList[const_cast<char*>(splitarr[0].c_str())]->Identifier = const_cast<char*>(splitarr[0].c_str());
        HashList[const_cast<char*>(splitarr[0].c_str())]->name = const_cast<char*>(splitarr[1].c_str());
        HashList[const_cast<char*>(splitarr[0].c_str())]->line = stoi(splitarr[2]);
        HashList[const_cast<char*>(splitarr[0].c_str())]->time = const_cast<char*>(splitarr[3].c_str());
        HashList[const_cast<char*>(splitarr[0].c_str())]->TotalMileage = stoi(splitarr[4]);
        // cout << HashList[const_cast<char*>(splitarr[0].c_str())]->name << "*" << endl;
        // cout << HashList[const_cast<char*>(splitarr[0].c_str())]->line << "*" << endl;
        // cout << HashList[const_cast<char*>(splitarr[0].c_str())]->time << "*" << endl;
        // cout << HashList[const_cast<char*>(splitarr[0].c_str())]->TotalMileage << "*" << endl;
    }
    inputfile.close();
    HashList.printTable();
    return 0;
}