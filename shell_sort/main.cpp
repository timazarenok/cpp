#include <iostream>
#define print_conteiner(first, last) std::for_each(first, last, [](int value){std::cout<< value << " ";}
#include <vector>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iterator>
#include <cstddef>

template<class Iter, class BO>
void shell_sort(Iter first, Iter last, BO op)
{
    auto size = std::distance(first, last);
    for(int step = size / 2; step > 0; step /= 2)
    {
        for(Iter i = first + step; i != last; ++i)
        {
            for(Iter j = i; j > first && op(*j, *(j - step));--j)
            {
                std::iter_swap(j,j - step);
            }
        }
    }
}

int main()
{
    std::vector<int> vec(5);
    std::iota(vec.begin(), vec.end(),0);
    std::mt19937 gen{std::random_device()()};
    std::uniform_int_distribution<int> uid(0, 10000);
    std::generate(vec.begin(), vec.end(), [&uid, &gen](){return uid(gen);});
    shell_sort(vec.begin(), vec.end(), [](int value1, int value2){return value1 < value2;});
    std::for_each(vec.begin(), vec.end(), [](int a){std::cout << a << " ";});
    return 0;
}
