// hht17.cpp  by wrchow 20110926 23:30~24:08
/*
����Ա�����⾫ѡ100 ��(17)�����ַ���ת��������
��Ŀ������һ����ʾ�������ַ������Ѹ��ַ���ת���������������
���������ַ���"345"�����������345��
*/

#include <string>
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

int main(int argc, char* argv[])
{
    assert(argc == 2);
    string a = argv[1];
    if(a.empty()) return -1;
    int num,i=0,flag=1;
    if (a[i] == '+') {
        i++;
        num = a[i++] - '0';
    } else if(a[i] == '-'){
        flag = -1;
        i++;
        num = a[i++] - '0';
    } else {
        num = a[i++] - '0';
    }
    for (; i<a.size(); i++) {
        num *= 10;
        num += (a[i]-'0');
    }    
    cout << num*flag << endl;
    return 0;
}