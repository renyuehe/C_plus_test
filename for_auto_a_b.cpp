/*

for(auto a:b)��bΪһ��������Ч��������a���������b�����е�ÿһ��ֵ������a�޷�Ӱ�쵽b�����е�Ԫ�ء�

for(auto &a:b)�м������÷��ţ����Զ������е����ݽ��и�ֵ������ͨ����a��ֵ����������b��������䡣

*/
using namespace std;

#include <iostream>
#include <vector>

int main(){
	vector<int> v(10);
	
	int i = 0;
	for(auto a:v)
	{
		cout << i++ << endl;
	}
	
	int j = 10;
	for(auto &b:v)
	{
		b = j++;
//		cout << b << endl;
//		cout << v[j-11];
		cout << v.at(j-11);
	}
	return 0;
}
