#include <iostream>

template<class T>
struct Figure
{
    Figure(){std::cout<< "Figure";}
    virtual T get_square() = 0;
    virtual T get_perimetr() = 0;
    std::string get_name()
    {
        std::cout << "Figure";
        return std::string("Figure");
    }
    bool is_greater_by_square(Figure* a, Figure* b)
    {
        return a->get_square() > b->get_square();
    }

    template<class F1, class F2>
    bool is_greater_by_square(const F1& a, const F2& b)
    {
        return a.get_square() > b.get_square();
    }
};

template<class T>
struct Rectangle: Figure<T>
{
    T side_a;
    T side_b;
    Rectangle() = default;
    Rectangle(T a, T b): side_a(a), side_b(b){/*Figure()*/}
    std::string get_name()
    {
        return std::string("Rectangle");
    }
    T get_perimetr()
    {
        return 2*(side_a + side_b);
    }
    T get_square()
    {
        return side_a * side_b;
    }
};



int main()
{
    Rectangle<double> a(4,5);
    a.get_name();
    return 0;
}
