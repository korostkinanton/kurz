/** @file interface.cpp
 * @author Коросткин А.П.
 * @version 1.0
 * @date 22.12.2023
 * @copyright ИБСТ ПГУ
 * @brief file interface.cpp 
 */
#include "mdfile.h"
#include "Server.h"
#include "error.h"
#include "interface.h"
bool Interface::get_options_from_comline(int argc, char* argv[]){
	if(argc == 1){
        cout << "калькулятор суммы векторов "  << endl;
        cout << "-h info" << endl;
        cout << "-f Имя файла с данными авторизации" << endl;
        cout << "-p Порт" << endl;
        cout << "-e Файл ошибок" << endl;
    }
    int opt;
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
        };
        break;
        case 'e':{
        file_error = string(optarg);
        };
        break;
        }
        }
    return true;
}
