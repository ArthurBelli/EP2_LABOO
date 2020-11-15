#ifndef ROTEADOR_H
#define ROTEADOR_H
#include "TabelaDeRepasse.h"
#include "No.h"

using namespace std;

class Roteador: public No {
 public:
    Roteador(int endereco);
    virtual ~Roteador();

    void processar();
    virtual TabelaDeRepasse* getTabela();
    virtual void imprimir();

 private:
    TabelaDeRepasse* tabela;
};

#endif // ROTEADOR_H