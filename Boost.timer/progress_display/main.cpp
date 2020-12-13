#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <boost/progress.hpp>

using namespace std;
using namespace boost;

/*
	progress_display��һ���������࣬��timer���е������������-timer��progress_timerû���κ�������

	ע�� ����ڴ�ӡ�������Ĺ����д�ӡ�����������ҽ���������ʾ
		һ�����ܵ����������İ취��ÿ����ʾ������ʱ������restart()������ʾ�������̶ȣ�Ȼ����operator+=��ָ����ǰ���ȡ�

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