

/*

����ģʽ��ϻص����ơ�

��������Ҫ����һ����������Ļ������磺
1.�����ڲ���Ҫ�и�ӳ��,Ҳ����һ���ַ�����Ӧһ����new�ķ�����
2.��������һ���ӿ�,���Ǵ����ַ���,��ô��������ַ�����Ӧ�ķ���new�����Ķ���ָ�롣
3.�����½�����,�����Ҫ֧�ַ������,��ô�������Ҫ�Զ����Լ���new����������ע�ᵽ������ӳ���С�

*/
#include <iostream>
using namespace std;


class ClassInfo;
class Object;

typedef Object* (*ObjectConstructorFn)(void);

//
class Object
{
public:
    Object(){}
    virtual ~Object(){}
    static bool Register(ClassInfo* ci);          //ע�ᴫ��һ��classInfo(����Ϣ),����������Ϣע�ᵽӳ����
    static Object* CreateObject(string name);     //������������Ľӿ�
};

//
class ClassInfo
{
public:
    ClassInfo(const std::string className, ObjectConstructorFn ctor)
        :m_className(className), m_objectConstructor(ctor)
    {
        Object::Register(this);             //classInfo�Ĺ��캯���Ǵ������������Ӧ��new����Ȼ���Զ�ע���map�С�
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
public:
    A(){ cout << hex << (long long)this << " A constructor!" << endl; }
    ~A(){ cout << hex << (long long)this << " A destructor!" << endl; }
    virtual ClassInfo* GetClassInfo() const{ return &ms_classinfo; }
    static Object* CreateObject() { return new A; }
protected:
    static ClassInfo ms_classinfo;
};
ClassInfo A::ms_classinfo("A", A::CreateObject);

//
class B : public Object
{
public:
    B(){ cout << hex << (long long)this << " B constructor!" << endl; }
    ~B(){ cout << hex << (long long)this << " B destructor!" << endl; }
    virtual ClassInfo* GetClassInfo() const{ return &ms_classinfo; }
    static Object* CreateObject() { return new B; }
protected:
    static ClassInfo ms_classinfo;
};
ClassInfo B::ms_classinfo("B", B::CreateObject);

//
class C : public Object
{
public:
    C(){ cout << hex << (long long)this << " C constructor!" << endl; }
    ~C(){ cout << hex << (long long)this << " C destructor!" << endl; }
    virtual ClassInfo* GetClassInfo() const{ return &ms_classinfo; }
    static Object* CreateObject() { return new C; }
protected:
    static ClassInfo ms_classinfo;
};
ClassInfo C::ms_classinfo("C", C::CreateObject);






