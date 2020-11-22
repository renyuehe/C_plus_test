#include <iostream>
using namespace std;

//结论： 类嵌套类，一定是用指针 
 
#if 0
//类嵌套类，如果不是指针，则报错 [Error] has incomplete type 'Base'
class Base{
	public:
		Base(){ name = "Base 你好";
			
		}
		
		Base b;
		
		string name;
};

int main(){
	
	return 0;
}
#endif 

#if 1
//类嵌套类  指针可用  √ √ √ √ √ √ √ √ √ √ √ 
class Base{
	public:
		Base(){ name = "Base 你好";
			
		}
		
		Base *b;
		
		string name;
};

int main(){
	
	Base *b = new Base;
	cout << b->name << endl;
	
	b->b = b;
	cout << b->b->name <<endl;
	cout << b->b->b->b->b->b->b->b->b->name<<endl;
	return 0;
}
#endif 


