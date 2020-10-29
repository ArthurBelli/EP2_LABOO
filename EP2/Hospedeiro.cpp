
#include "Hospedeiro.h"
#include "ServidorWeb.h"
#include "Navegador.h"
#include "Datagrama.h"
#include <stdexcept>
using namespace std;

Hospedeiro::Hospedeiro(int endereco, Roteador* gateway) : No(endereco) {
    this->gateway = gateway;
    processos = new vector<Processo*>();
}

Hospedeiro::~Hospedeiro()
{
    vector<Processo*>::iterator i = processos->begin();
    while (i != processos->end()) {
        delete (*i);
        i++;
    }
    delete processos; //não fala que é pra destruir o vetor mas me parece prudente, qualquer coisa a gente pergunta
}

void Hospedeiro::adicionarServidorWeb(int porta, string conteudo) {
    ServidorWeb* s = new ServidorWeb(endereco, porta, gateway, conteudo);
    vector<Processo*>::iterator i = processos->begin();
    if (!processos->empty()) {
        if (this->getProcesso(porta) != NULL) {
            throw logic_error("Porta já contem processo.");
            return;
        }
    }
    processos->push_back(s);
}

void Hospedeiro::adicionarNavegador(int porta) {
    Navegador* n = new Navegador(endereco, porta, gateway);
    vector<Processo*>::iterator i = processos->begin();
    if (!processos->empty()) {
        if (this->getProcesso(porta) != NULL) {
            throw logic_error("Porta já contem processo.");
            return;
        }
    }
    processos->push_back(n);
}

void Hospedeiro::processar() {
    try {
        Datagrama* atual = new Datagrama(0, 0, 0, new Segmento(0,0,""));
        atual = fila->dequeue();
        Processo* destino = this->getProcesso(atual->getDado()->getPortaDeDestino());
        if (destino != NULL) {
            destino->receber(atual->getOrigem(), atual->getDado());
            delete atual;
        } else delete atual;

    } catch (underflow_error *e) {
        cout << "\tFila vazia em " << this->getEndereco() << endl;
        delete e;
    }
}


Processo* Hospedeiro::getProcesso(int porta) {
    vector<Processo*>::iterator i = processos->begin();
    while (i != processos->end()) {
            if ((*i)->getPorta() == porta) return (*i);
            i++;
        }
    return NULL;
}

vector<Processo*>* Hospedeiro::getProcessos() {
    if (processos->empty()) return NULL;
    else return processos;
}

void Hospedeiro::imprimir() {
    cout << "Sou o hospedeiro " << this->getEndereco() << endl;
    cout << "meus processos: " << endl;
    vector<Processo*>::iterator i = processos->begin();
    while (i != processos->end()) {
        cout << (*i)->getPorta() << endl;
        i++;
    }
}
