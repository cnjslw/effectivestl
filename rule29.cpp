#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ifstream inputfile("text.txt");
    // v1
    // string filev1((istreambuf_iterator<char>(inputfile)), istreambuf_iterator<char>());
    // v2
    /* 创建了一个 char 类型的输入流迭代器，它可以从 inputfile 流中逐个读取字符。而
    istreambuf_iterator<char>() 创建了一个默认的“结束迭代器”，表示读取完毕*/
    string filev2((istreambuf_iterator<char>(inputfile)), istreambuf_iterator<char>());
    // cout << filev1 << endl;
    cout << "----------------------" << endl;
    cout << filev2 << endl;
    return 0;
}