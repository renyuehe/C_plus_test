#include <iostream>
using namespace std;

#if 0	//��º��� 
class fun{
public:
	void operator()(){
		cout<<"�º���"<<endl;
	}
};
#else	//�ṹ��º��� 
struct fun{
	void operator()(){
		cout<<"�º���"<<endl;
	}
};
#endif

int main(){
	
//	fun f;	//����� 
	
	struct fun f;	//�ṹ����� 
	f();
	
	return 0;
} 
