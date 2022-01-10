#include <iostream>
#include <functional>

using namespace std;

/**
 * 主体目的：学习类中持有函数指针的方法，并可以在构造时传入不同的实现方法，从而实现strategy设计模式
 * 该例子来源于 effective c++ 第35条
 **/
class GameCharacter;

int DefaultCalHealth(const GameCharacter& gc); 

// C++ 使用任何类型或者函数前 都要求声明  所以得先声明

class GameCharacter
{
public:
    typedef int(* FuncCalHealth)(const GameCharacter& gc);

    // 可以看到这里 可以传给对象 不同的计算血量的方式
    GameCharacter(FuncCalHealth fn = DefaultCalHealth):mFuncCalHealth(fn){}
    int getHealthVal() const 
    {
        return mHealthVal;
    }
    int getCalHealth()
    {
      return mFuncCalHealth(*this);
    }
    ~GameCharacter(){}
private:
    int mHealthVal=100;
    FuncCalHealth mFuncCalHealth;
  //  function<int(const GameCharacter& gc)> mFuncCalHealth; // 也可以用function 定义函数指针
};

int DefaultCalHealth(const GameCharacter& gc)
{
    return gc.getHealthVal() / 25; // 根据血量计算血条  0~100 -> 0~4
}

int newCalHealth(const GameCharacter& gc)
{
  return gc.getHealthVal() / 30; 
}


int main()
{
    GameCharacter gc1;
    cout<<"默认计算方式"<<endl;
    cout << gc1.getCalHealth()<<endl;
    cout<<"自定义计算方式"<<endl;
    GameCharacter gc2(newCalHealth);
    cout << gc2.getCalHealth();
}


