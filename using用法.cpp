/*
using namespace std;//�ͷ����������ռ䵽��ǰ������
using std::cout;    //�ͷ�ĳ����������ǰ������
*/

#include <iostream>
using namespace std;

#define DString std::string    //! ������ʹ�ã�
typedef std::string TString;   //! ʹ��typedef�ķ�ʽ
using Ustring = std::string;   //��ʹ�� using typeName_self = stdtypename;


//typedef void *tFunc(int a);//ע�⣺�����������ţ���Ȼ���� [Warning] declaration of 'void* tFunP(int)' has 'extern' and is initialized
//��ֱ��
typedef void (*tFunc)(int a); 
using uFunc = void(*)(void);

void tFun(int a){
	cout<<"tFun:"<<a<<endl;
}
void uFun(void){
	cout<<"uFun"<<endl;
} 

int main(int argc, char *argv[])
{

    TString ts("String!");
    Ustring us("Ustring!");   
	string s("sdfdfsd");
	cout<<ts<<endl;
    cout<<us<<endl;
    cout<<s<<endl;
    
    cout<<endl;
    
    tFunc tFunP = tFun;
    uFunc uFunP = uFun;
    tFunP(10);
    uFunP();
    return 0;
}
