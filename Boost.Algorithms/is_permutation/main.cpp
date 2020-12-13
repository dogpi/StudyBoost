#include <iostream>
#include <vector>
#include <boost/algorithm/cxx11/is_permutation.hpp>



int main()
{
	std::vector<int> c1 = { 0, 1, 2, 3, 14, 3, 15 };	
	std::vector<int> c2 = { 15, 14, 3, 1, 3, 2 };
	//	判断两个容器中的数据是否相同
	std::cout << boost::algorithm::is_permutation<std::vector<int>::iterator, std::vector<int>::iterator>(c1.begin()+1, c1.end(), c2.begin()) << std::endl;		// true
	//cout << boost::algorithm::is_permutation(c1.begin() + 1, c1.end(), c2.begin(), c2.end()) << endl;
	system("pause");
	return 0;
}