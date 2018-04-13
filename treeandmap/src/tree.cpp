#include "tree.h"

template<typename T>
bool MySearchTree<T>::contains(T value)
{
   return find(value);
}

template<typename T>
bool MySearchTree<T>::insert(T value)
{
    if (!m_root)
    {
        m_root.reset(new Node(value));
        return true;
    }

    Node* current = m_root.get();
    Node* parent = nullptr;
    int index = 0;
    do
    {
        // Node already exists
        if (current->m_value == value) return false;
        // Move further down the tree
        parent = current;
        index = current->m_value < value;
        current = current->m_children[index];
    } while(current);

    parent->m_children[index] = new Node(value, parent);
    return true;
}

template<typename T>
bool MySearchTree<T>::remove(T value)
{
    Node* node = find(value);
    
    // We didn't find the value in the tree
    if (!node) return false;

    // Lets reset any parents if needed
    Node* left = node->m_children[Node::Left];
    Node* right = node->m_children[Node::Right];
    Node* parent = node->m_parent;

    node->m_children[Node::Left] = nullptr;
    node->m_children[Node::Right] = nullptr;
    delete node;

    Node* primary = left;
    Node* secondary = right;
    int secondary_index = Node::Right;
    if (right)
    {
        primary = right;
        secondary = left;
        secondary_index = Node::Left;
    }

    if (parent)
    {
        int index = parent->m_children[Node::Right]->m_value == value;
        parent->m_children[index] = primary;
    }
    else
    {
        m_root.release();
        m_root.reset(primary);
    }

    // insert all other children
    if (secondary)
    {
        Node* curr_parent = parent;
        Node* current = primary;
        do
        {
            curr_parent = current;
            current = current->m_children[secondary_index];
        } while (current);
        curr_parent->m_children[secondary_index] = secondary;
    }
    return true;
}

/////////////////////////////////////////////////
//             Private methods                 //
/////////////////////////////////////////////////
template<typename T>
typename MySearchTree<T>::Node* MySearchTree<T>::find(T value)
{
    Node* current = m_root.get();
    while (current && current->m_value != value)
    {        
        // Move further down the tree
        current = current->m_children[current->m_value < value];
    }
    return current;
}

template<typename T>
MySearchTree<T>::Node::Node(T value, Node* parent) : m_value(value), m_parent(parent) 
{
    m_children[Right] = nullptr;
    m_children[Left] = nullptr;
}

template<typename T>
MySearchTree<T>::Node::~Node()
{
    delete m_children[Right];
    delete m_children[Left];
}

// Template Declarations
#define DECLARE(type) template class MySearchTree<type>;
DECLARE(int);
