#include <iostream>
#include <cmath>
#define Int int

using namespace std;
void f(Int*arr,Int size,Int A,Int D)
{
    for(Int i=0;i<size;++i)
    {
        arr[i] = A * (pow(D,i));
    }
}

Int main()
{
    Int n = 10;
    Int arr[n]{0};
    f(arr,10,5,6);
    for(Int i=0;i<n;++i)
        cout<<arr[i]<<endl;
    return 0;
}
