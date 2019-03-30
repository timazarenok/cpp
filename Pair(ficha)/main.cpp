#include <iostream>
#define Function(name, ret_type, body) ret_type name(){body;}
Function(random, int, return 4);


int main()
{
    std::cout<< random();
    return 0;
}
