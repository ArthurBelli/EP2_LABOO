#include "Rede.h"

Rede::Rede() {
    nos = new list<No*>();
    hospedeiros = new list<Hospedeiro*>();
}

Rede::~Rede() {
    while (!nos->empty()) {
        No* atual = nos->back();
        nos->pop_back();
        delete atual;
    }
    delete nos;
}

void Rede::adicionar(No* no) {
    list<No*>::iterator i = nos->begin();
    while (i != nos->end()) {
        if ((*i) == no) throw new logic_error("No ja esta incluso na rede");
        delete no; //diz apenas para nao incluir, mas parece prudente excluir
    }
    nos->push_back(no);
}

No* Rede::getNo(int endereco) {
    list<No*>::iterator i = nos->begin();
    while (i != nos->end()) {
        if ((*i)->getEndereco() == endereco) return (*i);
        i++;
    }
    return NULL;
}

list<Hospedeiro*>* Rede::getHospedeiros() {
    if (hospedeiros->empty()) return NULL;
    else return hospedeiros;
}

void Rede::passarTempo() {
    list<No*>::iterator i = nos->begin();
    while (i != nos->end()) { //como fizemos a inclusao dos nós com o metodo push_back, podemos começar a percorrer pelo começo
        (*i)->processar();
        i++;
    }
}

void Rede::imprimir() {

}
