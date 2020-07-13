//
// Created by wengle on 2020-03-14.
//

#include <string>
#include "my_list.h"

struct student {
    std::string name;
    int age;

    student(std::string n, int a) : name(n), age(a) {}

    //�������������
    friend std::ostream &operator<<(std::ostream &os, const student &stu) {
        os << stu.name << " " << stu.age;
        return os;
    }
    
};

int main() {
    my_list<student> l;
    l.push_back(student("bob", 1)); //��ʱ����Ϊʵ�δ��ݸ�push_back����
    l.push_back(student("allen", 2));
    l.push_back(student("anna", 3));
    l.print();

    for (my_list<student>::iterator it = l.begin(); it != l.end(); it++) {
        std::cout << *it << std::endl;
        *it = student("wengle", 18);
    }
//    std::ostream os;

    l.print();

    return 0;
}
