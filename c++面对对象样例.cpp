#include <iostream>
#include <time.h>
#include<stdlib.h>
#include<fstream>
#include<string>
using namespace std;
class PLAYER//角色类基类，包括玩家的姓名，性别等
{      
    public:
    char Name[50];//姓名
    int sex;//选择性别
    string Sex;//性别
    void get_Name();//从键盘中输入姓名
    void get_sex();//获取性别
};

void PLAYER::get_Name()
{
    cout << "请输入游戏角色姓名：" << endl;
    cin >> Name;
    cout<<"您创建的游戏角色名为：" << Name<<endl;
}
void PLAYER::get_sex()
{

    int flag=1;//标志，如果输入性别正确，则退出循环，否则继续循环
    cout << "请选择创建角色的性别：" << endl;
    cout << "1.男性，2.女性" << endl;
    while(flag)
    {
    cin >> sex;
        switch (sex){
        case 1:
            Sex="男性";
            cout <<"您选择的角色性别为："<< Sex<<endl;
            flag = 0;//赋值为0，退出循环
            break;
        case 2:
            Sex="女性";
            cout <<"您选择的角色性别为:"<< Sex << endl;
            flag = 0;
            break;
        default:
            cout << "输入错误，请重新输入" << endl;
        }
         }
}





class Race:public PLAYER//基类的派生类，种族类和职业类

{
public:
    int race;//选择种族
    int occ;//选择职业
    string RACE;//种族
    string OCC;//职业
    void get_Race();//获取种族的函数
    void get_Occ();//获取职业函数
};

void Race::get_Race()
{
    cout << "请为角色选择种族" << endl;
    cout << "1.人类，2.精灵，3.兽人，4.矮人，5.元素" << endl;
    while(1)
    {
    cin >> race;
    switch (race)
    {
    case 1:
        RACE = "人类";        
        cout <<"您选择的种族为:"<< RACE;
        break;
    case 2:
        RACE = "精灵";
        cout << "您选择的种族为:" << RACE;
        break;
    case 3:
        RACE = "兽人";
        cout << "您选择的种族为:" << RACE;
        break;
    case 4:
        RACE = "矮人";
        cout << "您选择的种族为:" << RACE;
        break;
    case 5:
        RACE = "元素";
        cout << "您选择的种族为:" << RACE;
        break;
    default:
        cout << "选择错误，请重新选择" << endl;
    }
    if(race>=1&&race<=5)
    {break;}
    }
}

void Race::get_Occ()//控制那些种猪不能选的职业
{
 while(1)
 {
    switch (race)
    {
    case 1:
        cout<< "可选职业为" << endl;
        cout << "1.狂战士 2.圣骑士 3.刺客 4.猎手 5.祭司 6.巫师" << endl;
        break;
    case 2:
        cout << "可选职业为" << endl;
        cout << "3.刺客    4.猎手 5.祭司 6.巫师" << endl;
        break;
    case 3:
        cout << "可选职业为" << endl;
        cout << "1.狂战士 4.猎手 5.祭司"<< endl;
        break;
    case 4:
        cout << "可选职业为" << endl;
        cout << "1.狂战士 2.圣骑士 5.祭司    " << endl;
        break;
    case 5:
        cout << "可选职业为" << endl;
        cout << "5.祭司 6.巫师" << endl;
        break;
    }
    cin >> occ;
          if (race == 1 && (occ >= 1 && occ<= 6)) break;         //判断对应的种族下是否有对应的职业
          else if (race == 2 && (occ > 2 && occ < 7)) break;      //以及限制不同的种族下可选择的职业
          else if (race == 3 && (occ == 1 || occ == 4 || occ == 5)) break;
          else if (race == 4 && (occ == 1 || occ== 2 || occ == 5))  break;
          else if (race== 5 && (occ > 4 && occ < 7)) break;
          else  cout << "输入错误，请重新输入" << endl;
      }

    switch (occ)
    {
    case 1: OCC= "狂战士";break;
    case 2: OCC = "圣骑士";break;
    case 3: OCC = "刺客";break;
    case 4: OCC = "猎手"; break;
    case 5: OCC = "祭司"; break;
    case 6:OCC = "巫师"; break;
    }

    cout << "您选择的种族为" << RACE << endl;
    cout<< "您选择的职业为" << OCC << endl;
}
class ATTRIBUTE :public Race//属性   力量、敏捷、体力、智力和智慧要求是随机值（利用随机数函数来取得随机数），

{
protected:
    int STR;//力量
    int AGL;//敏捷
    int    VIT;//体力
    int INT;//智力
    int WIS;//智慧
    int HP;//生命值
    int MP;//魔法值
public:
    int nature_Random(int num1,int num2,int num3,int num4,int num5);//随机生成属性函数及五个属性初值
    int nature(int occ);//取决于职业的属性偏差
     friend class Output;
        friend class File;
};

