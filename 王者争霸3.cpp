#include <iostream>
#include <conio.h>	//��ȡ��ֵ ��ͷ�ļ� 
#include <vector>
#include <windows.h>
using namespace std;

namespace State{
	
	typedef enum{
		//��ֵö�� 
		Up,		//�� 
		Down,	//�� 
		Left,	//�� 
		Right,	//�� 
	}Direction;
	
	typedef enum{
		//����Ч�� ö�� 
		/*
		��			0
		�س� 		1
		�޵�һ�� 	2
		�޵����� 	3
		˲��һ�� 	4
		˲������ 	5
		˲��ʮ�� 	6
		˫���˺�	7	
		*/ 
		Empty,					//��				0
		BackToCity, 			//�س� 				1
		InvinciblePerSecond,	//�޵�һ�� 			2
		InvincibleTwoSecond,	//�޵����� 			3
		ShiftPerMeter,			//˲��һ�� 			4
		ShiftTwoMeter,			//˲������ 			5
		ShiftTenMeter,			//˲��ʮ�� 			6
		DoubleBlood,			//˫���˺�			7				
		OneBlood,				//һ���˺� 
		Eight,					//
		Nine,					//
		Ten, 					//
	}SkillEffect;

}

struct SkillInfo{
	//������Ϣ�ṹ�� ������ �� ����Ч����State::SkillEffect ö�ٱ����� 
	string skill;
	State::SkillEffect skillEffect;
};

struct HeroInfo{
	//Ӣ����Ϣ�ṹ�� ���� �� �������ܽṹ�壨SkillInfo�� 
	string name;
	SkillInfo skill[3];
};

struct Coordinate{
	//Ӣ������ṹ�� 
	int x;
	int y;
};

void startGame();

//���ߴ�½�� ��ͼ���� �� Ӣ������ 
class WangZheDaLu{
	// ��ͼ Coordinate: map
	// Ӣ����Ϣ�б� vevtor װ HeroInfo{name , SkillInfo{skill, SkillInfo}}
public:
	WangZheDaLu()
	{
		cout<<"��ӭ�������ߴ�½!"<<endl<<endl; 
		cout<<"һ��������ң���ͼ��Χ��1000*1000,\n"
		"A����ƶ��� W�� A�� S�� D�ң�JKL�Ǽ���;\n"
		"B����ƶ��� up�� left�� down�� right�ң�����С����123;"<<endl<<endl;
		//���Ӣ�ۺ����ԣ���ֱ��ѹ��  heroInfoList ������ 
		HeroInfo libaiInfo = {"���",{{"����޺�",State::OneBlood},{"����",State::ShiftTwoMeter},{"����Ȫ��",State::BackToCity}}};
		this->heroInfoList.push_back(libaiInfo);
		
		HeroInfo fozuInfo = {"����",{{"��������",State::OneBlood},{"ָ������",State::ShiftTenMeter},{"����",State::BackToCity}}};
		this->heroInfoList.push_back(fozuInfo);

		HeroInfo wukongInfo = {"�����",{{"��ͷ����",State::DoubleBlood},{"���",State::ShiftTenMeter},{"��ʮ����仯",State::InvinciblePerSecond}}};
		this->heroInfoList.push_back(wukongInfo);

		HeroInfo wuzetianInfo = {"������",{{"��",State::DoubleBlood},{"��",State::ShiftTwoMeter},{"��",State::InvinciblePerSecond}}};
		this->heroInfoList.push_back(wuzetianInfo);
		
		HeroInfo yaseInfo = {"��ɪ",{{"�������ܳ��",State::ShiftTwoMeter},{"�ܻ�",State::OneBlood},{"̩ɽѹ��",State::DoubleBlood}}};
		this->heroInfoList.push_back(yaseInfo);
		
		HeroInfo anqilaInfo = {"������",{{"������",State::OneBlood},{"��������",State::ShiftTwoMeter},{"��������",State::InvinciblePerSecond}}};
		this->heroInfoList.push_back(anqilaInfo);
		
		HeroInfo gongbenwuzangInfo = {"�������",{{"��ʿ��",State::OneBlood},{"����λ��",State::ShiftTwoMeter},{"����ն",State::DoubleBlood}}};
		this->heroInfoList.push_back(gongbenwuzangInfo);
	}
	~WangZheDaLu(){
		cout<<"������Ϸ"<<endl;
	}
	
