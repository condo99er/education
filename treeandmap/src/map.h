#ifndef __MAP_H__
#define __MAP_H__

#include <memory>
#include <unordered_set>
#include <unordered_map>

template<typename T>
class MyMap
{
public:
    static const int NOT_FOUND = -1;
    bool connect(T objA, T objB);

    // returns NOT_FOUND if one of the nodes doesn't exist, or no connection is found 
    int distance(T objA, T objB);

    bool remove(T obj);

private:
    struct Node;
    struct Deref
    {
        struct Hash {
            std::size_t operator() (std::shared_ptr<Node> const &p) const {
                return std::hash<T>()(p->m_data);
            }
        };
        struct Compare {
            size_t operator() (std::shared_ptr<Node> const &a,
                            std::shared_ptr<Node> const &b) const {
                return a->m_data == b->m_data;
            }
        };
    };

    typedef std::unordered_set<std::shared_ptr<Node>, typename Deref::Hash, typename Deref::Compare> Node_unordered_set;

    struct Node
    {
    	Node(T data) : m_data(data) {};
    	T m_data;
        Node_unordered_set m_neighbors;
    };

private:
    std::unordered_map<T, std::shared_ptr<Node>> m_nodes;
};

#endif