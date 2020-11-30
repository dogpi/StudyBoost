#include <iostream>
#include <boost/algorithm/cxx11/any_of.hpp>
#include <vector>

using namespace boost::algorithm;
using std::cout;
using std::endl;

bool isOdd(int i)
{
	return i % 2 == 1;
}

bool lessThan10(int i)
{
	return i < 10;
}

/*
	容器中存在满足条件的值就返回true，否则返回false。
*/

int main()
{
	std::vector<int> c = { 0, 1, 2, 3, 14, 15 };

	cout<<any_of(c, isOdd)<<endl;	// true
	cout << any_of(c.begin(), c.end(), lessThan10) << endl;;	// ture
	cout << any_of(c.begin() + 4, c.end(), lessThan10) << endl;	// false
	cout << any_of(c.end(), c.end(), isOdd) << endl;			// false

	cout << any_of_equal(c, 3) << endl;							// true
	cout << any_of_equal(c.begin(), c.begin() + 3, 3) << endl;	// false
	cout << any_of_equal(c.begin(), c.begin(), 99) << endl;		// false empty range

	system("pause");
	return 0;
}