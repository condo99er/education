#ifndef __TREE_H__
#define __TREE_H__

#include <memory>

template<typename T>
class MySearchTree 
{
public:
	bool insert(T value);
	bool remove(T value);
	bool contains(T value);

private:
    struct Node
    {
        static const uint8_t Left = 0;
        static const uint8_t Right = 1;
        
        Node(T value, Node* parent = nullptr);
        ~Node();
        
        T m_value;
        Node* m_children[2];
        Node* m_parent;
    };

    Node* find(T value);

private:
    std::unique_ptr<Node> m_root;
};

#endif