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

//����ʱ new  
void test(A *b = new A)
{
	delete b;
}

int main()
{
	test();

    return 0;
}
