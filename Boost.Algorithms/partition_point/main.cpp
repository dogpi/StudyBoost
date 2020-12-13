#include <iostream>
#include <vector>
#include <boost/algorithm/cxx11/partition_point.hpp>

using namespace std;
using namespace boost::algorithm;

bool lessThan10(int i) { return i < 10; }
bool greatThan10(int i){ return i > 10; }
bool isOdd(int i) { return i % 2 == 1; }

int main()
{
	std::vector<int> c = { 0, 1, 12,2, 3, 14,5, 15 };

	// ����һ�����ֵ����к�һ��ν�ʣ����㷨�ҵ����ֵ㡣�������е����һ������ν�ʵ�Ԫ�ص���һ��Ԫ�ء�
	vector<int>::iterator it1 = partition_point(c, lessThan10);
	if (it1 != c.end()){
		cout << *it1 << endl;
	}
	else
	{
		cout << "it1.end()" << endl;
	}
	vector<int>::iterator it2 = partition_point(c, greatThan10);
	if (it2 != c.end()){
		cout << *it2 << endl;
	}
	else
	{
		cout << "it2.end()" << endl;
	}

	system("pause");
	return 0;
}