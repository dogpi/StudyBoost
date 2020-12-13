#include <iostream>
#include <vector>
#include <boost/algorithm/cxx11/copy_n.hpp>
#include <iomanip>
#include <cstring>

using namespace std;
using namespace boost::algorithm;

int main()
{

	vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	vector<int> v2(10);

	vector<int>::iterator it = boost::algorithm::copy_n(v1.begin(), 3, v2.begin());

	for (vector<int>::iterator _it = v2.begin(); _it != it; _it++){
		cout << *_it << " ";
	}
	cout << endl;


	string str1 = "Hello World!";
	string str2(20,'\0');
	char c_str1[] = "Hello World!";
	cout << sizeof(c_str1) << endl;
	cout << strlen(c_str1) << endl;
	cout << str1.length() << endl;

	char *c_str2 = "Hello World!";
	char *c_str3 = (char*)malloc(20);
	memset(c_str3,'0x30' ,20);

	strcpy(c_str3, c_str2);			// ¿½±´'\0'
	cout <<"c_str3:" <<c_str3 << endl;	





	string::iterator s_it = boost::algorithm::copy_n(str1.begin(), 12, str2.begin());
	for (string::iterator i = str2.begin(); i != s_it; ++i){
		cout << *i << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}