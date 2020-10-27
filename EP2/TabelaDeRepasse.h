#ifndef TABELADEREPASSE_H
#define TABELADEREPASSE_H
#include "No.h"

class TabelaDeRepasse
{
 public:
    TabelaDeRepasse();
    virtual ~TabelaDeRepasse();

    virtual void mapear(int endereco, No* adjacente);
    virtual No** getAdjacentes();
    virtual int getQuantidadeDeAdjacentes();
    virtual void setPadrao(No* padrao);
    virtual No* getDestino(int endereco);

    virtual void imprimir(); 
private:
    No** vetNo; //vetor de nos
    int* vetEnd; //vetor de endereços
    No* noPadrao;
    static const int MAXIMO_TABELA;
};

#endif // TABELADEREPASSE_H
