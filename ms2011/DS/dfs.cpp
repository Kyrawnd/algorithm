// dfs() ͼ��������ȱ��� / �ڽӾ���
// by wr-chow at 20111015
// refer to http://blog.csdn.net/lalor/article/details/6845788
// 1. dfs   ͼ��������ȱ���;
// 2. dfs2  ͨ����ȱ����ж�ͼ�Ƿ��л�/�����ж��㿪ʼ��ȱ�����
//          ���ж����̶����Ƿ��ѱ�����;�����Ҫ��ӡ���Ļ�����
//          2�����visit[]�еĵ�ǰ���ʽڵ㣻

#include<iostream>  
using namespace std;  
#define  MAX_NODE 4  
bool visited[MAX_NODE] ;  
int stack[ MAX_NODE] ; 
int Matric[4][4] = { // A-B-C-D(-A) // ����ͼ
    {0,1,0,0}, 
    {0,0,1,0},
    {0,0,0,1},
    {0,0,0,0},
};
int Matric1[12][12] =  {  
     {-1,1,1,0,0,0,0,0,0,0,0,0},  
     {1,-1,1,0,1,1,0,0,0,0,0,0},  
     {1,1,-1,1,0,0,0,0,0,0,0,0},  
     {0,0,1,-1,1,0,0,0,0,0,1,1},  
     {0,1,0,1,-1,0,0,0,0,0,0,0},  
     {0,1,0,0,0,-1,0,0,0,0,1,0},  
     {0,0,0,0,0,0,-1,1,1,1,0,0},  
     {0,0,0,0,0,0,1,-1,0,0,0,0},  
     {0,0,0,0,0,0,1,0,-1,1,1,0},  
     {0,0,0,0,0,0,1,0,1,-1,0,1},  
     {0,0,0,1,0,1,0,0,1,0,-1,0},  
     {0,0,0,1,0,0,0,0,0,1,0,-1},   
}; 

void dfs(int);
bool icdfs(int);
bool isCircle();

int main(int argc,char *argv[])  
{  
    dfs(1);  
    cout << isCircle() << endl;
    return 0 ;  
}  

void dfs(int v) {  
    cout << " v"<< v ;  
    int top = -1 ;  
    visited[v] = true;  
    stack[++top] = v ;  
    while (top != -1) {  
        v = stack[top] ;  
        int i;
        for ( i = 0 ; i < MAX_NODE ; i++)  {  
            if (Matric[v][i] == 1 &&!visited[i]) {  
                cout << " v" << i ;  
                visited[i] = true ;  
                stack[ ++top ] = i ;  
                break ;  
            }  
        }  
        if( i == MAX_NODE)  {  
           top -- ;  
        }  
    }  
    cout << endl;
}

bool icdfs(int v) {
    cout << " v"<< v;  
    int top = -1;  
    visited[v] = true;  
    stack[++top] = v;  
    while (top != -1) {  
        v = stack[top];  
        int i;
        for (i = 0; i < MAX_NODE; i++) {  
            if (Matric[v][i] == 1 && !visited[i]) {  
                cout << " v" << i ;  
                visited[i] = true ;  
                stack[++top] = i ;  
                break;  
            }  
        }  
        // �ж�i�ĺ�̽ڵ��Ƿ���ʹ�������ͼ��
        for (int j=0; j<MAX_NODE; j++)
            if (Matric[i][j] == 1 && visited[j] && j != v) {
                cout << endl;
                return false;
            }
        if(i == MAX_NODE) {  
           top -- ;  
        }  
    }  
    cout << endl;
    return true;
}

bool isCircle(){
    for (int i=0; i<MAX_NODE; i++) {
        if (icdfs(i) == false) return true;
    }
    return false;
}