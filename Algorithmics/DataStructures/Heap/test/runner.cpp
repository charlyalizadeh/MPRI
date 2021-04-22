/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_BinaryHeapTest_init = false;
#include "test.hpp"

static BinaryHeapTest suite_BinaryHeapTest;

static CxxTest::List Tests_BinaryHeapTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_BinaryHeapTest( "test.hpp", 5, "BinaryHeapTest", suite_BinaryHeapTest, Tests_BinaryHeapTest );

static class TestDescription_suite_BinaryHeapTest_test_constructors : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BinaryHeapTest_test_constructors() : CxxTest::RealTestDescription( Tests_BinaryHeapTest, suiteDescription_BinaryHeapTest, 7, "test_constructors" ) {}
 void runTest() { suite_BinaryHeapTest.test_constructors(); }
} testDescription_suite_BinaryHeapTest_test_constructors;

static class TestDescription_suite_BinaryHeapTest_test_merge : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BinaryHeapTest_test_merge() : CxxTest::RealTestDescription( Tests_BinaryHeapTest, suiteDescription_BinaryHeapTest, 12, "test_merge" ) {}
 void runTest() { suite_BinaryHeapTest.test_merge(); }
} testDescription_suite_BinaryHeapTest_test_merge;

static class TestDescription_suite_BinaryHeapTest_test_meld : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BinaryHeapTest_test_meld() : CxxTest::RealTestDescription( Tests_BinaryHeapTest, suiteDescription_BinaryHeapTest, 21, "test_meld" ) {}
 void runTest() { suite_BinaryHeapTest.test_meld(); }
} testDescription_suite_BinaryHeapTest_test_meld;

static class TestDescription_suite_BinaryHeapTest_test_peek : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BinaryHeapTest_test_peek() : CxxTest::RealTestDescription( Tests_BinaryHeapTest, suiteDescription_BinaryHeapTest, 29, "test_peek" ) {}
 void runTest() { suite_BinaryHeapTest.test_peek(); }
} testDescription_suite_BinaryHeapTest_test_peek;

static class TestDescription_suite_BinaryHeapTest_test_pop : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BinaryHeapTest_test_pop() : CxxTest::RealTestDescription( Tests_BinaryHeapTest, suiteDescription_BinaryHeapTest, 34, "test_pop" ) {}
 void runTest() { suite_BinaryHeapTest.test_pop(); }
} testDescription_suite_BinaryHeapTest_test_pop;

static class TestDescription_suite_BinaryHeapTest_test_delete_node : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BinaryHeapTest_test_delete_node() : CxxTest::RealTestDescription( Tests_BinaryHeapTest, suiteDescription_BinaryHeapTest, 40, "test_delete_node" ) {}
 void runTest() { suite_BinaryHeapTest.test_delete_node(); }
} testDescription_suite_BinaryHeapTest_test_delete_node;

static class TestDescription_suite_BinaryHeapTest_test_replace : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BinaryHeapTest_test_replace() : CxxTest::RealTestDescription( Tests_BinaryHeapTest, suiteDescription_BinaryHeapTest, 46, "test_replace" ) {}
 void runTest() { suite_BinaryHeapTest.test_replace(); }
} testDescription_suite_BinaryHeapTest_test_replace;

static class TestDescription_suite_BinaryHeapTest_test_size : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BinaryHeapTest_test_size() : CxxTest::RealTestDescription( Tests_BinaryHeapTest, suiteDescription_BinaryHeapTest, 52, "test_size" ) {}
 void runTest() { suite_BinaryHeapTest.test_size(); }
} testDescription_suite_BinaryHeapTest_test_size;

static class TestDescription_suite_BinaryHeapTest_test_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BinaryHeapTest_test_empty() : CxxTest::RealTestDescription( Tests_BinaryHeapTest, suiteDescription_BinaryHeapTest, 57, "test_empty" ) {}
 void runTest() { suite_BinaryHeapTest.test_empty(); }
} testDescription_suite_BinaryHeapTest_test_empty;

static class TestDescription_suite_BinaryHeapTest_test_left_child : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BinaryHeapTest_test_left_child() : CxxTest::RealTestDescription( Tests_BinaryHeapTest, suiteDescription_BinaryHeapTest, 64, "test_left_child" ) {}
 void runTest() { suite_BinaryHeapTest.test_left_child(); }
} testDescription_suite_BinaryHeapTest_test_left_child;

static class TestDescription_suite_BinaryHeapTest_test_right_child : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BinaryHeapTest_test_right_child() : CxxTest::RealTestDescription( Tests_BinaryHeapTest, suiteDescription_BinaryHeapTest, 70, "test_right_child" ) {}
 void runTest() { suite_BinaryHeapTest.test_right_child(); }
} testDescription_suite_BinaryHeapTest_test_right_child;

static class TestDescription_suite_BinaryHeapTest_test_parent : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BinaryHeapTest_test_parent() : CxxTest::RealTestDescription( Tests_BinaryHeapTest, suiteDescription_BinaryHeapTest, 75, "test_parent" ) {}
 void runTest() { suite_BinaryHeapTest.test_parent(); }
} testDescription_suite_BinaryHeapTest_test_parent;

static class TestDescription_suite_BinaryHeapTest_test_get_height : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BinaryHeapTest_test_get_height() : CxxTest::RealTestDescription( Tests_BinaryHeapTest, suiteDescription_BinaryHeapTest, 82, "test_get_height" ) {}
 void runTest() { suite_BinaryHeapTest.test_get_height(); }
} testDescription_suite_BinaryHeapTest_test_get_height;

static class TestDescription_suite_BinaryHeapTest_test_has_left_child : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BinaryHeapTest_test_has_left_child() : CxxTest::RealTestDescription( Tests_BinaryHeapTest, suiteDescription_BinaryHeapTest, 89, "test_has_left_child" ) {}
 void runTest() { suite_BinaryHeapTest.test_has_left_child(); }
} testDescription_suite_BinaryHeapTest_test_has_left_child;

static class TestDescription_suite_BinaryHeapTest_test_has_right_child : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BinaryHeapTest_test_has_right_child() : CxxTest::RealTestDescription( Tests_BinaryHeapTest, suiteDescription_BinaryHeapTest, 97, "test_has_right_child" ) {}
 void runTest() { suite_BinaryHeapTest.test_has_right_child(); }
} testDescription_suite_BinaryHeapTest_test_has_right_child;

static class TestDescription_suite_BinaryHeapTest_test_has_parent : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BinaryHeapTest_test_has_parent() : CxxTest::RealTestDescription( Tests_BinaryHeapTest, suiteDescription_BinaryHeapTest, 105, "test_has_parent" ) {}
 void runTest() { suite_BinaryHeapTest.test_has_parent(); }
} testDescription_suite_BinaryHeapTest_test_has_parent;

static class TestDescription_suite_BinaryHeapTest_test_has_child : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BinaryHeapTest_test_has_child() : CxxTest::RealTestDescription( Tests_BinaryHeapTest, suiteDescription_BinaryHeapTest, 111, "test_has_child" ) {}
 void runTest() { suite_BinaryHeapTest.test_has_child(); }
} testDescription_suite_BinaryHeapTest_test_has_child;

static class TestDescription_suite_BinaryHeapTest_test_get_vector : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BinaryHeapTest_test_get_vector() : CxxTest::RealTestDescription( Tests_BinaryHeapTest, suiteDescription_BinaryHeapTest, 119, "test_get_vector" ) {}
 void runTest() { suite_BinaryHeapTest.test_get_vector(); }
} testDescription_suite_BinaryHeapTest_test_get_vector;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
