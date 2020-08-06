#include <iostream>
using namespace std;

class Base
{
public:
    Base(){;}
private: 
    virtual void func1()
    {
        cout <<"Base:func1" <<endl;
    }

    virtual void func2()
    {
        cout <<"Base:func2" <<endl;
    }

    virtual void func3()
    {
        cout <<"Base:func3" <<endl;
    }
};

class Derive: public Base
{
public:
    Derive(){;}
private:
    void func1()
    {
        cout <<"Derive: func1" <<endl;
    }
    void func2()
    {
        cout <<"Derive: func2 "<<endl;
    }
};

typedef void (*Fun)();

typedef int u32;
//typedef long u32;
typedef long long u64;//���ݲ�ͬ�ı���������������ʹ�� (32λ)4�ֽ� (64λ)8���ֽڣ���ȷ������ʹ�� int �� long �� ���� long long 


//ȷ��Ŀ�꣺����ָ�� ȡ �麯��  typedef void (*Fun)();
//������������ ָ���λ�� , Ҫ������ȷ��ת��  �Ȳ��� sizeof(void *)<<endl ����ѡ�� sizeof(long long) ������ typedef long long u64;
//����ָ�� ָ��һ��ָ�����飬���ָ������ĵ�һ��Ԫ�ش�ŵ����麯������׵�ַ  : u64 address = ((u64*)p)[0]; ���ڵڶ���Ԫ�أ�������������Ҫ�о� 
//�麯����ĵ�ַ �ֶ�Ӧһ�� ָ�����飬���ָ�������Ԫ�����ζ�Ӧ ��Ӧ���麯��  ��Fun fun= (Fun)(  ((u64*)address)[0] );
//	Fun fun= (Fun)(  ((u64*)address)[0] );
//    fun = (Fun)(  ((u64*)address)[1]  ) ;
//    fun = (Fun)(  ((u64*)address)[2]  );
int main()
{
	cout <<"�������� sizeof(void *)λ�ģ�"<<sizeof(void *)<<endl; 
    cout <<"int:"<< sizeof(int) << endl;
    cout <<"long:"<< sizeof(long) << endl;
    cout <<"long long:"<< sizeof(long long) << endl;
    cout <<"choose:"<< sizeof(u64) << endl;
    cout <<endl;
	
    Base *p = new Derive;
#if 1
    u64 address = *(u64*)p;//p�Ƕ����ָ�� ��  (u32*)p ��һ��ָ������ �� *(u32 *)p ��ָ���������ָ�� �ȼ��� ((u32 *)p)[0]   
#else if
	u64 address = ((u64*)p)[0];	//�ȼ��� u32 address = *(u32*)p;
#endif
//	u32 address = ((u32 *)p)[1];	//��Զ�ˣ�
 
    cout << "�麯������׵�ַ��" << address << endl;// address �麯������׵�ַ 

#if 0 
	//address �麯������׵�ַ���ٽ�һ��ȡ * ����ȡ���麯���� 
	
    Fun fun= (Fun)(*(u64*)address);
    fun();
    
    fun = (Fun)(*(((u64*)address)+1));
    fun();
    fun = (Fun)(*((u64*)address+2));
    fun();
#else if
	//address �麯������׵�ַ���ٽ�һ��ȡ * ����ȡ���麯���� 
	Fun fun= (Fun)(  ((u64*)address)[0] );
    fun();
    
    fun = (Fun)(  ((u64*)address)[1]  ) ;
    fun();
    fun = (Fun)(  ((u64*)address)[2]  );
    fun();	
#endif
    
    return 0;
}

