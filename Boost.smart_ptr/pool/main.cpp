#include <iostream>
#include <boost/pool/pool.hpp>

#include <boost/nondet_random.hpp>

using namespace std;
using namespace boost;


// 注意在使用返回的指针时要判断是否为0，因为malloc分配内存失败不会抛出异常，会返回0。
// pool只能分配管理简单的变量，如int、double。因为pool只能简单的malloc和free内存，并不会调用对象的构造函数和析构函数。
// 复杂的数据类型要使用object_pool分配内存，object_pool可以通过construct构造对象，可以通过destroy释放对象。
// destroy()先调用对象的析构函数，然后再调用free()释放内存块。
int main()
{
	pool<> pl(sizeof(int));		// 分配内存池，每个元素大小为int的大小。
	
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
	cout << p4 + 2 << endl;			// 00BAC018		dangerous与5地址相同，p4+2越界	后面新分配内存会递增指向该位置，可能会导致数据被覆盖。
	cout << p4 + 3 << endl;			// 00BAC01C		dangerous			  p4+3越界	

	int *p5 = static_cast<int*>(pl.malloc());
	cout << p5 << endl;				// 00BAC018		

	assert(pl.is_from(p1));
	assert(pl.is_from(p2));
	assert(pl.is_from(p3));
	assert(pl.is_from(p4));
	assert(pl.is_from(p5));

	cout << p5+50 << endl;
	cout << pl.is_from(p5 +50) << endl;

	for (int i = 0; i < 50; ++i){						// 地址不一定是连续的
		cout << static_cast<int*>(pl.malloc()) << endl;
	}
	cout << p5 + 50 << endl;
	cout << pl.is_from(p5 + 50) << endl;				// 因为地址不一定连续，所以p5+50可能不在pl分配的内存空间中。



	cout << "-----------------" << endl;

	int *p6 = static_cast<int*>(pl.ordered_malloc(100));			// 指定分配内存大小，整合零散的内存片段，分配的内存是一整块，地址是连续的。
	for (int i = 0; i < 100; ++i){
		cout << p6 + i << endl;
	}

	system("pause");
	return 0;
}














