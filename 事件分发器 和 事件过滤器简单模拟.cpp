#include <stdio.h>
#include <iostream>
using namespace std;

class Event{
public:
	//枚举 
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
	//返回事件类型 
	int Type(){
		return t;
	}
	//设置事件类型 
	void setType(int n){
		t = n;
	}
	//事件类型 
	int t;
};

class A{
public:
	//通过filterFlag标志表示安装了事件过滤器，通过 watched 来接收安装过滤器的对象 
	void installEventFilter(A *obj){
		watched = obj;
		filterFlag = 1;
	}
	
protected:
	//事件分发器 
	virtual bool event(Event *e){
		if(e->Type() == 1){
			cout<<"A 类  One事件 处理"<<endl;
		}
		else if(e->Type() == 2){
			cout<<"A 类  Two事件 处理"<<endl;
		}
		else if(e->Type() == 3){
			cout<<"A 类  Three事件 处理"<<endl;
		}
		else if(e->Type() == 4){
			cout<<"A 类  Four事件 处理"<<endl;
		}
		else if(e->Type() == 5){
			cout<<"A 类  Five事件 处理"<<endl;
		}
		else if(e->Type() == 6){
			cout<<"A 类  Six事件 处理"<<endl;
		}
		else if(e->Type() == 7){
			cout<<"A 类  Seven事件 处理"<<endl;
		}
		else if(e->Type() == 8){
			cout<<"A 类  Eight事件 处理"<<endl;
		}
		else if(e->Type() == 9){
			cout<<"A 类  Nine事件 处理"<<endl;
		}
		else if(e->Type() == 10){
			cout<<"A 类  Ten事件 处理"<<endl;
		}
	}
	//事件过滤器 
	virtual bool eventFilter(A *watched, Event *e){
		cout<<"A类 原型事件过滤器"<<endl;
	}

	//类属性太牛了，可以用来做 参数 传递的中间人 ！！！！ 在参数传递不好使的时候，这玩意贼好使 
	Event *e;
	A *watched;
	int filterFlag = 0;
};

//只需要重写 B 类的 event 或者 eventFilter 就可以实现事件过滤 
class B:public A{
public:
	//与QT最不同的是这里，QT里重写event()函数，并不会判断 filterFlag，要达到完全模拟必须解决这一步，才能做到
	bool event(Event *e){								//*
		//如果安装了事件过滤器 							//*
		if(filterFlag==1)								//*
		{									//*
			if(eventFilter(watched, e)){						//*
				return true;						//*
			}								//*
		}									//*
	//与QT最不同的是这里，QT里重写event()函数，并不会判断 filterFlag，要达到完全模拟必须解决这一步，才能做到

		if(e->Type() == 1)
		{
			cout<<"B 类  One事件 处理"<<endl;
			return true;
		}
		else{
			A::event(e);
		}	
	}	
	
	bool eventFilter(A *watched, Event *e){
		if(e->Type() == 1){
			cout<<"B类 重写的事件过滤器"<<endl; 
			return false; //改成 true 就可以继续截断传递 
		}
		else{
			return A::eventFilter(watched, e);
		}
	}	
};

int main(){
#if 0
// 事件分发器 测试 
	Event e1;
	e1.setType(1);
	//e1.setType(2);
	A a1;
	B b1;
	b1.event(&e1);
#else	
//事件过滤器 测试 
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
