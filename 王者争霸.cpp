#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;

void startGame();

namespace State{
	typedef enum{
	Empty,					//无
	BackToCity, 			//回城 
	InvinciblePerSecond,	//无敌一秒 
	InvincibleTwoSecond,	//无敌两秒 
	ShiftPerMeter,			//瞬移一米 
	ShiftTwoMeter,			//瞬移两米 
	ShiftTenMeter,			//瞬移十米 
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

//王者大陆类 地图属性 和 英雄属性 
class WangZheDaLu{
	// 地图 Coordinate: map
	// 英雄信息列表 vevtor 装 HeroInfo{name , SkillInfo{skill, SkillInfo}}
public:
	WangZheDaLu()
	{
		cout<<"欢迎来到王者大陆!"<<endl; 
		//添加英雄和属性，会直接压入  heroInfoList 向量里 
		HeroInfo libaiInfo = {"李白",{{"风过无痕",State::InvinciblePerSecond},{"剑阵",State::InvinciblePerSecond},{"九天泉剑",State::InvinciblePerSecond}}};
		this->heroInfoList.push_back(libaiInfo);
		
		HeroInfo fozuInfo = {"佛祖",{{"如来神掌",State::InvinciblePerSecond},{"指尖天涯",State::InvinciblePerSecond},{"宇宙",State::InvinciblePerSecond}}};
		this->heroInfoList.push_back(fozuInfo);

		HeroInfo wukongInfo = {"孙悟空",{{"当头棒喝",State::InvinciblePerSecond},{"筋斗云",State::InvinciblePerSecond},{"七十二般变化",State::InvinciblePerSecond}}};
		this->heroInfoList.push_back(wukongInfo);

		HeroInfo wuzetianInfo = {"武则天",{{"哼",State::InvinciblePerSecond},{"哈",State::InvinciblePerSecond},{"嘿",State::InvinciblePerSecond}}};
		this->heroInfoList.push_back(wuzetianInfo);
		
		HeroInfo yaseInfo = {"亚瑟",{{"如来剑盾冲击",State::InvinciblePerSecond},{"盾击",State::InvinciblePerSecond},{"泰山压顶",State::InvinciblePerSecond}}};
		this->heroInfoList.push_back(yaseInfo);
		
		HeroInfo anqilaInfo = {"其拉",{{"火球冲击",State::InvinciblePerSecond},{"烈焰龙卷",State::InvinciblePerSecond},{"法力射线",State::InvinciblePerSecond}}};
		this->heroInfoList.push_back(anqilaInfo);
		
		HeroInfo gongbenwuzangInfo = {"宫本武藏",{{"武士刀",State::InvinciblePerSecond},{"铠甲位移",State::InvinciblePerSecond},{"七星斩",State::InvinciblePerSecond}}};
		this->heroInfoList.push_back(gongbenwuzangInfo);
	}
	~WangZheDaLu(){
		cout<<"结束游戏"<<endl;
	}
	
	void showHeros(){
		cout<<"一共有："<<this->heroInfoList.size()<<"个英雄"<<endl;
	}
	HeroInfo getHero(){
		cout<<"在：";
		vector<HeroInfo>::iterator iter;
    	for(iter = heroInfoList.begin(); iter != heroInfoList.end(); iter++){
        	cout <<iter->name << ",";
    	}
    	cout<<"中选一个英雄"<<endl;
    	
    	string tempName;
HERE:
    	cin>>tempName;
    	for(iter = heroInfoList.begin(); iter != heroInfoList.end(); iter++){
        	if(iter->name == tempName){
        		return *iter;
			}
    	}
    	cout<<"输入错误,重新输入"<<endl;
    	goto HERE;
//		HeroInfo nullHero = {"空",{{"空",State::Empty},{"空",State::Empty},{"空",State::Empty}}};s
		return nullHero;
	} 

private:
	const Coordinate map = {1000, 1000};
	vector <HeroInfo> heroInfoList;
};


class Hero{
	//英雄
	//属性： 名字name   生命值health   技能skill   位置xy (coordinate)结构体 
	//方法： birth（）		出场喊话 
	//方法： do_skill() 	放技能 
	//方法： showDetail() 显示信息 
	//方法： subHealth()  受到攻击，掉血 
	//方法： birth（）出场喊话 
	//方法:	 setXy() 设置坐标值 Coordinate 结构体 
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
		cout<<name<<":出场"<<endl;
	}
	int do_skill(int i){
		if(i = 0){
			cout<<name<<"释放"<<this->skill[0].skill<<endl;
			return i;
		}
		else if(i = 1)
		{
			cout<<name<<"释放"<<this->skill[1].skill<<endl;
			return i;
		}
		else if(i = 2)
		{
			cout<<name<<"释放"<<this->skill[2].skill<<endl;
			return i;
		}
		else if(i = 3)
		{
			cout<<name<<"释放"<<this->skill[3].skill<<endl;
			return i;
		}
		else
		{

		}
	} 
	
	void showDetail(){
		cout<<"英雄："<<name<<endl;
		cout<<"生命："<<health<<endl;
		cout<<"位置："<<"x:"<<xy.x<<"y:"<<xy.y<<endl;
	}
	
	int subHealth(){
		if(health == 0){
			cout<<"死人不能再死了"<<endl;
			return 0;
		}
		this->health--;
		cout<<name<<"：啊！！生命值为:"<<health<<endl; 
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
	SkillInfo skill[3];	//浅拷贝会不会有问题 
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
        if (_kbhit()){//如果有按键按下，则_kbhit()函数返回真
            ch = _getch();//使用_getch()函数获取按下的键值
            cout << "获取了键盘事件:" <<ch<<endl;
            if (ch == 27){ break; }//当按下ESC时循环，ESC键的键值时27.
        }
    }
} 
