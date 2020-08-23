#include <iostream>
using namespace std; 


/*
#define DECLARE_WAIT_QUEUE_HEAD(name) \
	wait_queue_head_t name = __WAIT_QUEUE_HEAD_INITIALIZER(name)
*/

#define DECLARE_WAIT_QUEUE_HEAD(name) \
	int name  = 10;
	
	
	
int main(){
	DECLARE_WAIT_QUEUE_HEAD(name)
	
	cout<<name<<endl;
	
	return 0;
}
