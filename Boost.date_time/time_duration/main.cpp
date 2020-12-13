#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>			// 日期组件
#include <boost/date_time/posix_time/posix_time.hpp>		// 时间组件


using namespace std;
using namespace boost::gregorian;
using namespace boost::posix_time;

/*
	time_duration可以在构造函数指定时分秒和微秒来构造
*/

int main()
{
	// 1小时10分钟30秒1毫秒（1000微妙）的时间长度
	time_duration t1(1, 10, 30, 1000);
	// 时 分秒等值可以时任意的数量，不一定必须在它们的限度内，超出的时间会自动进位或借位。
	// 2小时1分6.001秒
	//               1小时60分60秒6001000微妙=2小时1分6.001秒
	time_duration t2(1, 60, 60, 1000 * 1000 * 6 + 1000);

	// 使用time_duration的子类可以更直观地创建时间长度
	hours h(1);			// 1小时
	minutes m(10);		// 10分钟
	seconds s(30);		// 30秒
	milliseconds ms(1);	// 1微秒

	time_duration t3 = h + m + s + ms;
	time_duration t4 = hours(2) + seconds(10);

	time_duration t5 = duration_from_string("1:10:30:001");
	// time_duration t5 = duration_from_string("1:10:30:1");	// exception
	assert(t3 == t5);

	// time_duration里的时分秒可以用hours()、minutes()和seconds()成员函数访问。
	// total_seconds()】total_milliseconds()和total_microseconds()分别返回时间长度的总秒数、总毫秒数、总微妙数。
	// fractional_seconds()以long返回微秒数。
	time_duration td(1, 10, 30, 1000);
	assert(td.hours() == 1 && td.minutes() == 10 && td.seconds() == 30);
	assert(td.total_seconds() == 1 * 3600 + 10 * 60 + 30);		// 微秒被忽略（不够1s的部分被忽略）
	assert(td.total_milliseconds() == td.total_seconds() * 1000 + 1);	// 这里微秒中不足1毫秒的部分被忽略

	assert(td.fractional_seconds() == 1000);			// 返回微秒部分的值
	
	// time_duration可以位负值，专门有一个成员函数is_negative()来判断它的正负号。成员函数invert_sign()可以将时间长度改变符号后生成一个新的时间长度。
	hours n_h(-10);
	assert(n_h.is_negative());

	time_duration td2 = n_h.invert_sign();
	assert(!td2.is_negative() && td2.hours() == 10);

	cout << to_simple_string(t5) << endl;	// 01:10:30.001000
	cout << to_iso_string(t5) << endl;		// 011030.001000

	


	system("pause");
	return 0;
}