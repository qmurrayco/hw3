#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : public std::vector<T>
{
public:
    Stack() : std::vector<T>() {};
    ~Stack() {};
    
    bool empty() const{
        return std::vector<T>::empty();
    }

    size_t size() const{
        return std::vector<T>::size();
    }

    void push(const T& item){
        std::vector<T>::push_back(item);
    }

    // throws std::underflow_error if empty
    void pop() {
        if(empty()){
            throw(std::underflow_error(""));
        }else{
            std::vector<T>::pop_back();
        }
    }

    // throws std::underflow_error if empty
    const T& top() const{
        if(empty()){
            throw(std::underflow_error(""));
        }else{
            std::vector<T>::back();
        }
    }

    // Add other members only if necessary
};


#endif