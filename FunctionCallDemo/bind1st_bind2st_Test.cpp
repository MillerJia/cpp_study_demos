#include <functional>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

/*
* 主体目的，学习bind1st和bind2st的使用方法，可以将二元函数转化为一元函数，STL中使用的较多
*/

bool isBiggerEven(int lowwerBound,int val)
{
	return (!(val & 1)) && val > lowwerBound;
}

struct isBiggerEvenStruct
{
	int lowwerBound;
	
	explicit isBiggerEvenStruct(int val):lowwerBound(val){}
	bool operator() (int val) {
		return (!(val & 1)) && val > lowwerBound;
	}
	
};


int main()
{
	std::vector<int> datas{ 1,2,4,5,8,120,79 };
	std::vector<int> datas2{ 1,2,4,5,8,120,79 };
	// 删除datas中，小于10的数字
	// remove_if 会将容器中满足条件的元素移除，将不满足条件的元素保留。在实现时会将保留的元素覆盖放在容器的前面
	// 而并没有删除后面的元素，所以需要调用erase指定删除的区间
	//std::remove_if(datas.begin(), datas.end(), std::bind2nd(std::less<int>(),10)); // 容器中是 120 79 4 5 8 120 79
	std::vector<int> datas3{ 4,5,6,7,8,100 };
	std::vector<int> desVec;

	// 删除掉datas容器中val < 10的元素,bind2nd的作用是将原本需要俩个参数的less函数的第二个入参绑定为10，另一个参数从容器进入
	datas.erase(std::remove_if(datas.begin(), datas.end(), std::bind2nd(std::less<int>(), 10)), datas.end());
	std::copy(datas.begin(), datas.end(), std::ostream_iterator<int>(std::cout, " ")); // 120 79
	std::cout << std::endl;

	// 删除掉datas2容器中10 > val的元素,bind1st的作用是将原本需要俩个参数的less函数的第一个入参绑定为10，另一个参数从容器进入
	datas2.erase(std::remove_if(datas2.begin(), datas2.end(), std::bind1st(std::less<int>(), 10)), datas2.end());
	std::copy(datas2.begin(), datas2.end(), std::ostream_iterator<int>(std::cout, " ")); // 1 2 4 5 8
	std::cout << std::endl;

	// 将data3容器中的大于指定数字的偶数复制到desVec中
	// 方法1 借助bind，bind可以绑定普通函数、函数对象、成员函数等..
	// std::copy_if(datas3.begin(), datas3.end(), std::back_inserter(desVec), std::bind(isBiggerEven, 6, std::placeholders::_1));
	// 方法2 直接使用结构体对象就可以，将一个参数通过构造的方式放入结构体对象中，重载()操作符
	std::copy_if(datas3.begin(), datas3.end(), std::back_inserter(desVec),isBiggerEvenStruct(6));
	std::copy(desVec.begin(), desVec.end(), std::ostream_iterator<int>(std::cout, " ")); // 8 100

}