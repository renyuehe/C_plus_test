
#include <typeinfo>
#include <iostream>   
#include <list>   
#include <numeric>   
#include <algorithm>   
#include <stdio.h>
using namespace std;   

//����һ��list������ʵ��LISTINT   
typedef list<int> LISTINT;   
//����һ��list������ʵ��LISTCHAR   
typedef list<int> LISTCHAR;   

int main() 
{   
//	int a = 10;
//	int *x = &a;
//	
//	if(sizeof(x) == 8){
//		cout<<"64λ����ϵͳ"<<endl;
//	}
//	cout << typeid(x).name() <<endl;
//	printf("sizeof(x ptr) = %d\n",sizeof(x));
//	printf("sizeof(x ) = %d\n",sizeof(*x));
//	
//    //��list����������������    
//    //��LISTINT����һ����ΪlistOne��list����   
//    list<int> listOne;   
//    //����iΪ������   
//    list<int>::iterator i;
//    cout << typeid(i).name() <<endl;
//    printf("sizeof(iterator i) = %d\n", sizeof(i));
//    printf("d i= %d \n", i);
//    printf("p i= %p \n", i);
//    printf("sizeof(iterator *i) = %d\n", sizeof(*i));
////    printf("*i= %d \n", *i); 		//��û�и� i ��ֵ֮ǰ���ǲ��ܷ��ʵģ� �Լ�ȥ��ԭ�� 
////    printf("p *i= %p \n", *i);	//��û�и� i ��ֵ֮ǰ���ǲ��ܷ��ʵģ� �Լ�ȥ��ԭ�� 
//
//    //��ǰ����listOne�������������   
//    listOne.push_front (2);   
//    listOne.push_front (1);   
//    
//	cout<<"1---------------- listOne.begin()--- listOne.end():"<<endl;   
//    for(i = listOne.begin(); i != listOne.end(); ++i)
//		cout << *i << " ";
//	cout << endl; 
//
//    //�Ӻ�����listOne�������������   
//    listOne.push_back (3);   
//    listOne.push_back (4);   
//
//    //��ǰ�����ʾlistOne�е�����   
//    cout<<"2 --------------- listOne.begin()--- listOne.end():"<<endl;   
//    for (i = listOne.begin(); i != listOne.end(); ++i)   
//        cout << *i << " ";   
//    cout << endl;   
//
//    //�Ӻ������ʾlistOne�е�����   
//    LISTINT::reverse_iterator ir;   
//    cout<<"listOne.rbegin()---listOne.rend():"<<endl;   
//    for (ir =listOne.rbegin(); ir!=listOne.rend();ir++) {   
//        cout << *ir << " ";   
//    }   
//    cout << endl;   
//
//    //ʹ��STL��accumulate(�ۼ�)�㷨   
//    int result = accumulate(listOne.begin(), listOne.end(),0);   
//    int ret = accumulate(listOne.begin(), listOne.end(),5); //���������� �൱�� + b 
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
    //��list���������ַ�������   
    //--------------------------   

    //��LISTCHAR����һ����ΪlistOne��list����   
    LISTCHAR listTwo;   
    //����iΪ������   
    LISTCHAR::iterator j;   

    //��ǰ����listTwo�������������   
    listTwo.push_front ('A');   
    listTwo.push_front ('B');   

    //�Ӻ�����listTwo�������������   
    listTwo.push_back ('x');   
    listTwo.push_back ('y');   

    //��ǰ�����ʾlistTwo�е�����   
    cout<<"listTwo.begin()---listTwo.end():"<<endl;   
    for (j = listTwo.begin(); j != listTwo.end(); ++j)   
        cout << char(*j) << " ";   
    cout << endl;   

    //ʹ��STL��max_element�㷨��listTwo�е����Ԫ�ز���ʾ, ����ֵ�ǵ�����, ����������ͨ�� char(*m) ת��Ϊ �ַ�   
    j=max_element(listTwo.begin(),listTwo.end());   
    LISTCHAR::iterator m;
    m = min_element(listTwo.begin(), listTwo.end());
    cout << "The minimun elsement in list Two is : "<<char(*m)<<endl;
    cout << "The maximum element in listTwo is: "<<char(*j)<<endl;   
    
    return 0;
}   
