/** @file TEST.cpp
 * @author Коросткин А.П.
 * @version 1.0
 * @date 22.12.2023
 * @copyright ИБСТ ПГУ
 * @brief file TEST.cpp
 * @details нужен для модульного тестирования 
 */
#include <stdexcept>
#include <UnitTest++/UnitTest++.h>
#include <UnitTest++/TestReporterStdout.h>
#include "mdfile.h"
#include "Server.h"
#include "error.h"
#include "interface.h"


struct InterfaceTest {
    Interface interface;
};

SUITE( ComLineTests ) {
    TEST_FIXTURE(InterfaceTest, Empty) {
        int test_argc = 1;
        const char* test_argv[test_argc] = {"NAME"};
        CHECK_EQUAL(true,
                    interface.get_options_from_comline(test_argc, (char**)(test_argv)));
    }
    TEST_FIXTURE(InterfaceTest, OnlyHelp) {
        int test_argc = 2;
        const char* test_argv[test_argc] = {"NAME", "-h"};
        CHECK_EQUAL(true,
                    interface.get_options_from_comline(test_argc, (char**)(test_argv)));
    }
    TEST_FIXTURE(InterfaceTest, Help) {
        int test_argc = 8;
        const char* test_argv[test_argc] = {"NAME", "-f", "logpas.txt", "-p", "33333", "-e", "error.txt", "-h"};
        CHECK_EQUAL(true,
                    interface.get_options_from_comline(test_argc, (char**)(test_argv)));
    }
    TEST_FIXTURE(InterfaceTest, NonPort) {
        int test_argc = 5;
        const char* test_argv[test_argc] = {"NAME", "-f", "base.txt", "-e", "error.txt"};
        CHECK_EQUAL(false,
        			interface.get_options_from_comline(test_argc, (char**)(test_argv)));
    }
    TEST_FIXTURE(InterfaceTest, NonError) {
        int test_argc = 5;
        const char* test_argv[test_argc] = {"NAME", "-f", "base.txt", "-p", "33333"};
        CHECK_EQUAL(false,
        			interface.get_options_from_comline(test_argc, (char**)(test_argv)));
    }
    TEST_FIXTURE(InterfaceTest, NonFile) {
        int test_argc = 5;
        const char* test_argv[test_argc] = {"NAME", "-p", "33333", "-e", "error.txt"};
        CHECK_EQUAL(false,
        			interface.get_options_from_comline(test_argc, (char**)(test_argv)));
    }
	TEST_FIXTURE(InterfaceTest, FailF) {
        int test_argc = 7;
        const char* test_argv[test_argc] = {"NAME", "-t", "base.txt", "-p", "33333", "-e", "error.txt"};
        CHECK_EQUAL(false,
        			interface.get_options_from_comline(test_argc, (char**)(test_argv)));
    }
    TEST_FIXTURE(InterfaceTest, FailP) {
        int test_argc = 7;
        const char* test_argv[test_argc] = {"NAME", "-f", "base.txt", "-t", "33333", "-e", "error.txt"};
        CHECK_EQUAL(false,
        			interface.get_options_from_comline(test_argc, (char**)(test_argv)));
    }
    TEST_FIXTURE(InterfaceTest, FailE) {
        int test_argc = 7;
        const char* test_argv[test_argc] = {"NAME", "-f", "base.txt", "-p", "33333", "-t", "error.txt"};
        CHECK_EQUAL(false,
        			interface.get_options_from_comline(test_argc, (char**)(test_argv)));
    }
    TEST_FIXTURE(InterfaceTest, LostBase) {
        int test_argc = 6;
        const char* test_argv[test_argc] = {"NAME", "-f", "-p", "33333", "-e", "error.txt"};
        CHECK_EQUAL(false,
        			interface.get_options_from_comline(test_argc, (char**)(test_argv)));
    }
    TEST_FIXTURE(InterfaceTest, Lost33333) {
        int test_argc = 6;
        const char* test_argv[test_argc] = {"NAME", "-f", "base.txt", "-p", "-e", "error.txt"};
        CHECK_EQUAL(false,
        			interface.get_options_from_comline(test_argc, (char**)(test_argv)));
    }
    TEST_FIXTURE(InterfaceTest, LostError) {
        int test_argc = 6;
        const char* test_argv[test_argc] = {"NAME", "-f", "base.txt", "-p", "33333", "-e"};
        CHECK_EQUAL(false,
        			interface.get_options_from_comline(test_argc, (char**)(test_argv)));
    }
}

int main(int argc, char **argv)
{
	return UnitTest::RunAllTests();
}
