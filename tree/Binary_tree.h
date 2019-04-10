#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED
template<class T>
struct Binary_tree
{
    using size_type = std::size_t;
    using value_type = T;
    using reference = T&;
    using const_reference = const reference;
    struct Node
    {
        Node* m_left = nullptr;
        Node* m_right = nullptr;
        value_type m_value;
        Node() = default;
        Node(value_type value): m_value(value) {}
    };

    size_type m_size = 0;
    Node* head = nullptr;
    Binary_tree() = default;


private:
    Node* add(Node* node, T value)
    {
        if(node == nullptr)
        {
            ++m_size;
            return new Node(value);
        }
        if(value < node->m_value)
        {
            node->m_left = add(node->m_left, value);
        }
        if(value > node->m_value)
        {
            node->m_right = add(node->m_right, value);
        }
        return node;
    }

        Node* find(Node* node, T key) const
    {
        if(node == nullptr || node->m_value == key)
        {
            return node;
        }

        if(node->m_value < key)
        {
            return find(node->m_right, key);
        }
        return find(node->m_left, key);
    }

     void print(Node* node)
    {
        if(node != nullptr)
        {
            print(node->m_left);
            std::cout << node->m_value << " ";
            print(node->m_right);
        }
    }


public:
    void insert(T value)
    {
        head = add(head, value);
    }
    void print_all()
    {
        print(head);
    }

    bool contains(const_reference key) const
    {
        return find(head, key) != nullptr;
    }

    size_type size()
    {
        return m_size;
    }

};













#endif // BINARY_TREE_H_INCLUDED
