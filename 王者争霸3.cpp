#include <iostream>
#include <conio.h>	//获取键值 的头文件 
#include <vector>
#include <windows.h>
using namespace std;

namespace State{
	
	typedef enum{
		//键值枚举 
		Up,		//上 
		Down,	//下 
		Left,	//左 
		Right,	//右 
	}Direction;
	
	typedef enum{
		//技能效果 枚举 
		/*
		无			0
		回城 		1
		无敌一秒 	2
		无敌两秒 	3
		瞬移一米 	4
		瞬移两米 	5
		瞬移十米 	6
		双倍伤害	7	
		*/ 
		Empty,					//无				0
		BackToCity, 			//回城 				1
		InvinciblePerSecond,	//无敌一秒 			2
		InvincibleTwoSecond,	//无敌两秒 			3
		ShiftPerMeter,			//瞬移一米 			4
		ShiftTwoMeter,			//瞬移两米 			5
		ShiftTenMeter,			//瞬移十米 			6
		DoubleBlood,			//双倍伤害			7				
		OneBlood,				//一倍伤害 
		Eight,					//
		Nine,					//
		Ten, 					//
	}SkillEffect;

}

struct SkillInfo{
	//技能信息结构体 技能名 和 技能效果（State::SkillEffect 枚举变量） 
	string skill;
	State::SkillEffect skillEffect;
};

struct HeroInfo{
	//英雄信息结构体 名字 和 三个技能结构体（SkillInfo） 
	string name;
	SkillInfo skill[3];
};

struct Coordinate{
	//英雄坐标结构体 
	int x;
	int y;
};

void startGame();

//王者大陆类 地图属性 和 英雄属性 
class WangZheDaLu{
	// 地图 Coordinate: map
	// 英雄信息列表 vevtor 装 HeroInfo{name , SkillInfo{skill, SkillInfo}}
public:
	WangZheDaLu()
	{
		cout<<"欢迎来到王者大陆!"<<endl<<endl; 
		cout<<"一共两个玩家，地图范围是1000*1000,\n"
		"A玩家移动键 W上 A左 S下 D右，JKL是技能;\n"
		"B玩家移动键 up上 left左 down下 right右，技能小键盘123;"<<endl<<endl;
		//添加英雄和属性，会直接压入  heroInfoList 向量里 
		HeroInfo libaiInfo = {"李白",{{"风过无痕",State::OneBlood},{"剑阵",State::ShiftTwoMeter},{"九天泉剑",State::BackToCity}}};
		this->heroInfoList.push_back(libaiInfo);
		
		HeroInfo fozuInfo = {"佛祖",{{"如来神掌",State::OneBlood},{"指尖天涯",State::ShiftTenMeter},{"宇宙",State::BackToCity}}};
		this->heroInfoList.push_back(fozuInfo);

		HeroInfo wukongInfo = {"孙悟空",{{"当头棒喝",State::DoubleBlood},{"筋斗云",State::ShiftTenMeter},{"七十二般变化",State::InvinciblePerSecond}}};
		this->heroInfoList.push_back(wukongInfo);

		HeroInfo wuzetianInfo = {"武则天",{{"哼",State::DoubleBlood},{"哈",State::ShiftTwoMeter},{"嘿",State::InvinciblePerSecond}}};
		this->heroInfoList.push_back(wuzetianInfo);
		
		HeroInfo yaseInfo = {"亚瑟",{{"如来剑盾冲击",State::ShiftTwoMeter},{"盾击",State::OneBlood},{"泰山压顶",State::DoubleBlood}}};
		this->heroInfoList.push_back(yaseInfo);
		
		HeroInfo anqilaInfo = {"安其拉",{{"火球冲击",State::OneBlood},{"烈焰龙卷",State::ShiftTwoMeter},{"法力射线",State::InvinciblePerSecond}}};
		this->heroInfoList.push_back(anqilaInfo);
		
		HeroInfo gongbenwuzangInfo = {"宫本武藏",{{"武士刀",State::OneBlood},{"铠甲位移",State::ShiftTwoMeter},{"七星斩",State::DoubleBlood}}};
		this->heroInfoList.push_back(gongbenwuzangInfo);
	}
	~WangZheDaLu(){
		cout<<"结束游戏"<<endl;
	}
	
