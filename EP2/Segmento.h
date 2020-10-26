#include <string>
#include <iostream>
using namespace std;
#ifndef SEGMENTO_H
#define SEGMENTO_H

class Segmento
{
 public:
    Segmento(int portaDeOrigem, int portaDeDestino, string dado);
    virtual ~Segmento();
    
    virtual int getPortaDeOrigem();
    virtual int getPortaDeDestino();
    virtual string getDado(); 

    virtual void imprimir();

 private:
    int portaDeOrigem, portaDeDestino;
    string dado;
};

#endif // SEGMENTO_H