	void customHero(){
		//�Զ���Ӣ�� 
		cout<<"��������:"<<endl;
		string name;
		cin>>name;
		cout<<endl<<"����Ч����"<<endl;	
		cout<<"�ޣ�0"<<endl;
		cout<<"�سǣ�1"<<endl;
		cout<<"�޵�һ�룺2"<<endl;
		cout<<"�޵����룺3"<<endl;
		cout<<"˲��һ�ף�4"<<endl;
		cout<<"˲�����ף�5"<<endl;
		cout<<"˲��ʮ�ף�6"<<endl;
		cout<<"˫���˺���7"<<endl;
		cout<<"һ���˺���8"<<endl;
		
		cout<<endl<<"���뼼��1���֣�string��:"<<endl;
		string skill1;
		cin>>skill1;
		cout<<"����1Ч����int��:"<<endl;
		int i;
		cin>>i;
		cout<<"���뼼��2��string��:"<<endl;
		string skill2;
		cin>>skill2;
		cout<<"����2Ч����int��:"<<endl;
		int j;
		cin>>j;
		cout<<"���뼼��3��string��:"<<endl;
		string skill3;
		cin>>skill3;
		cout<<"����3Ч����int��:"<<endl;
		int k;
		cin>>k;
		
		// i��j��k�����Σ����������� State ���ֿռ���� ö������ 
		HeroInfo yaseInfo = {name,{{skill1,(State::SkillEffect)i},{skill2,(State::SkillEffect)j},{skill3,(State::SkillEffect)k}}};
		this->heroInfoList.push_back(yaseInfo);
	} 
	
	void showHeros(){
		//��ʾӢ������ 
		cout<<"һ���У�"<<this->heroInfoList.size()<<"��Ӣ��"<<endl;
	}
	HeroInfo getHero(){
		//ѡӢ�� 
		cout<<"�ڣ�";
		vector<HeroInfo>::iterator iter;
    	for(iter = heroInfoList.begin(); iter != heroInfoList.end(); iter++){
        	cout <<iter->name << ",";
    	}
    	cout<<"��ѡһ��Ӣ��"<<endl;
    	
    	string tempName;
HERE:
    	cin>>tempName;
    	for(iter = heroInfoList.begin(); iter != heroInfoList.end(); iter++){
        	if(iter->name == tempName){
        		return *iter;
			}
    	}
    	cout<<"�������,��������"<<endl;
    	goto HERE;
//		HeroInfo nullHero = {"��",{{"��",State::Empty},{"��",State::Empty},{"��",State::Empty}}};s
//		return nullHero;
	} 

private:
	const Coordinate map = {1000, 1000};//��ͼ��С��������Ϊ�ƶ����ƣ�Ŀǰû��ʵ�� 
	vector <HeroInfo> heroInfoList;//Ӣ�� ��Ϣ �б� 
};


class Hero{
	//Ӣ��
	//���ԣ� ����name   ����ֵhealth   ����skill   λ��xy (coordinate)�ṹ�� 
	//������ birth����		�������� 
	//������ do_skill() 	�ż��� 
	//������ showDetail() ��ʾ��Ϣ 
	//������ subHealth()  �ܵ���������Ѫ 
	//������ birth������������ 
	//����:	 setXy() ��������ֵ Coordinate �ṹ�� 
public:
	Hero(){
		this->health = 5;
		this->setXy(0, 0);
		this->direction = State::Up;
		directionChar = "��"; 
	}
	Hero(HeroInfo heroInfo){
		this->health = 5;
		this->setXy(0,0);
		this->name = heroInfo.name;
		this->skill[0] = heroInfo.skill[0];
		this->skill[1] = heroInfo.skill[1];
		this->skill[2] = heroInfo.skill[2];
		this->direction = State::Up;
		directionChar = "��"; 
	}

