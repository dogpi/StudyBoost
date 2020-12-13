#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>			// 日期组件
#include <boost/date_time/posix_time/posix_time.hpp>		// 时间组件


using namespace std;
using namespace boost::gregorian;
using namespace boost::posix_time;


/*
	日期长度是以天为单位的时长，是度量时长的一个标量。
	与日期不同，日期长度的值可以是任意整数，可正可负。
	is_special()和is_negative()可以判断date_duration对象是否为特殊值、是否为负值。
	unit()返回时长的最小单位，即date_duration(1)。
	date_duration支持全序比较操作（==、!=、<、<=等），也支持完全的加减法和递增递减操作，用起来很像一个整数。
	date_duration库位date_duration定义了一个常用的typedef：days，这个新名字更好地说明了date_duration的含义---它是一个天数的计量。
*/

int main()
{
	days dd1(10), dd2(-100), dd3(255);

	assert(dd1 > dd2&&dd1 < dd3);
	assert(dd1 + dd2 == days(-90));
	assert((dd1 + dd3).days() == 265);
	assert(dd3 / 5 == days(51));

	weeks w(3);
	assert(w.days() == 21);

	months m(5);
	years y(2);

	months m2 = y + m;
	assert(m2.number_of_months() == 29);
	assert((y * 2).number_of_years() == 4);

	date d1(2000, 1, 1), d2(2017, 11, 18);
	cout << d2 - d1 << endl;		// 6531天

	assert((d1 + (d2 - d1)) == d2);	

	d1 += days(10);					// 2000-1-11
	assert(d1.day() == 11);

	d1 += months(2);				// 2000-3-11
	assert(d1.month() == 3 && d1.day() == 11);

	d1 -= weeks(1);					// 2000-3-04
	assert(d1.day() == 4);

	d2 -= years(10);				// 2007-11-18
	assert(d2.year() == d1.year() + 7);

	/*
		在与months、years这两个时长类进行计算时要注意：如果日期时月末的最后一天，那么加减月或年会得到同样的月末时间，而不是简单的月份或年份加1，
		这是合乎生活常识的。但当天数是月末的28、29时，如果加减月份到2月份，那么随后的运算就是月末操作，原来的天数信息就会丢失。
	*/
	date dd(2017, 3, 30);

	dd -= months(1);		// 2017-2-28 变为月末，原来的30的日期信息丢失
	dd -= months(1);		// 2017-1-31
	dd += months(2);		// 2017-3-31
	assert(dd.day() == 31);	// 与原来的日期不等

	system("pause");
	return 0;
}