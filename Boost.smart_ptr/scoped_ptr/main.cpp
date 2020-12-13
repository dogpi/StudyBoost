#include <iostream>
#include <boost/smart_ptr.hpp>
#include <string>
using namespace std;
using namespace boost;

/*
	scoped_ptr
	����⣺����װ��new�������ڶ��Ϸ���Ķ�̬�����ܹ���֤��̬�����Ķ������κ�ʱ�򶼿��Ա���ȷ��ɾ����
	��scoped_ptr����Ȩ����ת�ã�һ��scoped_ptr��ȡ�˶���Ĺ���Ȩ�����Ǿ��޷���������ȡ�ء�

	scoped_ptrӵ��һ���ܺõ����֣����������Ķ��ߴ�������ȷ����Ϣ�����ֻ��ָ��ֻ���ڱ���������ʹ�ã���ϣ����ת�á�

	scoped_ptr�Ĺ��캯������һ������ΪT*��ָ��p������һ��scoped_ptr���󣬲��ڱ�������ָ�����p��
	p������һ��new���ʽ��̬����Ľ���������ǿ�ָ�루nullptr����
	��scoped_ptr������������ڽ���ʱ������������ʹ��delete�������Զ������������ָ����󣬴Ӷ���ȷ�ػ�����Դ��
	ʵ���ϵ��õ�ʱboost::check_delete()������

	scoped_ptr�ѿ������캯���͸�ֵ����������Ϊ˽�еģ���ֹ������ָ��Ŀ�����������֤�˱��������ָ�벻�ܱ�ת�á�

	��Աreset()�Ĺ���ʱ����scoped_ptr����ɾ��ԭ�������ָ�룬�ٱ����µ�ָ��ֵp�����p�ǿ�ָ�룬��ôscoped_ptr���������κ�ָ�롣
	һ�������reset()��Ӧ�ñ����ã���Ϊ��Υ����scoped_ptr�ı��⡪����ԴӦ��һֱ��scoped_ptr�Զ�����

	scoped_ptr��operator*()��operator->()�����˽����ò�����"*"�ͼ�ͷ������"->"����ģ�±������ԭʼָ�����Ϊ����˿��԰�scoped_ptr��ָͬ��һ��ʹ�á�
	���scoped_ptr������ǿ�ָ�룬��ô��������������Ϊ��δ����ġ�

	scoped_ptr�ṩ��һ��������bool�ﾳ����if���������ʽ�����Զ�ת����boolֵ�Ĺ��ܣ���������scoped_ptr�Ƿ����һ����Ч��ָ�루�ǿգ���

	��Ա����swap()���Խ�������scoped_ptr�����ԭʼָ�롣���Ǹ�Ч�Ĳ�����������ʵ��reset()������Ҳ���Ա�std::swap��ʹ�á�

	
	��Ա����get()����scoped_ptr�ڲ������ԭʼָ�룬��������ĳЩҪ�����ʹ��ԭʼָ��ĳ�������ײ��C�ӿڣ���
	��ʹ��ԭʼָ��ʱ����С�ģ��⽫ʹԭʼָ������scoped_ptr�Ŀ��ƣ����ܶ����ԭʼָ����delete����������scoped_ptr����ʱ����Ѿ�ɾ����ָ���ٽ���ɾ������������δ������Ϊ��

	scoped_ptr֧�����޵ıȽϲ���������������scoped_ptr֮�������Ȼ򲻵ȣ�==  !=���Ƚϡ�Ĭ��֧����nullptr���бȽϣ�Ҳ������NULL��0����Ϊ�����߶�������ʽת��Ϊnullptr����
	���ǿ���Ϊ����д����ıȽϺ��������������岻����Ϊʹ�ó�Ա����get()�Ϳ��Ի��ԭʼָ����бȽϡ�

	��һ��scoped_ptr��ͼ����һ��scoped_ptr�������ʱ���������ᱨ��һ��������ֹ���ô�����Ӷ��������ǵĴ��롣
	��Ҳ��������һ�����ۣ����һ���࣬����scoped_ptr��Ա��������ô��Ҳ���ǲ��ɿ����͸�ֵ�ġ�
	class ptr_owned final
	{
		scoped_ptr<int> m_ptr;
	};

	ptr_owned p;
	ptr_owned p2(p);	// error ������󣬲��ܿ�������

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
		cout << "����myClass�Ĺ��캯��" << endl;
		scoped_ptr<myClass> s_ptr(new myClass);
		assert(s_ptr);
		assert(s_ptr != nullptr);
		assert(s_ptr != 0);
		assert(s_ptr != NULL);
		s_ptr->ID = 0;
		s_ptr->printID();
		cout << "���� myClass����������" << endl;
	}

	cout << "scoped_ptr ���ͷ�" << endl;


	cout << "*************" << endl;
	{
		scoped_ptr<std::string> sp(new string("text"));
		cout << *sp << endl;
		cout << sp->size() << endl;

		// scoped_ptr<std::string> sp2 = sp;	// error scoped_ptr���ܿ�������
		// scoped_ptr<std::string> sp2 = new string("text"); // error �����ڸò���
	}
	/*
	{
		ptr_owned p;
		ptr_owned p2(p);	// error ������󣬲��ܿ�������
							// ����	1	error C2248: ��boost::scoped_ptr<int>::scoped_ptr��: 
							// �޷����� private ��Ա(�ڡ�boost::scoped_ptr<int>����������)	
							// e:\github\studyboost\boost.smart_ptr\scoped_ptr\main.cpp	53	1	scoped_ptr
	}
	*/



	system("pause");
	return 0;
}