#include <iostream>
using namespace std;
 
class Base{
public:
	
	Base(int i){
		cout<<"base i:"<<endl;
	} 
}; 

class Inherit : public Base{
public: 
	//������Ҫ�����ഫ�ݲ��� 
	Inherit(int i): Base(i){
		cout<<"Inherit i:"<<endl;
	}
};

int main()
{
	Inherit a(10);
 	return 0;
}

