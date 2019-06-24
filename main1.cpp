#include <string>
#include <stack>
#include <cassert>
#include <cstring>
#include <stdexcept>
#include <iostream>

template <class T>
class Stack
{
    std::stack<T> mainStack;
    int capacity;
public:
    Stack (int capacity) : mainStack{}, capacity{capacity}{}

    int getMaxCapacity()
    {
        return capacity;
    }

    Stack operator+(const T& object)
    {
        if(mainStack.size() == capacity)
        {
            throw std::runtime_error{"Stack is full!"};
        }
        mainStack.push(object);
        return *this;
    }

    T pop()
    {
        T value = mainStack.top();
        mainStack.pop();
        return value;
    }

};

void testStack()
{
    Stack<std::string> s{ 2 };
    assert(s.getMaxCapacity() == 2);
    try {
        s = s + "examination";
        s = s + "oop";
        s = s + "test";
    }
    catch (std::exception& e) {
        assert(strcmp(e.what(), "Stack is full!") == 0);
    }
    assert(s.pop() == "oop");
    assert(s.pop() == "examination");
}

int main()
{
    testStack();
    std::cout << "Tests passed!" << std::endl;
    return 0;
}