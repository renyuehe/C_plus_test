/**************************************************
*
*	�������⣬��Ϊ��һ��һ�д�Ӧ������޷���������ͼ��ƽ�С� 
* 
*	Ч�����⣬���� for ѭ����ӡ�����ʽ��ʵ����̫���ˣ���Ӧ�õ��Կ��Ľӿ� 
*
**************************************************/

#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;
 
void fullInterface();
void fozu(bool b=true, int x=0, int y=0); 
void libai(bool b=true, int x=0, int y=0);
void refreshInterface();
void image_move(void (*image_ptr)(bool, int, int), void (*image_ptr2)(bool, int, int));

int main()
{
    while (1){	
		image_move(fozu,libai); 
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

//�ص�һ������ͼ�Σ� �����Ӧ��������� 
void image_move(void (*image_ptr)(bool, int, int), void (*image_ptr2)(bool, int, int)){
	int ch;
	static int lx=0, ly=0, rx=0, ry=0;
    if (_kbhit()){//����а������£���_kbhit()����������
    ch = _getch();//ʹ��_getch()������ȡ���µļ�ֵ
//  cout << "��ȡ�˼����¼�:" <<ch<<endl;
 		if(ch==72){
        	if(ly>200){
        		ly--;
			} 	
			refreshInterface();
        	image_ptr(true,lx, ly);
        	image_ptr2(false,rx, ry);
		}
		else if(ch==80){
        	if(ly<200)
        	{
        		ly++;
			}
        	refreshInterface();
        	image_ptr(true,lx, ly);
        	image_ptr2(false,rx, ry);
		}
		else if(ch==75){

        	if(lx>0){
        		lx--;
			}
			refreshInterface();
        	image_ptr(true,lx, ly);
        	image_ptr2(false,rx, ry);
		}
		else if(ch==77){
        	if(lx < 200){
				lx++;
			}
			refreshInterface();
        	image_ptr(true,lx, ly);
        	image_ptr2(false,rx, ry);
		}
		else if(ch==97){
			//a ���� 
			if(rx>0)
			{
				rx--;
			} 
			refreshInterface();
			image_ptr(true,lx, ly);
			image_ptr2(false,rx, ry);
		}
		else if(ch==115){
			//s ���� 
			if(ry>0)
			{
				ry--;
			} 
			refreshInterface();
			image_ptr(true,lx, ly);
			image_ptr2(false,rx, ry);
		}
		else if(ch==100){
			//d ���� 
			if(rx<1000)
			{
				rx++;
			} 
			refreshInterface();
			image_ptr(true,lx, ly);
			image_ptr2(false,rx, ry);
		}
		else if(ch==119){
			//w ���� 
			if(ry<0)
			{
				ry--;
			} 
			refreshInterface();
			image_ptr(true,lx, ly);
			image_ptr2(false,rx, ry);
		}
        if (ch == 27){ return; }//������ESCʱѭ����ESC���ļ�ֵʱ27.
    }
}

void fozu(bool b, int x, int y){
	// ����ƫ�� 
	for(int i = 0; i < y; i++){
		cout<<endl;
	}
	// ����ƫ��
	if(b == true){
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"                       _oo0oo_        			"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"                      o8888888o        			"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"                     88\" . \"88        			"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"                      (| -_- |)        			"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"                      0\\  =  /0        			"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"                    ___/`---'\\___        		"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"                  .' \\|     |// '.        		"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"                 / \\|||  :  |||// \\        	"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"                / _||||| -:- |||||- \\        	"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"               |   | \\  -  /// |   |        	"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"               | \\_|  ''\\---/''  |_/ |        	"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"               \\  .-\\__  '-'  ___/-. /        	"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"             ___'. .'  /--.--\\  `. .'___       	"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"          ."" '<  `.___\\_<|>_/___.' >' "".     	"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"         | | :  `- \\`.;`\\ _ /`;.`/ - ` : | |  	"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"         \\  \\ `_.   \\_ __\\ /__ _/   .-` /  /	"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"     =====`-.____`.___ \\_____/___.-`___.-'====="<<endl;
	}
	if(b == false)
	{
		x += 40;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"                       _oo0oo_        			"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"                      o8888888o        			"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"                     88\" . \"88        			"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"                      (| -_- |)        			"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"                      0\\  =  /0        			"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"                    ___/`---'\\___        		"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"                  .' \\|     |// '.        		"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"                 / \\|||  :  |||// \\        	"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"                / _||||| -:- |||||- \\        	"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"               |   | \\  -  /// |   |        	"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"               | \\_|  ''\\---/''  |_/ |        	"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"               \\  .-\\__  '-'  ___/-. /        	"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"             ___'. .'  /--.--\\  `. .'___       	"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"          ."" '<  `.___\\_<|>_/___.' >' "".     	"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"         | | :  `- \\`.;`\\ _ /`;.`/ - ` : | |  	"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"         \\  \\ `_.   \\_ __\\ /__ _/   .-` /  /	"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"     =====`-.____`.___ \\_____/___.-`___.-'====="<<endl;
		x -=40;
	} 
	return;
}

void libai(bool b, int x, int y){
	for(int i = 0; i < y; i++){
		cout<<endl;
	}
	if(b == true){
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"        __----__       "<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"         111111        "<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"   _   [|--  --|]    	"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"   \\\\   |  []  |     "<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"    \\\\   --__--     	"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"     \\\\   |  |     	"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"     |--__--      |    "<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"     |--__--      |    "<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"     |--__--      |    "<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"     |--__--      |    "<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"     |--__--      |    "<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"       |--_||_--|     	"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"       |--_||_--| \\   "<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"       |--_||_--|  \\  "<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"       |--_||_--|   \\ "<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"       |--_||_--|\\__| "<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"       |--_||_--|     	"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"      _|_ |  |_ |_     "<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
	}
	if(b == false)
	{
		x += 40;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"        __----__       "<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"         111111        "<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"   _   [|--  --|]    	"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"   \\\\   |  []  |     "<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"    \\\\   --__--     	"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"     \\\\   |  |     	"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"     |--__--      |    "<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"     |--__--      |    "<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"     |--__--      |    "<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"     |--__--      |    "<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"     |--__--      |    "<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"       |--_||_--|     	"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"       |--_||_--| \\   "<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"       |--_||_--|  \\  "<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"       |--_||_--|   \\ "<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"       |--_||_--|\\__| "<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"       |--_||_--|     	"<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		cout<<"      _|_ |  |_ |_     "<<endl;
		for(int j = 0; j < x; j++){  cout<<" ";  }
		x -=40;
	} 
	return;
}
