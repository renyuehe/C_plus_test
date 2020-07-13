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

//这里定义 private 却能直接在外部访问的原因是下面 用 public 的权限定义了:  typedef list_iterator iterator; //类型别名  
private:
    class list_iterator {
    private:
        node<T> *ptr; //指向list容器中的某个元素的指针

    public:
        list_iterator(node<T> *p = nullptr) : ptr(p) {}
        
        //重载++、--、*、->等基本操作
        //返回引用，方便通过*it来修改对象
        T &operator*() const {
            return ptr->value;
        }

        node<T> *operator->() const {
            return ptr;
        }

		//前置++， 返回的是引用 
        list_iterator &operator++() {
            ptr = ptr->next;
            return *this;
        }

		//??????,  返回的是一个对象（拷贝构造），天哪这个到底是什么意思，int 有啥用，运算符是如何调用呢 
        list_iterator operator++(int) {
            node<T> *tmp = ptr;
            // this 是指向list_iterator的常量指针，因此*this就是list_iterator对象，前置++已经被重载过
            ++(*this);
            return list_iterator(tmp);
        }

		//通过迭代器对象的主题 ptr 来判断 
        bool operator==(const list_iterator &t) const {
            return t.ptr == this->ptr;
        }

		//通过迭代器对象的主题 ptr 来判断 
        bool operator!=(const list_iterator &t) const {
            return t.ptr != this->ptr;
        }
    };

public:
	//typedef list_iterator iterator; 原因是，list_iterator 是私有的不能直接访问，可以通过 iterator 间接访问 
    typedef list_iterator iterator; //类型别名
    my_list() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    //从链表尾部插入元素
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

    //打印链表元素
    //ostream 就是只管输出流 
    void print(std::ostream &os = std::cout) const {
        for (node<T> *ptr = head; ptr != tail->next; ptr = ptr->next)
            os << ptr->value << std::endl;
    }
    //下面这个方法一样可以做到，可能是因为上面的方法效率要高点？？？ 
//    void print() const {
//    	for (node<T> *ptr = head; ptr == tail->next; ptr = ptr->next){
//    		std::cout << ptr->value << std::endl;
//		}
//	}

public:
    //操作迭代器的方法
    //返回链表头部指针
    iterator begin() const {
        return list_iterator(head);
    }

    //返回链表尾部指针
    iterator end() const {
        return list_iterator(tail->next);
    }

    //其它成员函数 insert/erase/emplace
};

#endif //CPP_PRIMER_MY_LIST_H
