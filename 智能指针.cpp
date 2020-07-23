//ÖÇÄÜÖ¸Õë
#include <stdio.h>
#include <iostream>
#include <memory>

using namespace std;

class Person{
public:
	Person(){
		this->name = "default";
	}
	Person(string name){
		this->name = name;
	}
private:
	string name;
};

int main(){
	
	shared_ptr<Person> pt1(new Person("libai"));
	
	shared_ptr<int> pt2(new int());
	
	
	
	return 0;
}
