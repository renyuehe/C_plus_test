

/*

工厂模式结合回调机制。

首先我们要梳理一下这个方法的基本脉络：
1.工厂内部需要有个映射,也就是一个字符串对应一个类new的方法。
2.工厂给出一个接口,我们传入字符串,那么返回这个字符串对应的方法new出来的对象指针。
3.我们新建的类,如果需要支持反射机制,那么这个类需要自动将自己的new方法和名字注册到工厂的映射中。

*/


#include <iostream>
using namespace std;

//类申明中添加 classInfo 属性 和 CreatObject、GetClassInfo 方法
#define DECLARE_CLASS(name) \
    protected: \
        static ClassInfo ms_classinfo; \
    public:  \
        virtual ClassInfo* GetClassInfo() const; \
        static Object* CreateObject();
 
//实现CreatObject 和 GetClassInfo 的两个方法
#define IMPLEMENT_CLASS_COMMON(name,func) \
    ClassInfo name::ms_classinfo((#name), \
             (ObjectConstructorFn) func); \
                          \
    ClassInfo *name::GetClassInfo() const \
        {return &name::ms_classinfo;}
 
//classInfo 属性的初始化
#define IMPLEMENT_CLASS(name)            \
    IMPLEMENT_CLASS_COMMON(name,name::CreateObject) \
    Object* name::CreateObject()                   \
        { return new name;}


class ClassInfo;
class Object;

typedef Object* (*ObjectConstructorFn)(void);

//
class Object
{
public:
    Object(){}
    virtual ~Object(){}
    static bool Register(ClassInfo* ci);          //注册传入一个classInfo(类信息),将这个类的信息注册到映射中
    static Object* CreateObject(string name);     //工厂生产对象的接口
};

//
class ClassInfo
{
public:
    ClassInfo(const std::string className, ObjectConstructorFn ctor)
        :m_className(className), m_objectConstructor(ctor)
    {
        Object::Register(this);             //classInfo的构造函数是传入类名和类对应的new函数然后自动注册进map中。
    }
    virtual ~ClassInfo(){}
    Object* CreateObject()const { return m_objectConstructor ? (*m_objectConstructor)() : 0; }
    bool IsDynamic()const { return NULL != m_objectConstructor; }
    const std::string GetClassName()const { return m_className; }
    ObjectConstructorFn GetConstructor()const{ return m_objectConstructor; }
public:
    string m_className;
    ObjectConstructorFn m_objectConstructor;
};

/////////

// 
class A : public Object
{
    DECLARE_CLASS(A)
public:
    A(){ cout << hex << (long long)this << " A constructor!" << endl; }
    ~A(){ cout << hex << (long long)this << " A destructor!" << endl; }
};
IMPLEMENT_CLASS(A)


// 
class B : public Object
{
    DECLARE_CLASS(B)
public:
    B(){ cout << hex << (long long)this << " B constructor!" << endl; }
    ~B(){ cout << hex << (long long)this << " B destructor!" << endl; }
};
IMPLEMENT_CLASS(B)

//
class C : public Object
{
    DECLARE_CLASS(C)
public:
    C(){ cout << hex << (long long)this << " C constructor!" << endl; }
    ~C(){ cout << hex << (long long)this << " C destructor!" << endl; }
};
IMPLEMENT_CLASS(C)





