#include <stdio.h>
#include <iostream>
using namespace std;

char *ptr;

int main()
{
	ptr = (char *)malloc(sizeof(char)*8);
	
	/* ���ܣ���ԭ�����ٿռ����¿���,
	 * �����ʼ�ڴ��С������ԭ�ڴ�飬�ٴλ�������������ǿ�ʼ�ڴ������ڴ˻�����ȥβ���ڴ��
	 * */
	realloc(ptr,sizeof(char)*6);

	return 0;
}
