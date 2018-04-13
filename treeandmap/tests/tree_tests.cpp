#include "tests.h"
#include "tree.h"

Test_Registrar<TreeUnitTests> TreeUnitTests::registrar;

bool TreeUnitTests::SingleEntryTest()
{
    MySearchTree<int> search;
    VERIFY_TRUE(search.insert(5));
    VERIFY_FALSE(search.insert(5));
    VERIFY_TRUE(search.contains(5));
    VERIFY_FALSE(search.contains(1));
    VERIFY_TRUE(search.remove(5));
    VERIFY_FALSE(search.contains(5));
    VERIFY_FALSE(search.remove(5));
    return true;
}

bool TreeUnitTests::MultipleEntryTest()
{
    MySearchTree<int> search;
    VERIFY_TRUE(search.insert(50));
    VERIFY_TRUE(search.contains(50));
    VERIFY_TRUE(search.insert(200));
    VERIFY_TRUE(search.contains(200));
    VERIFY_TRUE(search.insert(1));
    VERIFY_TRUE(search.contains(1));
    return true;
}

bool TreeUnitTests::DeleteRootTest()
{
    MySearchTree<int> search;
    VERIFY_TRUE(search.insert(50));
    VERIFY_TRUE(search.insert(200));
    VERIFY_TRUE(search.insert(1));

    VERIFY_TRUE(search.remove(50));
    VERIFY_TRUE(search.contains(200));
    VERIFY_TRUE(search.contains(1));
    return true;
}

bool TreeUnitTests::DeleteMiddleTest()
{
    MySearchTree<int> search;
    VERIFY_TRUE(search.insert(200));
    VERIFY_TRUE(search.insert(50));
    VERIFY_TRUE(search.insert(1));
    VERIFY_TRUE(search.insert(51));
    VERIFY_TRUE(search.insert(12));
    VERIFY_TRUE(search.insert(5));
    VERIFY_TRUE(search.insert(17));
    VERIFY_TRUE(search.insert(15));
    VERIFY_TRUE(search.insert(4));

    // Remove random node in the middle
    VERIFY_TRUE(search.remove(12));
    VERIFY_FALSE(search.contains(12));
    VERIFY_TRUE(search.contains(200));
    VERIFY_TRUE(search.contains(50));
    VERIFY_TRUE(search.contains(1));
    VERIFY_TRUE(search.contains(51));
    VERIFY_TRUE(search.contains(5));
    VERIFY_TRUE(search.contains(17));
    VERIFY_TRUE(search.contains(15));
    VERIFY_TRUE(search.contains(4));


    // Remove root node
    VERIFY_TRUE(search.remove(200));
    VERIFY_FALSE(search.contains(200));
    VERIFY_TRUE(search.contains(50));
    VERIFY_TRUE(search.contains(1));
    VERIFY_TRUE(search.contains(51));
    VERIFY_TRUE(search.contains(5));
    VERIFY_TRUE(search.contains(17));
    VERIFY_TRUE(search.contains(15));
    VERIFY_TRUE(search.contains(4));
    return true;
}