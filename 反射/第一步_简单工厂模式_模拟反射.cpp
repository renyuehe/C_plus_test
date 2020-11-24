
/* Java �з������ʽ
	ClassT* obj = FactoryCreate("ClassT");
*/ 

/** 
����ʹ�ü򵥹���ģʽ�о������ǽ�������⣬����ʵ�����ַ���ȥnewһ����Ӧ�Ķ���
���Ǽ�������Ҫ�½�һ��������޸�һ���࣬��ô���FactoryCreat��Ҫ�����޸ġ�ʮ�ֲ�����ά����
**/
#include <iostream>
#include <list>
#include <Vector>
using namespace std;


class Object
{
public:
    virtual string ToString() = 0;
};

class MyClass :public Object
{
public:
    virtual string ToString(){ return "MyClass"; }
};



class ClassA : public MyClass{
public:
	string ToString(){
		cout<<"A to stream";
	}	
};

class ClassB : public MyClass{
public:
	string ToString(){
		cout<<"B to stream";
	}	
};

class ClassC : public MyClass{
public:
	string ToString(){
		cout<<"C to stream";
	}	
};

class ClassD : public MyClass{
public:
	string ToString(){
		cout<<"D to stream";
	}	
};



Object* FactoryCreat(const string& className)
{
    if (className == "ClassA"){
    	return new ClassA;
	}
    else if (className == "ClassB"){
    	return new ClassB;
	}
    else if(className == "ClassC"){
    	return new ClassC;
	}
    else if(className == "ClassD")
    {
    	return new ClassD;
	}
}

int main() {

	

	Object* obj = FactoryCreat("ClassC");
    cout << obj->ToString();
    delete obj;
    
    
	return 0;
}


