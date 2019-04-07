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

    Node* head = nullptr;
    Binary_tree() = default;

    Node* add(Node* node, int value)
    {
        if(node == nullptr)
        {
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

    Node* find(Node* node, int value)
    {
        if(node == nullptr || node->m_value == value)
        {
            return node;
        }

        if(node->m_value < value)
        {
            return find(node->m_right, value);
        }
        return find(node->m_left, value);
    }



};













#endif // BINARY_TREE_H_INCLUDED
