/*

for(auto a:b)中b为一个容器，效果是利用a遍历并获得b容器中的每一个值，但是a无法影响到b容器中的元素。

for(auto &a:b)中加了引用符号，可以对容器中的内容进行赋值，即可通过对a赋值来做到容器b的内容填充。

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
