// ������ C++ ��ʵ��
// by wrchow@20110911
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MyList;
//��ǰ���� 
class LNode
{//�����  friend MyList;
public:
    int data;
    LNode *next;
};
class MyList{
//������ 
public: 
    void InitList(int n);//ͷ�巨��ʼ����ͷ���ı�,����Ϊn,����ͷ��� 
    void DestroyList();//�ݻٱ� 
    void ClearList();//��ձ� 
    bool ListEmpty();//�п� 
    int ListLength();//ȡ�� 
    int GetElem(int i);//ȡ��i������ֵ 
    int LocateElem(int e);//�ҳ�ֵΪe��Ԫ���ǵڼ���Ԫ�� 
    bool ListInsert(int i, int e);//��i��λ�ò���Ԫ��e 
    bool ListDelete(int i);//ɾ����i��Ԫ�� 
    void PrintList();//������� 
public:
    void initList(); // wrchow
    void initList(string); // wrchow
private: 
    LNode *head;//ͷָ�� 
};
void MyList::InitList(int n)
{ 
    int x;
    head = new LNode;
    head->next = NULL;
    for(int i=n;i>0;--i){
        cin>>x;
        LNode *p = new LNode;
        p->data = x;
        p->next = head->next;
        head->next = p;
    }
}

void MyList::DestroyList()
{ 
    delete head;
    cout<<"��ݻ���!"<<endl;
}
void MyList::ClearList()
{ 
    head->next = NULL;
    cout<<"������!"<<endl;
}
bool MyList::ListEmpty()
{
    if(head->next == NULL) return true; else return false;
}
int MyList::ListLength()
{
    LNode *p=head;
    int j=0;
    while(p->next){ 
        p=p->next; 
        j++; 
    } 
    return j;
}
int MyList::GetElem(int i)
{ 
    int j=1;
    LNode *p=head->next;//��һ����� if(i<1) return NULL;
    while(p&&j<i){
        p=p->next; 
        j++; 
        } 
    return p->data;
}
int MyList::LocateElem(int e)
{
    int i=0; LNode *p=head->next;
    while(p!=NULL&&p->data!=e)
    {
        p=p->next;
        i++;
    }
    if(p==NULL) return 0;
    else return i+1;
}
bool MyList::ListInsert(int i, int e)
{ 
    LNode *p, *s;
    int j=1;
    p=head;
    while(p&&j<i)
    {p=p->next;j++;}
    if(p==NULL) return false;
    if((s = new LNode)==NULL) return false;
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}
bool MyList::ListDelete(int i)
{ 
    LNode *p,*q;
    int j=1;
    p=head;
    while(p&&j<i)
    { p=p->next;j++;}
    if(p==NULL) return false;
    q=p->next;
    p->next=q->next;
    delete q;
    return true;
}
void MyList::PrintList()
{ 
    if(ListEmpty()){ 
        cout<<"���ǿյģ�"<<endl;
    } else { 
        cout<<"����Ԫ��Ϊ:";
        LNode *p = head->next;
        while(p!=NULL)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
}

/////////wrchow/////////
void MyList::initList()
{
    head = new LNode;
    head->next = NULL;
}


int main(int argc,char *argv[])
{
    string str = argv[1]; 
    MyList mlist;    
    cout << "isEmpty : " << mlist.ListEmpty() << endl;
    cout << "init List(int) :" << mlist.InitList(str) << endl;
    return 0;
}
