#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>			// �������
#include <boost/date_time/posix_time/posix_time.hpp>		// ʱ�����


using namespace std;
using namespace boost::gregorian;
using namespace boost::posix_time;

/*
	time_duration�����ڹ��캯��ָ��ʱ�����΢��������
*/

int main()
{
	// 1Сʱ10����30��1���루1000΢���ʱ�䳤��
	time_duration t1(1, 10, 30, 1000);
	// ʱ �����ֵ����ʱ�������������һ�����������ǵ��޶��ڣ�������ʱ����Զ���λ���λ��
	// 2Сʱ1��6.001��
	//               1Сʱ60��60��6001000΢��=2Сʱ1��6.001��
	time_duration t2(1, 60, 60, 1000 * 1000 * 6 + 1000);

	// ʹ��time_duration��������Ը�ֱ�۵ش���ʱ�䳤��
	hours h(1);			// 1Сʱ
	minutes m(10);		// 10����
	seconds s(30);		// 30��
	milliseconds ms(1);	// 1΢��

	time_duration t3 = h + m + s + ms;
	time_duration t4 = hours(2) + seconds(10);

	time_duration t5 = duration_from_string("1:10:30:001");
	// time_duration t5 = duration_from_string("1:10:30:1");	// exception
	assert(t3 == t5);

	// time_duration���ʱ���������hours()��minutes()��seconds()��Ա�������ʡ�
	// total_seconds()��total_milliseconds()��total_microseconds()�ֱ𷵻�ʱ�䳤�ȵ����������ܺ���������΢������
	// fractional_seconds()��long����΢������
	time_duration td(1, 10, 30, 1000);
	assert(td.hours() == 1 && td.minutes() == 10 && td.seconds() == 30);
	assert(td.total_seconds() == 1 * 3600 + 10 * 60 + 30);		// ΢�뱻���ԣ�����1s�Ĳ��ֱ����ԣ�
	assert(td.total_milliseconds() == td.total_seconds() * 1000 + 1);	// ����΢���в���1����Ĳ��ֱ�����

	assert(td.fractional_seconds() == 1000);			// ����΢�벿�ֵ�ֵ
	
	// time_duration����λ��ֵ��ר����һ����Ա����is_negative()���ж����������š���Ա����invert_sign()���Խ�ʱ�䳤�ȸı���ź�����һ���µ�ʱ�䳤�ȡ�
	hours n_h(-10);
	assert(n_h.is_negative());

	time_duration td2 = n_h.invert_sign();
	assert(!td2.is_negative() && td2.hours() == 10);

	cout << to_simple_string(t5) << endl;	// 01:10:30.001000
	cout << to_iso_string(t5) << endl;		// 011030.001000

	


	system("pause");
	return 0;
}