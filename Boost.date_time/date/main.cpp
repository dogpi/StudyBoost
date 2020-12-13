#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>			// 日期组件
#include <boost/date_time/posix_time/posix_time.hpp>		// 时间组件


using namespace std;
using namespace boost::gregorian;
using namespace boost::posix_time;

int main()
{
	try{
		// date d1(1399, 12, 1);	// 超出日期下限 throw exception
		// date d2(10000, 1, 1);	// 超出日期上限 throw exception
		// date d3(2021, 2, 29);	// 不存在的日期
	}
	catch (exception e){
		cout << e.what() << endl;
	}
	
	date d(2020, 12, 13);
	assert(d.year() == 2020);
	assert(d.month() == 12);
	assert(d.day() == 13);
	
	date::ymd_type ymd = d.year_month_day();
	assert(ymd.year == 2020);
	assert(ymd.month == 12);
	assert(ymd.day == 13);

	// 成员函数day_of_week()返回date的星期数，0表示星期天。
	// 成员函数day_of_year()返回date是当年的第几天（最多是366）
	// 成员函数end_of_month()返回当月最后一天的date对象。
	// 成员函数week_number()返回date所在的周是当年的第几周，范围是0-53。

	cout << d.day_of_week() << endl;
	cout << d.day_of_year() << endl;

	assert(d.end_of_month() == date(2020, 12, 31));

	cout << date(2020, 12, 12).week_number() << endl;
	cout << date(2020, 12, 13).week_number() << endl;
	cout << date(2020, 12, 14).week_number() << endl;

	// date 对象转换成字符串
	// to_simple_string():转换为YYYY-mmm-DD格式的字符串，其中mmm为3字符的英文月份名
	// to_iso_string():转换为YYYYMMDD格式的数字字符串
	// to_iso_extended_string():转为YYYY-MM-DD格式的数字字符串
	// date也支持流输入输出，默认使用YYYY-mmm-DD格式。

	cout << to_simple_string(date(2020, 12, 13)) << endl;
	cout << to_iso_string(date(2020, 12, 12)) << endl;
	cout << to_iso_extended_string(date(2020, 12, 12)) << endl;
	//cout << "input date:";
	//date cin_d;
	//cin >> d;
	//cout << d << endl;;


	// date 支持与C标准库中的tm结构相互转换。
	// to_tm(date)：date转到tm。tm的时分秒成员（tm_hour/tm_min/tm_sec）均置为0，夏令时标志tm_isdst置为-1（表示未知）。
	// date_from_tm(tm datetm)：tm转换到data。只使用年、月、日三个成员（tm_year/tm_mon/tm_mday），其他成员均被忽略。

	date dd(2020, 12, 12);
	tm t = to_tm(dd);
	assert(t.tm_hour == 0 && t.tm_min == 0);
	assert(t.tm_year == (2020 - 1900) && t.tm_mday == 12);

	date dd2 = date_from_tm(t);
	assert(dd2 == dd);

	system("pause");
	return 0;
}