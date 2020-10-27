#ifndef ROTEADOR_H
#define ROTEADOR_H
#include "TabelaDeRepasse.h"
#include "No.h"
#include <stdexcept>

using namespace std;

class Roteador: public No {
 public:
    Roteador(int endereco);
    virtual ~Roteador();

    void processar();
    virtual TabelaDeRepasse* getTabela();

 private:
    TabelaDeRepasse* tabela;
    int endereco;
};

#endif // ROTEADOR_H