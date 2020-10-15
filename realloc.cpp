#include <stdio.h>
#include <iostream>
using namespace std;

char *ptr;

int main()
{
	ptr = (char *)malloc(sizeof(char)*8);
	
	/* 功能：在原来开辟空间重新开辟,
	 * 如果开始内存块小，保存原内存块，再次基础新增，如果是开始内存块大，则在此基础减去尾部内存块
	 * */
	realloc(ptr,sizeof(char)*6);

	return 0;
}
