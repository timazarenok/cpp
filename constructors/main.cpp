#include <iostream>

struct Rectangle
{
    int m_a;
    int m_b;
    Rectangle(): m_a(0), m_b(0){std::cout << "Rectangle()" << std::endl;}
    Rectangle(int a, int b): m_a(a), m_b(b){std::cout << "Rectangle(a,b)" << std::endl;}
    Rectangle(const Rectangle& that): m_a(that.m_a), m_b(that.m_b){std::cout << "Rectangle(a)" << std::endl;}
    Rectangle(Rectangle&& that)
    {
        m_a = 1000;
        std::cout << "Rectangle(that)" << std::endl;
    }
    int get_square()
    {
        return m_a * m_b;
    }
    int get_peripetr()
    {
        return 2*(m_a + m_b);
    }
    friend std::ostream& operator<<(std::ostream& out, const Rectangle& r);
    Rectangle& operator=(const Rectangle& that)
    {
        m_a = that.m_a;
        m_b = that.m_b;
        return *this;
    }
};
    std::ostream& operator<<(std::ostream& out, const Rectangle& r)
    {
        return out << r.m_a << " " << r.m_b;
    }

int main()
{
    Rectangle a(3,4);
    Rectangle b(1,2);
    b = std::move(a);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    return 0;
}
