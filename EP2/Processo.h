#ifndef PROCESSO_H
#define PROCESSO_H
#include "Roteador.h"
#include "Segmento.h"

class Processo {
 public:
    Processo(int endereco, int porta, Roteador* gateway);
    virtual ~Processo();

    virtual int getEndereco();
    virtual int getPorta();
    virtual void receber(int origem, Segmento* mensagem) = 0;
    static void setTtlPadrao(int padrao);
    static int getTtlPadrao();

    virtual void imprimir();
 protected:
    int endereco;
    int porta;
    static int ttlPadrao;
    Roteador* gateway;
};

#endif // PROCESSO_H