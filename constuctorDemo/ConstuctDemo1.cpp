#include <iostream>
#include <string>

using namespace std;

class person
{
public:
    string name;
    string address;
    char *pChar;
    person(){
        cout<<"调用无参构造函数"<<endl;
    }
    person(string pName,string pAddress):name(pName),address(pAddress){
        pChar = new char('a');
    }
    person(const person &p){
        cout<<"调用拷贝构造函数"<<endl;
        this->name = p.name;
        this->address = p.address;
    }
    person& operator=(const person &s){
        cout<<"调用赋值运算符"<<endl;
        this->name = s.name;
        this->address = s.address;
        return *this;
    }
    person(person && p){
        cout<<"调用移动构造函数"<<endl;
        this->name = p.name;
        this->address = p.address;
        // 如果类中存在指针变量,如pChar;则加入下面的代码
        this->pChar = p.pChar;
        p.pChar = nullptr;
    }
    void showInfo()
    {
        cout <<"name="<<name<<",address="<<address<<"pAddress"<<(void *)pChar<<endl;
    }
};

person createPerson(){
    person p("1","2");
    p.showInfo();
    return p;
}

int main()
{
    person s4(move(createPerson()));
    s4.showInfo();
}

