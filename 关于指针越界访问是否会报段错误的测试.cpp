#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	int *pa = &a;
	cout <<"&pa = "<< &pa << endl;	//pa �����ջ����ַ 
	cout <<"pa = "<< pa << endl;	//pa ָ���ջ����ַ 
	cout<<"pa + 1  = "<<(pa+1)<<endl;
	*(pa + 1) = 25;	//ջ����Խ�縳ֵ 
	
	
	int *b = new int;
	cout <<"&b = "<< &b << endl;	//b �����ջ����ַ 
	cout <<"b = "<< b << endl;		//b ָ��� ���� ��ַ
	cout<<"b + 1  = "<<(b+1)<<endl;
	*(b + 1) = 30; 	//������Խ�縳ֵ 
	
	
	int *w;
	cout<<"&w = "<<&w<<endl;
	cout<<"w = "<<w<<endl;
	cout<<"w + 1 = "<<(w+1)<<endl;
//	*w = 40;	//*w ���ܸ�ֵ����Ϊ��wָ�����ں��� 
//	*(w+1) = 50;	// *(w+1) ���ܸ�ֵ����Ϊ��w + 1 ָ�����ں��� 
	

#if 0 
	int *m;  
	// m ԭ��ָ�� 0x40e995 
	cout<<"&m = "<<&m<<endl;
	cout<<"m = "<<m<<endl;
	cout<<"m + 1 = "<<(m+1)<<endl;
	*(m + 1) = 60;	//m ԭ��ָ�� 0x40e995 ,�������֪����ʲô�������Բ���ȷ���Ƿ��δ��� 
#else
	int *m;  
	m = (int *)0x6ffe0c;	// m ԭ��ָ�� 0x40e995 
	cout<<"&m = "<<&m<<endl;
	cout<<"m = "<<m<<endl;
	cout<<"m + 1 = "<<(m+1)<<endl;
	*(m + 1) = 60;	//���ڰ� m ��ָ���Ϊ��ջ���� �����ֿ���ջ����Խ������� 
#endif 
	
    return 0;
}
