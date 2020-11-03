#include <iostream>
using namespace std;

class B{
public:
    B():num(num = 1){}
    B(int n):num(num = n){}
    ~B(){}

    void showNum(){
        cout<<"num ="<<num<<endl;
    }

private:
    int num;
};

class A{
public:
    A(){ 
        for(int i = 0; i < sizeof(bArr)/sizeof(B); i++){
            bArr[i] = i+100;
        }
    }
    ~A(){ }

    B& operator[](int a){
        if(a<0 || a>9){
            cout<<"输入错误";
            return bArr[0];
        }else{
            return bArr[a];
        }
    }

private:
    B bArr[10];
};

int main(){

    A aObj;
    B& bObj = aObj[0];
    bObj.showNum();
    
    system("pause");
    return 0;
}