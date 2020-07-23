#include <iostream>
using namespace std;

class A
{
public:
	A(){
		cout<<"A construction"<<endl;
	}
	~A(){
		cout<<"A destruction"<<endl;
	}
	
private:
    int *p;
};

//´«²ÎÊ± new  
void test(A *b = new A)
{
	delete b;
}

int main()
{
	test();

    return 0;
}
