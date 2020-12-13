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

timer 使用到了标准库头文件<ctime>里的std::clock()函数，它返回自程序启动以来的clock数，每秒的clock数则由宏CLOCKS_PER_SEC定义。
CLOCKS_PER_SEC的值因操作系统而不同，再macOS、Linux下是1000 000，而在Windows下则是1000，也就是说macOS、Linux下的精度是微妙，而在Windows下的精度是毫秒。

注：timer接口简单。轻巧好用，适用于大部分要求不高的程序计时任务。
	timer不适合高精度的时间测量任务，它的精度依赖于操作系统或编译器，难以做到跨平台。
	timer不适合大跨度时间段的测量，如果需要以天、月甚至年作为时间的单位则不能使用timer，应使用cpu_timer组件。
*/
int main()
{

	timer t;

	cout << "max time span:" << t.elapsed_max() / 60 / 60 << "h" << endl;	// timer 能够测量的最大时间范围
	cout << "min time span:" << t.elapsed_min() << "s" << endl;				// timer 能够测量的最小精度
	cout << "now time elapsed:" << t.elapsed() << "s" << endl;				// timer 对象创建后流逝的时间


	system("pause");
	return 0;
}
