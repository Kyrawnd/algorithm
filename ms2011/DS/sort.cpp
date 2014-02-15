//sort.cpp by wrchow @20111005 22:34~23:50 @20111006 9:58~
/* ������
    1. insertsort();
    2. selectsort();
    3. shellsort();
    4. mergesort(); merge();
    5. heapsort();
    6. quicksort(); selectK();
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void insertsort(vector<int>&);
void selectsort(vector<int>&);
void shellsort(vector<int>&);
void mergesort(vector<int>&);
void heapsort(vector<int>&);
void quicksort(vector<int>&);
void printv(string str,vector<int> v);

int main(int argc, char* argv[])
{
    int a[] = {6,8,10,9,11,7,5,11};
    vector<int> vt(a,a+8),vt1(a,a+8);
    printv("Origin array : ",vt);
    insertsort(vt); // 1.insertsort
    printv("After insertsort : ",vt);
    vt.clear();vt=vt1;
    selectsort(vt); // 2.selectsort
    printv("After selectsort : ",vt);
    vt.clear();vt=vt1;
    shellsort(vt); // 3.shellsort
    printv("After shellsort : ",vt);
    vt.clear();vt=vt1;
    mergesort(vt); // 4.mergesort
    printv("After mergesort : ",vt);
    vt.clear();vt=vt1;
    heapsort(vt); // 5.heapsort
    printv("After heapsort : ",vt);
    vt.clear();vt=vt1;
    quicksort(vt); // 6.quicksort
    printv("After quicksort : ",vt);
    return 0;
}
void printv(string str,vector<int> v){
    cout << str;
    for(size_t i=0; i<v.size(); i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}
////1. insertsort()////
// �㷨�������1��Ԫ���Ѿ��ź���ӵ�2��Ԫ�ؿ�ʼ��������;
// ʱ�䣺������ҪO(n)*������ҪO(n) = O(n^2);
// �ռ䣺һ��tmp���������Ԫ��O(1);�����˽�����
void insertsort(vector<int> &v){
    /* �ҵĴ������
    size_t j;
    for(size_t i=1; i<v.size(); i++) {
        int tmp = v[i]; // note1
        for(j=i; j>0; j--){
            if(tmp < v[j-1]) v[j] = v[j-1];
            else {
                v[j] = tmp;
                break; // note2
            }
        } 
        if (0 == j) v[0] = tmp;// note3       
    }    
    */
    // �����룺
    size_t j,p;
    int tmp;
    for (p=1; p<v.size(); p++){
        tmp = v[p];
        for (j=p; j>0 && tmp<v[j-1]; j--) 
            v[j] = v[j-1];
        v[j] = tmp;    
    }
}
////2. selectsort()////
// �㷨����0��ʼ����������Ԫ��ѡ����С�ģ����ʼλ�ý�����
// ʱ�䣺O(n^2);   // 5 8 5 2 9 ��5��2������λ���ȶ��Ա��ƻ���
// �ռ䣺0;
void selectsort(vector<int> &v){
    size_t i,j;
    int min;
    for (i=0; i<v.size(); i++){
        min = i;
        for (j=i+1; j<v.size(); j++){
            if (v[min] > v[j]) min = j;            
        }
        swap(v[i],v[min]);
    }
}
////3. shellsort()////
// �㷨����С��������n/2 -> 1��������������ʹ�ò�������;
// ʱ�䣺ƽ��O(n^1.5)���O(n^2)�����ǽϲ��������Ѿ������Ľ�;
// �ռ䣺1����������;
void shellsort(vector<int> &v){
    size_t i,j,increment;
    int tmp;
    for (increment=v.size()/2; increment>0; increment /= 2) {
        for (i=increment; i<v.size(); i++) {
            tmp = v[i];
            for (j=i; j>0 && tmp<v[j-increment]; j-=increment) // note
                v[j] = v[j-increment];
            v[j] = tmp;
        }
    }
}
////4. mergesort()////
// �㷨��ͨ���ݹ���ý������������۰�ֱ��Ϊ1;��ɷǵݹ�ʵ�֣�
// ʱ�䣺ƽ��O(n*log(n));
// �ռ䣺O(n);v2��Ϊ�ȳ�����ʱ�����ʺ�������
void merge(vector<int> &v,vector<int> &v2,
            size_t begin, size_t mid, size_t end){
    //cout << begin << ' ' << mid << ' ' << end << endl;        
    size_t i(begin),j(mid+1),p(begin); // p for v2
    while(i<=mid && j<=end) {
        if(v[i] <= v[j]) v2[p++] = v[i++];
        else v2[p++] = v[j++];
    }
    while(i<=mid) v2[p++] = v[i++];
    while(j<=end) v2[p++] = v[j++];
    // printv("",v2); 
    //v.clear(); v = v2; // note: ֻ�ǽ������򲿷ֿ�����v
    for (size_t k=begin; k<=end; k++) {
        v[k] = v2[k];
    }
}
void msort(vector<int> &v, vector<int> &v2, size_t begin, size_t end){
    int mid;
    if (begin < end) {
        mid = begin + (end-begin)/2;
        msort(v,v2,begin,mid);
        msort(v,v2,mid+1,end);
        merge(v,v2,begin,mid,end);// v����Ϊ2���ӱ�
    }
}
void mergesort(vector<int> &v){
    vector<int> v2(v.size(),0);
   // v2.reserve(v.size()); // push_back�Ǵ����
    msort(v,v2,0,v.size()-1); 
    //v2.clear(); // note
}
////5. heapsort()////
// �㷨��ͨ�����˲��������ѣ���ͨ�����˲���ɾ����Сֵ��������������С���ճ��Ŀռ䣻
// ʱ�䣺ƽ��O(n*log(n));����O(n*log(n)),deleteMin(O(n))��
// �ռ䣺O(n);
/* ���ѣ�n=7)��ԭ���������Ϊ����ѣ�
    31 41 59 26 53 58 97
           |        |  |
*/
void predown(vector<int> &v,int i, int n){
    //������i��Ԫ�أ��ѳ�����n����
    //cout << "i = " << i << endl;
    int child,tmp;
    // leftchild = 2*i+1;
    for (tmp = v[i]; 2*i+1 < n; i=child) {
        child = 2*i+1;
        if (child != n-1 && v[child+1] > v[child]) child++;
        if(tmp < v[child]) v[i] = v[child]; // max heap
        else break;
    }
    v[i] = tmp;
    //cout << i << ':' << v[i] << endl;
}
void heapsort(vector<int> &v){
    // ����size_t��int�ıȽϴ���
    cout << "heapsort.." << endl;
    if (v.empty()) return;
    int i;
    for (i=v.size()/2-1; i>=0; i--) // note '=' & '-1'
        predown(v,i,v.size()); // build heap
    for (i=v.size()-1; i>0; i--) {
        swap(v[0],v[i]); //  
        predown(v,0,i); // deletemax
    }    
}
////6. quicksort()////
// �㷨��ѡ��pivot�����ݹ�ؽ����Ϊ��С�����֣�
// ʱ�䣺ƽ��O(n*log(n)���O(n^2);
// �ռ䣺O(log(n));
void qsort1(vector<int> &v,int s,int e){
    int i(s),j(e),mid;
    int pivot = v[(s+e)/2];
   // cout << "pivot = " << pivot << endl;
    do{
        while (v[i]<pivot && i<e) i++;
        while (v[j]>pivot && j>s) j--;
        if (i <= j) {
            if(i != j)swap(v[i],v[j]);
            i++;
            j--;
        }
    }while (i <= j); // note "<="
    if (i < e) qsort1(v,i,e);
    if (j > s) qsort1(v,s,j);
}
void qsort2(vector<int> &v,int s,int e){
    
}
int median3(vector<int> &v,int s,int e) {
// s,e,mid�������򣬲���pivot�洢��v[e-1]��λ��;
    int mid = s + (s-e)/2;
    if (v[s] > v[mid]) swap(v[s], v[mid]);
    if (v[s] > v[e]) swap(v[s], v[e]);
    if (v[mid] > v[e]) swap(v[mid], v[e]);
    swap(v[mid],v[e-1]);
    return v[e-1];
}
void quicksort(vector<int> &v){
    cout << "quicksort.." << endl;
    if(v.empty()) return;
    qsort1(v,0,v.size()-1);
}









