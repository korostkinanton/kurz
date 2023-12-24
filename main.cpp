/** @file main.cpp
 * @author Коросткин А.П.
 * @version 1.0
 * @date 22.12.2023
 * @copyright ИБСТ ПГУ
 * @brief file main.cpp 
 */
#include "mdfile.h"
#include "Server.h"
#include "error.h"
#include "interface.h"
int main(int argc, char *argv[]) {
	Interface interface;
    string error;
	if (!interface.get_options_from_comline(argc, argv)) {
        return 1;
    }

    int port = interface.get_port();
    string file_name = interface.get_file_name();
    string file_error = interface.get_file_error();
    fstream file;
    file.exceptions(ifstream::badbit | ifstream::failbit);
    try{
        file.open(file_name);
    }catch(const exception & ex){
        string error = "error open file";
        return 1;
    }
    Error er(file_error);
        Server Server(er);

        int s = Server.self_addr(error, port);
        while(true) {
                
            int work_sock = Server.client_addr(s, error);

                Server.autorized(work_sock, file_name);    
                Server.math(work_sock);
        }

        
    return 0;
}
