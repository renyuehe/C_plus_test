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
	*ptr = 20;	//���û����һ�䣬ra ���޷��������Ϊ�����Ǻ����ݰ󶨵� 
	cout<<*ptr<<endl;	
	cout<<ra<<endl;	//ֻҪptr �ٴθ�ֵ�Ϳ��� �����ptr ָ��Ŀռ䱻�ͷ��˾Ͳ��У�ra �� ptr�ı����� 
	 
	return 0;
}

#endif

