// by wr-chow at 2011-3-10
// refer to http://zhidao.baidu.com/question/48996976.html

//�ݹ鷨
//�������е�10����ϣ����Բ��������ĵݹ�˼������������Ϻ������㷨��
//�躯��Ϊvoid    comb(int m,int k)Ϊ�ҳ�����Ȼ��1��2��... ��m����ȡk������������
//�ϡ�����ϵĵ�һ������ѡ��ʱ�����������Ǵ����µ�m-1������ȡk-1������ϡ���
//�ͽ���m������ȡk�������������ת������m-1������ȡk-1������������⡣�躯����
//�빤������a[ ]����������ϵ����֣�Լ��������ȷ����k��������ϵĵ�һ�����ַ�
//��a[k]�У���һ���������󣬲Ž�a[ ]�е�һ������������һ����������m��m-1��
//...��k��������ȷ����ϵĵ�һ�����ַ�������������ֿ��ܵ�ѡ����δȥ����
//�ϵ�����Ԫ�أ������ݹ�ȥȷ����������ȷ������ϵ�ȫ��Ԫ�أ���������ϡ�ϸ��
//�����³����еĺ���comb��
 

#include <time.h>
#include <iostream>

using namespace std;

# define      MAXN      100
int a[MAXN];
int counts=0;

 

void comb(int m, int k)
{     
	int i,j;
    for (i = m; i >= k; i--)
      {    
		  a[k] = i;
          if (k > 1)
              comb(i-1, k-1);
          else
          {   
              counts++;
              /*for (j = a[0]; j  > 0; j--)
                  printf("%4d",a[j]);
              printf("\n");*/
          }
      }
}

int main()
{   
	 time_t start = 0;
     time_t end   = 0;
     int m, r;
     cout << "m = ";     cin >> m;
     cout << "r = ";     cin >> r;
     counts = 0;
     a[0] = r;
	 start = time(0);
     comb(m, r);
	 end = time(0);
     cout << counts << endl;
	 printf("Total time is %d s.\n", end - start);
     return 0;
}

