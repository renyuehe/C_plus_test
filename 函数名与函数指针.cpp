#include <stdio.h>
#include <iostream>
using namespace std;


//�ܽ᣺ֵ��û������ģ�����������ʽ������ʱ���ܲ�ͨ�� 
void fun(){
	
} 

int main()
{
	cout<<fun<<endl;
	cout<<&fun<<endl;
	
	printf("fun ��ӡd: %d" , fun);
	printf("\n");
	printf("&fun ��ӡd: %d" , &fun);
	printf("\n");
	printf("fun ��ӡp: %p" , fun);
	printf("\n");
	printf("&fun ��ӡp: %p" , &fun);
	printf("\n");
	
	return 0;
}
