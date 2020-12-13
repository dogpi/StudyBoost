#include <boost/algorithm/cxx11/one_of.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace boost::algorithm;

bool isOdd(int i){ return i % 2 == 1; }
bool lessThan10(int i){ return i < 10; }

int main()
{
	std::vector<int> c = { 0, 1, 2, 3, 14, 15 };
	cout << one_of(c, isOdd) << endl;	// false
	cout << one_of(c.begin(), c.end(), lessThan10) << endl;		// false
	cout << one_of(c.begin() + 3, c.end(), isOdd) << endl;		// false
	cout << one_of(c.end(), c.end(), isOdd) << endl;			// false empty range
	cout << one_of_equal(c, 3) << endl;			// true
	cout << one_of_equal(c.begin(), c.begin() + 3, 3) << endl;	// false
	cout << one_of_equal(c.begin(), c.begin(), 99) << endl;		// false

	system("pause");
	return 0;
}