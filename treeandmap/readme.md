---------------------------------------------
-----------       UnitTests      ------------
---------------------------------------------
Running test:   MapUnitTests::SingleLinkTest
VERIFY_TRUE(graph.connect(5, 4))
VERIFY_FALSE(graph.connect(4, 5))
VERIFY_NOT_EQ(graph.distance(4, 4), 0)
VERIFY_EQ(graph.distance(4, 5), 1)
PASSED  MapUnitTests::SingleLinkTest

Running test:   MapUnitTests::MultipleLinkTest
VERIFY_TRUE(graph.connect(5, 4))
VERIFY_TRUE(graph.connect(5, 6))
VERIFY_EQ(graph.distance(4, 5), 1)
VERIFY_EQ(graph.distance(5, 6), 1)
VERIFY_EQ(graph.distance(4, 6), 2)
PASSED  MapUnitTests::MultipleLinkTest

Running test:   MapUnitTests::DisconnectedTest
VERIFY_TRUE(graph.connect(5, 4))
VERIFY_TRUE(graph.connect(1, 2))
VERIFY_EQ(graph.distance(1, 2), 1)
VERIFY_EQ(graph.distance(5, 4), 1)
VERIFY_EQ(graph.distance(1, 5), MyMap<int>::NOT_FOUND)
VERIFY_EQ(graph.distance(1, 4), MyMap<int>::NOT_FOUND)
VERIFY_EQ(graph.distance(2, 5), MyMap<int>::NOT_FOUND)
VERIFY_EQ(graph.distance(2, 4), MyMap<int>::NOT_FOUND)
PASSED  MapUnitTests::DisconnectedTest

Running test:   MapUnitTests::TwoRouteTest
VERIFY_TRUE(graph.connect(5, 4))
VERIFY_TRUE(graph.connect(1, 2))
VERIFY_TRUE(graph.connect(1, 3))
VERIFY_EQ(graph.distance(2, 4), MyMap<int>::NOT_FOUND)
VERIFY_TRUE(graph.connect(3, 4))
VERIFY_EQ(graph.distance(2, 4), 3)
VERIFY_TRUE(graph.connect(2, 5))
VERIFY_EQ(graph.distance(2, 4), 2)
VERIFY_TRUE(graph.connect(2, 4))
VERIFY_EQ(graph.distance(2, 4), 1)
PASSED  MapUnitTests::TwoRouteTest

Running test:   MapUnitTests::SingleRemoveNodeTest
VERIFY_FALSE(graph.remove(5))
VERIFY_TRUE(graph.connect(5, 4))
VERIFY_TRUE(graph.remove(5))
VERIFY_EQ(graph.distance(5, 4), MyMap<int>::NOT_FOUND)
PASSED  MapUnitTests::SingleRemoveNodeTest

Running test:   MapUnitTests::RemoveNodeTest
VERIFY_TRUE(graph.connect(5, 4))
VERIFY_TRUE(graph.connect(1, 2))
VERIFY_TRUE(graph.connect(1, 3))
VERIFY_EQ(graph.distance(2, 4), MyMap<int>::NOT_FOUND)
VERIFY_TRUE(graph.connect(3, 4))
VERIFY_EQ(graph.distance(2, 4), 3)
VERIFY_TRUE(graph.connect(2, 5))
VERIFY_EQ(graph.distance(2, 4), 2)
VERIFY_TRUE(graph.remove(5))
VERIFY_EQ(graph.distance(2, 4), 3)
PASSED  MapUnitTests::RemoveNodeTest

---------------------------------------------
-----------       UnitTests      ------------
---------------------------------------------
Running test:   TreeUnitTests::SingleEntryTest
VERIFY_TRUE(search.insert(5))
VERIFY_FALSE(search.insert(5))
VERIFY_TRUE(search.contains(5))
VERIFY_FALSE(search.contains(1))
VERIFY_TRUE(search.remove(5))
VERIFY_FALSE(search.contains(5))
VERIFY_FALSE(search.remove(5))
PASSED  TreeUnitTests::SingleEntryTest

Running test:   TreeUnitTests::MultipleEntryTest
VERIFY_TRUE(search.insert(50))
VERIFY_TRUE(search.contains(50))
VERIFY_TRUE(search.insert(200))
VERIFY_TRUE(search.contains(200))
VERIFY_TRUE(search.insert(1))
VERIFY_TRUE(search.contains(1))
PASSED  TreeUnitTests::MultipleEntryTest

Running test:   TreeUnitTests::DeleteRootTest
VERIFY_TRUE(search.insert(50))
VERIFY_TRUE(search.insert(200))
VERIFY_TRUE(search.insert(1))
VERIFY_TRUE(search.remove(50))
VERIFY_TRUE(search.contains(200))
VERIFY_TRUE(search.contains(1))
PASSED  TreeUnitTests::DeleteRootTest

Running test:   TreeUnitTests::DeleteMiddleTest
VERIFY_TRUE(search.insert(200))
VERIFY_TRUE(search.insert(50))
VERIFY_TRUE(search.insert(1))
VERIFY_TRUE(search.insert(51))
VERIFY_TRUE(search.insert(12))
VERIFY_TRUE(search.insert(5))
VERIFY_TRUE(search.insert(17))
VERIFY_TRUE(search.insert(15))
VERIFY_TRUE(search.insert(4))
VERIFY_TRUE(search.remove(12))
VERIFY_FALSE(search.contains(12))
VERIFY_TRUE(search.contains(200))
VERIFY_TRUE(search.contains(50))
VERIFY_TRUE(search.contains(1))
VERIFY_TRUE(search.contains(51))
VERIFY_TRUE(search.contains(5))
VERIFY_TRUE(search.contains(17))
VERIFY_TRUE(search.contains(15))
VERIFY_TRUE(search.contains(4))
VERIFY_TRUE(search.remove(200))
VERIFY_FALSE(search.contains(200))
VERIFY_TRUE(search.contains(50))
VERIFY_TRUE(search.contains(1))
VERIFY_TRUE(search.contains(51))
VERIFY_TRUE(search.contains(5))
VERIFY_TRUE(search.contains(17))
VERIFY_TRUE(search.contains(15))
VERIFY_TRUE(search.contains(4))
PASSED  TreeUnitTests::DeleteMiddleTest

---------------------------------------------
-----------        Summary       ------------
---------------------------------------------
PASSED  MapUnitTests::SingleLinkTest
PASSED  MapUnitTests::MultipleLinkTest
PASSED  MapUnitTests::DisconnectedTest
PASSED  MapUnitTests::TwoRouteTest
PASSED  MapUnitTests::SingleRemoveNodeTest
PASSED  MapUnitTests::RemoveNodeTest
PASSED  TreeUnitTests::SingleEntryTest
PASSED  TreeUnitTests::MultipleEntryTest
PASSED  TreeUnitTests::DeleteRootTest
PASSED  TreeUnitTests::DeleteMiddleTest
Test passed:    10 / 10
