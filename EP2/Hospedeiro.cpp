#include "Hospedeiro.h"


Hospedeiro::Hospedeiro(int endereco, Roteador* gateway) : No(endereco) {
    this->gateway = gateway;
    processos = new vector<Processo*>();
}

Hospedeiro::~Hospedeiro() {
    while (!processos->empty()) {
        Processo* atual = processos->back();
        processos->pop_back();
        delete atual;
    }
    delete processos; //nao explicita se deve apagar a estrutura, podemos perguntar dps
}

void Hospedeiro::adicionarServidorWeb(int porta, string conteudo) {
    ServidorWeb* s = new ServidorWeb(endereco, porta, gateway, conteudo);
    vector<Processo*>::iterator i = processos->begin();
    if (!processos->empty()) {
        if (this->getProcesso(porta) != NULL) {
            throw new logic_error("Porta ja contem processo.");
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
            throw new logic_error("Porta ja contem processo.");
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

    } catch (underflow_error* e) {
        cout << "\tFila em "<< this->getEndereco() << " vazia" << endl;
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
    return processos;
}
