#include <iostream>
#include <vector>

using namespace std;

class Chair{
public:
	Chair(){
		this->brand = "��ͨ";
		this->style = "��ͨ";
		this->value = 0;
	}
	~Chair(){
		cout<<"��������"<<endl;;
	}
	void showDetails(){
		cout<<"���ӵ�Ʒ��"<<this->brand<<endl;
		cout<<"��ʽ:"<<this->style<<endl;
		cout<<"��ֵ:"<<this->value<<endl; 
	}

private:
	string brand;
	string style;
	int value;
};

class Car{
public:
	Car(){
		value = 30;
		brand = "����";
		name = "x3";
		outputVolume = 2.0; 
	}
	~Car(){
		cout<<this->brand<<":"<<this->name<<"����"<<endl;
	}
	void setDetail(string brand, string name, int value, float volume){
		this->brand = brand;
		this->name = name;
		this->value = value;
	}
	void setChair(const Chair &chair){
		this->vec_chairs.push_back(chair);
	}
	void setChair(){
		
	}
	void setValue(const int n){
		this->value = n;
	}
	int getValue(){
		return this->value;
	}
	void showDetail(){
		cout<<brand<<" is worth:"<<value<<"w"<<endl;
		cout<<brand<<" name is:"<<name<<endl;
		cout<<brand<<" outputVolume is:"<<outputVolume<<endl;
		if(this->vec_chairs.size() == 0){
			cout<<"û������"<<endl;
		}
		else
		{
			//cout<<this->vec_chairs
			cout<<"��"<<vec_chairs.size()<<"����"<<endl;
			//���� vector ��װ���ӵ�ʱ�� �� զ������ӵ���Ϣ�� 
			this->vec_chairs.at(0).showDetails();
		}
	}
	
private:
	vector <Chair> vec_chairs;
	int value;
	string name;
	string brand;
	float outputVolume;
};

int main(){
	Car *car1 = new Car;
	car1->showDetail();
	
	Chair chair1;
	
	car1->setDetail("����","sss",30,3.0);
	car1->showDetail();
	cout<<"------------------"<<endl;
	car1->setChair(chair1);
	car1->showDetail();
	cout<<"------------------"<<endl;
	
	delete car1;
	return 0;
}


