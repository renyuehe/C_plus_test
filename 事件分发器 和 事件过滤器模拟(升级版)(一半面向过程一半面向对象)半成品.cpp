#include <stdio.h>
#include <iostream>
using namespace std;

class Event{
public:
	//ö�� 
	enum{
		One,
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten, 
	};	
	//�����¼����� 
	int Type(){
		return t;
	}
	//�����¼����� 
	void setType(int n){
		t = n;
	}
	//�¼����� 
	int t;
};

class A{
public:
	//ͨ��filterFlag��־��ʾ��װ���¼���������ͨ�� watched �����հ�װ�������Ķ��� 
	void installEventFilter(A *obj){
		watched = obj;
		filterFlag = 1;
	}
	
protected:
	//�¼��ַ��� 
	virtual bool event(Event *e){
		if(e->Type() == 1){
			cout<<"A ��  One�¼� ����"<<endl;
		}
		else if(e->Type() == 2){
			cout<<"A ��  Two�¼� ����"<<endl;
		}
		else if(e->Type() == 3){
			cout<<"A ��  Three�¼� ����"<<endl;
		}
		else if(e->Type() == 4){
			cout<<"A ��  Four�¼� ����"<<endl;
		}
		else if(e->Type() == 5){
			cout<<"A ��  Five�¼� ����"<<endl;
		}
		else if(e->Type() == 6){
			cout<<"A ��  Six�¼� ����"<<endl;
		}
		else if(e->Type() == 7){
			cout<<"A ��  Seven�¼� ����"<<endl;
		}
		else if(e->Type() == 8){
			cout<<"A ��  Eight�¼� ����"<<endl;
		}
		else if(e->Type() == 9){
			cout<<"A ��  Nine�¼� ����"<<endl;
		}
		else if(e->Type() == 10){
			cout<<"A ��  Ten�¼� ����"<<endl;
		}
	}
	//�¼������� 
	virtual bool eventFilter(A *watched, Event *e){
		cout<<"A�� ԭ���¼�������"<<endl;
	}

	//������̫ţ�ˣ����������� ���� ���ݵ��м��� �������� �ڲ������ݲ���ʹ��ʱ������������ʹ 
	Event *e;
	A *watched;
	int filterFlag = 0;
};

//ֻ��Ҫ��д B ��� event ���� eventFilter �Ϳ���ʵ���¼����� 
class B:public A{
public:
	//��QT�ͬ�������QT����дevent()�������������ж� filterFlag��Ҫ�ﵽ��ȫģ���������һ������������
	virtual bool event(Event *e){								//*
		//�����װ���¼������� 							//*
		if(filterFlag==1)								//*
		{												//*
			if(eventFilter(watched, e)){				//*
				return true;							//*
			}											//*
		}												//*
	//��QT�ͬ�������QT����дevent()�������������ж� filterFlag��Ҫ�ﵽ��ȫģ���������һ������������

		if(e->Type() == 1)
		{
			cout<<"B ��  One�¼� ����"<<endl;
			return true;
		}
		else{
			A::event(e);//����һ�����⣬QT��������Ȼ���õ���QWidget���µ�event();��������Ȼִ����Widget���event(),Ҳ����˵Qt ʵ���˸��������ഫ���¼� 
		}	
	}	
	
	virtual bool eventFilter(A *watched, Event *e){
		if(e->Type() == 1){
			cout<<"B�� ��д���¼�������"<<endl; 
			return false; //�ĳ� true �Ϳ��Լ����ضϴ��� 
		}
		else{
			return A::eventFilter(watched, e);
		}
	}	
};

class C:public B{
public:

	bool event(Event *e){													
		if(filterFlag==1)								
		{									
			if(eventFilter(watched, e)){						
				return true;						
			}								
		}									

		if(e->Type() == 1)
		{
			cout<<"C ��  One�¼� ����"<<endl;
			return true;
		}
		else{
			A::event(e);//����һ�����⣬QT��������Ȼ���õ���QWidget���µ�event();��������Ȼִ����Widget���event(),Ҳ����˵Qt ʵ���˸��������ഫ���¼� 
		}	
	}	
	
	bool eventFilter(A *watched, Event *e){
		// ������һ������ ��� д�� if(watched == a1){...} �ͻᱨ�� , ԭ�� QT �е� main ֻ���� new�� ���������๹���г�ʼ���ģ��Һ�����ִ��Ҳ�������������е��� 
		if(e->Type() == 1){
			cout<<"C�� ��д���¼�������"<<endl; 
			return false; //�ĳ� true �Ϳ��Լ����ضϴ��� 
		}
		else{
			return A::eventFilter(watched, e);
		}
	}	
};

int main(){
#if 1
// �¼��ַ��� ���� 
	Event e1;
	e1.setType(1);
	//e1.setType(2);
	A a1;
	B b1;
	C c1;
	//b1.event(&e1);
	c1.installEventFilter(&b1);
	c1.event(&e1);
#else	
//�¼������� ���� 
	Event e1;
	e1.setType(1);
	//e1.setType(2);

	A a1;
	B b1;	
	b1.installEventFilter(&a1);
	b1.event(&e1);	
#endif
	
	return 0;
}
