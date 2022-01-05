#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class FindKey
{
private:
    int s_;
public:
    FindKey(int str) :s_(str){}
    bool operator ()(map<string, int>::value_type item)
    {
        return item.second == s_;
    }
};



int main()
{
    map<string, int> t;
    t["cpu_syscall_pid"] = 1;
    t["cpu_syscall_cpu"] = 2;
    t["cpu_syscall_sys"] = 3;
    t["cpu_contxt_pid"] = 4;
    // t.insert(make_pair(1, "cpu_syscall_pid"));

    string n;
    auto it = find_if(t.begin(), t.end(), FindKey(1));
    if (it != t.end())
    {
        cout << (*it).first;
    }

    // cout << "n:" << n << endl;
    return 0;

}