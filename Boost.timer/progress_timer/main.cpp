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
	}	// progress_timer �������������Զ����ʱ��

	{
		progress_timer t;
		int i = 10000;
		int j = 0;
		while (i--){ j = i; };
	}

	stringstream ss;
	{
		progress_timer t(ss);		// Ҫ��progress_timer�����ss��
	}		
	cout << ss.str();

	system("pause");
	return 0;
}