	~Hero(){
	}

	void birth(){
		cout<<name<<":����"<<endl;
	}
	int do_skill(int i){
		/*
		�ż��ܣ� ͨ�� Force ��ʵ�������ã���ֱ�ӵ��õ�ԭ���ǣ� 
		������Ӣ���࣬���Ӣ�۷�Χ�������жϷ�Χ����û������Ӣ����Ҫ����Ӣ�۵�ʵ�����ж������꣬
		������������������ʵ��Ӣ�۵��б�ָ�룬��ôÿһ��ʵ��������һ���б��˷ѿռ䣬
		���ԾͶ���һ��force����泡������ʵ��Ӣ�۵�ָ���б� 
		*/
		if(i == 0){
			cout<<name<<"�ͷ�"<<this->skill[0].skill<<endl;
			rangEffect((skill[i].skillEffect));
			return i;
		}
		else if(i == 1)
		{
			cout<<name<<"�ͷ�"<<this->skill[1].skill<<endl;
			rangEffect((skill[i].skillEffect));
			return i;
		}
		else if(i == 2)
		{
			cout<<name<<"�ͷ�"<<this->skill[2].skill<<endl;
			rangEffect((skill[i].skillEffect));
			return i;
		}
		else if(i == 3)
		{
			cout<<name<<"�ͷ�"<<this->skill[3].skill<<endl;
			rangEffect((skill[i].skillEffect));
			return i;
		}
		else
		{

		}
	}  
	
	void rangEffect(const State::SkillEffect ef){
		if(ef == State::BackToCity){
			//�س�
			cout<<name<<":�س�"<<endl; 
			setXy(0, 0);
			health = 5;
			cout<<name<<":����ֵ��"<<health<<endl;
		}
		else if(ef == State::InvinciblePerSecond){
			//�޵�һ�� 
			cout<<"�޵�һ��(��Ҫһ���߲��ʱ��)"<<endl;
		}
		else if(ef == State::InvincibleTwoSecond){
			//�޵����� 
			cout<<"�޵�����(��Ҫһ���߲��ʱ��)"<<endl;
		}
		else if(ef == State::ShiftPerMeter){
			//˲��һ�� (3��) 
			if(this->direction == State::Up){
				for(int i = 0; i < 3; i++){
					this->upShift();
				}
			}
			else if(this->direction == State::Down){
				for(int i = 0; i < 3; i++){
					this->downShift();
				}
			}
			else if(this->direction == State::Left){
				for(int i = 0; i < 3; i++){
					this->leftShift();
				}
			}
			else if(this->direction == State::Right){
				for(int i = 0; i < 3; i++){
					this->rightShift();
				}
			}
		}
		else if(ef == State::ShiftTwoMeter){
			//˲������ 
			if(this->direction == State::Up){
				for(int i = 0; i < 6; i++){
					this->upShift();
				}
			}
			else if(this->direction == State::Down){
				for(int i = 0; i < 6; i++){
					this->downShift();
				}
			}
			else if(this->direction == State::Left){
				for(int i = 0; i < 6; i++){
					this->leftShift();
				}
			}
			else if(this->direction == State::Right){
				for(int i = 0; i < 6; i++){
					this->rightShift();
				}
			}
		}
		else if(ef == State::ShiftTenMeter){
			//˲��ʮ�� 
			if(this->direction == State::Up){
				for(int i = 0; i < 30; i++){
					this->upShift();
				}
			}
			else if(this->direction == State::Down){
				for(int i = 0; i < 30; i++){
					this->downShift();
				}
			}
			else if(this->direction == State::Left){
				for(int i = 0; i < 30; i++){
					this->leftShift();
				}
			}
			else if(this->direction == State::Right){
				for(int i = 0; i < 30; i++){
					this->rightShift();
				}
			}
		}
		else if(ef == State::DoubleBlood){
			//˫���˺� double damage 
			//�ڲ��޷�ʵ�֣�ֻ�п��ⲿ Force ��ʵ����װ������ʵ�� hero ʵ�� 
		}
	}
	
