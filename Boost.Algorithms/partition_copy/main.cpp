#include <iostream>
#include <vector>
#include <boost/algorithm/cxx11/partition_copy.hpp>

using namespace std;
using namespace boost::algorithm;

bool lessThan10(int i) { return i < 10; }
bool greatThan10(int i){ return i > 10; }
bool isOdd(int i) { return i % 2 == 1; }

int main()
{
	std::vector<int> c = { 0, 1, 12, 2, 3, 14, 5, 15 };
	std::vector<int> c_true(10);
	std::vector<int> c_false(10);

	// 符合谓词条件的值存入c_true，否则存入c_false。
	std::pair<vector<int>::iterator,vector<int>::iterator> it_pair =  partition_copy(c, c_true.begin(), c_false.begin(), lessThan10);

	cout << "c: ";
	for (vector<int>::iterator it = c.begin(); it != c.end();++it)
	{
		cout << *it << ", ";
	}
	cout << endl;

	cout << "c_true: ";
	for (vector<int>::iterator it = c_true.begin(); it != it_pair.first; ++it)
	{
		cout << *it << ", ";
	}
	cout << endl;

	cout << "c_false: ";
	for (vector<int>::iterator it = c_false.begin(); it != it_pair.second; ++it)
	{
		cout << *it << ", ";
	}
	cout << endl;





	system("pause");
	return 0;
}
