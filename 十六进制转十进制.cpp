#include<stdio.h>
#define N 50
long fun(char *s)
{
	int i,t;             //t记录临时加的数 
	long sum =0;
	for(i=0;s[i];i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		t=s[i]-'0';       //当字符是0~9时保持原数不变
		if(s[i]>='a'&&s[i]<='z')
		t=s[i]-'a'+10;
		if(s[i]>='A'&&s[i]<='Z')
		t=s[i]-'A'+10;
		sum=sum*16+t;
	}
	return sum;
 } 
int main()
{
	int m;
	char s[N];       //字符串与字符数组相结合的方式 
	printf("Enter 16进制数：");
	scanf("%s",s);        //注意此处%s 
	m=fun(s);
	printf("%d",m);
 }
