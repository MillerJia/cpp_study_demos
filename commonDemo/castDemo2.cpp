#include <iostream>

using namespace std;

class A
{
public:
    int a = 3;
    A(){
        
    }
};

int main()
{
    const A obj;
    cout <<obj.a<<endl;
    
    A& obj2 =  const_cast<A&>(obj); // const_cast一般不是用于更改const对象的，虽然它可以修改
    // 它一般用于，当需要调用别人的函数时，如果别人的函数类型不是const，你可以对自己的对象去掉cosnt属性再调用
    obj2.a = 5;
    cout <<obj.a<<endl;

    const int b = 5;
    const int *c = &b;
    int *d = (int*)c;
    *d= 10;
    cout << &b <<","<<c<<","<<d;
    
}