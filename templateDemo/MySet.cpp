#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

/**
 *  主体目的：学习根据stl模板类，自定义一个模板类。
 *  例子来源于 effective c++ 38条 ，同时学习 has-a 和 is-implemented-in-terms-of的区别
 *  前者描述的A对象包含B对象，来源于应用（现实）中的关系，更坚固,例如位置可以用类表示，人和位置就是has-a的关系
 *  后者是实现A时需要用到B的关系，描述的是实现的关系（此时B也可以换成C或者D)
 **/

template<class T>
class MySet
{
public:
    bool member(const T& item) const; // 包含item返回true 否则返回false
    void insert(const T& item); // 插入
    void remove(const T& item); // 删除
    std::size_t size() const; // 长度
private:
    std::list<T> data; // 数据,因为你在实现MySet时并不一定非得用list存放，所以这种类之间的关系就时is-implemented....
};

template<class T>
bool MySet<T>::member(const T& item) const
{
    return std::find(data.begin(),data.end(),item)!=data.end();
}

template<class T>
void MySet<T>::insert(const T& item)
{
    if(!member(item))
    {
        data.push_back(item);
    }
}

template<class T>
std::size_t MySet<T>::size() const
{
    return data.size();
}

template<class T>
void MySet<T>::remove(const T&item)
{
    if(member(item))
    {
        data.remove(item);
    }
}

int main()
{
    MySet<int> myset;
    cout << myset.size()<<endl; // 0
    myset.insert(4);
    cout << myset.size()<<endl; // 1
    myset.insert(3);
    myset.remove(2);
    myset.insert(3);
    cout<<myset.size()<<endl; // 2
    myset.remove(3);
    cout<<myset.size()<<endl; // 1
}