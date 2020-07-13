#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main(){
	vector<int> b(10,3);
	vector<int> c(10,5);
//	vector<int> a[10]; //定义了10个向量 的数组；！！！ 
	vector<int> a(10); //定义了10个整型元素的向量（尖括号中为元素类型名，它可以是任何合法的数据类型），但没有给出初值，其值是不确定的。
//	vector<int> a(10,1); //定义了10个整型元素的向量,且给出每个元素的初值为1
//	vector<int> a(b); //用b向量来创建a向量，整体复制性赋值
//	vector<int> a(b.begin(),b.begin+3); //定义了a值为b中第0个到第2个（共3个）元素
//	int b[7]={1,2,3,4,5,9,8};
//  vector<int> a(b,b+7); //从数组中获得初值

	a.assign(b.begin(), b.begin()+3); 
	
	cout<<"new line 1 ---------"<<endl;
	for(int i=0; i<a.size(); i++){
		cout<<a[i]<<endl;
	}
	
	a.assign(c.begin(), c.begin()+3); //b为向量，将b的0~2个元素构成的向量赋给a
	
	cout<<"new line 2 ---------"<<endl;
	for(int i=0; i<a.size(); i++){
		cout<<a[i]<<endl;
	}
	
	a.assign(3,2); //重置长度，重置值，是a只含4个元素，且每个元素为2

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
//	a.back(); //返回a的最后一个元素
//	a.front(); //返回a的第一个元素
//	a.clear(); //清空a中的元素
//	a.empty(); //判断a是否为空，空则返回ture,不空则返回false
//	a.pop_back(); //删除a向量的最后一个元素
	a.erase(a.begin()+1,a.begin()+3); //(顾头不顾尾),删除a中第1个（从第0个算起）到第2个元素，也就是说删除的元素从a.begin()+1算起（包括它）一直到a.begin()+         3（不包括它）
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
//	a.push_back(5); //在a的最后一个向量后插入一个元素，其值为5
//	a.insert(a.begin()+1,5); //在a的第1个元素（从第0个算起）的位置插入数值5，如a为1,2,3,4，插入元素后为1,5,2,3,4
//	a.insert(a.begin()+1,3,5); //在a的第1个元素（从第0个算起）的位置插入3个数，其值都为5
//	a.insert(a.begin()+1,b+3,b+6); //b为数组，在a的第1个元素（从第0个算起）的位置插入b的第3个元素到第5个元素（不包括b+6），如b为1,2,3,4,5,9,8         ，插入元素后为1,4,5,9,2,3,4,5,9,8
//	a.size(); 				//返回a中元素的个数；
	int size = a.capacity(); //返回a在内存中总共可以容纳的元素个数
	cout<<"new line 9 ---------"<<endl;
	cout<<"总个数是: "<<size<<endl;
	
	a.assign(1,1);
	size = a.capacity();
	cout<<"new line 10 ---------"<<endl;
	cout<<"总个数是: "<<size<<endl;

//	a.resize(10); //将a的现有元素个数调至10个，多则删，少则补，其值随机 (reserve :保留，储备，预留) 
	a.resize(10,2); //将a的现有元素个数调至10个，多则删，少则补，其值为2 (reserve :保留, 储备，预留) 
	cout<<"new line 11 ---------"<<endl;
	for(int i=0; i<a.size(); i++){
		cout<<a[i]<<endl;
	}
	
//	a.reserve(100); //将a的容量（capacity）扩充至100，也就是说现在测试a.capacity();的时候返回值是100.这种操作只有在需要给a添加大量数据的时候才         显得有意义，因为这将避免内存多次容量扩充操作（当a的容量不足时电脑会自动扩容，当然这必然降低性能） 
	
//	a.swap(b); //b为向量，将a中的元素和b中的元素进行整体性交换
	a.swap(c);
	cout<<"new line 12 ---------"<<endl;
	for(int i=0; i<a.size(); i++){
		cout<<a[i]<<endl;
	}

//	a==b; //b为向量，向量的比较操作还有!=,>=,<=,>,<
	
	return 0;
} 
