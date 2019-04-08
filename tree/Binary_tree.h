#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED

struct Binary_tree
{
    struct Node
    {
        Node* m_left = nullptr;
        Node* m_right = nullptr;
        int m_value;
        Node() = default;
        Node(int value): m_value(value) {}
    };

    std::size_t m_size = 0;
    Node* head = nullptr;
    Binary_tree() = default;


    Node* add(Node* node, int value)
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

    void insert(int value)
    {
        head = add(head, value);
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

    void print_all()
    {
        print(head);
    }

    Node* find(Node* node, int key) const
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


    bool contains(const int& key) const
    {
        return find(head, key) != nullptr;
    }

    std::size_t size()
    {
        return m_size;
    }

};













#endif // BINARY_TREE_H_INCLUDED
