#include <iostream>
#include <typeinfo>

namespace stu
{
template<class T, T v>
struct integer_type
{
    static constexpr T value = v;

    using value_type = T;
    using type = integer_type<T, v>;

    constexpr operator value_type()
    {
        return value;
    }
    constexpr value_type operator()()
    {
        return value;
    };
};

using true_type = integer_type<bool, true>;
using false_type = integer_type<bool, false>;

template<class>
struct is_array:false_type {};

template<class T>
struct is_array<T[]>:true_type {};

template<class T, std::size_t size>
struct is_array<T[size]>:true_type {};

template<class T>
class remove_const
{
    using type = T;
};

template<class T>
struct remove_const<T const>
{
    using type = T;
};

}

int main()
{
    using t = stu::remove_const<const int>::type;
    t a;
    std::cout << typeid(stu::is_array<int>).name();
    return 0;
}
