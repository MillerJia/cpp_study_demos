#include <iostream>
#include <functional>

/**
 *  主体目的：实现通过bind调用类对象的函数，比如有时候希望在类B完成某个功能后回调类A的方法。
 */ 

class FuncProviderUtils
{
public:
    int doPlus(int a,int b)
    {
         // 实际在乘法或者加法时考虑溢出 这里不管..
        return a+b;
    }
    void printMul(int a,int b);
};

void FuncProviderUtils::printMul(int value1,int value2)
{
    std::cout<<value1<<"*"<<value2<<"="<<value1*value2<<std::endl;
}

int main()
{
   
    FuncProviderUtils object;
    // 第一个参数是可以调用的方法，需要取&，根据类找到函数存放的位置，成员函数本身属于类共有
    // 第二个参数是对象，对象取地址后相当于类的this指针，需要通过对象才能调用成员函数
    // 其他参数，属于占位符，比如这里使用了俩个占位符，分别代表调用时替代类成员函数的第一个和第二个参数，也可以只使用一部分占位符,其他的用默认即可                   
    auto doPlusFunc =  std::bind(&FuncProviderUtils::doPlus,&object,std::placeholders::_1,std::placeholders::_2);
    auto doPlusFuncVar1 = std::bind(&FuncProviderUtils::doPlus,&object,std::placeholders::_1,std::placeholders::_3);
    auto doMulSwap = std::bind(&FuncProviderUtils::printMul,&object,std::placeholders::_2,std::placeholders::_1);
    auto doMulWithOneFix = std::bind(&FuncProviderUtils::printMul,&object,std::placeholders::_2,5);

    std::cout<<"normal version"<<std::endl;
    std::cout << doPlusFunc(1,2)<<std::endl; // 1 + 2 = 3

    std::cout<<"changed version1: use placeholders change input value"<<std::endl;
    std::cout<<doPlusFuncVar1(1,2,3)<<std::endl; // 1 + 3 = 4

    std::cout<<"changed version2: use placeholders change input order"<<std::endl;
    doMulSwap(3,4);  // 4 * 3 = 12

    std::cout<<"changed version3: use default value replace placeholders"<<std::endl;
    doMulWithOneFix(1,4); // 4 * 5 = 20
}



// reference
// https://zhuanlan.zhihu.com/p/77918754
// https://blog.csdn.net/qq_38410730/article/details/103637778
