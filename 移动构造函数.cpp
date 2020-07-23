#include <iostream>
using namespace std; 

class Person
{
public:
    const char*  name_;
    Person(const char* name):name_(name) {};

    Person(const Person& person)
    {
        name_ = person.name_;
        std::cout << "�������캯��" << std::endl;
    }

    Person(const Person&& person)
    {
        name_ = person.name_;
        std::cout << "�ƶ����캯��"<< std::endl;
    }

    Person& operator=(const Person& person)
    {

        name_ = person.name_;
        std::cout << "������ֵ�����" << std::endl;
        return *this;
    }

    Person& operator=(Person&& person)
    {
        if (this != &person) {
            name_ = person.name_;
            std::cout << "�ƶ���ֵ�����" << std::endl;
        }
        return *this;
    }
};

Person getPerson()
{
    Person person("person in func");
    return person;
}

int main(void)
{
    Person person1("xiaohong");
    Person person2("xiaoming");
    Person person3(getPerson());//�ƶ����캯��
    Person person4(std::move(person1));//�ƶ����캯��
    Person person5(person2);//�������캯��

    Person person6("xiaolan");
    person6 = std::move(person3);//�ƶ���ֵ����
    Person person7("xiaoqi");
    person7 = Person("xiaoqi");//�ƶ���ֵ����
    Person person8("xiaoba");
    person8 = person1;//������ֵ�����
    system("pause");
    return 0;
}
