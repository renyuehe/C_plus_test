#include<iostream>    
using namespace std;    
class IntNum{    
public:    
     IntNum(int x = 0):ptr(new int(x)){//构造函数    
       cout<<"Calling constructor..."<<endl;    
	}    
    IntNum(const IntNum &n):ptr(new int(*n.ptr)){//复制构造函数    
         cout<<"Calling copy constructor..."<<endl;    
	}   
   IntNum(IntNum && n):ptr(n.ptr){//移动构造函数  
     n.ptr = nullptr;  
     cout<<"Calling move constructor..."<<endl;  
	}  
       ~IntNum(){//析构函数    
        delete ptr;    
        cout<<"Destructing..."<<endl;  
	}   
        int getInt(){return *ptr;}//返回指针所指向的值，而不是返回指针本身    
private:    
         int *ptr;    
};    
    
//返回值为IntNum类对象    
IntNum getNum(){    
     //定义了一个局部对象，然后将局部对象作为结果返回    
      IntNum a;    
    //返回值是IntNum类型    
      return a;    
}    
  int main(){    
   //getNum()函数返回了一个IntNum类型的对象（临时无名对象），之后调用类的函数    
    cout<<"getNum().getInt()"<<endl;    
    return 0;    
} 
