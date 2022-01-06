#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

const int KEY = 76543;
const int P = 107;
struct Information {
    char *Identifier; // 该符号名
    char *name;  // 符号对应的类型
    int line;        // 该符号对应的值
    char *time;        // 该符号对应的值
    int TotalMileage;  // 定义所在的行号

    Information(char *);
    ~Information();
    bool Equ(char*);
};

struct Entry{
    unsigned long long Hash;
    Information *info;
    int next;
    Entry();
    ~Entry();
};


class Hash_Table {
public:
    int first[KEY], e;
    unsigned long long Get_Hash(char*);
    Information*& New_Entry(char*, unsigned long long);
    Information*& operator [] (char *);
    bool Count(char*);
    void printTable();
};
#endif