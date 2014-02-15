// <���ݽṹ���㷨����>����C����������page1
// �����֮�����ṩ�������㷨
// refer to http://wenku.baidu.com/view/ace04168011ca300a6c390d6.html
// Ѱ������K����

/* results : 
	N=10e6 , K = 1000;
	it takes :0.01s to generate 100
	choose1 : 32763 takes :154.089s !
	choose2 : 32763 takes :0.015s ! * 1000
*/ 
#include <iostream>
#include <vector> 
#include <cstdlib>
#include <ctime>
using namespace std;

int N, K;

vector<int> genv(int n); // �����������
int choose1(vector<int> v);	//  O(N^2) : ð������
int choose2(vector<int> v); //  O(N*K) ������ѡ��
int choose3(vector<int> v); //  O(N*log2(N)) ����������
void QuickSort(vector<int> &v, int s, int e);

int main()
{
	cout << "Input N = " ; cin >> N;
	cout << "Input K = " ; cin >> K;
	vector<int> v = genv(N);
	long s0 = clock();
	long e0 = clock();
	cout << "it takes :" << (double)(e0-s0)/CLOCKS_PER_SEC 
		<< "s to generate " << N << " nums." << endl;
	long s1 = clock();
	cout << "choose1 : " << choose1(v) ;
	long e1 = clock();
	cout << "	takes :" << (double)(e1-s1)/CLOCKS_PER_SEC << "s !" << endl;
	long s2 = clock();
	cout << "choose2 : " << choose2(v) ;
	long e2 = clock();
	cout << "	takes :" << (double)(e2-s2)/CLOCKS_PER_SEC << "s !" << endl;
}

vector<int> genv(int n)
{
	vector<int> v;
	srand(time(0));
	for (int i=0; i<N; i++) {
		v.push_back(rand()%N);
	}
	return v;
}

int choose1(vector<int> v)
{// ð������,ע��ֻ�Ǵ�����
	for (int i=0; i <v.size(); i++) {
		for (int j=v.size()-1; j>i; j--) {
			int tmp;
			if (v[j] >v[j-1]) {
				tmp = v[j];
				v[j] = v[j-1];
				v[j-1] = tmp;
			}
		}
	}
	return v[K];
}

int choose2(vector<int> v)
{// ����ѡ�񣻳�ΪK������
	vector<int> vk;
	for (int i=0; i<K; i++) {
		vk.push_back(v[i]);
	}
	for (int j=0; j<v.size(); j++) {
		for (int k=0; k<K; k++) {
			if (v[j] > vk[k]) {
				vk[k] = v[j];
			}
		}
	}
	int mink = vk[0];
	for (int k=0; k<K; k++) {
		if (mink > vk[k]) {
			mink = vk[k];
		}
	}
	return mink;
}

int choose3(vector<int> v)
{// ��������
	QuickSort(v, 0, v.size()-1);
	return v[K];
}

void QuickSort(vector<int> &v, int s, int e)
{
	if(e-s<=1) return;
	//srand(time(0));
	//int M = v[rand()%(e-s+1)]; // pivot
	int M = v[(e+s)/2];
	int i(s);
	int j(e);
	do
	{
		while(v[i]>M && i<e) i++;
		while(v[j]<M && j>s) j--;
		int tmp;
		if (i <= j) {
			tmp = v[j];
			v[j] = v[i];
			v[i] = tmp;
			i++;
			j--;
		}
	} while(i<=j);
	if (s < j) {
		QuickSort(v,s,j);
	}
	if (e > i) {
		QuickSort(v,i,e);
	}
}
















