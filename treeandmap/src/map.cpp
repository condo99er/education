#include "map.h"
#include <queue>

template<typename T>
bool MyMap<T>::connect(T objA, T objB)
{
    if (m_nodes.count(objA) == 0)
    {
        m_nodes[objA] = std::make_shared<Node>(objA);
    }
    if (m_nodes.count(objB) == 0)
    {
        m_nodes[objB] = std::make_shared<Node>(objB);
    }

    auto itA = m_nodes[objA];
    auto itB = m_nodes[objB];
    return itA->m_neighbors.insert(itB).second & itB->m_neighbors.insert(itA).second;
}

template<typename T>
int MyMap<T>::distance(T objA, T objB)
{
    if (m_nodes.count(objA) == 0 || m_nodes.count(objB) == 0) return NOT_FOUND;

    typedef std::pair<std::shared_ptr<Node>, int> Node_Distance;
    std::queue<Node_Distance> q;
    Node_unordered_set seen;

    q.push(std::make_pair(m_nodes[objA], 0));
    seen.insert(m_nodes[objA]);

    while (!q.empty())
    {
        auto data = q.front();
        q.pop();
        for (auto& it : data.first->m_neighbors)
        {
            if (it->m_data == objB) return data.second + 1;

            if (seen.count(it) == 0)
            {
                q.push(std::make_pair(it, data.second + 1));
                seen.insert(it);
            }
        }
    }
    return NOT_FOUND;
}

template<typename T>
bool MyMap<T>::remove(T obj)
{
    if (m_nodes.count(obj) == 0) return false;

    auto node = m_nodes[obj];
    m_nodes.erase(obj);

    for (auto& it : node->m_neighbors)
    {
        it->m_neighbors.erase(node);
    }

    return true;
}

// Template Declarations
#define DECLARE(type) template class MyMap<type>;
DECLARE(int);