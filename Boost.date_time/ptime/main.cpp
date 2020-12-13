#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>			// �������
#include <boost/date_time/posix_time/posix_time.hpp>		// ʱ�����


using namespace std;
using namespace boost::gregorian;
using namespace boost::posix_time;


/*
	ptimeʱdate_time�⴦��ʱ��ĺ����࣬��ʹ��64λ��΢�뼶�𣩻���96λ�����뼶�𣩵��������ڲ��洢ʱ�����ݣ�������date��time_duration����˽ӿں�С��
*/

int main()
{
	// ����ʱ���
	ptime p(date(2017, 7, 7), hours(1));	// 2017-7-7 01:00:00  2017��7��7�� �賿1��

	ptime p1 = time_from_string("2017-7-7 01:00:00");
	ptime p2 = from_iso_string("20170707T010000");

	// date_time��Ϊptime�ṩ��ʱ���࣬���Դ�ʼ�ղ�����ǰʱ�䡣
	// ��Ϊʱ�Ӿ��в�ͬ�ķֱ��ʣ�������������second_clock��microsec_clock�ֱ��ṩ�뼶��΢�뼶�ķֱ��ʣ����ǵĽӿ�ʱ��ͬ�ġ�
	// local_time()��ȡ����ʱ�䣬universal_time()���UTC��ǰʱ�䡣
	ptime p3 = second_clock::local_time();			// �뾫��
	ptime p4 = microsec_clock::local_time();		// ΢�뾫��
	cout << p3 << endl << p4 << endl;
	cout << to_simple_string(p3) << endl << to_simple_string(p4) << endl;
	cout << to_iso_string(p3) << endl << to_iso_string(p4) << endl;
	cout << to_iso_extended_string(p3) << endl << to_iso_extended_string(p4) << endl;

	assert(p3 > p2);

	// תΪC�ṹ��
	tm t_time = to_tm(p);
	assert(t_time.tm_year == 2017 - 1900 && t_time.tm_hour == 1);
	assert(ptime_from_tm(t_time) == p);

	// ����from_time_t()��to_time_t()������time_t��p_time֮���໥ת��
	ptime p5 = from_time_t(std::time(0));
	cout << "****************8" << endl;
	cout << to_iso_extended_string(p5) << endl;
	assert(p5.date() == day_clock::local_day());
	cout << to_time_t(p5) << endl;		// ��1900-1-1 0:0:0 �����ڵ����� time_t
	system("pause");
	return 0;
}