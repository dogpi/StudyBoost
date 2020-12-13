#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>			// �������
#include <boost/date_time/posix_time/posix_time.hpp>		// ʱ�����


using namespace std;
using namespace boost::gregorian;
using namespace boost::posix_time;


/*
	���ڳ���������Ϊ��λ��ʱ�����Ƕ���ʱ����һ��������
	�����ڲ�ͬ�����ڳ��ȵ�ֵ���������������������ɸ���
	is_special()��is_negative()�����ж�date_duration�����Ƿ�Ϊ����ֵ���Ƿ�Ϊ��ֵ��
	unit()����ʱ������С��λ����date_duration(1)��
	date_duration֧��ȫ��Ƚϲ�����==��!=��<��<=�ȣ���Ҳ֧����ȫ�ļӼ����͵����ݼ�����������������һ��������
	date_duration��λdate_duration������һ�����õ�typedef��days����������ָ��õ�˵����date_duration�ĺ���---����һ�������ļ�����
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
	cout << d2 - d1 << endl;		// 6531��

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
		����months��years������ʱ������м���ʱҪע�⣺�������ʱ��ĩ�����һ�죬��ô�Ӽ��»����õ�ͬ������ĩʱ�䣬�����Ǽ򵥵��·ݻ���ݼ�1��
		���ǺϺ����ʶ�ġ�������������ĩ��28��29ʱ������Ӽ��·ݵ�2�·ݣ���ô�������������ĩ������ԭ����������Ϣ�ͻᶪʧ��
	*/
	date dd(2017, 3, 30);

	dd -= months(1);		// 2017-2-28 ��Ϊ��ĩ��ԭ����30��������Ϣ��ʧ
	dd -= months(1);		// 2017-1-31
	dd += months(2);		// 2017-3-31
	assert(dd.day() == 31);	// ��ԭ�������ڲ���

	system("pause");
	return 0;
}