#ifndef NO_H
#define NO_H
#include "Fila.h"
#include "Datagrama.h"
#include <stdexcept>


class No {
 public:
    No(int endereco);
    virtual ~No();

    virtual Fila* getFila();
    virtual int getEndereco();
    virtual void processar() = 0;
    virtual void receber(Datagrama* d);

    virtual void imprimir() = 0;
 protected:
    static const int TAMANHO_FILA;
    int endereco;
    Fila* fila;
};

#endif // NO_H