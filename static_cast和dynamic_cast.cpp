 #include <iostream>
 using namespace std;
 
 class QDomNode{
 	
 };
 class QDomElement : public QDomNode{
 	
 };
 
 //���ۣ�����dynamic��dynamic�����ܲ���static 
 int main(){
 	QDomNode *nd;
    QDomElement *element;
    //test
    nd = dynamic_cast<QDomNode*>(element); //dynamic ָ�� ���� ת ���� 

    //test 
//    element = dynamic_cast<QDomNode*>(nd);

    //test
    nd = static_cast<QDomNode*>(element); //static ָ�� ���� ת ���� 

    //test
//    element = static_cast<QDomNode*>(nd);

    QDomNode nd1;
    QDomElement element1;
    //test
//    nd1 = dynamic_cast<QDomNode>(element1);

    //test
//    element1 = dynamic_cast<QDomNode*>(nd1);

    //test
    nd1 = static_cast<QDomNode>(element1); //static ���� ���� ת ���� 

    //test
//    element1 = static_cast<QDomNode>(nd1);
 }
 

