#include <iostream>
#include <memory>

using namespace std;

#if 0
int& fun(int n){
	int a = n;
	return a;
}
int main(){	
	cout << fun(10) <<endl;
	return 0;
}

#else

int main(){

	int a = 10;
	int *ptr = &a;
//	int &w = &ptr;//[Error] invalid initialization of non-const reference of type 'int&' from an rvalue of type 'int**'
//	int &y = ptr; //[Error] invalid initialization of reference of type 'int&' from expression of type 'int*'
	int &ra = *ptr;
//	free(ptr);
	*ptr = 20;	//如果没有这一句，ra 就无法输出，因为引用是和内容绑定的 
	cout<<*ptr<<endl;	
	cout<<ra<<endl;	//只要ptr 再次赋值就可行 ，如果ptr 指向的空间被释放了就不行（ra 是 ptr的别名） 
	 
	return 0;
}

#endif

