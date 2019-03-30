#include <iostream>
#include <algorithm>
#define print_container(first, last) std::for_each(first, last, [](int a){std::cout << a << " ";})

template<class Iter>
void fill_container(Iter first, Iter last)
{
    for(; first != last; ++first)
    {
        std::cin >> *first;
    }
}


int main()
{
    int arr[14]{0};
    fill_container(arr, arr + 14);
    int* temp = (arr + 5);
    std::accumulate(arr, 14, temp) / 14;
    print_container(arr, 14);
    //std::for_each(arr, arr + 14, [](int a){ if(a % 2 == 0){std::cout << a << " ";};});78
    return 0;
}
