#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
    private:
        T data_;
        Node<T>* next_;
    public:
        Node();
        Node(const T& data, Node<T>* next);
        Node(const Node<T>*& other);
        ~Node();
        T& operator=(const Node<T>*& other);
        T getData() const;
        Node<T>* getNext() const;
        void setData(const T& data);
        void setNext(Node<T>* next);
};

#endif