#ifndef FILA_H
#define FILA_H
#include "Datagrama.h"
#include <stdexcept>

using namespace std;

class Fila {
 public:
    Fila(int tamanho);
    virtual ~Fila();

    virtual void enqueue(Datagrama* d);
    virtual Datagrama* dequeue();
    virtual bool isEmpty();

    virtual void imprimir();
 private:
    int inicio, fim, tamanho, quantidade;
    Datagrama** vetFila;
};

#endif // FILA_H
