
#include <typeinfo>
#include <iostream>   
#include <list>   
#include <numeric>   
#include <algorithm>   
#include <stdio.h>
using namespace std;   

//创建一个list容器的实例LISTINT   
typedef list<int> LISTINT;   
//创建一个list容器的实例LISTCHAR   
typedef list<int> LISTCHAR;   

int main() 
{   
//	int a = 10;
//	int *x = &a;
//	
//	if(sizeof(x) == 8){
//		cout<<"64位操作系统"<<endl;
//	}
//	cout << typeid(x).name() <<endl;
//	printf("sizeof(x ptr) = %d\n",sizeof(x));
//	printf("sizeof(x ) = %d\n",sizeof(*x));
//	
//    //用list容器处理整型数据    
//    //用LISTINT创建一个名为listOne的list对象   
//    list<int> listOne;   
//    //声明i为迭代器   
//    list<int>::iterator i;
//    cout << typeid(i).name() <<endl;
//    printf("sizeof(iterator i) = %d\n", sizeof(i));
//    printf("d i= %d \n", i);
//    printf("p i= %p \n", i);
//    printf("sizeof(iterator *i) = %d\n", sizeof(*i));
////    printf("*i= %d \n", *i); 		//在没有给 i 赋值之前，是不能访问的？ 自己去看原理 
////    printf("p *i= %p \n", *i);	//在没有给 i 赋值之前，是不能访问的？ 自己去看原理 
//
//    //从前面向listOne容器中添加数据   
//    listOne.push_front (2);   
//    listOne.push_front (1);   
//    
//	cout<<"1---------------- listOne.begin()--- listOne.end():"<<endl;   
//    for(i = listOne.begin(); i != listOne.end(); ++i)
//		cout << *i << " ";
//	cout << endl; 
//
//    //从后面向listOne容器中添加数据   
//    listOne.push_back (3);   
//    listOne.push_back (4);   
//
//    //从前向后显示listOne中的数据   
//    cout<<"2 --------------- listOne.begin()--- listOne.end():"<<endl;   
//    for (i = listOne.begin(); i != listOne.end(); ++i)   
//        cout << *i << " ";   
//    cout << endl;   
//
//    //从后向后显示listOne中的数据   
//    LISTINT::reverse_iterator ir;   
//    cout<<"listOne.rbegin()---listOne.rend():"<<endl;   
//    for (ir =listOne.rbegin(); ir!=listOne.rend();ir++) {   
//        cout << *ir << " ";   
//    }   
//    cout << endl;   
//
//    //使用STL的accumulate(累加)算法   
//    int result = accumulate(listOne.begin(), listOne.end(),0);   
//    int ret = accumulate(listOne.begin(), listOne.end(),5); //第三个参数 相当于 + b 
//    cout<<"result ="<<result<<endl;   
//    cout<<"------------------"<<endl;   
//    cout<<"ret = "<<ret<<endl;
//    cout<<"------------------"<<endl;
//    
//	cout<<"3 --------------- listOne.begin()--- listOne.end():"<<endl;   
//    for (i = listOne.begin(); i != listOne.end(); ++i)   
//        cout << *i << " ";   
//    cout << endl;   


    //--------------------------   
    //用list容器处理字符型数据   
    //--------------------------   

    //用LISTCHAR创建一个名为listOne的list对象   
    LISTCHAR listTwo;   
    //声明i为迭代器   
    LISTCHAR::iterator j;   

    //从前面向listTwo容器中添加数据   
    listTwo.push_front ('A');   
    listTwo.push_front ('B');   

    //从后面向listTwo容器中添加数据   
    listTwo.push_back ('x');   
    listTwo.push_back ('y');   

    //从前向后显示listTwo中的数据   
    cout<<"listTwo.begin()---listTwo.end():"<<endl;   
    for (j = listTwo.begin(); j != listTwo.end(); ++j)   
        cout << char(*j) << " ";   
    cout << endl;   

    //使用STL的max_element算法求listTwo中的最大元素并显示, 返回值是迭代器, 迭代器可以通过 char(*m) 转换为 字符   
    j=max_element(listTwo.begin(),listTwo.end());   
    LISTCHAR::iterator m;
    m = min_element(listTwo.begin(), listTwo.end());
    cout << "The minimun elsement in list Two is : "<<char(*m)<<endl;
    cout << "The maximum element in listTwo is: "<<char(*j)<<endl;   
    
    return 0;
}   
