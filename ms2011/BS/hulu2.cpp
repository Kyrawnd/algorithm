// hulu2.cpp by wrchow at 20110924-20:05~21:33
// ��֪����ǰ����������������������
/* �㷨������
    1. ǰ��/�������������
    2. �����������������(�����Ǳ����)
    3. �ݹ���������..
*/
#include <iostream>
#include <vector>
using namespace std;

struct node{
    int     data;
    node*   left;
    node*   right;
};

node* createTreeNode(int d);
node* createTree(vector<int> &pre, vector<int> &in); // ǰ��������
void postOrder(vector<int> &post,node *t); // ������ӡ��
int findv(vector<int> &v, int x);

int main()
{
    int prea[] = {8,6,5,7,10,9,11};
    int ina[] = {5,6,7,8,9,10,11};
    vector<int> pre(prea,prea+7),in(ina,ina+7);
    node* head = createTree(pre,in);
    vector<int> post;
    cout << "postOrder : ";
    postOrder(post,head);
    //vector<int>::iterator it = post.end();
    //cout<< post.at(it) << endl; // error
    return 0;
}

node* createTreeNode(int d){
    node* tn = new node;
    tn->data = d;
    tn->left = NULL;
    tn->right = NULL;
    return tn;
}

node* createTree(vector<int> &pre,vector<int> &in){
    if(pre.empty() && in.empty()) return NULL;
    // 1. ǰ��/�������������
    node *head = createTreeNode(pre[0]);
    if (pre.size() == 1 && in.size() == 1) return head;
    int div = findv(in,head->data);                     cout << "div = " << div << endl;
    // 2. �����������������
    vector<int> leftin(in.begin(), in.begin()+div);     cout << "leftin size = " << leftin.size() << endl;
    vector<int> rightin(in.begin()+div+1, in.end());    cout << "rightin size = " << rightin.size() << endl;
    vector<int> leftpre(pre.begin()+1, pre.begin()+1+leftin.size()); cout << "leftpre size = " << leftpre.size() << endl;
    vector<int> rightpre(pre.end()-rightin.size(), pre.end()); cout << "rightpre size = " << rightpre.size() << endl;
    // ע��pre.end()����ָ�����һ��Ԫ��
    head->left = createTree(leftpre,leftin);   
    head->right = createTree(rightpre,rightin);
    return head;
}

void postOrder(vector<int> &post, node* t){
    if (t) {
        postOrder(post,t->left);
        postOrder(post,t->right);
        post.push_back(t->data);
        cout << t->data << ' ';
    }
}

int findv(vector<int> &v,int x){
    for (int i=0; i<v.size(); i++) {
        if (v[i] == x) return i;
    }
    return -1;
}




