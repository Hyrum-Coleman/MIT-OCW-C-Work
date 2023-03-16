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
    bool isEmpty() {return mStack.empty();}
    void push(const T &item) {mStack.push_back(item);}
    [[nodiscard]] T& top() {return mStack.back();}
    void pop() {(this->isEmpty()) ? (void()) : (mStack.pop_back());}

private:
    std::vector<T> mStack;
};