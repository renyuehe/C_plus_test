#include <iostream>
#include <time.h>
#include<stdlib.h>
#include<fstream>
#include<string>
using namespace std;
class PLAYER//��ɫ����࣬������ҵ��������Ա��
{      
    public:
    char Name[50];//����
    int sex;//ѡ���Ա�
    string Sex;//�Ա�
    void get_Name();//�Ӽ�������������
    void get_sex();//��ȡ�Ա�
};

void PLAYER::get_Name()
{
    cout << "��������Ϸ��ɫ������" << endl;
    cin >> Name;
    cout<<"����������Ϸ��ɫ��Ϊ��" << Name<<endl;
}
void PLAYER::get_sex()
{

    int flag=1;//��־����������Ա���ȷ�����˳�ѭ�����������ѭ��
    cout << "��ѡ�񴴽���ɫ���Ա�" << endl;
    cout << "1.���ԣ�2.Ů��" << endl;
    while(flag)
    {
    cin >> sex;
        switch (sex){
        case 1:
            Sex="����";
            cout <<"��ѡ��Ľ�ɫ�Ա�Ϊ��"<< Sex<<endl;
            flag = 0;//��ֵΪ0���˳�ѭ��
            break;
        case 2:
            Sex="Ů��";
            cout <<"��ѡ��Ľ�ɫ�Ա�Ϊ:"<< Sex << endl;
            flag = 0;
            break;
        default:
            cout << "�����������������" << endl;
        }
         }
}





class Race:public PLAYER//����������࣬�������ְҵ��

{
public:
    int race;//ѡ������
    int occ;//ѡ��ְҵ
    string RACE;//����
    string OCC;//ְҵ
    void get_Race();//��ȡ����ĺ���
    void get_Occ();//��ȡְҵ����
};

void Race::get_Race()
{
    cout << "��Ϊ��ɫѡ������" << endl;
    cout << "1.���࣬2.���飬3.���ˣ�4.���ˣ�5.Ԫ��" << endl;
    while(1)
    {
    cin >> race;
    switch (race)
    {
    case 1:
        RACE = "����";        
        cout <<"��ѡ�������Ϊ:"<< RACE;
        break;
    case 2:
        RACE = "����";
        cout << "��ѡ�������Ϊ:" << RACE;
        break;
    case 3:
        RACE = "����";
        cout << "��ѡ�������Ϊ:" << RACE;
        break;
    case 4:
        RACE = "����";
        cout << "��ѡ�������Ϊ:" << RACE;
        break;
    case 5:
        RACE = "Ԫ��";
        cout << "��ѡ�������Ϊ:" << RACE;
        break;
    default:
        cout << "ѡ�����������ѡ��" << endl;
    }
    if(race>=1&&race<=5)
    {break;}
    }
}

void Race::get_Occ()//������Щ������ѡ��ְҵ
{
 while(1)
 {
    switch (race)
    {
    case 1:
        cout<< "��ѡְҵΪ" << endl;
        cout << "1.��սʿ 2.ʥ��ʿ 3.�̿� 4.���� 5.��˾ 6.��ʦ" << endl;
        break;
    case 2:
        cout << "��ѡְҵΪ" << endl;
        cout << "3.�̿�    4.���� 5.��˾ 6.��ʦ" << endl;
        break;
    case 3:
        cout << "��ѡְҵΪ" << endl;
        cout << "1.��սʿ 4.���� 5.��˾"<< endl;
        break;
    case 4:
        cout << "��ѡְҵΪ" << endl;
        cout << "1.��սʿ 2.ʥ��ʿ 5.��˾    " << endl;
        break;
    case 5:
        cout << "��ѡְҵΪ" << endl;
        cout << "5.��˾ 6.��ʦ" << endl;
        break;
    }
    cin >> occ;
          if (race == 1 && (occ >= 1 && occ<= 6)) break;         //�ж϶�Ӧ���������Ƿ��ж�Ӧ��ְҵ
          else if (race == 2 && (occ > 2 && occ < 7)) break;      //�Լ����Ʋ�ͬ�������¿�ѡ���ְҵ
          else if (race == 3 && (occ == 1 || occ == 4 || occ == 5)) break;
          else if (race == 4 && (occ == 1 || occ== 2 || occ == 5))  break;
          else if (race== 5 && (occ > 4 && occ < 7)) break;
          else  cout << "�����������������" << endl;
      }

    switch (occ)
    {
    case 1: OCC= "��սʿ";break;
    case 2: OCC = "ʥ��ʿ";break;
    case 3: OCC = "�̿�";break;
    case 4: OCC = "����"; break;
    case 5: OCC = "��˾"; break;
    case 6:OCC = "��ʦ"; break;
    }

    cout << "��ѡ�������Ϊ" << RACE << endl;
    cout<< "��ѡ���ְҵΪ" << OCC << endl;
}
class ATTRIBUTE :public Race//����   ���������ݡ��������������ǻ�Ҫ�������ֵ�����������������ȡ�����������

{
protected:
    int STR;//����
    int AGL;//����
    int    VIT;//����
    int INT;//����
    int WIS;//�ǻ�
    int HP;//����ֵ
    int MP;//ħ��ֵ
public:
    int nature_Random(int num1,int num2,int num3,int num4,int num5);//����������Ժ�����������Գ�ֵ
    int nature(int occ);//ȡ����ְҵ������ƫ��
     friend class Output;
        friend class File;
};

