#include <iostream>
using namespace std;

template<class T>
inline T* _allocate(ptrdiff_t size,T*)
{
    set_new_handler(0);
    T* tmp=(T*)(operator new((size_t)(size*sizeof(T))));
    if(tmp==0)
    {
        cerr<<"out of memory"<<endl;
        exit(1);
    }
    else
    {
    	cout<<"temp is not 0"<<endl;
	}
    return tmp;
}

int main(){
	int *a;
	int b = 19;
	a = &b; 
	_allocate(100, a);
	
	return 0;
}

