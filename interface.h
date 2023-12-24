/** @file interface.h
 * @author Коросткин А.П.
 * @version 1.0
 * @date 22.12.2023
 * @copyright ИБСТ ПГУ
 * @brief Главный файл сервера 
 */
#pragma once
#include "mdfile.h"
/**
 * @brief Класс для описывания интерфейса для взаимодействия с командной строкой
*/
class Interface {
private:
/**
 * @brief создается объект port типа int, с значением 33333
*/
	int port = 33333;
/**
 * @brief создается объект file_name типа string, с значением "/ect/vcalc.conf"(путь к файлу конфигурации по умолчанию)
*/
    string file_name = "/ect/vcalc.conf";
/**
 * @brief создается объект file_error типа string, с значением "/var/log/vcalc.log"(путь к файлу с записью ошибок по умолчанию)
*/
    string file_error = "/var/log/vcalc.log";
public:
/**
 * @brief Определяется сигнатура (прототип) метода get_options_from_comline класса Interface
*/
	bool get_options_from_comline(int argc, char* argv[]);
/**
 * @brief Эта строчка определяет метод get_port, который принадлежит классу Interface. Метод не принимает аргументов и возвращает целочисленное значение (int).
 * @details Когда этот метод вызывается для объекта класса Interface, он возвращает значение переменной port, которое является приватным членом класса. В данном случае, метод get_port предоставляет возможность получения значения порта, хранящегося в объекте Interface.
*/
    int get_port() {
        return port;
    }
/**
 * @brief Эта строчка определяет метод get_file_name, который принадлежит классу Interface. Метод не принимает аргументов и возвращает значение string.
 * @details Когда этот метод вызывается для объекта класса Interface, он возвращает значение переменной file_name, которое является приватным членом класса. В данном случае, метод get_file_name предоставляет возможность получения значения порта, хранящегося в объекте Interface.
*/
    string get_file_name() {
        return file_name;
    }
/**
 * @brief Эта строчка определяет метод get_file_error, который принадлежит классу Interface. Метод не принимает аргументов и возвращает значение string.
 * @details Когда этот метод вызывается для объекта класса Interface, он возвращает значение переменной file_error, которое является приватным членом класса. В данном случае, метод get_file_error предоставляет возможность получения значения порта, хранящегося в объекте Interface.
*/
    string get_file_error() {
        return file_error;
    }
};

