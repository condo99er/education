#include "tests.h"
#include "map.h"

Test_Registrar<MapUnitTests> MapUnitTests::registrar;

bool MapUnitTests::SingleLinkTest()
{
    MyMap<int> graph;
    VERIFY_TRUE(graph.connect(5, 4));
    VERIFY_FALSE(graph.connect(4, 5));
    VERIFY_NOT_EQ(graph.distance(4, 4), 0);
    VERIFY_EQ(graph.distance(4, 5), 1);
    return true;
}

bool MapUnitTests::MultipleLinkTest()
{
    MyMap<int> graph;
    VERIFY_TRUE(graph.connect(5, 4));
    VERIFY_TRUE(graph.connect(5, 6));
    VERIFY_EQ(graph.distance(4, 5), 1);
    VERIFY_EQ(graph.distance(5, 6), 1);
    VERIFY_EQ(graph.distance(4, 6), 2);
    return true;
}

bool MapUnitTests::DisconnectedTest()
{
    MyMap<int> graph;
    VERIFY_TRUE(graph.connect(5, 4));
    VERIFY_TRUE(graph.connect(1, 2));
    VERIFY_EQ(graph.distance(1, 2), 1);
    VERIFY_EQ(graph.distance(5, 4), 1);
    VERIFY_EQ(graph.distance(1, 5), MyMap<int>::NOT_FOUND);
    VERIFY_EQ(graph.distance(1, 4), MyMap<int>::NOT_FOUND);
    VERIFY_EQ(graph.distance(2, 5), MyMap<int>::NOT_FOUND);
    VERIFY_EQ(graph.distance(2, 4), MyMap<int>::NOT_FOUND);
    return true;
}

bool MapUnitTests::TwoRouteTest()
{
    MyMap<int> graph;
    VERIFY_TRUE(graph.connect(5, 4));
    VERIFY_TRUE(graph.connect(1, 2));
    VERIFY_TRUE(graph.connect(1, 3));
    VERIFY_EQ(graph.distance(2, 4), MyMap<int>::NOT_FOUND);
    VERIFY_TRUE(graph.connect(3, 4));
    VERIFY_EQ(graph.distance(2, 4), 3);
    VERIFY_TRUE(graph.connect(2, 5));
    VERIFY_EQ(graph.distance(2, 4), 2);
    VERIFY_TRUE(graph.connect(2, 4));
    VERIFY_EQ(graph.distance(2, 4), 1);
    return true;
}

bool MapUnitTests::SingleRemoveNodeTest()
{
    MyMap<int> graph;
    VERIFY_FALSE(graph.remove(5));
    VERIFY_TRUE(graph.connect(5, 4));
    VERIFY_TRUE(graph.remove(5));
    VERIFY_EQ(graph.distance(5, 4), MyMap<int>::NOT_FOUND);
    return true;
}

bool MapUnitTests::RemoveNodeTest()
{
    MyMap<int> graph;
    VERIFY_TRUE(graph.connect(5, 4));
    VERIFY_TRUE(graph.connect(1, 2));
    VERIFY_TRUE(graph.connect(1, 3));
    VERIFY_EQ(graph.distance(2, 4), MyMap<int>::NOT_FOUND);
    VERIFY_TRUE(graph.connect(3, 4));
    VERIFY_EQ(graph.distance(2, 4), 3);
    VERIFY_TRUE(graph.connect(2, 5));
    VERIFY_EQ(graph.distance(2, 4), 2);
    VERIFY_TRUE(graph.remove(5));
    VERIFY_EQ(graph.distance(2, 4), 3);    
    return true;
}