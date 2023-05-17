#include <iostream>
#include <set>
#include <string>
using namespace std;

// V3
struct StringPtrLess : public binary_function<const string*, const string*, bool> {
    bool operator()(const string* ps1, const string* ps2) const { return *ps1 < *ps2; }
};

int main()
{ // V1,V2
    // set<string*> ssp;
    set<string*, StringPtrLess> ssp;
    ssp.insert(new string("Alic"));
    ssp.insert(new string("Wobat"));
    ssp.insert(new string("Lemic"));
    ssp.insert(new string("Italia"));
    ssp.insert(new string("Penguin"));
    for (set<string*>::const_iterator i = ssp.begin(); i != ssp.end(); i++) {
        // V1
        /*cout << *i << endl;*/
        /*output:
            0x55555556ceb0
            0x55555556cf10
            0x55555556cf70
            0x55555556cfd0
            0x55555556d030
        */

        // V2
        /*cout << **i << endl;*/
        /*output:
            Alic
            Wobat
            Lemic
            Italia
            Penguin
            //指针序而非字节序，因为set<string*> == set<string* , less<string*>,allocator<string*>> ssp;
        */

        // V3
        cout << **i << endl;
        /*
        Alic
        Italia
        Lemic
        Penguin
        Wobat
        */
    }

    return 0;
}