	void showDetail(){
		cout<<"Ӣ�ۣ�"<<name<<"���ܣ�"<<skill[0].skill<<", "<<skill[1].skill<<", "<<skill[2].skill<<", "<<endl;
		cout<<"������"<<health<<endl;
		cout<<"λ�ã�"<<"x:"<<xy.x<<"y:"<<xy.y<<endl;
	}
	
	int subHealth(){
		if(health == 0){
			cout<<"���˲���������"<<endl;
			return 0;
		}
		this->health--;
		cout<<name<<"������������ֵΪ:"<<health<<endl; 
		if(health == 0){
			delete this;
		}
		return health;
	}
	int addHealth(){
		if(health < 5){
			health++;
			cout<<name<<"����:"<<health<<endl;
		}
		return health;
	}
	
	void leftShift(){
		if(xy.x>0){
			xy.x--;
		}
		this->direction = State::Left;
		this->directionChar = "��";
		showCoordinate();
	}
	void rightShift(){
		if(xy.x<1000){
			xy.x++;
		}
		this->direction = State::Right;
		this->directionChar = "��";
		showCoordinate();
		
	}
	void upShift(){
		if(xy.y>0){
			xy.y--;
		}
		this->direction = State::Up;
		this->directionChar = "��";
		showCoordinate();
	}
	void downShift(){
		if(xy.y<1000){
			xy.y++;
		}
		this->direction = State::Down;
		this->directionChar = "��";
		showCoordinate();
	}
	
	void showCoordinate(){ 
		cout<<this->name<<":("<<this->xy.x<<","<<this->xy.y<<")"<<"����:"<<this->directionChar<<endl;
	}
	void setXy(int x, int y){
		xy.x = x;
		xy.y = y;
	}
	
	Coordinate getXy(){
		return xy;
	}
	
	State::SkillEffect getSkillType(const int i){
		return skill[i].skillEffect;
	}
	
	string getName(){
		return name;
	}
protected:
	Coordinate xy;
	State::Direction direction;
	string directionChar;
	SkillInfo skill[3];	//ǳ�����᲻�������� 
	string name;
	int health;
private:
	
};

class Force{
	/*
		ͨ�� Force ��Ӣ��ʵ����ָ���б�
		������ attacked_by�������жϳ������� ������Ϊ������������Ϊ�� ����Ǵ�����Ϊ obj ==�� obj �Ǿ���Ҫָ���б�Ȼ���ж��Ƿ���ϴ�������
		���ԸĽ��ĵط��ǣ����԰ѹ̶�������Ӣ��ָ�� �ĳ� Ӣ���б� vector�� �������� Ҳ������ ѡӢ��ʱ�� ѭ����ʽ��ѡ �� �� vector ������װ�� 
	*/
public:
	int attacked_by(Hero *hero, const int ch){
		int i = 0;
		if(ch == 106 || ch == 48)
			i = 0;
		else if (ch == 107 || ch == 49){
			i = 1;
		}
		else if (ch == 108 || ch == 50){
			i = 2;
		}
		if (hero->getSkillType(i) == State::DoubleBlood)
		{
			int x1 = hero1->getXy().x;
			int x2 = hero2->getXy().x;
			int y1 = hero1->getXy().y;
			int y2 = hero2->getXy().y;
			//ע�⣺  ������д�����޴���   if(-3<(x1-x2)<3 && -3<(y1-y2)<3)
			//�ж� Ӣ�� a �� b �ľ��� 
			if(-3<(x1-x2) && (x1-x2)<3 && -3<(y1-y2) && (y1-y2)<3){
				if(hero == hero1){
					hero2->subHealth();
					hero2->subHealth();
				}
				else{
					hero1->subHealth();
					hero1->subHealth();
				}
			}
			else{
				cout<<hero->getName()<<"���п�����"<<endl;
			}
		}
		else if (hero->getSkillType(i) == State::OneBlood)
		{
			int x1 = hero1->getXy().x;
			int x2 = hero2->getXy().x;
			int y1 = hero1->getXy().y;
			int y2 = hero2->getXy().y;
			//ע�⣺  ������д�����޴���   if(-3<(x1-x2)<3 && -3<(y1-y2)<3)
			if(-3<(x1-x2) && (x1-x2)<3 && -3<(y1-y2) && (y1-y2)<3){
				if(hero == hero1){
					hero2->subHealth();
				}
				else{
					hero1->subHealth();
				}
			}
			else{
				cout<<hero->getName()<<"���п�����"<<endl;
			}
		}
		else{
			hero->do_skill(i);
		}
	}	
	// �˴�û�ж��� vector ��Ϊֻ������Ӣ��  
	void setHeros(Hero *hero1, Hero *hero2){
		this->hero1 = hero1;
		this->hero2 = hero2;
	}
private:
	// ���Զ��� vector ����Ŷ��Ӣ�� 
	Hero *hero1;
	Hero *hero2;
};

