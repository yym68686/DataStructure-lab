#include <iostream>
#include "huffmantree.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	const string sourceFile("source.txt");//未编码文件名
//	const string sourceFile("test.txt");//测试文件

	//要求一
	CharTable charTable;
	charTable.calculateFreq(sourceFile);//统计词频
	HuffmanTree hTree(charTable);//建树
	hTree.show("Huffman.txt");//打印词频及编码，并写入文件

	//要求二
	hTree.encode(sourceFile, "code.dat");//给文件编码

	//要求三
	hTree.decode("code.dat", "解码结果.txt");//给文件解码

	return 0;
}