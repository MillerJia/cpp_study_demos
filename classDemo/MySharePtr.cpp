#include <iostream>

template<class T>
class MySharePtr
{
public:
    MySharePtr<T>(T data) {
        data_ = new T(data);
        ref_count_ = new int(1);
    }
    ~MySharePtr(){
        (*ref_count_)--;
        if((*ref_count_) == 0) {
            std::cout<<"delete resource" << std::endl;
            delete data_;
            data_ = nullptr;
        }
    }
    MySharePtr(const MySharePtr& pt2) {
        data_ = &(pt2.get());
        ref_count_ = pt2.ref_count_;
        (*ref_count_)++;
        std::cout<<"copy construct" << std::endl;
    }
    MySharePtr& operator=(const MySharePtr& pt2) {
        (*ref_count_)--;
        if((*ref_count_) == 0) {
            std::cout<<"delete resource" << std::endl;
            delete data_;
            data_ = nullptr;
        }
        data_ = &(pt2.get());
        ref_count_ = pt2.ref_count_;
        (*ref_count_)++;
        std::cout<<"operator = " << std::endl;
        return *this;
    }
    int refCount(){return (*ref_count_);}
    int* pRefCount(){return ref_count_;}
    T& get() const {return (*data_);}
private:
    T* data_;
    int *ref_count_;
};

int main()
{
    MySharePtr<int> pt1(3);
    MySharePtr<int> pt2(pt1);
    MySharePtr<int> pt3(4);
    std::cout << pt1.refCount() << std::endl;
    pt3 = pt1;
    std::cout << pt1.refCount() << std::endl;
}