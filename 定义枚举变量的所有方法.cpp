#include <iostream>
using namespace std;

/*
	һ�����ַ�ʽ 2^3 = 8��
	 
	enum ***{}�� enum  {};   	һ�� 
	typedef 					����
	{}***; 	{};					���� 
		ע�⣺	typedef enum {}***; 	// ***�� ����
				enum {}***; 			// ***�� ���� 
				typedef enum Em{}typeEm; 	// enum Em �� typeEm �����Զ���ö�ٱ��� ������ͬʱ���� 
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
	
	enum Em e;	//����ֱ�� ���ַ�ʽ����ö�ٱ��� 
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
	
	enum Area::Em e;	//�������ֿռ����ֱ�� ���ַ�ʽ����ö�ٱ��� 
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
	// enum Em �� typeEm �����Զ���ö�ٱ��� ������ͬʱ���� 
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

