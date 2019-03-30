#include <iostream>



int main()
{
    int a = 5;
    int b;
    b = std::move(a);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    return 0;
}
