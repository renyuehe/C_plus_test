#include <iostream>
using namespace std;

class QFont{
public:
	QFont(int a){
		this->a = a;	
	}
	QFont(){	
	}
	~QFont(){
	}

	void show(){
		cout<<a<<endl;
	}
private:
	int a;
};


int main()
{
	QFont a;
	
	a = QFont(10); //���캯��ֱ��ͨ����ʱ������ֵ ͬ���Ͷ��� 
	
	a.show();
	
	return 0;
 } 
