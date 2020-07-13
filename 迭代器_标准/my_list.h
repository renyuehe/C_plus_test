//
// Created by wengle on 2020-03-14.
//

#ifndef CPP_PRIMER_MY_LIST_H
#define CPP_PRIMER_MY_LIST_H

#include <iostream>

template<typename T>
class node {
public:
    T value;
    node *next;
    node() : next(nullptr) {}
    node(T val, node *p = nullptr) : value(val), next(p) {}
};

template<typename T>
class my_list {
private:
    node<T> *head;
    node<T> *tail;
    int size;

//���ﶨ�� private ȴ��ֱ�����ⲿ���ʵ�ԭ�������� �� public ��Ȩ�޶�����:  typedef list_iterator iterator; //���ͱ���  
private:
    class list_iterator {
    private:
        node<T> *ptr; //ָ��list�����е�ĳ��Ԫ�ص�ָ��

    public:
        list_iterator(node<T> *p = nullptr) : ptr(p) {}
        
        //����++��--��*��->�Ȼ�������
        //�������ã�����ͨ��*it���޸Ķ���
        T &operator*() const {
            return ptr->value;
        }

        node<T> *operator->() const {
            return ptr;
        }

		//ǰ��++�� ���ص������� 
        list_iterator &operator++() {
            ptr = ptr->next;
            return *this;
        }

		//??????,  ���ص���һ�����󣨿������죩���������������ʲô��˼��int ��ɶ�ã����������ε����� 
        list_iterator operator++(int) {
            node<T> *tmp = ptr;
            // this ��ָ��list_iterator�ĳ���ָ�룬���*this����list_iterator����ǰ��++�Ѿ������ع�
            ++(*this);
            return list_iterator(tmp);
        }

		//ͨ����������������� ptr ���ж� 
        bool operator==(const list_iterator &t) const {
            return t.ptr == this->ptr;
        }

		//ͨ����������������� ptr ���ж� 
        bool operator!=(const list_iterator &t) const {
            return t.ptr != this->ptr;
        }
    };

public:
	//typedef list_iterator iterator; ԭ���ǣ�list_iterator ��˽�еĲ���ֱ�ӷ��ʣ�����ͨ�� iterator ��ӷ��� 
    typedef list_iterator iterator; //���ͱ���
    my_list() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    //������β������Ԫ��
    void push_back(const T &value) {
        if (head == nullptr) {
            head = new node<T>(value);
            tail = head;
        } else {
            tail->next = new node<T>(value);
            tail = tail->next;
        }
        size++;
    }

    //��ӡ����Ԫ��
    //ostream ����ֻ������� 
    void print(std::ostream &os = std::cout) const {
        for (node<T> *ptr = head; ptr != tail->next; ptr = ptr->next)
            os << ptr->value << std::endl;
    }
    //�����������һ��������������������Ϊ����ķ���Ч��Ҫ�ߵ㣿���� 
//    void print() const {
//    	for (node<T> *ptr = head; ptr == tail->next; ptr = ptr->next){
//    		std::cout << ptr->value << std::endl;
//		}
//	}

public:
    //�����������ķ���
    //��������ͷ��ָ��
    iterator begin() const {
        return list_iterator(head);
    }

    //��������β��ָ��
    iterator end() const {
        return list_iterator(tail->next);
    }

    //������Ա���� insert/erase/emplace
};

#endif //CPP_PRIMER_MY_LIST_H
