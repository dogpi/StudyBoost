#include <iostream>
#include <boost/algorithm/cxx11/copy_if.hpp>
#include <vector>


using namespace std;
using namespace boost::algorithm;

bool lessThan10(int i) { return i < 10; }
bool greatThan10(int i){ return i > 10; }
bool isOdd(int i) { return i % 2 == 1; }

int main()
{
	std::vector<int> c = { 0, 1, 12, 2, 3, 14, 5, 15 };
	std::vector<int> c_true(10);


	std::vector<int>::iterator it = copy_if(c.begin(),c.end(), c_true.begin(), lessThan10);

	cout << "c: ";
	for each (auto ele in c)
	{
		cout << ele << " ";
	}
	cout << endl;

	cout << "if lessThan10\t: ";
	for (vector<int>::iterator _it = c_true.begin(); _it !=it; ++_it)
	{
		cout << *_it << " ";
	}
	cout << endl;

	// 遇到不满足条件的元素，停止。
	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> pair_1 = copy_while(c.begin(), c.end(), c_true.begin(), lessThan10);
	cout << "while lessThan10: ";
	for (vector<int>::iterator _it = c_true.begin(); _it != pair_1.second; ++_it)
	{
		cout << *_it << " ";
	}
	cout << endl;
	
	
	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> pair_2 = copy_until(c.begin(), c.end(), c_true.begin(), isOdd);
	cout << "until isODD\t: ";
	for (vector<int>::iterator _it = c_true.begin(); _it != pair_2.second; ++_it)
	{
		cout << *_it << " ";
	}
	cout << endl;
	
	// 遇到满足条件的元素立即停止，否则保存元素
	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> pair_3 = copy_until(c.begin(), c.end(), c_true.begin(), greatThan10);
	cout << "until greatThan10: ";
	for (vector<int>::iterator _it = c_true.begin(); _it != pair_3.second; ++_it)
	{
		cout << *_it << " ";
	}
	cout << endl;
	
	system("pause");
	return 0;
}