// treeByArray
// by wr-chow at 20110830

/*
refer to http://wenku.baidu.com/view/902e52ff700abb68a982fb35.html
	�������ķǵݹ���������������򣬺���
	�Ӹ��ڵ�����ѹջ��ѹ���׷�������Ǹ��㣬�ڿ�ͬ�����Ǹ�������ͬ��������
	����������ѹ���׷���֪��������������ʹ��ˣ��Ͱ��Һ��ӷ��ʣ���֮������
	���ʸ��ڵ�֮ǰҪȷ�������Һ��Ӷ��Ѿ����ʹ������Ҫ�ǳ�ע��ջ�Ĵ���
test data:
13
ABD*F***CE***
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node{
	char c;
	Node *lchild, *rchild;
	bool flag;
};

int top = -1;
char getonech(char ar[])
{
	static int i;
	return ar[i++];
}

void Create(Node *&p, char ar[])
{
	char ch;
	ch = getonech(ar);
	//cout << ch << " ";
	if (ch != '*') {
		p = new Node;
		p -> flag = 0;
		p -> c = ch;
		Create(p->lchild, ar);
		Create(p->rchild, ar);
	}
	else
		p = NULL;
}

// �ǵݹ��������
void preorder(Node *r, Node *Stack[])
{
	Node *p = r;
	while(p != NULL || top != -1)
	{
		if(p != NULL)
		{
			cout << p ->c;
			top++;
			Stack[top] = p;
			p = p ->lchild;
		}
		else
		{
			p = Stack[top];
			top --;
			p = p-> rchild;
		}
	}
}

int main(int argc, char *argv[])
{
	char s[100];
	Node *tree;
	int n;
	printf("Input n : ");
	scanf("%d", &n);
	getchar();
	printf("Input n chs : ");
	for (int i=0; i<n; i++) {
		scanf("%c", &s[i]);
	}
	Create(tree, s); // create tree
    /*
	// PreOrder Tree
	Node *Stack1[100] = {0};
	top = -1;
	preorder(tree, Stack1);
	//Node* Stack2[100] = {0};
    */
	return 0;
}











