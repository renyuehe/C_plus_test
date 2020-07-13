#include <conio.h>
#include <iostream>
#include <windows.h>
 
using namespace std;
 
void fullInterface();
void lubu(int x=0, int y=0); 
void refreshInterface();
void image_move(void (*image_ptr)(int, int), int x, int y);

int main()
{
    int ch;
    int lx=0, ly=0, rx=0, ry=0;
    while (1){
    	
        if (_kbhit()){//����а������£���_kbhit()����������
            ch = _getch();//ʹ��_getch()������ȡ���µļ�ֵ
//            cout << "��ȡ�˼����¼�:" <<ch<<endl;
            if(ch==72){
            	refreshInterface();
            	if(ly>0){
            		ly--;
				} 	
            	image_move(lubu,lx,ly);
			}
			else if(ch==80){
            	refreshInterface();
            	if(ly<20)
            	{
            		ly++;
				}
            	image_move(lubu,lx,ly);
			}
			else if(ch==75){
            	refreshInterface();
            	if(lx>0){
            		lx--;
				}
            	image_move(lubu,lx,ly);
			}
			else if(ch==77){
            	refreshInterface();
            	if(lx < 20){
					lx++;
				}
            	image_move(lubu,lx,ly);
			}
            if (ch == 27){ break; }//������ESCʱѭ����ESC���ļ�ֵʱ27.
        }
    }
    system("pause");
}

void fullInterface(){
	for(int i = 0; i < 30; i++){
		cout<<"                                                                                                                ";
	}
	return;
}

void refreshInterface(){
	system("cls");
}

//�ص�һ������ͼ�Σ� 
void image_move(void (*image_ptr)(int, int), int x, int y){
	image_ptr(x, y);
}
void lubu(int x, int y){
	for(int i = 0; i < y; i++){
		cout<<endl;
	}
	for(int j = 0; j < x; j++){  cout<<" ";  }
	cout<<"                       _oo0oo_        	"<<endl;
	for(int j = 0; j < x; j++){  cout<<" ";  }
	cout<<"                      o8888888o        	"<<endl;
	for(int j = 0; j < x; j++){  cout<<" ";  }
	cout<<"                     88\" . \"88        	"<<endl;
	for(int j = 0; j < x; j++){  cout<<" ";  }
	cout<<"                      (| -_- |)        	"<<endl;
	for(int j = 0; j < x; j++){  cout<<" ";  }
	cout<<"                      0\\  =  /0        	"<<endl;
	for(int j = 0; j < x; j++){  cout<<" ";  }
	cout<<"                    ___/`---'\\___        "<<endl;
	for(int j = 0; j < x; j++){  cout<<" ";  }
	cout<<"                  .' \\|     |// '.        "<<endl;
	for(int j = 0; j < x; j++){  cout<<" ";  }
	cout<<"                 / \\|||  :  |||// \\        "<<endl;
	for(int j = 0; j < x; j++){  cout<<" ";  }
	cout<<"                / _||||| -:- |||||- \\        "<<endl;
	for(int j = 0; j < x; j++){  cout<<" ";  }
	cout<<"               |   | \\  -  /// |   |        "<<endl;
	for(int j = 0; j < x; j++){  cout<<" ";  }
	cout<<"               | \\_|  ''\\---/''  |_/ |        "<<endl;
	for(int j = 0; j < x; j++){  cout<<" ";  }
	cout<<"               \\  .-\\__  '-'  ___/-. /        "<<endl;
	for(int j = 0; j < x; j++){  cout<<" ";  }
	cout<<"             ___'. .'  /--.--\\  `. .'___        "<<endl;
	for(int j = 0; j < x; j++){  cout<<" ";  }
	cout<<"          ."" '<  `.___\\_<|>_/___.' >' "".        "<<endl;
	for(int j = 0; j < x; j++){  cout<<" ";  }
	cout<<"         | | :  `- \\`.;`\\ _ /`;.`/ - ` : | |        "<<endl;
	for(int j = 0; j < x; j++){  cout<<" ";  }
	cout<<"         \\  \\ `_.   \\_ __\\ /__ _/   .-` /  /        "<<endl;
	for(int j = 0; j < x; j++){  cout<<" ";  }
	cout<<"     =====`-.____`.___ \\_____/___.-`___.-'=====      "<<endl;
	return;
}
