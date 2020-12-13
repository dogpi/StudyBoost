#include <iostream>
#include <boost/smart_ptr.hpp>
#include <string>
using namespace std;
using namespace boost;

/*
	scoped_ptr
	简单理解：它包装了new操作符在堆上分配的动态对象，能够保证动态创建的对象在任何时候都可以被正确地删除。
	但scoped_ptr所有权不可转让，一旦scoped_ptr获取了对象的管理权，我们就无法从它那里取回。

	scoped_ptr拥有一个很好的名字，它向代码的阅读者传递了明确的信息：这个只能指针只能在本作用域里使用，不希望被转让。

	scoped_ptr的构造函数接受一个类型为T*的指针p，创建一个scoped_ptr对象，并在北部保存指针参数p。
	p必须是一个new表达式动态分配的结果，或这是空指针（nullptr）。
	当scoped_ptr对象的生命周期结束时，析构函数会使用delete操作符自动销毁所保存的指针对象，从而正确地回收资源。
	实际上调用的时boost::check_delete()函数。

	scoped_ptr把拷贝构造函数和赋值操作都声明为私有的，禁止对智能指针的拷贝操作，保证了被它管理的指针不能被转让。

	成员reset()的功能时重置scoped_ptr：它删除原来保存的指针，再保存新的指针值p。如果p是空指针，那么scoped_ptr将不持有任何指针。
	一般情况下reset()不应该被调用，因为它违背了scoped_ptr的本意——资源应该一直由scoped_ptr自动管理。

	scoped_ptr用operator*()和operator->()重载了解引用操作符"*"和箭头操作符"->"，以模仿被代理的原始指针的行为，因此可以把scoped_ptr如同指针一样使用。
	如果scoped_ptr保存的是空指针，那么这两个操作的行为是未定义的。

	scoped_ptr提供了一个可以在bool语境（如if的条件表达式）中自动转换成bool值的功能，用来测试scoped_ptr是否持有一个有效的指针（非空）。

	成员函数swap()可以交换两个scoped_ptr保存的原始指针。它是高效的操作，被用于实现reset()函数，也可以被std::swap所使用。

	
	成员函数get()返回scoped_ptr内部保存的原始指针，可以用在某些要求必须使用原始指针的场景（如底层的C接口）。
	但使用原始指针时必须小心，这将使原始指针脱离scoped_ptr的控制！不能对这个原始指针做delete操作，否则scoped_ptr析构时会对已经删除的指针再进行删除操作，发生未定义行为。

	scoped_ptr支持有限的比较操作，不能在两个scoped_ptr之间进行相等或不等（==  !=）比较。默认支持与nullptr进行比较（也可以是NULL或0，因为这两者都可以隐式转换为nullptr）。
	我们可以为它编写额外的比较函数，但这样意义不大，因为使用成员函数get()就可以获得原始指针进行比较。

	当一个scoped_ptr企图用另一个scoped_ptr构造或复制时，编译器会报出一个错误，阻止这个么做，从而保护我们的代码。
	这也引出了另一个结论：如果一个类，持有scoped_ptr成员变量，那么它也会是不可拷贝和赋值的。
	class ptr_owned final
	{
		scoped_ptr<int> m_ptr;
	};

	ptr_owned p;
	ptr_owned p2(p);	// error 编译错误，不能拷贝构造

*/

class ptr_owned final
{
	scoped_ptr<int> m_ptr;
};



class myClass{
public:
	myClass(){
		cout << "construct myClass" << endl;
	}

	~myClass(){
		cout << "destruct myClass" << endl;
	}

	int ID;

	void printID()
	{
		cout << ID << endl;
	}
};

int main()
{
	{
		cout << "调用myClass的构造函数" << endl;
		scoped_ptr<myClass> s_ptr(new myClass);
		assert(s_ptr);
		assert(s_ptr != nullptr);
		assert(s_ptr != 0);
		assert(s_ptr != NULL);
		s_ptr->ID = 0;
		s_ptr->printID();
		cout << "调用 myClass的析构函数" << endl;
	}

	cout << "scoped_ptr 已释放" << endl;


	cout << "*************" << endl;
	{
		scoped_ptr<std::string> sp(new string("text"));
		cout << *sp << endl;
		cout << sp->size() << endl;

		// scoped_ptr<std::string> sp2 = sp;	// error scoped_ptr不能拷贝构造
		// scoped_ptr<std::string> sp2 = new string("text"); // error 不存在该操作
	}
	/*
	{
		ptr_owned p;
		ptr_owned p2(p);	// error 编译错误，不能拷贝构造
							// 错误	1	error C2248: “boost::scoped_ptr<int>::scoped_ptr”: 
							// 无法访问 private 成员(在“boost::scoped_ptr<int>”类中声明)	
							// e:\github\studyboost\boost.smart_ptr\scoped_ptr\main.cpp	53	1	scoped_ptr
	}
	*/



	system("pause");
	return 0;
}