#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main(){
	vector<int> b(10,3);
	vector<int> c(10,5);
//	vector<int> a[10]; //������10������ �����飻������ 
	vector<int> a(10); //������10������Ԫ�ص���������������ΪԪ�������������������κκϷ����������ͣ�����û�и�����ֵ����ֵ�ǲ�ȷ���ġ�
//	vector<int> a(10,1); //������10������Ԫ�ص�����,�Ҹ���ÿ��Ԫ�صĳ�ֵΪ1
//	vector<int> a(b); //��b����������a���������帴���Ը�ֵ
//	vector<int> a(b.begin(),b.begin+3); //������aֵΪb�е�0������2������3����Ԫ��
//	int b[7]={1,2,3,4,5,9,8};
//  vector<int> a(b,b+7); //�������л�ó�ֵ

	a.assign(b.begin(), b.begin()+3); 
	
	cout<<"new line 1 ---------"<<endl;
	for(int i=0; i<a.size(); i++){
		cout<<a[i]<<endl;
	}
	
	a.assign(c.begin(), c.begin()+3); //bΪ��������b��0~2��Ԫ�ع��ɵ���������a
	
	cout<<"new line 2 ---------"<<endl;
	for(int i=0; i<a.size(); i++){
		cout<<a[i]<<endl;
	}
	
	a.assign(3,2); //���ó��ȣ�����ֵ����aֻ��4��Ԫ�أ���ÿ��Ԫ��Ϊ2

	cout<<"new line 3 ---------"<<endl;
	for(int i=0; i<a.size(); i++){
		cout<<a[i]<<endl;
	}
	
	for(int i=0;i<10;i++)
    	a.push_back(i);
    	
    cout<<"new line 4 ---------"<<endl;
	for(int i=0; i<a.size(); i++){
		cout<<a[i]<<endl;
	}
	
	a.front() = 1;
	*(&a.front()+1) = 2;
	*(&a.front()+2) = 3;
	
	cout<<"new line 5 ---------"<<endl;
	for(int i=0; i<a.size(); i++){
		cout<<a[i]<<endl;
	}
//	a.back(); //����a�����һ��Ԫ��
//	a.front(); //����a�ĵ�һ��Ԫ��
//	a.clear(); //���a�е�Ԫ��
//	a.empty(); //�ж�a�Ƿ�Ϊ�գ����򷵻�ture,�����򷵻�false
//	a.pop_back(); //ɾ��a���������һ��Ԫ��
	a.erase(a.begin()+1,a.begin()+3); //(��ͷ����β),ɾ��a�е�1�����ӵ�0�����𣩵���2��Ԫ�أ�Ҳ����˵ɾ����Ԫ�ش�a.begin()+1���𣨰�������һֱ��a.begin()+         3������������
	cout<<"new line 6 ---------"<<endl;
	for(int i=0; i<a.size(); i++){
		cout<<a[i]<<endl;
	}
	
	a.assign(5,2);
	cout<<"new line 7 ---------"<<endl;
	for(int i=0; i<a.size(); i++){
		cout<<a[i]<<endl;
	}
	
//	a.insert(a.begin()+1, 5);
	cout<<"new line 8 ---------"<<endl;
	for(int i=0; i<a.size(); i++){
		cout<<a[i]<<endl;
	}
//	a.push_back(5); //��a�����һ�����������һ��Ԫ�أ���ֵΪ5
//	a.insert(a.begin()+1,5); //��a�ĵ�1��Ԫ�أ��ӵ�0�����𣩵�λ�ò�����ֵ5����aΪ1,2,3,4������Ԫ�غ�Ϊ1,5,2,3,4
//	a.insert(a.begin()+1,3,5); //��a�ĵ�1��Ԫ�أ��ӵ�0�����𣩵�λ�ò���3��������ֵ��Ϊ5
//	a.insert(a.begin()+1,b+3,b+6); //bΪ���飬��a�ĵ�1��Ԫ�أ��ӵ�0�����𣩵�λ�ò���b�ĵ�3��Ԫ�ص���5��Ԫ�أ�������b+6������bΪ1,2,3,4,5,9,8         ������Ԫ�غ�Ϊ1,4,5,9,2,3,4,5,9,8
//	a.size(); 				//����a��Ԫ�صĸ�����
	int size = a.capacity(); //����a���ڴ����ܹ��������ɵ�Ԫ�ظ���
	cout<<"new line 9 ---------"<<endl;
	cout<<"�ܸ�����: "<<size<<endl;
	
	a.assign(1,1);
	size = a.capacity();
	cout<<"new line 10 ---------"<<endl;
	cout<<"�ܸ�����: "<<size<<endl;

//	a.resize(10); //��a������Ԫ�ظ�������10��������ɾ�����򲹣���ֵ��� (reserve :������������Ԥ��) 
	a.resize(10,2); //��a������Ԫ�ظ�������10��������ɾ�����򲹣���ֵΪ2 (reserve :����, ������Ԥ��) 
	cout<<"new line 11 ---------"<<endl;
	for(int i=0; i<a.size(); i++){
		cout<<a[i]<<endl;
	}
	
//	a.reserve(100); //��a��������capacity��������100��Ҳ����˵���ڲ���a.capacity();��ʱ�򷵻�ֵ��100.���ֲ���ֻ������Ҫ��a��Ӵ������ݵ�ʱ���         �Ե������壬��Ϊ�⽫�����ڴ������������������a����������ʱ���Ի��Զ����ݣ���Ȼ���Ȼ�������ܣ� 
	
//	a.swap(b); //bΪ��������a�е�Ԫ�غ�b�е�Ԫ�ؽ��������Խ���
	a.swap(c);
	cout<<"new line 12 ---------"<<endl;
	for(int i=0; i<a.size(); i++){
		cout<<a[i]<<endl;
	}

//	a==b; //bΪ�����������ıȽϲ�������!=,>=,<=,>,<
	
	return 0;
} 
