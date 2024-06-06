//
// Created by xzz on 2024/6/6.
//

#ifndef TEST_LINKLIST_H
#define TEST_LINKLIST_H

#include<bits/stdc++.h>
namespace linear{
    template<typename T>
    struct node{

        T data;
        struct node *next;
        struct node *prev;
        node(T val): data(val), next(nullptr), prev(nullptr){};

    };

    template<typename T>
    class Linklist{
    public:

        /** RAII 构造函数申请资源头结点 **/
        Linklist(){
            std::cout << "construct ........." << std::endl;
            head = new node<T>(-1);
            std::cout << "linklist head address = " << head << std::endl;
        }

        /** RAII 当对象到达作用域尾部时，析构对象回收系统资源 **/
        ~Linklist(){

            std::cout << "deconstruct .........." << std::endl;
            node<T> *p = nullptr;
            while (head){
                p = head;
                head = head->next;
                std::cout << "delete p = " << p << std::endl;
                delete p;
            }

        }

        /** 获取头结点 **/
        node<T>* get() const{
            return head;
        }

        /** 头插法加入节点 **/
        void addNode2Head(T val){
            auto n = new node<T>(val);
            n->next = head->next;
            head->next = n;
            len++;
        }


    private:
        int len;
        node<T> *head;
    };

    template<typename T>
    class stack{
    public:
        stack(){

            std::cout << "construct stack ........" << std::endl;
            stk = new node<T>(-1);
            std::cout << "stack address = " << stk << std::endl;

        }

        ~stack(){
            std::cout << " ~stack ......... " << std::endl;
            node<T> *p = nullptr;

            while(stk){

                p = stk;
                stk = stk->prev;
                std::cout << "delete p = " << p << std::endl;
                delete p;

            }

        }

        void push(T val){

            node<T> *p = new node<T>(val);
            stk->next = p;
            p->prev = stk;
            stk = p;
            len++;

        };

        void pop(){
            node<T> *p = stk;
            stk = stk->prev;
            std::cout << "stack pop address = " << p << std::endl;
            delete p;
            len--;
        }

        T top(){
            return stk->data;
        }

        int size(){
            return len;
        }
    private:

        node<T> *stk;
        int len;

    };
}


#endif //TEST_LINKLIST_H
