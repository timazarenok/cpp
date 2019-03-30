#include <iostream>

void task1(int* arr, int size, int a, int b)
{
    arr[0] = a;
    arr[1] = b;
    for(int i = 2; i < size; +i)
    {
        arr[i] = arr[i-1] * arr[i-2];
    }
}

int min_el(int* arr, int size)
{
    int min_ = arr[0];
    for(int i = 0; i < size; ++i)
    {
        if(min_ > arr[i])
        {
            min_ = arr[i];
        }
    }
    return min_;
}

int main()
{
    int arr[10]{0};
    task1(arr, 10, 2, 3);
    std::cout << "hell" << std::endl;
}
