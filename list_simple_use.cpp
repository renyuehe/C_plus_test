#include <iostream>
#include <list>
using namespace std;

class A{
public:
	A(){
	}
	A(string name){
		this->name = name;
		cout<<"struct "<<name<<endl;
	}
	~A(){
	}
	string name;
};

int main(){
	list<A> la;
	A a1("A");
	A a2("B");
	A a3("C"); 
	la.push_front(a1);
	la.push_front(a2);
	la.push_front(a3);
	
	list<A>::iterator iter;
	
	//从前向后显示  la  中的数据   
    for (iter = la.begin(); iter != la.end(); ++iter)   
        cout << (*iter).name << " ";   
    cout << endl;   
}
