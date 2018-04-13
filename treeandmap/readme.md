---------------------------------------------
-----------       UnitTests      ------------
---------------------------------------------
[1;33mRunning test:	MapUnitTests::SingleLinkTest[0m
VERIFY_TRUE(graph.connect(5, 4))
VERIFY_FALSE(graph.connect(4, 5))
VERIFY_NOT_EQ(graph.distance(4, 4), 0)
VERIFY_EQ(graph.distance(4, 5), 1)
[1;32mPASSED	MapUnitTests::SingleLinkTest
[0m
[1;33mRunning test:	MapUnitTests::MultipleLinkTest[0m
VERIFY_TRUE(graph.connect(5, 4))
VERIFY_TRUE(graph.connect(5, 6))
VERIFY_EQ(graph.distance(4, 5), 1)
VERIFY_EQ(graph.distance(5, 6), 1)
VERIFY_EQ(graph.distance(4, 6), 2)
[1;32mPASSED	MapUnitTests::MultipleLinkTest
[0m
[1;33mRunning test:	MapUnitTests::DisconnectedTest[0m
VERIFY_TRUE(graph.connect(5, 4))
VERIFY_TRUE(graph.connect(1, 2))
VERIFY_EQ(graph.distance(1, 2), 1)
VERIFY_EQ(graph.distance(5, 4), 1)
VERIFY_EQ(graph.distance(1, 5), MyMap<int>::NOT_FOUND)
VERIFY_EQ(graph.distance(1, 4), MyMap<int>::NOT_FOUND)
VERIFY_EQ(graph.distance(2, 5), MyMap<int>::NOT_FOUND)
VERIFY_EQ(graph.distance(2, 4), MyMap<int>::NOT_FOUND)
[1;32mPASSED	MapUnitTests::DisconnectedTest
[0m
[1;33mRunning test:	MapUnitTests::TwoRouteTest[0m
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
[1;32mPASSED	MapUnitTests::TwoRouteTest
[0m
[1;33mRunning test:	MapUnitTests::SingleRemoveNodeTest[0m
VERIFY_FALSE(graph.remove(5))
VERIFY_TRUE(graph.connect(5, 4))
VERIFY_TRUE(graph.remove(5))
VERIFY_EQ(graph.distance(5, 4), MyMap<int>::NOT_FOUND)
[1;32mPASSED	MapUnitTests::SingleRemoveNodeTest
[0m
[1;33mRunning test:	MapUnitTests::RemoveNodeTest[0m
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
[1;32mPASSED	MapUnitTests::RemoveNodeTest
[0m
---------------------------------------------
-----------       UnitTests      ------------
---------------------------------------------
[1;33mRunning test:	TreeUnitTests::SingleEntryTest[0m
VERIFY_TRUE(search.insert(5))
VERIFY_FALSE(search.insert(5))
VERIFY_TRUE(search.contains(5))
VERIFY_FALSE(search.contains(1))
VERIFY_TRUE(search.remove(5))
VERIFY_FALSE(search.contains(5))
VERIFY_FALSE(search.remove(5))
[1;32mPASSED	TreeUnitTests::SingleEntryTest
[0m
[1;33mRunning test:	TreeUnitTests::MultipleEntryTest[0m
VERIFY_TRUE(search.insert(50))
VERIFY_TRUE(search.contains(50))
VERIFY_TRUE(search.insert(200))
VERIFY_TRUE(search.contains(200))
VERIFY_TRUE(search.insert(1))
VERIFY_TRUE(search.contains(1))
[1;32mPASSED	TreeUnitTests::MultipleEntryTest
[0m
[1;33mRunning test:	TreeUnitTests::DeleteRootTest[0m
VERIFY_TRUE(search.insert(50))
VERIFY_TRUE(search.insert(200))
VERIFY_TRUE(search.insert(1))
VERIFY_TRUE(search.remove(50))
VERIFY_TRUE(search.contains(200))
VERIFY_TRUE(search.contains(1))
[1;32mPASSED	TreeUnitTests::DeleteRootTest
[0m
[1;33mRunning test:	TreeUnitTests::DeleteMiddleTest[0m
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
[1;32mPASSED	TreeUnitTests::DeleteMiddleTest
[0m
---------------------------------------------
-----------        Summary       ------------
---------------------------------------------
[1;32mPASSED	MapUnitTests::SingleLinkTest[0m
[1;32mPASSED	MapUnitTests::MultipleLinkTest[0m
[1;32mPASSED	MapUnitTests::DisconnectedTest[0m
[1;32mPASSED	MapUnitTests::TwoRouteTest[0m
[1;32mPASSED	MapUnitTests::SingleRemoveNodeTest[0m
[1;32mPASSED	MapUnitTests::RemoveNodeTest[0m
[1;32mPASSED	TreeUnitTests::SingleEntryTest[0m
[1;32mPASSED	TreeUnitTests::MultipleEntryTest[0m
[1;32mPASSED	TreeUnitTests::DeleteRootTest[0m
[1;32mPASSED	TreeUnitTests::DeleteMiddleTest[0m
Test passed:	10 / 10
