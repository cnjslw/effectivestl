#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <vector>
using namespace std;

void print_container(auto begin, auto end) // C++20
{
    for (auto i = begin; i != end; i++) {
        cout << *i << " ";
    }
    cout << endl;
}
int main(int argc, char const* argv[])
{
    vector<int> ivec { 1, 4, 7, 4, 8, 9, 4 };
    list<int> il { 1, 4, 7, 4, 8, 9, 4 };
    map<int, int> imap { { 1, 1 }, { 2, 4 }, { 3, 7 }, { 4, 4 }, { 5, 8 }, { 6, 9 }, { 7, 4 } };

    cout << "----------Before remove-----------" << endl;
    cout << "vector.size()" << ivec.size() << endl;
    cout << "il.size()" << il.size() << endl;
    cout << "map.size()" << imap.size() << endl;

    cout << "----------After  remove-----------" << endl;
    remove(ivec.begin(), ivec.end(), 4);
    cout << "vector.size()" << ivec.size() << endl;
    print_container(ivec.begin(), ivec.end());
    il.remove(4);
    cout << "list.size()" << il.size() << endl;
    print_container(il.begin(), il.end());

    return 0;
}