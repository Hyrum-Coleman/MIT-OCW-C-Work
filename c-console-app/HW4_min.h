#pragma once
#include <iostream>
#include <vector>

template <typename T> T min_template(T val1, T val2)
{
    if (val1 == val2)
    {
        std::cout << "The values are equal to each other... " << "Returning the first input" << std::endl;
        return val1;
    }
    if (val1 < val2)
    {
        return val1;
    }
    return val2;
}


template <typename T>
class Stack {

public:
    explicit Stack() = default;
    explicit Stack(T init_val) {mStack.push_back(init_val);}
    bool is_empty() {return mStack.empty();}
    void push(const T &item) {mStack.push_back(item);}
    [[nodiscard]] T& top() {return mStack.back();}
    void pop() {(this->is_empty()) ? (void()) : (mStack.pop_back());}
    [[nodiscard]] int get_size() {return mStack.size();}  // NOLINT(clang-diagnostic-shorten-64-to-32)



    void print_stack() { for (int i = this->get_size()-1; i >= 0; --i) { std::cout << this->mStack[i] << std::endl; } }

    friend Stack operator+(Stack<T> stack1, Stack<T> stack2)
    {
        Stack<T> overload_result;

        overload_result.mStack.insert(overload_result.mStack.end(), stack1.mStack.begin(), stack1.mStack.end());
        overload_result.mStack.insert(overload_result.mStack.end(), stack2.mStack.begin(), stack2.mStack.end());

        return overload_result;
    }

private:
    std::vector<T> mStack;
};