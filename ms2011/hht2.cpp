// refer to http://zhedahht.blog.163.com/blog/static/25411174201102642136998/
// by wr-chow at 20110830
// two questions a day
#include<cstdio>

class B;
class A;

struct Point3D
{
	int x,y,z;
};

int main()
{
	Point3D* pPoint = NULL;
	int offset1 = (int)(&(pPoint)->z);
	int offset2 = (int)(&(pPoint)->x);
	int offset3 = (int)(&(pPoint)->y);
	/*
	���8��������pPoint->z��ǰ�������ȡ��ַ���ţ����е���ʱ��ʱ��
	����pPoint��ָ���ַ�ϼ�z������Point3D�е�ƫ����8������pPoint�ĵ�ַ��0��
	�������offset��ֵ��8��
	&(pPoint->z)����������pPoint�б���z�ĵ�ַ��pPoint�ĵ�ַ0��z��ƫ����8����
	������Ҫ����pPointָ����ڴ档ֻҪ�����ʷǷ����ڴ棬����Ͳ������
	*/
	printf("%d, %d, %d", offset1,offset2,offset3);
	// һ��int ��4���ֽ�
	//----------2-----------//
	A* pA = new A(); //??? no appropriate default constructor available
	delete pA;
	return 0;
}

//------------------------2-------------------------------//
/*
�Ⱥ��ӡ������:A is constructed. B is constructed. ����B�Ĺ��캯��ʱ��
�Ȼ����B�Ļ��༰A�Ĺ��캯����Ȼ����A�Ĺ��캯�������Print��
���ڴ�ʱʵ��������B�Ĳ��ֻ�û�й���ã���������ֻ��A��һ��ʵ����
�����麯����ָ��ָ���������A���麯������˴�ʱ���õ�Print��A::Print��
������B::Print�����ŵ�������B�Ĺ��캯����������Print����ʱ�Ѿ���ʼ����B��
��˴�ʱ���õ�Print��B::Print��
ͬ���ǵ������⺯��Print�����Ƿ���������A�Ĺ��캯���У����õ���A::Print��
��B�Ĺ��캯���У����õ���B::Print������麯���ڹ��캯���У�
�Ѿ�ʧȥ���麯���Ķ�̬�����ԡ�
*/
class A
{
public:
	A()
	{
		Print();
	}
	virtual void Print()
	{
		printf("A is constructed.\n");
	}
};

class B: public A
{
	public:
		B()
		{
			Print();
		}
		virtual void Print()
		{
			printf("B is constructed.\n");
		}
};

/*
��Ŀ���ţ�����C++��C#�У�struct��class��ʲô��ͬ��

�𰸣���C++�У����û�б����������߱����ǵķ���Ȩ�޼���
��struct�У���public�ģ�����class�У���private�ġ�

                ��C#�У����û�б����������߱����ķ���Ȩ�޼���
				struct��class�ж���private�ġ�struct��class�������ǣ�
				struct����ֵ���ͣ���ʵ����ջ�Ϸ����ڴ棻class�����������ͣ�
				��ʵ���ڶ��Ϸ����ڴ档
*/



