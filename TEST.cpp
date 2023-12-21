#include <stdexcept>
#include <UnitTest++/UnitTest++.h>
#include "mdfile.h"
#include "Server.h"
#include "error.h"

SUITE(ErrorTests)
{
    TEST(ErrorConstructor)
    {
        std::string errorMessage = "Test error message";
        Error err(errorMessage);
        CHECK_EQUAL(errorMessage, err.getErrorMessage());
    }

    // Дополнительные тесты для класса Error
}

SUITE(ServerTests)
{
    TEST(ServerSelfAddr)
    {
        Error err("test.log");
        Server server(err);
        int port = 33333;
        int result = server.self_addr("Error occurred during self_addr", port);
        CHECK_EQUAL(1, result);
    }

    // Другие тесты для класса Server
    TEST(Calculator){
 		Server server;
 		vector<uint32_t> numbers = {5, 6, 7, 8};
 		int work_sock = 123; // Замените на фактическое значение сокета для вашего теста
 		int result = server.math(work_sock);
 		CHECK_EQUAL(1, result);
 }
}

int main(int argc, char **argv)
{
	return UnitTest::RunAllTests();
}
