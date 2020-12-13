#include <iostream>
#include <vector>
#include <boost/algorithm/cxx11/iota.hpp>

using namespace boost::algorithm;

int main()
{
	std::vector<int> c(10);
	// ����һ����������������
	iota(c.begin(), c.end(), 2);
	for each (auto ele in c)
	{
		std::cout << ele << " ";
	}
	std::cout << std::endl;

	std::vector<int> c1(10);
	iota(c1, 10);
	for each (auto ele in c1)
	{
		std::cout << ele << " ";		
	}
	std::cout << std::endl;

	std::vector<int> c2(10);
	std::vector<int>::iterator it = iota_n(c2.begin(), 1, 10);			// ����ֵΪ���һ����ֵԪ�صĵ�����
	for each (auto ele in c2)
	{
		std::cout << ele << " ";
	}
	std::cout << std::endl;

	system("pause");
	return 0;
}