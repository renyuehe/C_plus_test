#include <conio.h>
#include <iostream>
 
using namespace std;
 
int main()
{
    int ch;
    while (1){
        if (_kbhit()){//����а������£���_kbhit()����������
            ch = _getch();//ʹ��_getch()������ȡ���µļ�ֵ
            cout << "��ȡ�˼����¼�:" <<ch<<endl;
            if (ch == 27){ break; }//������ESCʱѭ����ESC���ļ�ֵʱ27.
        }
    }
    system("pause");
}
