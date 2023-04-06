/*****************************************************************************
*    Brian Chairez                                                           *
*    Goal: Manual implementation of std::List using dynamic nodes            *
*    Progess: Basic implementation and methods complete                      *
*****************************************************************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.cpp"

template<class T>
class LinkedList {
    private:
        Node<T>* head_;
        int size_;
        
        void deleteRecursive_(Node<T>*& node);
    public:
        LinkedList();
        LinkedList(Node<T>*& head);
        LinkedList(LinkedList<T>& other);
        ~LinkedList();
        T& operator=(const LinkedList<T>& other);
        Node<T>* getHead();
        void push_front(T& data);
        void push_back(T& data);
        void replace(T& replace, T& data);
        void pop_front();
        void pop_back();
        void remove(T& data);
        void clear();
        void reverse();
        bool contains(T& data);
        bool empty() const;
        int size() const; 
        int count(T& data);
        void print();
};

#endif
