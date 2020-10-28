#include "PersistenciaDeRede.h"
#include "Roteador.h"
#include "Hospedeiro.h"
#include <fstream>

PersistenciaDeRede::PersistenciaDeRede()
{
    rede = new Rede();
}

PersistenciaDeRede::~PersistenciaDeRede()
{
    delete rede;
}

Rede* PersistenciaDeRede::carregar(string arquivo) {
    ifstream leitor;
    int i, j, quantRoteadores, quantHospedeiros, endereco, quantProcessos, endGateway, porta, endPadrao, quantMapeamentos, endAdj, destino;
    string tipoProcesso, conteudo;
    leitor.open(arquivo);
    if (leitor.fail()) {
        throw new invalid_argument("Erro na abertura do arquivo, verifique se o nome esta correto.");
        leitor.close();
        return NULL;
    }
    while(leitor) {
        //primeiro adicionamos os roteadores
        leitor >> quantRoteadores;
        for (i=0; i<quantRoteadores; i++) {
            try {
                leitor >> endereco;
                rede->adicionar(new Roteador(endereco));
            } catch (logic_error *e) {
                cout << "Tentando adicionar Roteador já adicionado." << endl;
                delete e;
            }
        }
        //depois os hospedeiros  
        leitor >> quantHospedeiros; // aqui quantidade representa a quantidade de hospedeiros
        for (i=0; i<quantHospedeiros; i++) {
            leitor >> endereco;
            leitor >> endGateway;
            Roteador* gateway = new Roteador(0);
            gateway = dynamic_cast<Roteador*> (rede->getNo(endGateway));
            if (gateway == NULL) throw new invalid_argument("Arquivo formatado errado.");
            else {
                try {
                    rede->adicionar(new Hospedeiro(endereco, gateway));
                    delete gateway;
                } catch (logic_error *e) {
                    cout << "Tentando adicionar Hospedeiro já adicionado." << endl;
                    delete e;
                }
                leitor >> quantProcessos;
                for (j=0; j<quantProcessos; j++) { //cada hospedeiro tem processos, aqui eles são adicionados
                    leitor >> tipoProcesso;
                    leitor >> porta;
                    if (tipoProcesso == "n") {
                        Hospedeiro* h = dynamic_cast<Hospedeiro*>(rede->getNo(endereco));
                        if (h==NULL) throw new invalid_argument("Hospedeiro invalido");
                        else h->adicionarNavegador(porta);
                    }
                    else if (tipoProcesso == "w") {
                        leitor >> conteudo;
                        Hospedeiro* h = dynamic_cast<Hospedeiro*>(rede->getNo(endereco));
                        if (h==NULL) throw new invalid_argument("Hospedeiro invalido");
                        else h->adicionarServidorWeb(porta, conteudo);
                    }
                    else throw new invalid_argument("Arquivo formatado errado");
                }
            }
        }
        // agora falta montar a tabela
        for (i=0; i<quantRoteadores; i++) {
            leitor >> endereco;
            leitor >> endPadrao;
            Roteador* r = dynamic_cast<Roteador*>(rede->getNo(endereco));
            r->getTabela()->setPadrao(rede->getNo(endPadrao));
            leitor >> quantMapeamentos;
            for (j=0; j<quantMapeamentos; j++) {
                try {
                    leitor >> endAdj;
                    leitor >> destino;
                    r->getTabela()->mapear(endAdj, rede->getNo(destino));
                } catch (overflow_error* e) {
                    cout << "Tabela cheia" << endl;                      
                  }
            }
        }
    }
    if (!leitor.eof()) throw new invalid_argument("Erro de leitura");
    leitor.close();

    return rede;
}