// qsort again
// by wrchow 20110923

#include <iostream>
#include <vector>

using namespace std;

void qsort(vector<int>& v,int s, int e){
// Asending
    //cout << "qsort.. in Asending .." << endl;
    if(e-s <= 0) return;
    int i(s),j(e);
    int pivot = v[(s+e)/2];
    cout << "pivot = " << pivot << endl;
    do {
    while (v[i]<pivot && i<e) i++;
    while (v[j]>pivot && j>s) j--; // j--
        if (i <= j) {
            if(i != j){
                int tmp = v[i];
                v[i] = v[j];
                v[j] = tmp; // note          
            }
            i++;
            j--;
        }
    } while (i <= j);      
    if(j>s) qsort(v,s,j);
    if(i<e) qsort(v,i,e);
}

void printv(vector<int>& v){
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
}

int main()
{
    int a1[] = {3,8,7,9,6};// swap(8,6), {3,6,{7},9,8}, swap(9,8)
    int a[] = {1,2,2,2,2};
    vector<int> v(a,a+5);
    printv(v);
    qsort(v,0,v.size()-1);
    cout << "after qsort .. " << endl;
    printv(v);
    return 0;
}

int Partition(vector<int> &A, int s, int e )
{// Asending 
    int p_pos,tmp,i,j;//�м��λ��    
    p_pos = s; //�����м��λ���ڵ�һλ
    //�����м��ֵΪ��һλԪ�ص�ֵ ע���м��Ԫ�ص�ֵ��ȷ���� �����һλ �����м��Ԫ�ص���ȷλ����Ҫ������
    int pivot = A[p_pos];
    for(i=s+1; i<=e; i++){    //�ӵڶ�λ��ʼ���� ����iλԪ��С���м��ֵ
        if(A[i] < pivot){
          p_pos++; //�м��λ������һλ        
          swap<int>(A[p_pos],A[i]);//�����˿��м��λ������Ԫ�����iλԪ�ص�ֵ
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
        QuickSort(A,p,r-1);
        QuickSort(A,r+1,q);
    }
}