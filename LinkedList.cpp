#include "LinkedList.h"

/*****************************************************************************
    Constructors/ Destructor
*****************************************************************************/

template <class T>
LinkedList<T>::LinkedList() : head_(nullptr), size_(0) {}

template <class T>
LinkedList<T>::LinkedList(Node<T>*& head) : head_(nullptr), size_(0) {
    if (head == nullptr) {
        return;
    }
    
    Node<T>* curr_node = head;
    T data = curr_node->getData();

    Node<T>* new_first_node = new Node<T>(data, nullptr);

    head_ = new_first_node;
    ++size_;

    curr_node = curr_node->getNext();
    Node<T>* temp_node = head_;
    while (curr_node != nullptr) {
        data = curr_node->getData();
        Node<T>* new_node = new Node<T>(data, nullptr);

        temp_node->setNext(new_node);
        ++size_;

        temp_node = temp_node->getNext();
        curr_node = curr_node->getNext();
    }
}

template <class T>
LinkedList<T>::LinkedList(LinkedList<T>& other) : head_(nullptr), size_(0) {
    LinkedList<T> temp(other.head_);
    head_ = temp.getHead();
    size_ = temp.size();
}

template<class T>
LinkedList<T>::~LinkedList() {
    clear();
}

/*****************************************************************************
    Overloaded Operator(s)
*****************************************************************************/
template <class T>
T& LinkedList<T>::operator=(const LinkedList<T>& other) {
    LinkedList<T> temp(other.head_);
    head_ = temp.getHead();
    size_ = temp.size();
}

/*****************************************************************************
    List Operations
*****************************************************************************/
template <class T>
void LinkedList<T>::push_front(T& data) {
    if (empty()) {
        Node<T>* new_node = new Node<T>(data, nullptr);

        head_ = new_node;
        ++size_;

        return;
    }

    Node<T>* curr_node = head_;
    Node<T>* new_node = new Node<T>(data, curr_node);

    head_ = new_node;
    ++size_;
}

template <class T>
void LinkedList<T>::push_back(T& data) {
    if (empty()) {
        Node<T>* new_node = new Node<T>(data, nullptr);
        
        head_ = new_node;
        ++size_;
        
        return;
    }

    Node<T>* curr_node = head_;
    while (curr_node->getNext() != nullptr) {
        curr_node = curr_node->getNext();
    }

    Node<T>* new_node = new Node<T>(data, nullptr);

    curr_node->setNext(new_node);
    ++size_;
}

template <class T>
void LinkedList<T>::replace(T& replace, T& data) {
    if (!contains(replace)) {
        std::cout << replace << " does not exist in the list. Failure to replace()" << '\n';
        return;
    }

    Node<T>* curr_node = head_;
    while (curr_node->getData() != replace) {
        curr_node = curr_node->getNext();
    }

    curr_node->setData(data);
}

template <class T>
void LinkedList<T>::pop_front() {
    if (empty()) {
        std::cout << "The list is empty. Failure to pop_front()" << '\n';
        return;
    }

    Node<T>* curr_node = head_;
    if (curr_node->getNext() != nullptr) {
        head_ = curr_node->getNext();
        
        delete curr_node;
        --size_;

        return;
    }

    head_ = nullptr;
    delete curr_node;
    --size_;
}

template <class T>
void LinkedList<T>::pop_back() {
    if (empty()) {
        std::cout << "The list is empty. Failure to pop_back()" << '\n';
        return;
    }

    Node<T>* curr_node = head_;
    if (curr_node->getNext() != nullptr) {
        while (curr_node->getNext()->getNext() != nullptr) {
            curr_node = curr_node->getNext();
        }

        Node<T>* temp_node = curr_node->getNext();
        curr_node->setNext(nullptr);
        
        delete temp_node;
        --size_;
        
        return;
    }

    head_ = nullptr;
    delete curr_node;
    --size_;
}

template <class T>
void LinkedList<T>::remove(T& data) {
    if (!contains(data)) {
        std::cout<< data << " does not exist in this list. Failure to perform remove()" << '\n';
        return;
    }
    
    // CASE 1: Its the only node that exists
    if (size() == 1) {
        delete head_;
        head_ = nullptr;
        --size_;
        return;
    }
    
    Node<T>* curr_node = head_;
    Node<T>* temp_node = head_;
    
    // CASE 2: Its the First Node
    if (head_->getData() == data) {
        curr_node = curr_node->getNext();
        head_ = curr_node;
        delete temp_node;
        --size_;
        return;
    }

    // Travel to second to last node in list unless data is not found somewhere in middle
    while (temp_node->getNext()->getData() != data && curr_node->getNext()->getNext() != nullptr) {
        temp_node = temp_node->getNext();
        curr_node = curr_node->getNext();
    }
    
    // CASE 3: Its a Middle Node or the Last node
    temp_node = curr_node->getNext();
    Node<T>* right_side = temp_node->getNext();
    curr_node->setNext(right_side);
    delete temp_node;
    --size_;
}

template <class T>
void LinkedList<T>::clear() {
    deleteRecursive_(head_);
    head_ = nullptr;
}

template <class T>
void LinkedList<T>::reverse() {
    // TO DO 
}

/*****************************************************************************
    Data Retrieval/ Observation
*****************************************************************************/
template <class T>
Node<T>* LinkedList<T>::getHead() {
    return head_;
}

template <class T>
bool LinkedList<T>::contains(T& data) {
    if (empty()) {
        std::cout << "The list is empty." << '\n';
        return false;
    }

    Node<T>* curr_node = head_;
    while (curr_node->getData() != data && curr_node->getNext() != nullptr) {
        curr_node = curr_node->getNext();
    }

    if (curr_node->getData() == data) {
        return true;
    }

    return false;
}

template <class T>
bool LinkedList<T>::empty() const {
    return size_ == 0;
}

template <class T>
int LinkedList<T>::size() const {
    return size_;
}

template <class T>
int LinkedList<T>::count(T& data) {
    if (empty()) {
        std::cout << "The list is empty. Failed to perform count()" << '\n';
        return 0;
    }

    int count = 0;
    Node<T>* curr_node = head_;
    while (curr_node != nullptr) {
        if (curr_node->getData() == data) {
            ++count;
        }
        
        curr_node = curr_node->getNext();
    }

    return count; 
}

template <class T>
void LinkedList<T>::print() {
    if (empty()) {
        std::cout << "Failed to execute print. The List is empty" << '\n';
        return;
    }

    Node<T>* curr_node = head_;
    while (curr_node != nullptr) {
        std::cout << curr_node->getData() << " -> ";
        curr_node = curr_node->getNext();
    } 
    std::cout << "nullptr" << '\n';
}

/*****************************************************************************
    Private Functions
*****************************************************************************/
template <class T>
void LinkedList<T>::deleteRecursive_(Node<T>*& node) {
    if (node == nullptr) {
        return;
    }

    node = node->getNext();
    deleteRecursive_(node);
    
    delete node;
    --size_;
}