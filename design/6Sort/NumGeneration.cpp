#include <stdio.h>
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
int num = 50000, n, a = num;
int main(void) {
	srand((unsigned)time(NULL));
    ofstream out("1Sample");
	while (num)
		out << a - num-- << endl;
	out.close();

    out.open("2Sample");
	num = a;
	while (num--) out << num << endl;
	out.close();

	num = 10;
	for (int i = 3; i <= num; i++){
		out.open(to_string(i) + "Sample");
		n = a;
		while (n--)
			out << rand() % a << endl;
		out.close();
	}
	return 0;
}