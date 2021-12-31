#include <stdio.h>
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
int num = 50000, n;
int main(void) {
	srand((unsigned)time(NULL));
    ofstream out("1Sample");
	while (num)
		out << 50000 - num-- << endl;
	out.close();
    out.open("2Sample");
	num = 50000;
	while (num--)
		out << num << endl;
	out.close();
	num = 10;
	for (int i = 3; i <= num; i++){
		out.open(to_string(i) + "Sample");
		n = 50000;
		while (n--)
			out << rand() % 50000 << endl;
		out.close();
	}
	return 0;
}