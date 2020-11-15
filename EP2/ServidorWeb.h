
#ifndef SERVIDORWEB_H
#define SERVIDORWEB_H
#include "Processo.h"
#include <string>


class ServidorWeb: public Processo {
 public:
    ServidorWeb(int endereco, int porta, Roteador* gateway, string conteudo);
    virtual ~ServidorWeb();

    void receber(int origem, Segmento* mensagem);

 private:
    string conteudo;
};

#endif // SERVIDORWEB_H