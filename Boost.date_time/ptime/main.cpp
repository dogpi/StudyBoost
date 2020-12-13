#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>			// 日期组件
#include <boost/date_time/posix_time/posix_time.hpp>		// 时间组件


using namespace std;
using namespace boost::gregorian;
using namespace boost::posix_time;


/*
	ptime时date_time库处理时间的核心类，它使用64位（微秒级别）或者96位（纳秒级别）的整数在内部存储时间数据，依赖于date和time_duration，因此接口很小。
*/

int main()
{
	// 创建时间点
	ptime p(date(2017, 7, 7), hours(1));	// 2017-7-7 01:00:00  2017年7月7日 凌晨1点

	ptime p1 = time_from_string("2017-7-7 01:00:00");
	ptime p2 = from_iso_string("20170707T010000");

	// date_time库为ptime提供了时钟类，可以从始终产生当前时间。
	// 因为时钟具有不同的分辨率，所以有两个类second_clock和microsec_clock分别提供秒级和微秒级的分辨率，它们的接口时相同的。
	// local_time()获取本地时间，universal_time()获得UTC当前时间。
	ptime p3 = second_clock::local_time();			// 秒精度
	ptime p4 = microsec_clock::local_time();		// 微秒精度
	cout << p3 << endl << p4 << endl;
	cout << to_simple_string(p3) << endl << to_simple_string(p4) << endl;
	cout << to_iso_string(p3) << endl << to_iso_string(p4) << endl;
	cout << to_iso_extended_string(p3) << endl << to_iso_extended_string(p4) << endl;

	assert(p3 > p2);

	// 转为C结构体
	tm t_time = to_tm(p);
	assert(t_time.tm_year == 2017 - 1900 && t_time.tm_hour == 1);
	assert(ptime_from_tm(t_time) == p);

	// 函数from_time_t()和to_time_t()可以在time_t和p_time之间相互转换
	ptime p5 = from_time_t(std::time(0));
	cout << "****************8" << endl;
	cout << to_iso_extended_string(p5) << endl;
	assert(p5.date() == day_clock::local_day());
	cout << to_time_t(p5) << endl;		// 从1900-1-1 0:0:0 到现在的秒数 time_t
	system("pause");
	return 0;
}