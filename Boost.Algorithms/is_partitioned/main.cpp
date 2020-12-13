#include <iostream>
#include <boost/algorithm/cxx11/is_partitioned.hpp>
#include <vector>

using namespace std;
using namespace boost::algorithm;


bool isOdd(int i){ return i % 2 == 1; }
bool lessThan10(int i){ return i < 10; }

int main()
{
	std::vector<int> c = { 0, 1, 2, 3, 14, 15 };
	std::vector<int> c1 = { 1, 3, 5, 7, 12, 16 };
	std::vector<int> c2 = { 12, 1,1, 3, 5, 7 };
	std::vector<int> c3 = { 14, 15, 0, 1, 2, 3 };

	// ����������ݰ�ν�ʱ���Ϊ�����֣�ǰ��������ȫ������ν�ʣ��󲿷�����ȫ��������ν�ʣ��򷵻�true�����򷵻�false��
	cout << is_partitioned(c.begin(), c.end(), lessThan10) << endl;		// true
	cout << is_partitioned(c3.begin(), c3.end(), lessThan10) << endl;		// false
	cout << is_partitioned(c1.begin(), c1.end(), isOdd) << endl;		// true
	cout << is_partitioned(c2.begin(), c2.end(), isOdd) << endl;		// false

	system("pause");
	return 0;
}