	void customHero(){
		//自定义英雄 
		cout<<"输入名字:"<<endl;
		string name;
		cin>>name;
		cout<<endl<<"技能效果："<<endl;	
		cout<<"无：0"<<endl;
		cout<<"回城：1"<<endl;
		cout<<"无敌一秒：2"<<endl;
		cout<<"无敌两秒：3"<<endl;
		cout<<"瞬移一米：4"<<endl;
		cout<<"瞬移两米：5"<<endl;
		cout<<"瞬移十米：6"<<endl;
		cout<<"双倍伤害：7"<<endl;
		cout<<"一倍伤害：8"<<endl;
		
		cout<<endl<<"输入技能1名字（string）:"<<endl;
		string skill1;
		cin>>skill1;
		cout<<"技能1效果（int）:"<<endl;
		int i;
		cin>>i;
		cout<<"输入技能2（string）:"<<endl;
		string skill2;
		cin>>skill2;
		cout<<"技能2效果（int）:"<<endl;
		int j;
		cin>>j;
		cout<<"输入技能3（string）:"<<endl;
		string skill3;
		cin>>skill3;
		cout<<"技能3效果（int）:"<<endl;
		int k;
		cin>>k;
		
		// i，j，k是整形，参数必须是 State 名字空间里的 枚举类型 
		HeroInfo yaseInfo = {name,{{skill1,(State::SkillEffect)i},{skill2,(State::SkillEffect)j},{skill3,(State::SkillEffect)k}}};
		this->heroInfoList.push_back(yaseInfo);
	} 
	