/*��������ɽ�ɫ����*/
int ATTRIBUTE::nature_Random(int num1, int num2, int num3, int num4, int num5)
{
    int sum;//����ֵ�ܺ�
    srand((unsigned)time(NULL));
    do
    {
        STR = (rand() % 10)-5 + num1;//����
        AGL = (rand() % 10)-5 + num2;//����
        VIT = (rand() % 10)-5  + num3;//����
        INT = (rand() % 10)-5 + num4;//����
        WIS = (rand() % 10)-5 + num5;//�ǻ�
        sum = STR + AGL + VIT + INT + WIS;//�ܺ�
    } while (sum!=100);
    HP = VIT * 20;//����ֵ
    MP = (INT + WIS) * 10;//ħ��ֵ
    return 0;
}
//ȡ����ְҵ����������ֵ
int ATTRIBUTE::nature(int occ)
{
    if (occ == 1) nature_Random(35, 15, 25, 5, 5);//��սʿ�Ļ�������    
    if (occ == 2) nature_Random(20, 10, 25, 15, 15);//ʥ��ʿ�Ļ�������
    if (occ  == 3) nature_Random(15, 30, 15, 10, 15);//�̿͵Ļ�������
    if (occ  == 4) nature_Random(10, 35, 10, 5, 25);//���ֵĻ�������
    if (occ  == 5) nature_Random(10, 25, 10, 30, 20);//��˾�Ļ�������
    if (occ  == 6) nature_Random(5, 15, 5, 15, 45);//��ʦ�Ļ�������
return 0;
}

class Output  //����ɫ�����������ʾ����
{
    public:
        void show(PLAYER &, Race &, ATTRIBUTE &);
};  
/*����������ɫ��Ϣ*/
void Output::show(PLAYER &l, Race &r, ATTRIBUTE &n)
{
    cout << endl;
    cout << "**********************************************************" << endl; 
    cout << "\t����\t\t\t" << l.Name << endl;
    cout << "**********************************************************" << endl;
    cout << "\t�Ա�\t\t\t" << l.Sex << endl;
    cout << "**********************************************************" << endl;
    cout << "\t����\t\t\t" << r.RACE << endl;
    cout << "**********************************************************" << endl;
    cout << "\tְҵ\t\t\t" << r.OCC << endl;
    cout << "**********************************************************" << endl;
    cout << "\t����\t\t\t" << n.STR << endl;
    cout << "**********************************************************" << endl;
    cout << "\t����\t\t\t" << n.AGL << endl;
    cout << "**********************************************************" << endl;
    cout << " \t����\t\t\t" << n.VIT << endl;
    cout << "**********************************************************" << endl;
    cout << "\t����\t\t\t" << n.INT << endl;
    cout << "**********************************************************" << endl;
    cout << "\t�ǻ�\t\t\t" << n.WIS << endl;
    cout << "**********************************************************" << endl;
    cout << "\t����ֵ\t\t\t" << n.HP << endl;
    cout << "**********************************************************" << endl;
    cout << "\tħ��ֵ\t\t\t" << n.MP << endl;
    cout << "**********************************************************" << endl;
}

class File  //����ɫ��Ϣ���浽�ĵ�
{
  public:
      void file(PLAYER &, Race &, ATTRIBUTE &);
}; 

/*д���ļ����������洴����ɫ����Ϣ*/
void File ::file(PLAYER &l, Race &r, ATTRIBUTE &n)
{
    ofstream f1("data.txt");//���ļ����ڣ���ֱ�Ӹ���д�룻�������ڣ��򴴽��ļ���д��
    f1 << "�������Ľ�ɫ��Ϣ����" << endl;
    f1 << "**********************************************************" << endl;
    f1 << "\t����\t\t\t" << l.Name << endl;
    f1 << "**********************************************************" << endl;
    f1 << "\t�Ա�\t\t\t" << l.Sex << endl;
    f1 << "**********************************************************" << endl;
    f1 << "\t����\t\t\t" << r.RACE << endl;

    f1 << "**********************************************************" << endl;
    f1 << "\tְҵ\t\t\t" << r.OCC<< endl;

    f1 << "**********************************************************" << endl;
    f1 << "\t����\t\t\t" << n.STR << endl;
    f1 << "**********************************************************" << endl;
    f1 << "\t����\t\t\t" << n.AGL << endl;
    f1 << "**********************************************************" << endl;
    f1 << " \t����\t\t\t" << n.VIT << endl;
    f1 << "**********************************************************" << endl;
    f1 << "\t����\t\t\t" << n.INT << endl;
    f1 << "**********************************************************" << endl;
    f1 << "\t�ǻ�\t\t\t" << n.WIS << endl;
    f1 << "**********************************************************" << endl;
    f1 << "\t����ֵ\t\t\t" << n.HP << endl;
    f1 << "**********************************************************" << endl;
    f1 << "\tħ��ֵ\t\t\t" << n.MP << endl;
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
       cout << "�����ɵĽ�ɫ�Ƿ����⣿�粻���⣬����������" << endl;
       cout << "0.����     1.������" << endl;
       cin >> x;
    } while (x);
    f.file(l, r, n);
    cout << "����ɹ�" << endl;
    return 0;
}
