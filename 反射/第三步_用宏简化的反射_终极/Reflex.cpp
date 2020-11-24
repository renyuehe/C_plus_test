
/*

工厂模式结合回调机制。

首先我们要梳理一下这个方法的基本脉络：
1.工厂内部需要有个映射,也就是一个字符串对应一个类new的方法。
2.工厂给出一个接口,我们传入字符串,那么返回这个字符串对应的方法new出来的对象指针。
3.我们新建的类,如果需要支持反射机制,那么这个类需要自动将自己的new方法和名字注册到工厂的映射中。

*/

/*
最好的方式还有就是用到宏来简化代码 
*/
#include <iostream>
#include <map>
#include "Reflex.h"
using namespace std;


static std::map<string, ClassInfo*> *classInfoMap = NULL;
bool Object::Register(ClassInfo* ci)
{
    if (!classInfoMap)   {
        classInfoMap = new std::map< string, ClassInfo*>();      //这里我们是通过map来存储这个映射的。
    }
    if (ci)  {
        if (classInfoMap->find(ci->m_className) == classInfoMap->end()){
            classInfoMap->insert(std::map< string, ClassInfo*>::value_type(ci->m_className, ci)); // 类名 <-> classInfo
        }
    }
    return true;
}
Object* Object::CreateObject(std::string name)
{
    std::map< string, ClassInfo*>::const_iterator iter = classInfoMap->find(name);
    if (classInfoMap->end() != iter)  {
        return iter->second->CreateObject();         //当传入字符串name后,通过name找到info,然后调用对应的CreatObject()即可
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


