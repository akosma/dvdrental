/*!
 * \file unittests.cpp
 * Contains the entry point of the test application, using the CppUnit framework.
 */

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cstdlib>

/*!
 * Entry point of the test application.
 * 
 * \return An error code to the application, stating whether
 * the test run was successful or not.
 */
int main()
{
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(CppUnit::TestFactoryRegistry::getRegistry().makeTest());
    bool wasSucessful = runner.run();
    getchar();
    return wasSucessful ? EXIT_SUCCESS : EXIT_FAILURE;
}
