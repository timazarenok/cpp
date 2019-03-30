#include <iostream>

bool Binary_search(int* arr, int left, int right, int key)
{
    int middle;
    while(left <= right)
    {
        middle = (left + right)/2;
        if(key < arr[middle])
        {
            right = middle - 1;
        }
        if(key > arr[middle])
        {
            left = middle + 1;
        }
        if(key == arr[middle])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
