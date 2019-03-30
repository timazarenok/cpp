#include <iostream>

template<class T>
struct Singletone
{
    using value_type = T;
    using pointer = value_type*;
    using reference = value_type&;
    using const_reference = const reference;
    const pointer container = nullptr;
    Singletone() = default;
    Singletone(const_reference v): cont(new value_type(v)){}
    pointer get_instance()
    {
        return container;
    }
};




int main()
{
    Singletone<Myclass> a;
    Myclass* b = a;
    return 0;
}
