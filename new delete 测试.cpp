/*
new  ��  delete  ����
*/ 

#include <iostream>
using namespace std;

class A{
public:
	~A(){
		cout<<"������"<<endl; 
	}
	
	void setCapacity(int n){
		this->_capacity = n;
	}
	void showCapacity(){
		cout<<"capacity is :"<<_capacity<<endl;
	}
private:
	int _capacity;
};

int main(){
	
	A *a = new A;
	A *b = new A [10];
	
	b[0].setCapacity(11);	
	b[0].showCapacity();
	b[3].setCapacity(19);
	b[3].showCapacity();
	
	b->setCapacity(111);
	b->showCapacity();
	(b+1)->setCapacity(112);
	(b+1)->showCapacity();
	(b+16)->setCapacity(116);	//��Ȼû������������Խ���� 
	(b+16)->showCapacity();		//��Ȼû��������Խ���� 
	
	
	delete a;
//	delete b;	//�������ʱ���Ǵ����� �����������ʽ������ʱҲҪ�� [] �����򱨴� !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	delete [] b;

	
	return 0;
}
