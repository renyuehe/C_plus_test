#include <iostream>
using namespace std;

/*
	一共八种方式 2^3 = 8种
	 
	enum ***{}； enum  {};   	一阶 
	typedef 					二阶
	{}***; 	{};					三阶 
		注意：	typedef enum {}***; 	// ***是 类型
				enum {}***; 			// ***是 变量 
				typedef enum Em{}typeEm; 	// enum Em 和 typeEm 都可以定义枚举变量 ，两种同时成立 
*/

#if 0
//**************************************************** 1 *******************
enum Em{
	One,
	Two,
	Three,
	Four,
};


int main(){
	
	enum Em e;	//可以直接 这种方式定义枚举变量 
	e = One;
//	e = 2;	//[Error] invalid conversion from 'int' to 'Em' [-fpermissive]
	
	return 0;
}
#endif
#if 0
//**************************************************** 2 ********************
namespace Area{
	enum Em{
		One,
		Two,
		Three,
		Four,
	};	
}
int main(){
	
	enum Area::Em e;	//加上名字空间可以直接 这种方式定义枚举变量 
	e = Area::One;
	
	return 0;
}
#endif 
#if 0
//**************************************************** 3 ********************
namespace Area{
	typedef enum Em{
		One,
		Two,
		Three,
		Four,
	}typeEm;	
}
int main(){
	// enum Em 和 typeEm 都可以定义枚举变量 ，两种同时成立 
	Area::typeEm e;		
//	enum Area::Em e;	
	e = Area::One;
	
	return 0;
}
#endif
#if 0
//**************************************************** 4 ********************
namespace Area{
	typedef enum{
		One,
		Two,
		Three,
		Four,
	}typeEm;	
}
int main(){
	Area::typeEm e;		
	e = Area::One;
	
	return 0;
}
#endif 
//**************************************************** 5 ******************** 
#if 1
	namespace Area{
		enum{
			One,
			Two,
			Three,
			Four,
		}e;	
	}
	int main(){
		Area::e = Area::One;	
		
		return 0;
	}
#endif
//**************************************************** 6 ******************** 
//**************************************************** 7 ******************** 
//**************************************************** 8 ******************** 

