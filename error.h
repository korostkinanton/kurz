/** @file error.h
 * @author Коросткин А.П.
 * @version 1.0
 * @date 22.12.2023
 * @copyright ИБСТ ПГУ
 * @brief Файл с классом Error
 */
#pragma once
#include "mdfile.h"

/**
 * @brief Класс описания ошибок
*/

class Error
{
private:

/**
 * @brief Создается объект err_file типа string
*/

	string err_file;

/**
 * @brief Создается объект errMessage типа string
*/

	string errMessage;
public:

/**
 * @brief Kонструктор класса Error, который инициализирует поля err_file и errMessage.
 * @details Конструктор принимает константную ссылку на объект типа string и использует её для инициализации поля err_file. Поле errMessage инициализируется пустой строкой.
*/

	Error(const string& error) : err_file(error), errMessage("") {}
	/*string getErrorMessage() const {
        return errMessage;
    }*/

/**
 * @brief Kонструктор копирования класса Error.
 * @details Конструктор копирования принимает ссылку на объект типа Error и использует её для инициализации поля err_file. Таким образом, он создает новый объект Error, который является копией существующего объекта Error, используя значение поля err_file из переданного объекта.
*/

	Error(const Error& name):err_file(name.err_file){};

/**
 * @brief объявление функции errors в классе Error. Функция ожидает один параметр - ссылку на объект типа string с именем error и не возвращает никакого значения.
*/

	void errors(string& error);
	

};
