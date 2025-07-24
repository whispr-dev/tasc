#pragma once
#include <stack>

class StackMachine {
public:
    std::stack<int> stk;

    void push(int value);
    int pop();

    void add();
    void sub();
    void mul();
    void div();
};
