// basic c++ for '&' and '*' and template 
// by wrchow at 20110913

// const ��������
// http://www.cnblogs.com/qingquan/archive/2010/10/21/1857444.html
// �������ڱ���׶�ʵ�ֵģ����������ݺ�����ͬ�Ĳ�������ͬ������������������
/*
�ܽ᣺
1.const������Ҫ��ͨ���ܷ�Դ���Ĳ��������޸�Ϊ�жϵġ�
2.const�������غ�const�������ػ��ƶ���һ���ģ���Ϊ����const �������ؿɿ����Ƕ�������ָ��this�Ĳ������ء�
3.�������ڱ���׶��Ѿ���ɣ����ڻ���������˵͸���ġ�
*/
#include <iostream>
#include <string>

using namespace std;

// const string & print(const string& s);
// void print(string s);

const string & print(const string *s);
void print(string *s);
void print(int a[]);

int main()
{
    const string s("abc");
    print(&s);
    int a[] = {3,4,5};
    
    return 0;
}

const string & print(const string* s)
{
    cout << "const string & print(const string& s).." << endl;
    cout << *s << endl;
    return *s;
} 

void print(string s)
{
    cout << "void print(string s) .. " << endl
        << s << endl;
}

void print(int a[])
{
    
}



