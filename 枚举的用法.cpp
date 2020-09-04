#include <stdio.h> 
#include <iostream>
using namespace std;

#if 0 
enum em{
	One,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven
};
int main()
{	
	//em e = em(One);
	//em e = em::Two;
	em e = Three;
	cout<<e;
	
	return 0;
}
#else 
namespace A{

	enum em{
		One,
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven
	};
}
int main()
{	
//	em e = em(Seven);
	A::em e = A::(em(seven));	 //这个语法应该怎么改 
//	A::em e = A::em::Two;
//	A::em e = A::Three;
	cout<<e;
	
	return 0;
}
#endif

