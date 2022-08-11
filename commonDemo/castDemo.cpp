/**
 * @file castDemo.cpp
 * @author jcy
 * @brief 学习各种转化
 * @version 0.1
 * @date 2022-04-16
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>

using namespace std;

class Base
{
public:
    int baseInt;
    virtual void func()
    {
        cout << "base virtual func()" << endl;
    }
};

class Derive : public Base
{
public:
    void func()
    {
        cout << "Derive func()" << endl;
    }
    void func2()
    {
        cout << "func2" << endl;
    }
};

class Derive2 : public Base
{
public:
    int value = 3;
    void func3()
    {
        cout << "func3" << endl;
    }
};

int main()
{
    Base *base = new Derive();
    Base *base2 = new Base();
    // dynamic_cast适用于向下转型，它会检查指针指向的对象类型是否合法 
    // dynamic_cast转化时需要进行类型检查，会利用到虚函数表，因而基类必须包含虚函数，否则会报错
    Derive *d = dynamic_cast<Derive *>(base);
    if (d)
    {
        d->func2();
    }
    // 这里因为base2指向的对象类型是Base，无法转化为Derive2*类型的对象，所以返回nullptr
    Derive2 *d2 = dynamic_cast<Derive2 *>(base2);
    if (d2)
    {
        d2->func3();
    }

    // static_cast 相比较 dynamic_cast没有类型检查，不要求类中必须包含虚函数，但是可能转化失败导致出错
    Derive2* d3 = static_cast<Derive2*>(base2);
    cout<<d3->value<<endl;

}