int main(){
	
	startGame();
	
	return 0;
}

void startGame(){
	WangZheDaLu wangZheDaLu;
//	HeroInfo tempInfo;
	
	cout<<"�����Ҫ���Զ���Ӣ�۾�����(Ҫ)������������";
	string c;
	cin>>c;
	if(c == "Ҫ"){
		while(1){
			wangZheDaLu.customHero();
			cout<<"���������루��ɣ��˳����������";
			cin>>c;
			if(c == "���")
			{
				break;
			}
		}
	}	
	wangZheDaLu.showHeros();
	Hero *hero1 = new Hero(wangZheDaLu.getHero());
	Hero *hero2 = new Hero(wangZheDaLu.getHero());
	cout<<endl<<"��ս������:"<<endl;
	hero1->showDetail();
	cout<<endl;
	hero2->showDetail();
	
	Force force;
	force.setHeros(hero1, hero2);
	
	
	cout<<endl;
	cout<<"�����ʼ��Ϸ"<<endl;
	for(int i = 5; i >= 0; i--){
		Sleep(1000);
		cout<<i<<endl;
	}
	cout<<"Ͽ�ȴ�"<<endl; 
	 
	int ch;
    while (1){
        if (_kbhit()){//����а������£���_kbhit()����������
            ch = _getch();//ʹ��_getch()������ȡ���µļ�ֵ
            if (ch == 27){
            	break;
			}
			else if (ch == 75){
				//b �� 
				hero2->leftShift();
			}
			else if (ch == 77){
				//b �� 
				hero2->rightShift();
			}
			else if (ch == 72){
				//b �� 
				hero2->upShift();
			}
			else if (ch == 80){
				//b �� 
				hero2->downShift();
			}
			else if (ch == 97){
				//a �� 
				hero1->leftShift();
			}
			else if (ch == 115){
				//a �� 
				hero1->downShift();
			}
			else if (ch == 100){
				//a ��	
				hero1->rightShift();		
			}
			else if (ch == 119){
				//a �� 
				hero1->upShift();
			}
			else if (ch == 106){
				//a 1
				force.attacked_by(hero1, ch);
			}
			else if (ch == 107){
				//a 2
				force.attacked_by(hero1, ch);
			}
			else if (ch == 108){
				//a 3
				force.attacked_by(hero1, ch);
			}
			else if (ch == 49){
				//b 1
				force.attacked_by(hero2, ch);
			}
			else if (ch == 50){
				//b 2
				force.attacked_by(hero2, ch);
			}
			else if (ch == 51){
				//b 3
				force.attacked_by(hero2, ch);
			}

            if (ch == 27){ break; }//������ESCʱѭ����ESC���ļ�ֵʱ27.
        }
    }
} 
