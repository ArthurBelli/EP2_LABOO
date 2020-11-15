#include "Segmento.h"

Segmento::Segmento(int portaDeOrigem, int portaDeDestino, string dado) {
    this->portaDeOrigem = portaDeOrigem;
    this->portaDeDestino = portaDeDestino;
    this->dado = dado;
}

Segmento::~Segmento() {}

int Segmento::getPortaDeOrigem() {
    return portaDeOrigem;
}

int Segmento::getPortaDeDestino() {
    return portaDeDestino;
}

string Segmento::getDado() {
    return dado;
}

void Segmento::imprimir() {
    cout << "oi sou segmento" << endl;
}
