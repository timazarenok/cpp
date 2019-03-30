#include <iostream>

class Base
{
    public:
    int b_var_1;
    int b_var_2;
    private:
        int b_var_3;
        public:
    Base(): b_var_1(0),
            b_var_2(0),
            b_var_3(0){}
    Base(double x): Base(){}
    int& get_set_var_3()
    {
        return b_var_3;
    }
};

class Derived:public Base
    {
    public:
    int d_var_1;
    int d_var_2;
    int d_var_3;
    Derived(): d_var_1(0),
               d_var_2(0),
               d_var_3(0){}
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
