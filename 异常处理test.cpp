//�쳣����
#include <iostream>
using namespace std;


int main(){
	try{
		//try ���з��ÿ����׳��쳣�Ĵ��� -�� ��������
		//new �ռ�̫�������ڴ�ʧ�ܣ��ͻ��׳��쳣 
		char * p = new char[0xfffffffff];
	}
	catch(exception e){
		cout<<"new space fail"<<endl;//�����쳣������ exception ��ϵͳ�쳣 
//		cout<<"new space fail"<<e.what()<<endl;
	}
	
	return 0;
} 
