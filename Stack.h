#ifndef STACK_H
#define STACK_H

#include <iostream>

template<typename T> class Stack;

template<typename T>
class Node{
    friend class Stack<T>;
    T m_value;
    Node *m_next = nullptr;

public:
    Node() = default;
    Node(const Node &other) = delete;
    Node& operator = (const Node &rhs) = delete;

    Node(const T &val) :m_value(val) {}
    Node(T &&val) :m_value(std::move(val)) {}
    const T& value() const {return m_value;}
    Node* next() {return m_next;}
};

template<typename T>
class Stack{
    Node<T> *m_top = nullptr;
    uint32_t m_size = 0;

public:
    Stack() = default;
    Stack(const Stack&) = delete;
    Stack& operator = (const Stack&) = delete;

    ~Stack();
    void clear();
    void push(const T &val);
    void push(T&& val);
    void pop();
    bool empty()const {
        return m_top == nullptr;
    }
    const T& top() {
        return m_top->m_value;
    }
    uint32_t size() const { return m_size; }
};

template<typename T>
Stack<T>::~Stack() {
    clear();
}

template<typename T>
void Stack<T>::push(const T &val) {
    Node<T> *node = new Node<T>(val);
    node->m_next = m_top;
    m_top = node;
    ++m_size;
}

template<typename T>
void Stack<T>::push(T &&val) {
    Node<T> *node = new Node<T>(std::move(val));
    node->m_next = m_top;
    m_top = node;
    ++m_size;
}

template<typename T>
void Stack<T>::clear() {
    Node<T> *p = nullptr;
    while (m_top != nullptr) {
        p = m_top;
        m_top = m_top->m_next;
        delete p;
    }
    m_size = 0;
}

template<typename T>
void Stack<T>::pop() {
    Node<T> *p = m_top;
    m_top = m_top->m_next;
    delete p;
    --m_size;
}

#endif // STACK_H
