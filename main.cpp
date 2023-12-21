#include "mdfile.h"
#include "Server.h"
#include "error.h"
int main(int argc, char *argv[]) {
    if(argc == 1){
        cout << "калькулятор суммы векторов "  << endl;
        cout << "-h info" << endl;
        cout << "-f Имя файла с данными авторизации" << endl;
        cout << "-p Порт" << endl;
        cout << "-e Файл ошибок" << endl;
    }
    int opt;
    int port = 33333;
    string file_name = "/ect/vcalc.conf";
    string file_error = "/var/log/vcalc.log";
    string error;
    while ((opt = getopt(argc, argv, "hf:p:i:e:" ))!=-1 ){
    switch(opt){
        case 'h':
        cout << "Калькулятор суммы векторов"  << endl;
        cout << "Вы открыли калькулятор суммы векторов" << endl;
        cout << "В данном калькуляторе вы можете..." << endl;
        cout << "Запросить Базу данных пользователей камандой ./main -f" << endl;
        cout << "Запросить порт командой ./main -p" << endl;
        cout << "Запросить файл ошибок командой ./main -e" << endl;
        cout << "-f Имя файла с данными авторизации" << endl;
        cout << "-p Порт" << endl;
        cout << "-e Файл ошибок" << endl;
        cout << "Cама программа предназначена для рассчета суммы векторов" << endl;
        cout << "Для этого вам нужно запустить сервер командой - ./main -f base.txt -p 33333 -e error.txt" << endl;
        cout << "После этого нужно открыть новое окно, перейти в деректорию калькулятора - cd /home/stud/Desktop/kurz и запустить клиента командой ./client[x]" << endl;
        cout << "(под х подразумевается число или символ после слова client, если оно имеется)" << endl;
        return 1;
        break;
        case 'f':{
        file_name = string(optarg);
        };
        break;
        case 'p':{
        port = stoi(string(optarg));
        }
        case 'e':{
        file_error = string(optarg);
        };
        break;
        }
        }
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
