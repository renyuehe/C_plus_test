
/* Java 中反射的形式
	ClassT* obj = FactoryCreate("ClassT");
*/ 

/** 
我们使用简单工厂模式感觉好像是解决了问题，可以实现用字符串去new一个对应的对象，
但是假如我们要新建一个类或者修改一个类，那么这个FactoryCreat都要进行修改。十分不利于维护。
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


