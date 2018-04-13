#ifndef __TESTS_H__
#define __TESTS_H__

#include <test_helpers.h>

class TreeUnitTests final : public UnitTests
{
protected:
    void RunTests() final
    {
        ADD_TEST(TreeUnitTests::SingleEntryTest);
        ADD_TEST(TreeUnitTests::MultipleEntryTest);
        ADD_TEST(TreeUnitTests::DeleteRootTest);
        ADD_TEST(TreeUnitTests::DeleteMiddleTest);
    }

private:
    static bool SingleEntryTest();
    static bool MultipleEntryTest();
    static bool DeleteMiddleTest();
    static bool DeleteRootTest();

    static Test_Registrar<TreeUnitTests> registrar;
};

class MapUnitTests final : public UnitTests
{   
protected:
    void RunTests() final
    {
        ADD_TEST(MapUnitTests::SingleLinkTest);
        ADD_TEST(MapUnitTests::MultipleLinkTest);
        ADD_TEST(MapUnitTests::DisconnectedTest);
        ADD_TEST(MapUnitTests::TwoRouteTest);
        ADD_TEST(MapUnitTests::SingleRemoveNodeTest);
        ADD_TEST(MapUnitTests::RemoveNodeTest);
    }

private:
    static bool SingleLinkTest();
    static bool MultipleLinkTest();
    static bool DisconnectedTest();
    static bool TwoRouteTest();
    static bool SingleRemoveNodeTest();
    static bool RemoveNodeTest();
    
    static Test_Registrar<MapUnitTests> registrar;
};

#endif
