#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
    private:
        T data_;
        Node<T>* next_;
    public:
        Node();
        Node(T& data, Node<T>* next);
        Node(const Node<T>*& other);
        ~Node();
        T& operator=(const Node<T>*& other);
        T getData();
        void setData(T& data);
        Node<T>* getNext() const;
        void setNext(Node<T>* next);
};

#endif