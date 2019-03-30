#include <iostream>
#include <cstddef>
#include <initializer_list>
#include <algorithm>
#include "List.h"



int main()
{
    stu::forward_list<int> a{1, 12, 3, 4};
    a.erase_after(a.begin());
    for(auto i = a.begin(); i != a.end(); ++i)
    {
        std::cout << *i << " ";
    }
    return 0;
}
