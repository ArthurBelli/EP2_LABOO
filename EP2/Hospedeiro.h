#ifndef HOSPEDEIRO_H
#define HOSPEDEIRO_H
#include "No.h"
#include "Processo.h"
#include "Roteador.h"
#include "Hospedeiro.h"
#include "ServidorWeb.h"
#include "Navegador.h"
#include "Datagrama.h"
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

class Hospedeiro : public No {
 public:
    Hospedeiro(int endereco, Roteador* gateway);
    virtual ~Hospedeiro();

    virtual void adicionarServidorWeb(int porta, string conteudo);
    virtual void adicionarNavegador(int porta);
    virtual void processar();

    virtual Processo* getProcesso(int porta);
    virtual vector<Processo*>* getProcessos();
    virtual void imprimir();

 private:
    vector<Processo*>* processos;
    Roteador* gateway;
};

#endif // HOSPEDEIRO_H
