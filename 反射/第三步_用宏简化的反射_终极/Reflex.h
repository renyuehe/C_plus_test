

/*

����ģʽ��ϻص����ơ�

��������Ҫ����һ����������Ļ������磺
1.�����ڲ���Ҫ�и�ӳ��,Ҳ����һ���ַ�����Ӧһ����new�ķ�����
2.��������һ���ӿ�,���Ǵ����ַ���,��ô��������ַ�����Ӧ�ķ���new�����Ķ���ָ�롣
3.�����½�����,�����Ҫ֧�ַ������,��ô�������Ҫ�Զ����Լ���new����������ע�ᵽ������ӳ���С�

*/


#include <iostream>
using namespace std;

//����������� classInfo ���� �� CreatObject��GetClassInfo ����
#define DECLARE_CLASS(name) \
    protected: \
        static ClassInfo ms_classinfo; \
    public:  \
        virtual ClassInfo* GetClassInfo() const; \
        static Object* CreateObject();
 
//ʵ��CreatObject �� GetClassInfo ����������
#define IMPLEMENT_CLASS_COMMON(name,func) \
    ClassInfo name::ms_classinfo((#name), \
             (ObjectConstructorFn) func); \
                          \
    ClassInfo *name::GetClassInfo() const \
        {return &name::ms_classinfo;}
 
//classInfo ���Եĳ�ʼ��
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





