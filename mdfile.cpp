
#include "mdfile.h"
#include "Server.h"
#include "error.h"
int Server::self_addr(string error, int port){
    int s = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in * self_addr = new (sockaddr_in);
    self_addr->sin_family = AF_INET;
    self_addr->sin_port = htons(port);
    self_addr->sin_addr.s_addr = inet_addr("127.0.0.1");
    cout << "Ожидание клиента...\n";
    int b = bind(s,(const sockaddr*) self_addr,sizeof(sockaddr_in));
        if(b == -1) {
            cout << "Binding error\n";
            error = "error binding";
            er.errors(error);
            return 1;
            }
    listen(s, SOMAXCONN);
return s;
}

int Server::client_addr(int s, string error){
    sockaddr_in * client_addr = new sockaddr_in;
    socklen_t len = sizeof (sockaddr_in);
    int work_sock = accept(s, (sockaddr*)(client_addr), &len);
    if(work_sock == -1) {
        cout << "Error #2\n";
        error = "error #2";
        er.errors(error);
        return 1;
    }
    else {
        //Успешное подключение к серверу
        cout << "Клиент подключился!\n";
        return work_sock;
    }
    }

int Server::autorized(int work_sock, string file_name){

        string ok = "OK";
        string salt = "1111111111111111";
        string err = "ERR";
        string error;
        char msg[255];
        
        //Авторизация
        int size;
        size = recv(work_sock, &msg, sizeof(msg), 0);
            string message(msg, size);
    string login, hashq;
    fstream file;
    file.open(file_name);
    getline (file, login, ':');
    getline (file, hashq);

            //СВЕРКА ЛОГИНОВ
            if(message != login){
    msgsend(work_sock,  err);
    error = "Ошибка логина";
    er.errors(error);
    close(work_sock);
    return 1;
            }else{
            //соль отправленная клиенту
            msgsend(work_sock,  salt);
            size = recv(work_sock, msg, sizeof(msg), 0);
            string H(msg, size);
            string sah = salt + hashq;
            string digest;
            digest = MD(sah);
            //СВЕРКА ПАРОЛЕЙ
            if(digest != H){
    cout << digest << endl;
    cout << H << endl;
    msgsend(work_sock,  err);
    error = "Ошибка пароля";
    er.errors(error);
    close(work_sock);
    return 1;
            }else{
    msgsend(work_sock,  ok);
            }
}
return 1;
}

void msgsend(int work_sock, string mess){
    char *buffer = new char[4096];
    strcpy(buffer, mess.c_str());
    send(work_sock, buffer, mess.length(), 0);
}



string MD(string sah){
Weak::MD5 hash;
    string digest;
    StringSource(sah, true,  new HashFilter(hash, new HexEncoder(new StringSink(digest))));  // строка-приемник
      return digest;
 }
void Error::errors(string& error){
    ofstream file;
    file.open(err_file, ios::app);
    if(file.is_open()){
        time_t seconds = time(NULL);
        tm* timeinfo = localtime(&seconds);
        file<<error<<':'<<asctime(timeinfo)<<endl;
        cout << "error: " << error << endl;
    }
}


int Server::math(int work_sock){
    uint32_t kolvo;
    uint32_t numb;
    uint64_t vect;
        recv(work_sock, &kolvo, sizeof(kolvo), 0);
    //цикл векторов
    for(uint32_t j=0; j<kolvo; j++){
        recv(work_sock, &numb, sizeof(numb), 0);//прием длинны для первого вектора
        uint32_t sum = 0;
    //цикл значений
    for(uint32_t i=0; i<numb; i++){
        recv(work_sock, &vect, sizeof(vect), 0);
        sum = sum+vect;
    }
    uint64_t mfc;
    mfc = sum;
    send(work_sock, &mfc, sizeof(mfc), 0);
    } 
cout << "Program finish!" <<endl;
close(work_sock);
return 1;
}
