#include <iostream>
#include <algorithm>
#include <utility>

void insertion_sort(int* arr, int size)
{
      for (int i = 1; i < size; ++i)
        {
            for(int j = i; j > 0 && arr[j - 1] > arr[j]; --j)
            {
                  std::swap(arr[j], arr[j - 1]);
            }
      }
}

int main()
{
    int arr[10]{98, 53, 23, 76, 427, 76, 346, 79, 23, 876};
    insertion_sort(arr, 10);
    std::for_each(arr, arr+10, [](int v){std::cout << v << std::endl;});
    return 0;
}
