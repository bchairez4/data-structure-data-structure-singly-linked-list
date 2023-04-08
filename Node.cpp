#include "Node.h"

/*****************************************************************************
    Constructors/ Desctuctor
*****************************************************************************/

template <class T>
Node<T>::Node() : next_(nullptr) {}

template <class T>
Node<T>::Node(const T& data, Node<T>* next) 
    : data_(data), next_(next) {} 

template <class T>
Node<T>::Node(const Node<T>*& other)
    : data_(other->data_), next_(other->next_) {} 

template <class T>
Node<T>::~Node() {
    next_ = nullptr;        //Let LinkedList Destructor handle the delete.
}

/*****************************************************************************
    Overloaded Operator(s)
*****************************************************************************/

template <class T>
T& Node<T>::operator=(const Node<T>*& other) {
    data_ = other->data_;
    next_ = other->next_;
}

/*****************************************************************************
    Data Retrieval/ Manipulation
*****************************************************************************/

template <class T>
T Node<T>::getData() const {
    return data_;
}

template <class T>
Node<T>* Node<T>::getNext() const {
    return next_;
}

template <class T>
void Node<T>::setData(const T& data) {
    data_ = data;
}

template <class T>
void Node<T>::setNext(Node<T>* next) {
    next_ = next;
}