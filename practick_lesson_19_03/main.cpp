#include <iostream>
#include <cmath>

int f(int value)
{
    int v = value%10;
    int counter = 1;
    for(value /= 10;value; value /= 10)
    {
        if(value%10 == v)
        {
            counter++;
        }
        if(value%10 > v)
        {
            v = value%10;
            counter = 1;
        }
    }
    return counter;
}

bool is_prime(int value)
{
    if(value%2 == 0)
    {
        return false;
    }
    for(int i = 3; i < value; i+=2)
    {
        if(value%i == 0)
        {
            return false;
        }
    }
    return true;
}

void f1(int value)
{
    int end = value/2;
    for(int i = 3; i < end; ++i)
    {
        if(is_prime(i) && value%i == 0)
        {
            std::cout << i << " ";
        }
    }
    if(is_prime(value))
    {
        std::cout << value << std::endl;
    }

}

int find_min_digit(int value)
{
    int min_el = value%10;
    for(value /= 10; value; value /= 10)
    {
        if(min_el > value%10)
        {
            min_el = value%10;
        }
    }
    return min_el;
}

int find_max_digit(int value)
{
    int max_el = value%10;
    for(value /= 10; value; value /= 10)
    {
        if(max_el < value%10)
        {
            max_el = value%10;
        }
    }
    return max_el;
}

int swap_max_min_digit(int value)
{
    int temp;
    int digit = 1;
    int result = 0;
    int max = find_max_digit(value);
    int min = find_min_digit(value);
    for(; value; value /= 10)
    {
        temp = (value%10) * digit;
        if(value%10 == min)
        {
            temp = max*digit;
        }
        if(value%10 == max)
        {
            temp = min * digit;
        }
        digit *= 10;
        result += temp;
    }
    return result;
}



int main()
{
    //std::cout << f(33311) << std::endl;
    //f1(45);
    //std::cout<< find_max_digit(4531);
    //std::cout<< swap_max_min_digit(12345);
    return 0;
}
