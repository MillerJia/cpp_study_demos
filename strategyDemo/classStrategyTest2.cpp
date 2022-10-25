#include <iostream>
#include <tr1/functional>

using namespace std;

/**
 * 主体目的，实现更通用版的基于设计模式 设计的类
 * 例子来源于effective c++ 35条
 **/
class GameCharacter;
class HealthCal
{
public:
    virtual int calHealth(const GameCharacter &gc) = 0; // 纯虚函数声明
};

// 前向声明

class GameCharacter
{
public:
    explicit GameCharacter(HealthCal* healthCal)
    {
        pHealthCal = healthCal;
    }
    int getHealthVal() const
    {
        return healthVal;
    }
    int calHealth()
    {
        return pHealthCal->calHealth(*this);
    }
private:
    int healthVal=100;
    HealthCal* pHealthCal;
};



class HealthLossQuick : public HealthCal
{
public:
    int calHealth(const GameCharacter &gc)
    {
        return gc.getHealthVal() / 30;
    }
};

class HealthLossSlow : public HealthCal
{
public:
    int calHealth(const GameCharacter &gc)
    {
        return gc.getHealthVal() / 20 + 1;
    }
};

class HealthLossDefault : public HealthCal
{
public:
    int calHealth(const GameCharacter &gc)
    {
        // 显示调用基类的纯虚函数实现
        return HealthCal::calHealth(gc); 
    }
};

// 包含纯虚函数的基类 也可以包含纯虚函数的实现
int HealthCal::calHealth(const GameCharacter& gc)
{
    return gc.getHealthVal() / 25;
}



int main()
{
    HealthCal* healthcal1 = new HealthLossQuick();
    GameCharacter gc(healthcal1);
    cout << gc.calHealth()<<endl; // 3
    delete healthcal1;
    healthcal1 = new HealthLossSlow();
    cout << gc.calHealth()<<endl; // 6
    delete healthcal1;
    healthcal1 = new HealthLossDefault();
    cout << gc.calHealth()<<endl; // 4
}