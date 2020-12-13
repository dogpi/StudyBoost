#include <iostream>
#include <sstream>
#include <boost/progress.hpp>

using namespace std;
using namespace boost;

int main()
{
	progress_timer t;
	cout << t.elapsed_max() << endl;
	cout << t.elapsed_min() << endl;
	cout << t.elapsed() << endl;

	{
		progress_timer t;
		int i = 100000;
		int j = 0;
		while (i--){ j = i; };
	}	// progress_timer 在这里析构，自动输出时间

	{
		progress_timer t;
		int i = 10000;
		int j = 0;
		while (i--){ j = i; };
	}

	stringstream ss;
	{
		progress_timer t(ss);		// 要求progress_timer输出到ss中
	}		
	cout << ss.str();

	system("pause");
	return 0;
}
