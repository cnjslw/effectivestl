#include <iostream>
#include <set>
#include <typeinfo>
#include <utility>
using namespace std;

struct setless {
    template <typename T>
    // V1
    // bool operator()(T a, T b) const { return a < b; }
    /*output:
        8
        10
        13
        17
        19
        20
        -----------------------
        10
    */

    // V2
    bool operator()(T a, T b) const
    {
        return a <= b;
    }
    /*output:
        8
        10
        10
        13
        17
        19
        20
        -----------------------
    */
};

int main()
{
    set<int, setless> iset;
    iset.insert(10);
    iset.insert(10);
    iset.insert(8);
    iset.insert(13);
    iset.insert(19);
    iset.insert(20);
    iset.insert(17);

    for (auto& i : iset) {
        cout << i << endl;
    }

    cout << "-----------------------" << endl;
    auto pairset = iset.equal_range(10);

    for (auto it = pairset.first; it != pairset.second; it++) {
        cout << *it << endl;
    }

    return 0;
}