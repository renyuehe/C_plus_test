#include <iostream>
#include <queue>
using namespace std;

int main()
{
	priority_queue<int> que;
	que.push(10);
	que.push(5);
	que.push(18);
	que.push(30);
	que.push(7);
	que.push(2);
	for(int i = 0; i < 6; i++)
	{
		cout<<que.top()<<endl;
		que.pop(); 
	}
	return 0;
} 
