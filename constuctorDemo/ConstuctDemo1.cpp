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
        cout<<"�����޲ι��캯��"<<endl;
    }
    person(string pName,string pAddress):name(pName),address(pAddress){
        pChar = new char('a');
    }
    person(const person &p){
        cout<<"���ÿ������캯��"<<endl;
        this->name = p.name;
        this->address = p.address;
    }
    person& operator=(const person &s){
        cout<<"���ø�ֵ�����"<<endl;
        this->name = s.name;
        this->address = s.address;
        return *this;
    }
    person(person && p){
        cout<<"�����ƶ����캯��"<<endl;
        this->name = p.name;
        this->address = p.address;
        // ������д���ָ�����,��pChar;���������Ĵ���
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

