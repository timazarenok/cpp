#include <iostream>
#include "auto_ptr.h"

struct Test
{
    int var;
    Test(int var_ = 0): var(var_){std::cout << "Test(int)" << std::endl;}
    Test(const Test& that): var(that.var){std::cout << "COPY INITIALIZATION" << std::endl;}
};


int main()
{
    stu::auto_ptr<Test> a(new Test(10));
    std::cout << a->var << std::endl;
    return 0;
}
