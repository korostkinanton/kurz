#pragma once
#include "mdfile.h"
#include "error.h"
class Server{
private:
Error& er;
public:
int self_addr(string error, int port);
int client_addr(int s, string error);
int autorized(int work_sock, string file_name);
int math(int work_sock);
Server(Error& wer):er(wer){};
Server() : er() {}
};
