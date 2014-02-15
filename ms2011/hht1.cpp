// refer to http://zhedahht.blog.163.com/blog/static/254111742011012111557832/
// by wr-chow at 2011-0829
#include <iostream>
#include <stdio.h>

// ----------------------1--------------------------//
// static & const

// ----------------------2--------------------------//
class A {};

class B 
{
public:
	B() {}
	~B() {}
};

class C
{
public:
	C() {}
	virtual ~C() {}
};
// ----------------------3--------------------------//
/*
����Print1������������ӡ��hello world����������Print2ʱ�����������
����Print1ʱ��������ҪpA�ĵ�ַ����ΪPrint1�ĺ�����ַ�ǹ̶��ġ�
���������Print1����һ��thisָ�룬��ָ��ΪNULL������Print1�и�thisָ�벢û���õ���
ֻҪ��������ʱû�з��ʲ��÷��ʵ��ڴ�Ͳ�������������������������print2ʱ��
��Ҫthisָ����ܵõ�m_value��ֵ�����ڴ�ʱthisָ��ΪNULL����˳�������ˡ�	
*/
class D
{
private:
		int m_value;

public:
		D(int value)
		{
			m_value = value;
		}
		void Print1()
		{
			printf("hello world");
		}
		void Print2()
		{
			printf("%d", m_value);
		}
// ----------------------4--------------------------//
		virtual void Print3()
		{
			printf("hello world");
		}
};

//int _tmain(int argc, _TCHAR* argv[])
int main()
{
	printf("%d, %d, %d\n", sizeof(A), sizeof(B), sizeof(C));
	
	D* pD = NULL;
	pD -> Print1();
	pD -> Print3();
	//pD -> Print2();
	
	return 0;
}



