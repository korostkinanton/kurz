#pragma once
#include "mdfile.h"
class Error
{
private:
	string err_file;
	string errMessage;
public:
	Error(const string& error) : err_file(error), errMessage("") {}
	string getErrorMessage() const {
        return errMessage;
    }
	Error(const Error& name):err_file(name.err_file){};
	void errors(string& error);
	

};
