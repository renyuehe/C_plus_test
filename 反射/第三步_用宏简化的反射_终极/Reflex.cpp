
/*

����ģʽ��ϻص����ơ�

��������Ҫ����һ����������Ļ������磺
1.�����ڲ���Ҫ�и�ӳ��,Ҳ����һ���ַ�����Ӧһ����new�ķ�����
2.��������һ���ӿ�,���Ǵ����ַ���,��ô��������ַ�����Ӧ�ķ���new�����Ķ���ָ�롣
3.�����½�����,�����Ҫ֧�ַ������,��ô�������Ҫ�Զ����Լ���new����������ע�ᵽ������ӳ���С�

*/

/*
��õķ�ʽ���о����õ������򻯴��� 
*/
#include <iostream>
#include <map>
#include "Reflex.h"
using namespace std;


static std::map<string, ClassInfo*> *classInfoMap = NULL;
bool Object::Register(ClassInfo* ci)
{
    if (!classInfoMap)   {
        classInfoMap = new std::map< string, ClassInfo*>();      //����������ͨ��map���洢���ӳ��ġ�
    }
    if (ci)  {
        if (classInfoMap->find(ci->m_className) == classInfoMap->end()){
            classInfoMap->insert(std::map< string, ClassInfo*>::value_type(ci->m_className, ci)); // ���� <-> classInfo
        }
    }
    return true;
}
Object* Object::CreateObject(std::string name)
{
    std::map< string, ClassInfo*>::const_iterator iter = classInfoMap->find(name);
    if (classInfoMap->end() != iter)  {
        return iter->second->CreateObject();         //�������ַ���name��,ͨ��name�ҵ�info,Ȼ����ö�Ӧ��CreatObject()����
    }
    return NULL;
}


int main() {

	
    Object* obj = Object::CreateObject("B");
//    delete obj;

    obj = Object::CreateObject("A");
    delete obj;
    
    obj = Object::CreateObject("C");
    delete obj;
    
    
	return 0;
}


