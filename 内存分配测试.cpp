//内存分配
#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

int a = 0;	//全局区 
char *p1;	//全局区 

int main(){
	
	char p1[] = "abcdefg";//栈区 （因为是数组，所以不是常量区） 
	
	char *p2 = "hahahaha";//"haha"在常量区 
//	strcpy(p2, "1234");//报错，因为 p 指向的是常量区（只读，不能改） 

	

	return 0;
} 
