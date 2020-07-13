#include <iostream>
using namespace std;

class A
{
public:
   operator   int() { return this->b_; } 
   operator const   int() { return this->b_; }
   operator   int&() { return this->b_; }
private:
   int b_;
};

int main(){
	A a;
	
	return 0;
} 


