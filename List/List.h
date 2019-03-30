#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED



namespace stu
{
template<class T>
struct forward_list
{
private:
    struct Node
    {
        Node* next = nullptr;
        T m_value;
        Node() = default;
        Node(const T& value): m_value(value) {}
    };

    struct m_iterator
    {
        Node* m_current = nullptr;
        m_iterator() = default;
        m_iterator(Node* current): m_current(current){}

        operator bool()
        {
            return m_current != nullptr;
        }

        auto operator++()
        {
            m_current = m_current->next;
            return *m_current;
        }

        auto& operator*()
        {
            return m_current->m_value;
        }

        bool operator==(const m_iterator& that)
        {
            return this->m_current == that.m_current;
        }

        bool operator!=(const m_iterator& that)
        {
            return this->m_current != that.m_current;
        }



    };


public:
    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = T&;
    using const_reference = const reference;
    using iterator = m_iterator;

    Node* head = nullptr;
    size_type m_size = 0;

    void push_back(const_reference value)
    {
        Node* current = find_last();
        current->m_value = value;
        current->next = new Node(value);
        ++m_size;
    }

    void push_back(T&& value)
    {
        Node* temp = find_last();
        temp->next = new Node(value);
        ++m_size;
    }

    iterator erase_after(iterator pos)
    {
        iterator i = pos;
        iterator for_del = ++i;
        iterator after_del = ++i;
        pos.m_current->next = after_del.m_current;
        delete for_del.m_current;
        --m_size;
        return after_del;
    }


    iterator begin()
    {
        return iterator(head);
    }

    iterator end()
    {
        return iterator(find_last());
    }



    Node* find(iterator key)
    {
        for(auto i = begin(); i != end(); ++i)
        {
            if(i == key)
            {
                return i;
            }
        }
        return end();
    }

    iterator insert_after(const iterator pos, value_type value)
    {
        Node* temp = pos.m_current->next;
        pos.m_current->next = new Node(value);
        pos.m_current->next->next = temp;
    }



    void push_front(value_type value)
    {
        Node* temp = head;
        head = new Node(value);
        head->next = temp;
    }

    void pop_front()
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void swap(forward_list& other)
    {
        std::iter_swap(this->head, other.head);
    }


    forward_list():head(new Node()) {}
    forward_list(std::initializer_list<value_type> l):forward_list()
    {
        for(typename std::initializer_list<value_type>::iterator i = l.begin(); i != l.end(); ++i)
        {
            push_back(const_cast<const_reference> (*i));
        }
    }
private:
    Node* find_last()
    {
        Node* i = head;
        for(; i->next != nullptr; i = i->next);
        return i;
    }



public:

    //capacity
    size_type size() const noexcept
    {
        return m_size;
    }

    size_type max_size() const noexcept
    {
        size_type temp = 0;
        return temp - 1;
    }
    bool empty() const noexcept
    {
        return head->next == nullptr;
    }

};
}









#endif // LIST_H_INCLUDED
