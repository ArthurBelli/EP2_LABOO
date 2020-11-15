#include "Processo.h"

int Processo::ttlPadrao = 5;

Processo::Processo(int endereco, int porta, Roteador* gateway) {
    this->endereco = endereco;
    this->porta = porta;
    this->gateway = gateway;
}

Processo::~Processo() {}

int Processo::getEndereco() {
    return endereco;
}

int Processo::getPorta() {
    return porta;
}

void Processo::setTtlPadrao(int padrao) {
    Processo::ttlPadrao = padrao;
}

int Processo::getTtlPadrao() {
    return Processo::ttlPadrao;
}

void Processo::imprimir() {
    cout << "meu ttl padrao e " << Processo::ttlPadrao;

}