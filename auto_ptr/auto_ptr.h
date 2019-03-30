#ifndef AUTO_PTR_H_INCLUDED
#define AUTO_PTR_H_INCLUDED

namespace stu{



    template<class T>
class auto_ptr
{
public:

    using element_type = T;

//private:
        using pointer = element_type*;
public:


    pointer m_ptr;
    auto_ptr(pointer p = nullptr): m_ptr(p){}
    auto_ptr(const auto_ptr& that): m_ptr(that.realese()){}

    pointer realese()
    {
        pointer temp = m_ptr;
        m_ptr = nullptr;
        return temp;
    }

    void reset(pointer p = nullptr)
    {
       if(p != m_ptr)
       {
           delete m_ptr;
           m_ptr = p;
       }
    }

    pointer get()
    {
        return *m_ptr;
    }

    auto_ptr& operator=(auto_ptr& that)
    {
        reset(that.realese());
        return *this;
    }

    element_type& operator*()
    {
        return *m_ptr;
    }

    pointer operator->()
    {
        return m_ptr;
    }

    ~auto_ptr(){delete m_ptr;}
};
}


#endif // AUTO_PTR_H_INCLUDED
