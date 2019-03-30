#include <iostream>
#include "reverse_iterator.h"


struct Fill{
    int m_value;
    Fill() = default;
    Fill(int value): m_value(value){}
    int operator()()
    {
        m_value += 2;
        return m_value;
    }
};


template<class Iter, class Generate>
void generate(Iter first, Iter last, Generate g)
{
    for(; first != last; ++first)
    {
        *first = g();
    }
}


int main()
{
    Fill a(4);
    a();
    std::cout << a.m_value << std::endl;
    return 0;
}
