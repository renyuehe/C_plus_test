#include <iostream>
using namespace std;

class LiveThing{
public:
	liveThing(int weight=0, int hight=0, int width=0, string type = "界"){
		this->weight = weight;	
		this->width = width;
		this->hight = hight;
		this->type = type;
	}
	LiveThing(){
		this->weight = 0;	
		this->width = 0;
		this->hight = 0;
		this->type = "无";
	}
	
	~LiveThing(){
//		cout<<"LiveThing 析构！！！"<<endl;
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
		this->type = "哺乳动物";
	}
	~Animal(){
//		cout<<"Animal 析构！！！"<<endl;
	}
	
	//重写了父类的方法 void show() ，并且隐藏了父类的方法 void show(string name) 和 int show() 
	//子类函数与父类重名，除了覆盖，剩下都是隐藏（屏蔽） 
	void showType(){
		cout<<"Animal type="<<type<<endl;
	}

	void run(int speed){
		cout<<limbs<<"条腿，"<<"以"<<speed<<"米每秒的速度："<<"run a run"<<endl;
	}
	void run(){
		cout<<limbs<<"条腿"<<"run a run"<<endl;
	}
	//为什么同参数，不同返回值的不能重写，因为 调用函数 可以不带返回值（若如此，编译器无法判断） 
//	int run(){
//		cout<<limbs<<"条腿"<<"run a run"<<endl;
//	}

private:
	int limbs;
	int year;
	string type;
};

int main(){
	
	Animal am1;
	am1.run(10);	//重写 
	am1.run();		//重写 
	am1.showType();	//animal 覆盖 livething 的方法
	LiveThing *lt1;
	lt1 = &am1;
	lt1->showType(); //被覆盖的方法可以通过父类指针访问 
//	lt1->showType("悟空");	//被隐藏(屏蔽)的方法 是 无法访问的 

	return 0;
}
