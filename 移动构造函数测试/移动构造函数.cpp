#include<iostream>    
using namespace std;    
class IntNum{    
public:    
     IntNum(int x = 0):ptr(new int(x)){//���캯��    
       cout<<"Calling constructor..."<<endl;    
	}    
    IntNum(const IntNum &n):ptr(new int(*n.ptr)){//���ƹ��캯��    
         cout<<"Calling copy constructor..."<<endl;    
	}   
   IntNum(IntNum && n):ptr(n.ptr){//�ƶ����캯��  
     n.ptr = nullptr;  
     cout<<"Calling move constructor..."<<endl;  
	}  
       ~IntNum(){//��������    
        delete ptr;    
        cout<<"Destructing..."<<endl;  
	}   
        int getInt(){return *ptr;}//����ָ����ָ���ֵ�������Ƿ���ָ�뱾��    
private:    
         int *ptr;    
};    
    
//����ֵΪIntNum�����    
IntNum getNum(){    
     //������һ���ֲ�����Ȼ�󽫾ֲ�������Ϊ�������    
      IntNum a;    
    //����ֵ��IntNum����    
      return a;    
}    
  int main(){    
   //getNum()����������һ��IntNum���͵Ķ�����ʱ�������󣩣�֮�������ĺ���    
    cout<<"getNum().getInt()"<<endl;    
    return 0;    
} 
