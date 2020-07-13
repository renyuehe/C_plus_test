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
    	
        if (_kbhit()){//如果有按键按下，则_kbhit()函数返回真
            ch = _getch();//使用_getch()函数获取按下的键值
//            cout << "获取了键盘事件:" <<ch<<endl;
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
            if (ch == 27){ break; }//当按下ESC时循环，ESC键的键值时27.
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

//回调一个人物图形， 
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
