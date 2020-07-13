#include <iostream>
#include <conio.h>
using namespace std;

//void fullInterface();
//void lubu();

int main(){
	int ch;
    while (1){
        if (_kbhit()){//如果有按键按下，则_kbhit()函数返回真
            ch = _getch();//使用_getch()函数获取按下的键值
            cout << "获取了键盘事件:" <<ch<<endl;
//            if(ch==75)
//			{
////				fullInterface();
////				lubu();
//			}
//			else if(ch==77)
//			{
//				
//			} 
//			else if(ch==72)
//            {
//            	
//			}
//			else if(ch==80){
//				
//			}
//            else if(ch == 27){ break; }//当按下ESC时循环，ESC键的键值时27.
        }
    }
	return 0;
}

//void fullInterface(){
//	for(int i = 0; i < 30; i++){
//		cout<<"                                                                                                                                                  ";
//	}
//	return;
//}

//void lubu(){
//	cout<<"                       _oo0oo_        	";
//	cout<<"                      o8888888o        	";
//	cout<<"                     88\" . \"88        	";
//	cout<<"                      (| -_- |)        	";
//	cout<<"                      0\\  =  /0        	";
//	cout<<"                    ___/`---'\\___        ";
//	cout<<"                  .' \\|     |// '.        ";
//	cout<<"                 / \\|||  :  |||// \\        ";
//	cout<<"                / _||||| -:- |||||- \\        ";
//	cout<<"               |   | \\  -  /// |   |        ";
//	cout<<"               | \\_|  ''\\---/''  |_/ |        ";
//	cout<<"               \\  .-\\__  '-'  ___/-. /        ";
//	cout<<"             ___'. .'  /--.--\\  `. .'___        ";
//	cout<<"          ."" '<  `.___\\_<|>_/___.' >' "".        ";
//	cout<<"         | | :  `- \\`.;`\\ _ /`;.`/ - ` : | |        ";
//	cout<<"         \\  \\ `_.   \\_ __\\ /__ _/   .-` /  /        ";
//	cout<<"     =====`-.____`.___ \\_____/___.-`___.-'=====      ";
//	return;
//}
