#ifndef REDE_H
#define REDE_H
#include <list>
#include <stdexcept>
#include "Hospedeiro.h"
#include "No.h"

using namespace std;

class Rede {
 public:
    Rede();
    virtual ~Rede();

    virtual void adicionar(No* no);
    virtual No* getNo(int endereco);
    virtual list<Hospedeiro*>* getHospedeiros();
    virtual void passarTempo();

    virtual void imprimir();

 private:
    list<Hospedeiro*>* hospedeiros;
    list<No*>* nos; //optamos pela estrutura list para armazenar os nós
};

#endif // REDE_H