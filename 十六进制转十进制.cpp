#include<stdio.h>
#define N 50
long fun(char *s)
{
	int i,t;             //t��¼��ʱ�ӵ��� 
	long sum =0;
	for(i=0;s[i];i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		t=s[i]-'0';       //���ַ���0~9ʱ����ԭ������
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
	char s[N];       //�ַ������ַ��������ϵķ�ʽ 
	printf("Enter 16��������");
	scanf("%s",s);        //ע��˴�%s 
	m=fun(s);
	printf("%d",m);
 }
