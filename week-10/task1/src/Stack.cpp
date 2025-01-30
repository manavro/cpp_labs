#include "StackInterface.h"
#include <iostream>
#include <stdexcept>

template<typename T>
class Stack : public StackInterface<T> {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* topNode;

public:
    Stack() : topNode(nullptr) {}

    void push(const T& value) override {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    T pop() override {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        T value = topNode->data;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        return value;
    }

    T top() const override {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        return topNode->data;
    }

    bool isEmpty() const override {
        return topNode == nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};


template class Stack<int>;
template class Stack<double>;
template class Stack<std::string>;