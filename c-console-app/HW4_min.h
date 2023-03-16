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
    explicit Stack(T initVal) {mStack.push_back(initVal);}
    bool isEmpty() {return mStack.empty();}
    void push(const T &item) {mStack.push_back(item);}
    [[nodiscard]] T& top() {return mStack.back();}
    void pop() {(this->isEmpty()) ? (void()) : (mStack.pop_back());}
    [[nodiscard]] int getSize() {return mStack.size();}


    void printStack() {for(int i = this->getSize(); i > 0, i--;){std::cout << this->mStack[i] << std::endl;}}

    friend Stack operator+(Stack<T> stack1, Stack<T> stack2)
    {
        Stack<T> overloadResult;

        overloadResult.mStack.insert(overloadResult.mStack.end(), stack1.mStack.begin(), stack1.mStack.end());
        overloadResult.mStack.insert(overloadResult.mStack.end(), stack2.mStack.begin(), stack2.mStack.end());

        return overloadResult;
    }

private:
    std::vector<T> mStack;
};