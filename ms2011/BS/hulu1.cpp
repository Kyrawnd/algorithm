// hulu1 ������- 50����ÿ��ɾ������/ż�����ʣ�µ���
// by wrchow at 20110926

#include <iostream>
#include <vector>
using namespace std;

int oddeven50(int f){
// ����˼��
    if(f == 1) cout << "Delete odd.." << endl;
    else cout << "Delete even.." << endl;
    vector<int> v;
    v.clear();
    int i=0;
    for (i=1; i<=50; i++) {
        v.push_back(i);
    }
    while (v.size() != 1) { // ���鲻��ѭ��ɾ��
        vector<int> t;
        for (i=f; i<v.size(); i+=2){   
            t.push_back(v[i]);
            cout << v[i] << ' ';
        }  cout << endl;
        v.clear();
        v=t;
    }   
    return v[0];
}

int * postOrder() {
    
}

int main()
{
    // ---------------------
    cout << "odd & even of 1..50 is :"  // 32 & 1
         << "odd = " <<  oddeven50(1)   
         << ", even = " << oddeven50(0) << endl;  //��ߵ��ȵ���  
    // --------------------- 
     
    return 0;
}