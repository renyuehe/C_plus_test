/*
*	���ۣ���ͨ �麯�� �ᱻ���ǣ� ��������ᱻ " ���� " 
*/

#include<iostream>
using namespace std;
//����
class ClxBase{
public:
    ClxBase() {};
#if 0
    //�������������麯��
    ~ClxBase() {
        cout << "��������" << endl;
    };
#else
	//�����������麯�� 
    virtual ~ClxBase() {
        cout << "����������" << endl;
    };
#endif
 
#if 0
 	void DoSomething() {
        cout << "Do something in class ClxBase!" << endl;
    };
#else
    virtual void DoSomething() {
        cout << "Do something in class ClxBase!" << endl;
    };
#endif
};
 
//������
class ClxDerived : public ClxBase{
public:
    ClxDerived() {};
    ~ClxDerived() {
        cout << "��������" << endl;
    };
 
    void DoSomething() {
        cout << "Do something in class ClxDerived!" << endl;
    }
};
  int main(){ 
      //�ж�̬
      ClxBase *p =  new ClxDerived;

      p->DoSomething();
      delete p;
      return 0;
  } 

