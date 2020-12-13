#include <iostream>
#include <boost/timer.hpp>

using namespace std;
using namespace boost;
/*
class timer
{
public:
	timer() { _start_time = std::clock(); } // postcondition: elapsed()==0
	//         timer( const timer& src );      // post: elapsed()==src.elapsed()
	//        ~timer(){}
	//  timer& operator=( const timer& src );  // post: elapsed()==src.elapsed()
	void   restart() { _start_time = std::clock(); } // post: elapsed()==0
	double elapsed() const                  // return elapsed time in seconds
	{ return  double(std::clock() - _start_time) / CLOCKS_PER_SEC; }

	double elapsed_max() const   // return estimated maximum value for elapsed()
	// Portability warning: elapsed_max() may return too high a value on systems
	// where std::clock_t overflows or resets at surprising values.
	{
	return (double((std::numeric_limits<std::clock_t>::max)())
	- double(_start_time)) / double(CLOCKS_PER_SEC);
	}

	double elapsed_min() const            // return minimum value for elapsed()
	{ return double(1)/double(CLOCKS_PER_SEC); }

private:
	std::clock_t _start_time;
}; // timer

timer ʹ�õ��˱�׼��ͷ�ļ�<ctime>���std::clock()�������������Գ�������������clock����ÿ���clock�����ɺ�CLOCKS_PER_SEC���塣
CLOCKS_PER_SEC��ֵ�����ϵͳ����ͬ����macOS��Linux����1000 000������Windows������1000��Ҳ����˵macOS��Linux�µľ�����΢�����Windows�µľ����Ǻ��롣

ע��timer�ӿڼ򵥡����ɺ��ã������ڴ󲿷�Ҫ�󲻸ߵĳ����ʱ����
	timer���ʺϸ߾��ȵ�ʱ������������ľ��������ڲ���ϵͳ�������������������ƽ̨��
	timer���ʺϴ���ʱ��εĲ����������Ҫ���졢����������Ϊʱ��ĵ�λ����ʹ��timer��Ӧʹ��cpu_timer�����
*/
int main()
{

	timer t;

	cout << "max time span:" << t.elapsed_max() / 60 / 60 << "h" << endl;	// timer �ܹ����������ʱ�䷶Χ
	cout << "min time span:" << t.elapsed_min() << "s" << endl;				// timer �ܹ���������С����
	cout << "now time elapsed:" << t.elapsed() << "s" << endl;				// timer ���󴴽������ŵ�ʱ��


	system("pause");
	return 0;
}
