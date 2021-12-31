#include <stdio.h>
#include <fstream>
#include <stdlib.h>
using namespace std;
int inde = 1, num[55555], n;
string temp;
int main(){
    ifstream ReadFile(to_string(inde) + "Sample");
    while(getline(ReadFile, temp)) num[n++] = stoi(temp);
    ReadFile.close();
    printf("%d", n);

}