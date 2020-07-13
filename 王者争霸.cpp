#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;

void startGame();

namespace State{
	typedef enum{
	Empty,					//��
	BackToCity, 			//�س� 
	InvinciblePerSecond,	//�޵�һ�� 
	InvincibleTwoSecond,	//�޵����� 
	ShiftPerMeter,			//˲��һ�� 
	ShiftTwoMeter,			//˲������ 
	ShiftTenMeter,			//˲��ʮ�� 
	Six,
	Seven,
	Eight,
	Nine,
	Ten, 
}SkillEffect;
}

struct SkillInfo{
	string skill;
	State::SkillEffect skillEffect;
};

struct HeroInfo{
	string name;
	SkillInfo skill[3];
};

struct Coordinate{
	int x;
	int y;
};

//���ߴ�½�� ��ͼ���� �� Ӣ������ 
class WangZheDaLu{
	// ��ͼ Coordinate: map
	// Ӣ����Ϣ�б� vevtor װ HeroInfo{name , SkillInfo{skill, SkillInfo}}
public:
	WangZheDaLu()
	{
		cout<<"��ӭ�������ߴ�½!"<<endl; 
		//���Ӣ�ۺ����ԣ���ֱ��ѹ��  heroInfoList ������ 
		HeroInfo libaiInfo = {"���",{{"����޺�",State::InvinciblePerSecond},{"����",State::InvinciblePerSecond},{"����Ȫ��",State::InvinciblePerSecond}}};
		this->heroInfoList.push_back(libaiInfo);
		
		HeroInfo fozuInfo = {"����",{{"��������",State::InvinciblePerSecond},{"ָ������",State::InvinciblePerSecond},{"����",State::InvinciblePerSecond}}};
		this->heroInfoList.push_back(fozuInfo);

		HeroInfo wukongInfo = {"�����",{{"��ͷ����",State::InvinciblePerSecond},{"���",State::InvinciblePerSecond},{"��ʮ����仯",State::InvinciblePerSecond}}};
		this->heroInfoList.push_back(wukongInfo);

		HeroInfo wuzetianInfo = {"������",{{"��",State::InvinciblePerSecond},{"��",State::InvinciblePerSecond},{"��",State::InvinciblePerSecond}}};
		this->heroInfoList.push_back(wuzetianInfo);
		
		HeroInfo yaseInfo = {"��ɪ",{{"�������ܳ��",State::InvinciblePerSecond},{"�ܻ�",State::InvinciblePerSecond},{"̩ɽѹ��",State::InvinciblePerSecond}}};
		this->heroInfoList.push_back(yaseInfo);
		
		HeroInfo anqilaInfo = {"����",{{"������",State::InvinciblePerSecond},{"��������",State::InvinciblePerSecond},{"��������",State::InvinciblePerSecond}}};
		this->heroInfoList.push_back(anqilaInfo);
		
		HeroInfo gongbenwuzangInfo = {"�������",{{"��ʿ��",State::InvinciblePerSecond},{"����λ��",State::InvinciblePerSecond},{"����ն",State::InvinciblePerSecond}}};
		this->heroInfoList.push_back(gongbenwuzangInfo);
	}
	~WangZheDaLu(){
		cout<<"������Ϸ"<<endl;
	}
	
	void showHeros(){
		cout<<"һ���У�"<<this->heroInfoList.size()<<"��Ӣ��"<<endl;
	}
	HeroInfo getHero(){
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
		return nullHero;
	} 

private:
	const Coordinate map = {1000, 1000};
	vector <HeroInfo> heroInfoList;
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
	}
	Hero(HeroInfo heroInfo){
		this->health = 5;
		this->setXy(0,0);
		this->name = heroInfo.name;
		this->skill[0] = heroInfo.skill[0];
		this->skill[1] = heroInfo.skill[1];
		this->skill[2] = heroInfo.skill[2];
	}

	~Hero(){
	}

	void birth(){
		cout<<name<<":����"<<endl;
	}
	int do_skill(int i){
		if(i = 0){
			cout<<name<<"�ͷ�"<<this->skill[0].skill<<endl;
			return i;
		}
		else if(i = 1)
		{
			cout<<name<<"�ͷ�"<<this->skill[1].skill<<endl;
			return i;
		}
		else if(i = 2)
		{
			cout<<name<<"�ͷ�"<<this->skill[2].skill<<endl;
			return i;
		}
		else if(i = 3)
		{
			cout<<name<<"�ͷ�"<<this->skill[3].skill<<endl;
			return i;
		}
		else
		{

		}
	} 
	
	void showDetail(){
		cout<<"Ӣ�ۣ�"<<name<<endl;
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
	
	Coordinate setXy(int x, int y){
		xy.x = x;
		xy.y = y;
	}

protected:
	Coordinate xy;
	SkillInfo skill[3];	//ǳ�����᲻�������� 
	string name;
	int health;
private:
	
};

class Force{
public:
	static int attacked_to(Hero &hero){
		hero.subHealth();
	}
};

int main(){
	WangZheDaLu wangZheDaLu;
	wangZheDaLu.showHeros();
	HeroInfo tempInfo;
	Hero *hero1 = new Hero(wangZheDaLu.getHero());
	Hero *hero2 = new Hero(wangZheDaLu.getHero());

	hero1->showDetail();
	hero2->showDetail();

	int a;
	cin>>a;


	startGame();
	return 0;
}

void startGame(){
	int ch;
    while (1){
        if (_kbhit()){//����а������£���_kbhit()����������
            ch = _getch();//ʹ��_getch()������ȡ���µļ�ֵ
            cout << "��ȡ�˼����¼�:" <<ch<<endl;
            if (ch == 27){ break; }//������ESCʱѭ����ESC���ļ�ֵʱ27.
        }
    }
} 
