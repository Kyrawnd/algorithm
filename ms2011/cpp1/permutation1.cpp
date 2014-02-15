// by wr-chow at 2011-3-10
// refer to http://www.cppblog.com/goal00001111/archive/2009/01/20/72378.html
/*
�������ƣ�Permutation
�������ܣ���ͨ�ݹ��㷨�����n����������ȫ����
���������int n��1��2��3��...��n��n����Ȼ��
�����������
*/
#include <iostream>
using namespace std;

void Permutation(int n);
void Recursion(int a[], int n, int k, int dpn);
void Print(int a[], int n);
void Printn(int a[], int n);
void printdpn(int dpn);

void printdpn(int dpn)
{
	cout << dpn ;
	for (size_t i = 0; i < dpn; i++) {
		cout << "--";
	}
}

void Permutation(int n)
{
    int *a = new int[n];//�����洢n����Ȼ�� 
	for (int i = 0; i < n; i++){ //�洢ȫ���е�Ԫ��ֵ
        a[i] = i + 1;  
	}
    Recursion(a, n, n-1, 0); //���õݹ麯��     
    delete []a;
}
/*
�������ƣ�Recursion
�������ܣ��ݹ����n����������ȫ����
���������int a[]���洢��1��2��3��...��n��n����Ȼ�������� 
          int n������a[]�ĳ���
          int k�����ڴ����k��Ԫ������ɵ����� 
�����������
*/
void Recursion(int a[], int n, int k, int dpn)
{
	dpn++; printdpn(dpn);
	if (k == 0) {//����ֻ��һ��Ԫ��a[k]��ֱ����� 
        Print(a, n);
	}
    else {
        int temp;
        for (int i = 0; i <= k; i++) //��٣������õ�k��Ԫ����ǰ���Ԫ�ؽ��� 
        {
			cout << "			 (1)i: " << i << "	k: " << k << "	*"; Print(a, n); 
            temp = a[i];
            a[i] = a[k];
            a[k] = temp;    
			cout << "			 (2)i: " << i << "	k: " << k << "	*"; Print(a, n); 
            Recursion(a, n, k-1, dpn); //�ݹ�����k-1��Ԫ�ص�ȫ���� 
            temp = a[i]; //�ٻ����� 
            a[i] = a[k];
            a[k] = temp;
			cout << "			 (3)i: " << i << "	k: " << k << "	*"; Print(a, n); 
        }
    }
}
 

void Print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i];
    cout << endl;
}

 

int main()
{
	cout << "Input the no of the permutation you want : ";
	int n;
	cin >> n;
	Permutation(n);
	getchar();
	return 0;
}

//Input the no of the permutation you want : 3
//1--                      (1)i: 0        k: 2    *123
//                         (2)i: 0        k: 2    *321
//2----                    (1)i: 0        k: 1    *321
//                         (2)i: 0        k: 1    *231
//3------231
//                         (3)i: 0        k: 1    *321
//                         (1)i: 1        k: 1    *321
//                         (2)i: 1        k: 1    *321
//3------321
//                         (3)i: 1        k: 1    *321
//                         (3)i: 0        k: 2    *123
//                         (1)i: 1        k: 2    *123
//                         (2)i: 1        k: 2    *132
//2----                    (1)i: 0        k: 1    *132
//                         (2)i: 0        k: 1    *312
//3------312
//                         (3)i: 0        k: 1    *132
//                         (1)i: 1        k: 1    *132
//                         (2)i: 1        k: 1    *132
//3------132
//                         (3)i: 1        k: 1    *132
//                         (3)i: 1        k: 2    *123
//                         (1)i: 2        k: 2    *123
//                         (2)i: 2        k: 2    *123
//2----                    (1)i: 0        k: 1    *123
//                         (2)i: 0        k: 1    *213
//3------213
//                         (3)i: 0        k: 1    *123
//                         (1)i: 1        k: 1    *123
//                         (2)i: 1        k: 1    *123
//3------123
//                         (3)i: 1        k: 1    *123
//                         (3)i: 2        k: 2    *123



