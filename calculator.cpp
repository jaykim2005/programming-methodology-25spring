#include "calculator.h"
#include <stdexcept>
#include <limits>
int max = std::numeric_limits<int>::max();
int min = std::numeric_limits<int>::min();

int Calculator::add(int a, int b) {
    // TODO
    
    if((b>max-a && a>0 )|| (a>max-b&&b>0)) throw std::overflow_error("Addition overflow");
    if((a<min-b && b<0)||( b<min-a && a<0)) throw std::overflow_error("Addition underflow");
    return a+b;
}

int Calculator::sub(int a, int b) {
    // TODO
    if(-b>max-a) throw std::overflow_error("Subtraction overflow");
    if(a<min+b) throw std::overflow_error("Subtraction underflow");
    return a-b;
}

int Calculator::mul(int a, int b) {
    // TODO
    if(a>max/b && b>0 || b>max/a && a>0) throw std::overflow_error("Multiplication overflow");
    if(a<min/b && b>0|| b<min/a && a>0) throw std::overflow_error("Multiplication underflow");
    return a*b;
}

int Calculator::div(int a, int b) {
    // TODO
    if(b==0) throw std::invalid_argument("Division by zero");
    if(1/b>max/a) throw std::overflow_error("Division overflow");
    if(1/b<min/a || 1/b<min/a) throw std::overflow_error("Division underflow");
    return a/b;
}