	void showHeros(){
		//显示英雄总数 
		cout<<"一共有："<<this->heroInfoList.size()<<"个英雄"<<endl;
	}
	HeroInfo getHero(){
		//选英雄 
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
//		return nullHero;
	} 

private:
	const Coordinate map = {1000, 1000};//地图大小，可以做为移动限制，目前没有实现 
	vector <HeroInfo> heroInfoList;//英雄 信息 列表 
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
		this->direction = State::Up;
		directionChar = "北"; 
	}
	Hero(HeroInfo heroInfo){
		this->health = 5;
		this->setXy(0,0);
		this->name = heroInfo.name;
		this->skill[0] = heroInfo.skill[0];
		this->skill[1] = heroInfo.skill[1];
		this->skill[2] = heroInfo.skill[2];
		this->direction = State::Up;
		directionChar = "北"; 
	}

	~Hero(){
	}

	void birth(){
		cout<<name<<":出场"<<endl;
	}
	int do_skill(int i){
		/*
		放技能， 通过 Force 类实例来调用，不直接调用的原因是： 
		此类是英雄类，如果英雄范围攻击，判断范围类有没有其他英雄需要其他英雄的实例并判断其坐标，
		如果再属性里加入所有实例英雄的列表指针，那么每一个实例都会有一个列表，浪费空间，
		所以就定义一个force类类存场上所有实例英雄的指针列表 
		*/
		if(i == 0){
			cout<<name<<"释放"<<this->skill[0].skill<<endl;
			rangEffect((skill[i].skillEffect));
			return i;
		}
		else if(i == 1)
		{
			cout<<name<<"释放"<<this->skill[1].skill<<endl;
			rangEffect((skill[i].skillEffect));
			return i;
		}
		else if(i == 2)
		{
			cout<<name<<"释放"<<this->skill[2].skill<<endl;
			rangEffect((skill[i].skillEffect));
			return i;
		}
		else if(i == 3)
		{
			cout<<name<<"释放"<<this->skill[3].skill<<endl;
			rangEffect((skill[i].skillEffect));
			return i;
		}
		else
		{

		}
	}  
	
	void rangEffect(const State::SkillEffect ef){
		if(ef == State::BackToCity){
			//回城
			cout<<name<<":回城"<<endl; 
			setXy(0, 0);
			health = 5;
			cout<<name<<":生命值："<<health<<endl;
		}
		else if(ef == State::InvinciblePerSecond){
			//无敌一秒 
			cout<<"无敌一秒(需要一个线层计时器)"<<endl;
		}
		else if(ef == State::InvincibleTwoSecond){
			//无敌两秒 
			cout<<"无敌量秒(需要一个线层计时器)"<<endl;
		}
		else if(ef == State::ShiftPerMeter){
			//瞬移一米 (3格) 
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
			//瞬移两米 
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
			//瞬移十米 
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
			//双倍伤害 double damage 
			//内部无法实现，只有靠外部 Force 类实例，装下所有实例 hero 实现 
		}
	}
	
	void showDetail(){
		cout<<"英雄："<<name<<"技能："<<skill[0].skill<<", "<<skill[1].skill<<", "<<skill[2].skill<<", "<<endl;
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
	int addHealth(){
		if(health < 5){
			health++;
			cout<<name<<"生命:"<<health<<endl;
		}
		return health;
	}
	
	void leftShift(){
		if(xy.x>0){
			xy.x--;
		}
		this->direction = State::Left;
		this->directionChar = "西";
		showCoordinate();
	}
	void rightShift(){
		if(xy.x<1000){
			xy.x++;
		}
		this->direction = State::Right;
		this->directionChar = "东";
		showCoordinate();
		
	}
	void upShift(){
		if(xy.y>0){
			xy.y--;
		}
		this->direction = State::Up;
		this->directionChar = "北";
		showCoordinate();
	}
	void downShift(){
		if(xy.y<1000){
			xy.y++;
		}
		this->direction = State::Down;
		this->directionChar = "南";
		showCoordinate();
	}
	
	void showCoordinate(){ 
		cout<<this->name<<":("<<this->xy.x<<","<<this->xy.y<<")"<<"面向:"<<this->directionChar<<endl;
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
	SkillInfo skill[3];	//浅拷贝会不会有问题 
	string name;
	int health;
private:
	
};

class Force{
	/*
		通过 Force 存英雄实例（指针列表）
		可以在 attacked_by方法中判断出到底是 传递行为，还是自身行为， 如果是传递行为 obj ==》 obj 那就需要指针列表，然后判断是否符合传递条件
		可以改进的地方是：可以把固定的两个英雄指针 改成 英雄列表 vector， 主进程中 也可以在 选英雄时候 循环方式来选 并 用 vector 向量来装。 
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
			//注意：  这样的写法是愚蠢的   if(-3<(x1-x2)<3 && -3<(y1-y2)<3)
			//判断 英雄 a 和 b 的距离 
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
				cout<<hero->getName()<<"打中空气！"<<endl;
			}
		}
		else if (hero->getSkillType(i) == State::OneBlood)
		{
			int x1 = hero1->getXy().x;
			int x2 = hero2->getXy().x;
			int y1 = hero1->getXy().y;
			int y2 = hero2->getXy().y;
			//注意：  这样的写法是愚蠢的   if(-3<(x1-x2)<3 && -3<(y1-y2)<3)
			if(-3<(x1-x2) && (x1-x2)<3 && -3<(y1-y2) && (y1-y2)<3){
				if(hero == hero1){
					hero2->subHealth();
				}
				else{
					hero1->subHealth();
				}
			}
			else{
				cout<<hero->getName()<<"打中空气！"<<endl;
			}
		}
		else{
			hero->do_skill(i);
		}
	}	
	// 此处没有定义 vector 因为只有两个英雄  
	void setHeros(Hero *hero1, Hero *hero2){
		this->hero1 = hero1;
		this->hero2 = hero2;
	}
private:
	// 可以定义 vector 来存放多个英雄 
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
	
	cout<<"如果需要玩自定义英雄就输入(要)，否则跳过：";
	string c;
	cin>>c;
	if(c == "要"){
		while(1){
			wangZheDaLu.customHero();
			cout<<"继续吗？输入（完成）退出，否则继续";
			cin>>c;
			if(c == "完成")
			{
				break;
			}
		}
	}	
	wangZheDaLu.showHeros();
	Hero *hero1 = new Hero(wangZheDaLu.getHero());
	Hero *hero2 = new Hero(wangZheDaLu.getHero());
	cout<<endl<<"对战阵容是:"<<endl;
	hero1->showDetail();
	cout<<endl;
	hero2->showDetail();
	
	Force force;
	force.setHeros(hero1, hero2);
	
	
	cout<<endl;
	cout<<"五秒后开始游戏"<<endl;
	for(int i = 5; i >= 0; i--){
		Sleep(1000);
		cout<<i<<endl;
	}
	cout<<"峡谷打开"<<endl; 
	 
	int ch;
    while (1){
        if (_kbhit()){//如果有按键按下，则_kbhit()函数返回真
            ch = _getch();//使用_getch()函数获取按下的键值
            if (ch == 27){
            	break;
			}
			else if (ch == 75){
				//b 左 
				hero2->leftShift();
			}
			else if (ch == 77){
				//b 右 
				hero2->rightShift();
			}
			else if (ch == 72){
				//b 上 
				hero2->upShift();
			}
			else if (ch == 80){
				//b 下 
				hero2->downShift();
			}
			else if (ch == 97){
				//a 左 
				hero1->leftShift();
			}
			else if (ch == 115){
				//a 下 
				hero1->downShift();
			}
			else if (ch == 100){
				//a 右	
				hero1->rightShift();		
			}
			else if (ch == 119){
				//a 上 
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

            if (ch == 27){ break; }//当按下ESC时循环，ESC键的键值时27.
        }
    }
} 
