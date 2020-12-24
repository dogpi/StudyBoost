#include <iostream>
#include <boost/pool/pool.hpp>

#include <boost/nondet_random.hpp>

using namespace std;
using namespace boost;


// ע����ʹ�÷��ص�ָ��ʱҪ�ж��Ƿ�Ϊ0����Ϊmalloc�����ڴ�ʧ�ܲ����׳��쳣���᷵��0��
// poolֻ�ܷ������򵥵ı�������int��double����Ϊpoolֻ�ܼ򵥵�malloc��free�ڴ棬��������ö���Ĺ��캯��������������
// ���ӵ���������Ҫʹ��object_pool�����ڴ棬object_pool����ͨ��construct������󣬿���ͨ��destroy�ͷŶ���
// destroy()�ȵ��ö��������������Ȼ���ٵ���free()�ͷ��ڴ�顣
int main()
{
	pool<> pl(sizeof(int));		// �����ڴ�أ�ÿ��Ԫ�ش�СΪint�Ĵ�С��
	
	int *p = static_cast<int*>(pl.malloc());
	cout << p << endl;				// 00BAC000

	int *p1 = static_cast<int*>(pl.malloc());
	cout << p1 << endl;				// 00BAC004 = 00BAC000 + sizeof(int)

	int *p2 = static_cast<int*>(pl.malloc());
	cout << p2 << endl;				// 00BAC008 = 00BAC004 + sizeof(int)

	int *p3 = static_cast<int*>(pl.malloc());
	cout << p3 << endl;				// 00BAC00C = 00BAC008 + sizeof(int)

	int *p4 = static_cast<int*>(pl.ordered_malloc(2));
	cout << p4 << endl;				// 00BAC010
	cout << p4 + 1 << endl;			// 00BAC014
	cout << p4 + 2 << endl;			// 00BAC018		dangerous��5��ַ��ͬ��p4+2Խ��	�����·����ڴ�����ָ���λ�ã����ܻᵼ�����ݱ����ǡ�
	cout << p4 + 3 << endl;			// 00BAC01C		dangerous			  p4+3Խ��	

	int *p5 = static_cast<int*>(pl.malloc());
	cout << p5 << endl;				// 00BAC018		

	assert(pl.is_from(p1));
	assert(pl.is_from(p2));
	assert(pl.is_from(p3));
	assert(pl.is_from(p4));
	assert(pl.is_from(p5));

	cout << p5+50 << endl;
	cout << pl.is_from(p5 +50) << endl;

	for (int i = 0; i < 50; ++i){						// ��ַ��һ����������
		cout << static_cast<int*>(pl.malloc()) << endl;
	}
	cout << p5 + 50 << endl;
	cout << pl.is_from(p5 + 50) << endl;				// ��Ϊ��ַ��һ������������p5+50���ܲ���pl������ڴ�ռ��С�



	cout << "-----------------" << endl;

	int *p6 = static_cast<int*>(pl.ordered_malloc(100));			// ָ�������ڴ��С��������ɢ���ڴ�Ƭ�Σ�������ڴ���һ���飬��ַ�������ġ�
	for (int i = 0; i < 100; ++i){
		cout << p6 + i << endl;
	}

	system("pause");
	return 0;
}














