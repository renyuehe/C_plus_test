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
	
	a = QFont(10); //构造函数直接通过临时变量赋值 同类型对象 
	
	a.show();
	
	return 0;
 } 
