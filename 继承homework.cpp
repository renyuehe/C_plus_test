#include <iostream>
using namespace std;

class LiveThing{
public:
	liveThing(int weight=0, int hight=0, int width=0, string type = "��"){
		this->weight = weight;	
		this->width = width;
		this->hight = hight;
		this->type = type;
	}
	LiveThing(){
		this->weight = 0;	
		this->width = 0;
		this->hight = 0;
		this->type = "��";
	}
	
	~LiveThing(){
//		cout<<"LiveThing ����������"<<endl;
	}
	
	void showType(){
		cout<<"LiveThing type = "<<type<<endl;
	}
	void show(string name){
		cout<<name<<" : LiveThing type = "<<type<<endl;
	}
	int show(){
		cout<<"return int, LiveThing type = "<<type<<endl;
	}
private:
	int weight;
	int hight;
	int width;
	string type;
};

class Animal: public LiveThing{
public:
	Animal(){
		this->limbs = 0;
		this->year = 100;
		this->type = "���鶯��";
	}
	~Animal(){
//		cout<<"Animal ����������"<<endl;
	}
	
	//��д�˸���ķ��� void show() �����������˸���ķ��� void show(string name) �� int show() 
	//���ຯ���븸�����������˸��ǣ�ʣ�¶������أ����Σ� 
	void showType(){
		cout<<"Animal type="<<type<<endl;
	}

	void run(int speed){
		cout<<limbs<<"���ȣ�"<<"��"<<speed<<"��ÿ����ٶȣ�"<<"run a run"<<endl;
	}
	void run(){
		cout<<limbs<<"����"<<"run a run"<<endl;
	}
	//Ϊʲôͬ��������ͬ����ֵ�Ĳ�����д����Ϊ ���ú��� ���Բ�������ֵ������ˣ��������޷��жϣ� 
//	int run(){
//		cout<<limbs<<"����"<<"run a run"<<endl;
//	}

private:
	int limbs;
	int year;
	string type;
};

int main(){
	
	Animal am1;
	am1.run(10);	//��д 
	am1.run();		//��д 
	am1.showType();	//animal ���� livething �ķ���
	LiveThing *lt1;
	lt1 = &am1;
	lt1->showType(); //�����ǵķ�������ͨ������ָ����� 
//	lt1->showType("���");	//������(����)�ķ��� �� �޷����ʵ� 

	return 0;
}
