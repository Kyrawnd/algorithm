// binarySearch.cpp by wrchow at 20111005 21:44~22:33
/*
������
    �������������۰���ң����ز���ֵ�ڱ��е�λ�ã�δ�ҵ�����-1��
    ѭ������������1.min = max, 2.min = max-1; 3. �ж�vt[max] == x;
*/
#include <iostream>
#include <vector>
using namespace std;

// �ҵĴ�����룺
template<typename T>
int binarySearch1(vector<T> vt, T a){
    printv(vt);
    cout << "find " << a << " in " ;
    if (vt.size() < 1) return -1;
    else if (vt.size() == 1) return 0; // note1
    int begin(0),end(vt.size()-1),mid=vt.size()/2;
    while (begin < end) {
        if (a < vt[mid]) {
            end = mid-1;
            mid = begin + (end-begin)/2;
        } else if(a > vt[mid]){
            begin = mid+1;
            mid = begin + (end-begin)/2;
        } else {
            return mid;
        }
    }
    return -1;
}

// ��ȷ���룺
template<typename T>
int binarySearch(vector<T> vt, T a){
    printv(vt);
    if (vt.empty()) return -1;
    cout << "find " << a << " in " ;
    int min(0),max(vt.size()-1),mid;
    // ѭ������������1.min = max, 2.min = max-1;
    while (min < max-1) {
        mid = min + (max-min)/2;
        if (a < vt[mid])  max = mid-1;
        else min = mid+1;
    }
    if (vt[max] == a) return max+1;
    return -1;
}


template<typename T>
void printv(vector<T> vt){
    for (size_t i=0; i<vt.size(); i++){
        cout << vt[i] << ' ';
    }
    cout << " .. " ;
}
/* results:
$ ./bins
 .. -1
1  .. find 1 in 1
1 2  .. find 2 in 2
1 2 3  .. find 3 in 3
*/
int main(int argc,char *argv[])
{
    int t1[] = {};//t1
    vector<int> vt1;
    cout << binarySearch(vt1,0) << endl;
    int t2[] = {1};//t2
    vector<int> vt2(t2,t2+1);
    cout << binarySearch(vt2,1) << endl;
    int t3[] = {1,2};//t3
    vector<int> vt3(t3,t3+2);
    cout << binarySearch(vt3,2) << endl;
    int t4[] = {1,2,3};//t4
    vector<int> vt4(t4,t4+3);
    cout << binarySearch(vt4,3) << endl;
    return 0;
}


