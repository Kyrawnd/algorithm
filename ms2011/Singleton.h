// for �ٶ�������
// by wr-chow at 20110903

// һ��ʵ��
// �Լ�����Ψһʵ��
// ���������������ṩ��һʵ��
Class Singleton{

public:
	static Singleton* Instance();
protected:
	Singleton();
private:
	static Singleton* _instance;	
}