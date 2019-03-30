#ifndef REVERSE_ITERATOR_H_INCLUDED
#define REVERSE_ITERATOR_H_INCLUDED


namespace stu{
template<class Iter>
struct reverse_iter{
    Iter m_current = nullptr;
    reverse_iter() = default;
    reverse_iter(Iter current): m_current(current){}

    void operator++()
    {
        --m_current;
    }
    Iter& operator++(int)
    {
        Iter temp = m_current;
        --m_current;
        return temp;
    }
    bool operator==(const reverse_iter& that)
    {
        return this->m_current == that.m_current;
    }
    auto& operator*()
    {
        return *m_current;
    }
    operator bool()
    {
        return m_current != nullptr;
    }
    bool operator!=(const reverse_iter& that)
    {
        return !(*this == that);
    }



};







}


#endif // REVERSE_ITERATOR_H_INCLUDED
