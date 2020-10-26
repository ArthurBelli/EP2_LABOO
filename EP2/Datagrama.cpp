#include "Datagrama.h"

Datagrama::Datagrama(int origem, int destino, int ttl, Segmento* dado)
{
    this->origem = origem;
    this->destino = destino;
    this->ttl = ttl;
    this->dado = dado;
}

Datagrama::~Datagrama()
{
    delete dado;
    cout << "Datagrama destruido" << endl;
}

int Datagrama::getOrigem() {
    return origem;
}

int Datagrama::getDestino() {
    return destino;
}

int Datagrama::getTtl() {
    return ttl;
}

Segmento* Datagrama::getDado() {
    return dado;
}

void Datagrama::processar() {
    ttl--;
}

bool Datagrama::ativo() {
    return (ttl > 0);
}

void Datagrama::imprimir() {
    cout << "Oi sou datagrama" << endl;
}
