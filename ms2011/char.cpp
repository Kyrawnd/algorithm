// ��Ϊ������Ŀ
// �����ַ��������ȥ���ַ�����������google���gle
#include <iostream>
#include <string>
#include <cstring>
#include <malloc.h>
using namespace std;
// Segmentation fault (core dumped)  �δ���
// �ڴ泬����ϵͳ�����Ŀռ�
// http://blog.sina.com.cn/s/blog_4d3a41f40100ejlh.html
//  
void unistr(const char *pIn, char *pOut)
{
    //strcpy(pOut, pIn);
    int i(0);
    while ( *pIn != '\0') { // note *
        bool flag = true;
        int j(0); 
        char *p = pOut;
        //cout << ">i  :   " << i << "," << *pIn << endl;
        if ( p == '\0') cout << "test3!\n";
        while (*p != '\0') {
            //cout << j << ','<<  *p << ','<< *pIn << endl;
            if (*pIn == *p) flag = false;
            p++;
        }
        if (flag == true) pOut[i++] = *pIn;
        pIn ++;
    }
}

int main(int argc, char* argv[])
{
	const char *pIn = argv[1];
	char *pOut = (char *)malloc(sizeof(char)*strlen(pIn));
	unistr(pIn, pOut);
	cout << "pOut = " << pOut << endl;
    /*
    while (*pIn != '\0') {   
     cout << *pIn++;
    } 
    const char *p = "abc",*q;
    q = pOut;
    cout << "*p++ : " << *p++ << endl; 
    cout << "*p++ : " << *p << endl;
    cout << "*p++ : " << *q << endl;
    */
	return 0;
}

