#include <string>
#include <iostream>
#include <list>
#include <boost/foreach.hpp>

int main()
{
	std::string hello("Hello, world!");

	BOOST_FOREACH(char ch, hello)
	{
		std::cout << ch;
		ch = '1';
	}
	std::cout << std::endl;
	std::cout << hello.c_str() << std::endl;	// Hello, world!

	BOOST_FOREACH(char &ch, hello)
	{
		ch = '1';
	}
	std::cout << std::endl;
	std::cout << hello.c_str() << std::endl;	// 1111111111111


	std::list<int> list_int = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	BOOST_FOREACH(int i, list_int)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	// foreach ��Ϊ��ֱ��ȡ�������е�Ԫ�أ�����ʹ�����ö����޸ģ�û��Ҫ����ʹ�õ�������
	//BOOST_FOREACH(std::list<int>::iterator i, list_int)
	//{
	//	std::cout << *i << " ";
	//}
	//std::cout << std::endl;


	system("pause");
	return 0;
}