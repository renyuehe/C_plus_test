#include <assert.h>
#include <iostream>
using namespace std;

int main(){ 
    
    const char *str = "nihao";
    assert(str != NULL);//������ֹ 
    assert(str == NULL);//����ֹ 
    
    return 0;   
}
