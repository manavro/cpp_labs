#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H

template<typename T>
class StackInterface {
public:
    virtual void push(const T& value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual ~StackInterface() {}
};

#endif // STACK_INTERFACE_H