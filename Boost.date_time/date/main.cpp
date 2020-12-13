#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>			// �������
#include <boost/date_time/posix_time/posix_time.hpp>		// ʱ�����


using namespace std;
using namespace boost::gregorian;
using namespace boost::posix_time;

int main()
{
	try{
		// date d1(1399, 12, 1);	// ������������ throw exception
		// date d2(10000, 1, 1);	// ������������ throw exception
		// date d3(2021, 2, 29);	// �����ڵ�����
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

	// ��Ա����day_of_week()����date����������0��ʾ�����졣
	// ��Ա����day_of_year()����date�ǵ���ĵڼ��죨�����366��
	// ��Ա����end_of_month()���ص������һ���date����
	// ��Ա����week_number()����date���ڵ����ǵ���ĵڼ��ܣ���Χ��0-53��

	cout << d.day_of_week() << endl;
	cout << d.day_of_year() << endl;

	assert(d.end_of_month() == date(2020, 12, 31));

	cout << date(2020, 12, 12).week_number() << endl;
	cout << date(2020, 12, 13).week_number() << endl;
	cout << date(2020, 12, 14).week_number() << endl;

	// date ����ת�����ַ���
	// to_simple_string():ת��ΪYYYY-mmm-DD��ʽ���ַ���������mmmΪ3�ַ���Ӣ���·���
	// to_iso_string():ת��ΪYYYYMMDD��ʽ�������ַ���
	// to_iso_extended_string():תΪYYYY-MM-DD��ʽ�������ַ���
	// dateҲ֧�������������Ĭ��ʹ��YYYY-mmm-DD��ʽ��

	cout << to_simple_string(date(2020, 12, 13)) << endl;
	cout << to_iso_string(date(2020, 12, 12)) << endl;
	cout << to_iso_extended_string(date(2020, 12, 12)) << endl;
	//cout << "input date:";
	//date cin_d;
	//cin >> d;
	//cout << d << endl;;


	// date ֧����C��׼���е�tm�ṹ�໥ת����
	// to_tm(date)��dateת��tm��tm��ʱ�����Ա��tm_hour/tm_min/tm_sec������Ϊ0������ʱ��־tm_isdst��Ϊ-1����ʾδ֪����
	// date_from_tm(tm datetm)��tmת����data��ֻʹ���ꡢ�¡���������Ա��tm_year/tm_mon/tm_mday����������Ա�������ԡ�

	date dd(2020, 12, 12);
	tm t = to_tm(dd);
	assert(t.tm_hour == 0 && t.tm_min == 0);
	assert(t.tm_year == (2020 - 1900) && t.tm_mday == 12);

	date dd2 = date_from_tm(t);
	assert(dd2 == dd);

	system("pause");
	return 0;
}