// �����κ�ѭ����䣬�⺯����һ�������ַ����ĳ���

#include <iostream>
using namespace std;

int lens(char *s){
     if(*s == '\0') return 0;
     else return 1+lens(++s);
}

int main(int argc,char *argv[])
{
    char * s = argv[1];
    cout << lens(s) << endl;
    return 0;
}
