#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <boost/progress.hpp>

using namespace std;
using namespace boost;

/*
	progress_display是一个独立的类，与timer库中的其他两个组件-timer和progress_timer没有任何来呢西

	注： 如果在打印进度条的过程中打印其他输出会打乱进度条的显示
		一个可能单并非完美的办法是每次显示进度条时都调用restart()重新显示进度条刻度，然后用operator+=来指定当前进度。

*/

int main()
{
	vector<string> v(10);
	ofstream fs("./test.txt");
	progress_display pd(v.size());
	for (auto& x : v){
		fs << x << endl;
		Sleep(100);
		++pd;
	}

	progress_display pd1(v.size());
	for (auto& x : v){
		fs << x << endl;
		Sleep(100);
		++pd1;
		cout << "123" << endl;
	}

	progress_display pd2(v.size());
	for (vector<string>::iterator x = v.begin(); x != v.end(); ++x){
		fs << *x << endl;
		Sleep(100);
		pd2.restart(v.size());
		pd2 += (x - v.begin() + 1);
		cout << "123" << endl;
	}

	system("pause");
	return 0;
}