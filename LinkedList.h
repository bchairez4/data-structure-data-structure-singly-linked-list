/*****************************************************************************
*    Brian Chairez                                                           *
*    Started: 31 May 2022                                                    *
*    Completed: 27 August 2022                                               *
*    Goal: Manual implementation of std::forward_list using dynamic nodes    *
*    Progess: Basic implementation and methods complete                      *
*****************************************************************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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
        T front() const;
        Node<T>* getHead() const;
        void push_front(const T& data);
        void push_back(const T& data);
        void replace(const T& replace, const T& data);
        void pop_front();
        void pop_back();
        void remove(const T& data);
        void clear();
        bool contains(const T& data) const;
        bool empty() const;
        int size() const; 
        int count(const T& data);
};

#endif