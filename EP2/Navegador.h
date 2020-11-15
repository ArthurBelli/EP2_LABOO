#ifndef NAVEGADOR_H
#define NAVEGADOR_H
#include "Processo.h"
#include <string>


class Navegador: public Processo {
 public:
    Navegador(int endereco, int porta, Roteador* gateway);
    virtual ~Navegador();

    void receber(int origem, Segmento* mensagem);
    virtual void abrir(int endereco, int porta);
    virtual void abrir(int endereco);

    virtual string getConteudo();

 private:
    string conteudo;
    int requestEnd; //vai guardar o endereco para qual foi enviado o requestDat
};

#endif // NAVEGADOR_H