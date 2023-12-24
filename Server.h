/** @file Server.h
 * @author Коросткин А.П.
 * @version 1.0
 * @date 22.12.2023
 * @copyright ИБСТ ПГУ
 * @brief Файл с классом Server
 */
#pragma once
#include "mdfile.h"
#include "error.h"

/**
 * @brief Класс с методами для сервера
*/

class Server{
private:

/**
 * @brief Определяется поле с именем "er" в классе, которое является ссылкой на объект типа Error.
 * @details Таким образом, класс Server содержит поле "er", которое указывает на объект типа Error.
*/

Error& er;
public:

/**
 * @brief Объявляется функция self_addr в классе Server. Функция ожидает два параметра: строку error и целочисленный port, и возвращает целочисленное значение.
*/

int self_addr(string error, int port);

/**
 * @brief Объявляется функция client_addr в классе Server. Функция ожидает два параметра: строку error и целочисленный s, и возвращает целочисленное значение.
*/

int client_addr(int s, string error);

/**
 * @brief Объявляется функция autorized в классе Server. Функция ожидает два параметра: строку file_name и целочисленный work_sock, и возвращает целочисленное значение.
*/

int autorized(int work_sock, string file_name);

/**
 * @brief Объявляется функция autorized в классе math. Функция ожидает  целочисленный параметр work_sock, и возвращает целочисленное значение.
*/

int math(int work_sock);

/**
 * @brief Конструктор класса Server, который инициализирует поле er объектом типа Error по ссылке.
 * @details Конструктор принимает ссылку на объект типа Error и использует её для инициализации поля er.
*/

Server(Error& wer):er(wer){};

//Server() : er() {}
};
