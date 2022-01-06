#include <bits/stdc++.h>
#include "ChainAddress.h"
using namespace std;
struct Entry a[KEY];
unsigned long long HashTable[KEY];
int head = 0;

Information::Information(char *s) {
    Identifier = strdup(s);
}
Information::~Information() { free(Identifier); Identifier = NULL; }
bool Information::Equ(char* a) {
    return strcmp(Identifier, a) == 0;
}

Entry::Entry() { }
Entry::~Entry() { delete info; info = NULL; }

unsigned long long Hash_Table::Get_Hash(char* Identifier) {
    unsigned long long Ans = 0;
    for (int i = 0; Identifier[i]; ++i)
        Ans = Ans * P + Identifier[i];
    return Ans;
}

Information*& Hash_Table::New_Entry(char* Identifier, unsigned long long Hash) {
        int nowindex = first[Hash % KEY];
        HashTable[head++] = Hash % KEY;
        while(a[nowindex].next != 0) nowindex = a[nowindex].next;
        if (first[Hash % KEY] == 0) {
            first[Hash % KEY] = ++e;
            a[e].next = 0;
        }
        else
            a[nowindex].next = ++e;
        a[e].Hash = Hash;
        a[e].info = new Information(Identifier);
        return a[e].info;
}

Information*& Hash_Table::operator [] (char * Identifier) {
        unsigned long long Hash = Get_Hash(Identifier);
        for (int i = first[Hash % KEY]; i; i = a[i].next)
            if (a[i].info && a[i].info -> Equ(Identifier))
                return a[i].info;
        return New_Entry(Identifier, Hash);
}

bool Hash_Table::Count(char* Identifier) {
    unsigned long long Hash = Get_Hash(Identifier);
    for (int i = first[Hash % KEY]; i; i = a[i].next)
        if (a[i].info && a[i].info -> Equ(Identifier))
            return true;
    return false;
}

void Hash_Table::printTable() {
    printf("\n+-------------------------------------------------------------------+\n");
      printf("|                            Hash  Table                            |\n");
      printf("+--------------------+----------+----------+------------+-----------+\n");
      printf("|      IDnumber      |   Name   |   Line   |    Time    |   Total   |\n");
      printf("+--------------------+----------+----------+------------+-----------+\n");
    for(int i; i < head; i++){
        for (unsigned long long j = first[HashTable[i]]; j; j = a[j].next){
            // cout << a[j].info->Identifier << a[j].info->name << a[j].info->line << a[j].info->time << a[j].info->TotalMileage << endl;
            printf("|%19s | %10s  |%10d|%12s|%11d|\n", a[j].info->Identifier, a[j].info->name, a[j].info->line, a[j].info->time, a[j].info->TotalMileage);
            printf("+--------------------+----------+----------+------------+-----------+\n");

        }
    }
}