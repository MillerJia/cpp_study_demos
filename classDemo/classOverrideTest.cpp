#include <iostream>
#include <stdio.h>

using namespace std;

/**
 * 主体目的：温习virtual虚函数和non-virtual函数在继承时的区别
 * 按照 effective C++ 中所说，如果一个类能够被继承，那么如果函数需要由派生类实现并且可以保留
 * 默认实现，那么就用virtual，否则，如果所有的派生类不修改实现，那就使用non-virtual
 **/

class Base
{
public:
    void show()
    {
        cout <<"Base show"<<endl;
    }
    virtual void vshow()
    {
        cout <<"Base virtual show"<<endl;;
    }
};

class Derive : public Base
{
public:
    void show()
    {
        cout << "Derive show"<<endl;
    } 
    virtual void vshow()
    {
        cout <<"Derive virtual show"<<endl;;
    }
};


int main()
{
    Base * base = new Derive();
    base->show(); // Base show
   // cout << &Base::show<<endl; // 1;  cout 没有对该输出类型重载，而是转化为bool类型
    printf("Base::show的地址%p\n",Base::show); // Base::show的地址000000000061fde0
    printf("Derive::show的地址%p\n",Derive::show); // Derive::show的地址000000000061fdd0

    Base * vbase = new Derive(); // Derive virtual show
    vbase->vshow();
    printf("Base::vshow的地址%p\n",Base::vshow);   // 和上面输出都一样.. 以后研究下为啥函数不同 输出的都一样
    printf("Derive::vshow的地址%p\n",Derive::vshow); 

    // typedef void (*pf)(Base &b);
    // pf fn = **(pf**)(base);
    // fn(*base);
    return 0;
}