/*随机数生成角色属性*/
int ATTRIBUTE::nature_Random(int num1, int num2, int num3, int num4, int num5)
{
    int sum;//属性值总和
    srand((unsigned)time(NULL));
    do
    {
        STR = (rand() % 10)-5 + num1;//力量
        AGL = (rand() % 10)-5 + num2;//敏捷
        VIT = (rand() % 10)-5  + num3;//体力
        INT = (rand() % 10)-5 + num4;//智力
        WIS = (rand() % 10)-5 + num5;//智慧
        sum = STR + AGL + VIT + INT + WIS;//总和
    } while (sum!=100);
    HP = VIT * 20;//生命值
    MP = (INT + WIS) * 10;//魔法值
    return 0;
}
//取决于职业的属性生成值
int ATTRIBUTE::nature(int occ)
{
    if (occ == 1) nature_Random(35, 15, 25, 5, 5);//狂战士的基础属性    
    if (occ == 2) nature_Random(20, 10, 25, 15, 15);//圣骑士的基础属性
    if (occ  == 3) nature_Random(15, 30, 15, 10, 15);//刺客的基础属性
    if (occ  == 4) nature_Random(10, 35, 10, 5, 25);//猎手的基础属性
    if (occ  == 5) nature_Random(10, 25, 10, 30, 20);//祭司的基础属性
    if (occ  == 6) nature_Random(5, 15, 5, 15, 45);//巫师的基础属性
return 0;
}

class Output  //将角色属性输出到显示器上
{
    public:
        void show(PLAYER &, Race &, ATTRIBUTE &);
};  
/*向界面输出角色信息*/
void Output::show(PLAYER &l, Race &r, ATTRIBUTE &n)
{
    cout << endl;
    cout << "**********************************************************" << endl; 
    cout << "\t姓名\t\t\t" << l.Name << endl;
    cout << "**********************************************************" << endl;
    cout << "\t性别\t\t\t" << l.Sex << endl;
    cout << "**********************************************************" << endl;
    cout << "\t种族\t\t\t" << r.RACE << endl;
    cout << "**********************************************************" << endl;
    cout << "\t职业\t\t\t" << r.OCC << endl;
    cout << "**********************************************************" << endl;
    cout << "\t力量\t\t\t" << n.STR << endl;
    cout << "**********************************************************" << endl;
    cout << "\t敏捷\t\t\t" << n.AGL << endl;
    cout << "**********************************************************" << endl;
    cout << " \t体力\t\t\t" << n.VIT << endl;
    cout << "**********************************************************" << endl;
    cout << "\t智力\t\t\t" << n.INT << endl;
    cout << "**********************************************************" << endl;
    cout << "\t智慧\t\t\t" << n.WIS << endl;
    cout << "**********************************************************" << endl;
    cout << "\t生命值\t\t\t" << n.HP << endl;
    cout << "**********************************************************" << endl;
    cout << "\t魔法值\t\t\t" << n.MP << endl;
    cout << "**********************************************************" << endl;
}

class File  //将角色信息保存到文档
{
  public:
      void file(PLAYER &, Race &, ATTRIBUTE &);
}; 

/*写入文件函数，保存创建角色的信息*/
void File ::file(PLAYER &l, Race &r, ATTRIBUTE &n)
{
    ofstream f1("data.txt");//若文件存在，则直接更新写入；若不存在，则创建文件再写入
    f1 << "您创建的角色信息如下" << endl;
    f1 << "**********************************************************" << endl;
    f1 << "\t姓名\t\t\t" << l.Name << endl;
    f1 << "**********************************************************" << endl;
    f1 << "\t性别\t\t\t" << l.Sex << endl;
    f1 << "**********************************************************" << endl;
    f1 << "\t种族\t\t\t" << r.RACE << endl;

    f1 << "**********************************************************" << endl;
    f1 << "\t职业\t\t\t" << r.OCC<< endl;

    f1 << "**********************************************************" << endl;
    f1 << "\t力量\t\t\t" << n.STR << endl;
    f1 << "**********************************************************" << endl;
    f1 << "\t敏捷\t\t\t" << n.AGL << endl;
    f1 << "**********************************************************" << endl;
    f1 << " \t体力\t\t\t" << n.VIT << endl;
    f1 << "**********************************************************" << endl;
    f1 << "\t智力\t\t\t" << n.INT << endl;
    f1 << "**********************************************************" << endl;
    f1 << "\t智慧\t\t\t" << n.WIS << endl;
    f1 << "**********************************************************" << endl;
    f1 << "\t生命值\t\t\t" << n.HP << endl;
    f1 << "**********************************************************" << endl;
    f1 << "\t魔法值\t\t\t" << n.MP << endl;
    f1 << "**********************************************************" << endl;
}

int main()
{
    PLAYER l;
    Race r;
    ATTRIBUTE n;
    Output o;
    File f;
    int x;
    do{
     l.get_Name();
     l.get_sex();
     r.get_Race();
     r.get_Occ();
     n.nature(r.occ);
     o.show(l,r,n);
     cout << endl;
       cout << "对生成的角色是否满意？如不满意，则重新生成" << endl;
       cout << "0.满意     1.不满意" << endl;
       cin >> x;
    } while (x);
    f.file(l, r, n);
    cout << "保存成功" << endl;
    return 0;
}
