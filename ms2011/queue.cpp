// ����ʵ��queue, refer to �����ݽṹ���㷨������C���ԣ���

#include <iostream>
#include <string>
using namespace std;

class Queue{
public:
    Queue();
    bool empty(){
    }
    bool full(){
    }
    void makeEmpty(){
    }
    char front(){
    }
    void enqueue(){
    }
    void dequeue(){
    }
        
private:
    int capacity;
    int front;
    int rear;
    int size;
    char *m_q;
}; // class Queue

int main(int argc, char *argv[])
{
    string s(argv[1]);
    Queue qe;
    for (int i=0; i<s.size(); i++) {
        qe.enqueue(s[i]);
    }
    qe.dequeue();
    return 0;
}