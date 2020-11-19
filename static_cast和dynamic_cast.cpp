 #include <iostream>
 using namespace std;
 
 class QDomNode{
 	
 };
 class QDomElement : public QDomNode{
 	
 };
 
 //结论：能用dynamic用dynamic，不能采用static 
 int main(){
 	QDomNode *nd;
    QDomElement *element;
    //test
    nd = dynamic_cast<QDomNode*>(element); //dynamic 指针 派生 转 基类 

    //test 
//    element = dynamic_cast<QDomNode*>(nd);

    //test
    nd = static_cast<QDomNode*>(element); //static 指针 派生 转 基类 

    //test
//    element = static_cast<QDomNode*>(nd);

    QDomNode nd1;
    QDomElement element1;
    //test
//    nd1 = dynamic_cast<QDomNode>(element1);

    //test
//    element1 = dynamic_cast<QDomNode*>(nd1);

    //test
    nd1 = static_cast<QDomNode>(element1); //static 对象 派生 转 基类 

    //test
//    element1 = static_cast<QDomNode>(nd1);
 }
 

