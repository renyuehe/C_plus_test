#include <iostream>
using namespace std; 

class T{  
public:  
    T(){  
        cout << "���캯����" << endl;  
    }  

    ~T(){  
        cout << "����������" << endl;  
    }  

    void * operator new(size_t sz){  

        T * t = (T*)malloc(sizeof(T));  //operator new���Ǽ򵥵ķ����ڴ漴��
        cout << "�ڴ���䡣" << endl;  

        return t;  
    }  

    void operator delete(void *p){  

        free(p);  
        cout << "�ڴ��ͷš�" << endl;  

        return;  
    }  
};  

int main()  
{  
    T * t = new T(); // �� �ڴ���� ���� ���캯��  

    delete t; // �� ���������� �� �ڴ��ͷ�  

    return 0;  
} 
