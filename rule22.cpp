#include <iostream>
#include <set>
#include <typeinfo>
#include <utility>
using namespace std;

int main()
{
    set<int> iset;
    iset.insert(10);
    iset.insert(20);
    set<int>::iterator it = iset.begin();
    const type_info& type = typeid(it);
    cout << type.name() << endl;
    /*output:
        St23_Rb_tree_const_iteratorIiE
    */
    // V1 强制修改
    // int* ptr = const_cast<int*>(&(*it));
    // *ptr = 30;
    // for (auto i : iset)
    //     cout << i << endl;
    // cout << "---------------------" << endl;
    // /*output:
    //     30
    //     20
    //     //已经失序，容器被破坏
    // */
    // V2 无效的修改,见书上代码
    cout << "---------------------" << endl;
    // V3 安全的修改
    // 查找，拷贝，修改拷贝，删除目标元素，插入拷贝后的元素
    auto its = iset.find(10);
    cout << *its << endl;
    iset.erase(*its);
    cout << "-------删除后---------" << endl;
    for (auto i : iset)
        cout << i << endl;
    cout << "-------插入后---------" << endl;
    iset.insert(30);
    for (auto i : iset)
        cout << i << endl;

    return 0;
}