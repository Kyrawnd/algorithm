// for Works Applications
// O(N) find the median of random array
// by wrchow at 20110923
// refer to http://blog.csdn.net/figoren/article/details/1611605
 /* ������
 ��������֮���Ե���"����",�����˵���������Ϊ���ž���һ�ַ������򷨣�
 ͬ��������λ��Ҳ�����ÿ��ŷ��ε�˼�롣�������£�
    ������һ��Ԫ�أ��Ը�Ԫ��Ϊ֧�㣬���ּ���Ϊ�����֣�
    �����༯�ϳ���ǡΪ (n-1)/2����ô֧��ǡΪ��λ����
    �����೤��<(n-1)/2, ��ô��λ�����Ҳ࣬��֮����λ������ࡣ 
    ������Ӧ��һ�����Ѱ����λ�㡣
    ���ַ����ܿ죬��������������ʱ�临�Ӷ�ΪO(N^2), 
    ����ƽ��ʱ�临�ӶȺ�����O(N)��
 */
 
#include <string>
#include <iostream>
#include <vector>
using namespace::std;
void printa(vector<int>& A);
void reada(vector<int>& A, int n);

int Partition(vector<int> &A, int s, int e ){
// Asending 
    int p_pos,tmp,i,j;
    p_pos = s; 
    int pivot = A[p_pos];
    for(i=s+1; i<=e; i++){   
        if(A[i] < pivot){
          p_pos++;     
          swap<int>(A[p_pos],A[i]);
        }
    }
    swap<int>(A[s],A[p_pos]);       
    return p_pos; 
}

void QuickSort( vector<int>& A, int p, int q ){
    if( p < q ) {
        int r = Partition(A, p, q);
        //cout << "r = " << r << endl;
        QuickSort(A,p,r-1);
        QuickSort(A,r+1,q);
    }
}

void median(vector<int>& A, int s, int e){   
    if( s < e) {       
        int r = Partition(A, s, e);
        //cout << "r = " << r << endl;
        if (e-r < r-s) median(A, s, r-1);
        else median(A, r+1, e);
    }
}

 int main()
{
    int a1[10] = {5,1,4,9,0,3,5,2,7,6};
    int a2[5] = {7,8,3};
    vector<int> A(a1,a1+10);
    printa(A);
    cout << "median.." ;
    median(A,0,A.size()-1);
    printa(A);
    cout << "quicksort.." ;
    vector<int> A1(a1,a1+10);
    QuickSort(A1,0,A1.size()-1);
    printa(A1);
    
}
 
void printa(vector<int>& A){
    for (int i=0; i<A.size(); i++) {
        cout << A[i] << ' ';
    }
    cout << endl;
}

 