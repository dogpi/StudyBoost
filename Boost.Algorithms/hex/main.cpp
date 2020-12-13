#include <iostream>
#include <vector>
#include <boost/algorithm/hex.hpp>

using namespace boost::algorithm;

int main()
{
	std::vector<char> vec_hex(20);	
	
	hex("abcdef", vec_hex.begin());//616263646566
	for (std::vector<char>::iterator i = vec_hex.begin(); i != vec_hex.end(); ++i)
	{
		std::cout << (*i);
	}
	std::cout << std::endl;


	int x = 0;
	std::cout << "char\t" << "hex" << std::endl;
	std::cout << "*************" << std::endl;
	x = 'a';
	std::cout << "a\t0x"<<std::hex << x << std::endl;
	x = 'b';
	std::cout << "b\t0x"<<std::hex << x << std::endl;
	x = 'c';
	std::cout << "c\t0x"<<std::hex << x << std::endl;
	x = 'd';
	std::cout << "d\t0x"<<std::hex << x << std::endl;
	x = 'e';
	std::cout << "e\t0x"<<std::hex << x << std::endl;
	x = 'f';
	std::cout << "f\t0x"<<std::hex << x << std::endl;




	system("pause");
	return 0;
}