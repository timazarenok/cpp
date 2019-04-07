#include <iostream>
#include "Binary_tree.h"


int main()
{
    Binary_tree a;
    a.insert(10);
    a.insert(25);
    a.insert(27);
    a.insert(30);
    a.insert(47);
    a.insert(666);
    a.insert(9);
    a.insert(8);
    a.insert(7);
    a.insert(4);
    auto f = a.find(a.head, 666);
    f->m_value = 35;
    /*for(auto i = a.head; i != nullptr; i = i->m_right)
    {
        std::cout << i->m_value << " ";
    }*/
    a.print_all();
    return 0;
}
