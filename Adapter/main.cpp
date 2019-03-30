#include <iostream>

template<class T, class Container = std::vector<T>>
struct Stack{
    Container container;
    Container() = default;
    T& top()
    {
        return container.back();
    }
    bool empty()
    {
        return container.empty();
    }

};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
