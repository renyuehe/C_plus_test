/*
using namespace std;//释放整个命名空间到当前作用域
using std::cout;    //释放某个变量到当前作用域
*/

#include <iostream>
using namespace std;

#define DString std::string    //! 不建议使用！
typedef std::string TString;   //! 使用typedef的方式
using Ustring = std::string;   //！使用 using typeName_self = stdtypename;


//typedef void *tFunc(int a);//注意：这里必须加括号，不然报错 [Warning] declaration of 'void* tFunP(int)' has 'extern' and is initialized
//更直观
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
