#include <iostream>
using namespace std;
 
class Base{
public:
	virtual void show(){
		cout<< "base show virtual "<<endl;
	}
}; 

class Inherit : public Base{
public: 
	void show(){
		Base::show();
		cout<<" m show "<<endl;
	}
};

int main()
{
	Inherit a;
	a.show();
	
 	return 0;
}

