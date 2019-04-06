#include <iostream>
#include "Tamogochi.h"
#include "Food.h"

int main()
{
    Animal a;
    int control = 0;
    while(!a.is_life())
    {
        switch(control)
        {
        case 0:
            a.feed();
            break;
        }
    }
    return 0;
}
