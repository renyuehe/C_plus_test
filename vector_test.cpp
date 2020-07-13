#include <iostream>
#include <vector>
using namespace std;

class A{
public:
	A(){
		this->name = "¹þ¹þ";
		num = 19;
	} 
	int show(){
		cout<<name<<endl;
		cout<<num<<endl;
		cout<<"---------\n";
	}
	
private:
	string name;
	int num;
};

int main(){
	
	A a;
	vector <A> as;
	as.push_back(a);
	cout<<as.at(0).show();
	
	return 0;
}
