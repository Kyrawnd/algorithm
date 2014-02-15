// dianp1.cpp
// ���ڵ�����1��
// ������
//      Input:  һ��n����������,����ĳ�����ֳ��ִ�������N/2;
//      Outpu:  �ҳ��Ǹ���
//              

#include <iostream>
#include <vector>
using namespace std;

int findk(vector<int> a); // ��������������ͬ��ӣ������
int rfindk(vector<int> a,int s,int e); // ���Ż��ַ�,��ֵ,���м�ֵ���ֵķ�ʽ���ʺ�
int Partition(vector<int> &A, int s, int e );
void QuickSort2( vector<int>& A, int p, int q );

int main()
{
    int a[] = {1,2,3,2,2,2,5}; // test
    vector<int> v(a,a+7);
    cout << findk(v) << endl;
    cout << rfindk(v,0,7) << endl;
    return 0;
}

int findk(vector<int> a){
    if (a.size() < 0) return -1;   //���ü�¼�Ҳ�����״̬;
    int i,vn(a[0]),cnt(1); 
    for (i=1; i< a.size(); i++) {        
        if(a[i] == a[i-1]) cnt ++;           
        else cnt --;    
        if(cnt == 0) vn = a[i];        
    }
    return vn;
}

int rfindk(vector<int> a,int s,int e){
    int r = Partition(a,s,e);
    if (e-s > a.size()/2) return a[(s+e)/2];
    if (e-r > r-s) rfindk(a,r+1,e);
    else rfindk(a,s,r-1);
}

int Partition(vector<int> &A, int s, int e )
{// Asending 
    int p_pos,tmp,i,j;//�м��λ��    
    p_pos = s; //�����м��λ���ڵ�һλ
    //�����м��ֵΪ��һλԪ�ص�ֵ ע���м��Ԫ�ص�ֵ��ȷ���� �����һλ �����м��Ԫ�ص���ȷλ����Ҫ������
    int pivot = A[p_pos];
    for(i=s+1; i<=e; i++){ //�ӵڶ�λ��ʼ���� ����iλԪ��С���м��ֵ
        if(A[i] < pivot){
          p_pos++; //�м��λ������һλ        
          if(p_pos != i) swap<int>(A[p_pos],A[i]);//�����˿��м��λ������Ԫ�����iλԪ�ص�ֵ
        }
    }
    //��ʱ�Ѿ��ҵ��м��Ԫ��������ȷλ�� ���м��Ԫ��λ�õ�ֵ������һλΪ�м��ֵ���� 
    swap<int>(A[s],A[p_pos]);       
    return p_pos; //���ظ��м��λ��
}

void QuickSort2( vector<int>& A, int p, int q )
{
    if( p < q )
    {
        int r = Partition(A, p, q);
        QuickSort2(A,p,r-1);
        QuickSort2(A,r+1,q);
    }
}











