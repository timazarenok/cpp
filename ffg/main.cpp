#include <iostream>

using namespace std;

int main()
{
    int i, j = 7;
    int *q = &j;
    i = *q;
    i = *q + 3 + j++;
    cout << i << endl;
    return 0;
}
