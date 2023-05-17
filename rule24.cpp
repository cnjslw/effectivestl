#include <iostream>
#include <map>
using namespace std;

class Widget {
public:
    Widget(/* args */)
    {
        cout << "Widget()" << endl;
    };
    Widget(double weightvaule)
        : weight(weightvaule)
    {
        cout << "Widget(double)" << endl;
    }
    ~Widget()
    {
        cout << "~Widget()" << endl;
    }

private:
    double weight = 0;
};

// V3 二者兼容的模板
template <typename MapType, typename KeyArgType, typename ValueArgType>
typename MapType::iterator
efficientAddOrUpdate(MapType& m, const KeyArgType& k, const ValueArgType& v)
{
    typename MapType::iterator lb = m.lower_bound(k);

    if (lb != m.end() && !(m.key_comp()(k, lb->first))) {
        lb->second = v;
        return lb;
    } else {
        typedef typename MapType::value_type MVT;
        return m.insert(lb, MVT(k, v));
    }
}

int main()
{
    map<int, Widget> m;
    // v1
    // m[1] = 1.50;
    // 在添加map中没有的键值时，发生了三个步骤
    // 1.查找键为1的对象
    // 2.发现没有键为1的对象，通过Widget的默认构造函数创建新的对象,operator[]返回该对象的引用
    // 3.给返回的对象赋值，1.5
    /*
        output:
        Widget()
        Widget(double)
        ~Widget()
        ~Widget()
        pay attention:要使用fno-elide-constructors fno-elide-constructors关闭编译器中的构造函数省略优化（copy elision）
    */
    // 同等效果
    // typedef map<int, Widget> IntWidgetMap;
    // pair<IntWidgetMap::iterator, bool> result = m.insert(IntWidgetMap::value_type(1, Widget()));
    // result.first->second = 1.50;
    /*
        output:
        Widget()
        ~Widget()
        ~Widget()
        Widget(double)
        ~Widget()
        ~Widget()
    */

    // V2
    // m.insert(IntWidgetMap::value_type(1, 1.5));
    /*
        output:
        Widget(double)
        ~Widget()
        ~Widget()
    */
    efficientAddOrUpdate(m, 2, 1.3);
    /*
    output:
        Widget(double)
        ~Widget()
        ~Widget()
    */
    efficientAddOrUpdate(m, 2, 1.9);
    /*
    output:
        Widget(double)
        ~Widget()
        Widget(double)
        ~Widget()
        ~Widget()
    */
    return 0;
}