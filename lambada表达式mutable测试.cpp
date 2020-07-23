#include <iostream>
using namespace std;


int main()
{
#if 0 
	size_t v1=42;
    auto f=[v1] () {return v1; };
    cout<<&f<<endl;
    cout<<f()<<endl;
#endif 

#if 0
	size_t v1=42;
	//v1 默认是不可能改的， 所以这句话是不成立的，只有加了mutable 关键字才可以 
    auto f=[v1] () {return ++v1; };
    cout<<&f<<endl;
    cout<<f()<<endl;
#endif

#if 1
	//加了 mutable 之后 v1 就可以 ++ 了 
	size_t v1=42;
    auto f=[v1] () mutable { return ++v1; };
    cout<<&f<<endl;
    cout<<f()<<endl;
#endif

    return 0;
}
