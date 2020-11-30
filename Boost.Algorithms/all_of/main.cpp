#include <iostream>
#include <boost/algorithm/cxx11/all_of.hpp>
#include <vector>
bool isOdd(int i)
{
	return i % 2 == 1;
}

bool lessThan10(int i)
{
	return i < 10;
}

/*
all_of/all_of_equal：容器内所有数据都满足条件才返回true，否则返回false。
*/

using std::cout;
using std::endl;
using namespace boost::algorithm;
int main()
{
	std::vector<int> c = { 0, 1, 2, 3, 14, 15 };
	
	cout<<all_of(c, isOdd)<<endl;									// false
	cout << all_of(c.begin(), c.end(), lessThan10) << endl;			// false
	cout << all_of(c.begin(), c.begin() + 4, lessThan10) << endl;	// ture 左闭右开，不包括第二个迭代器指向的元素
	cout << all_of(c.end(), c.end(), isOdd) << endl;				// true  empty range
	
	cout << all_of_equal(c, 3) << endl;								// false
	cout << all_of_equal(c.begin() + 3, c.begin() + 4, 3) << endl;	// true
	cout << all_of_equal(c.begin(), c.begin(), 99) << endl;			// true empty range


	system("pause");
	return 0;
}