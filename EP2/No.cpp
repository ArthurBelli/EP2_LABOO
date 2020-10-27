#include "No.h"

No::No(int endereco) {
    this->endereco = endereco;
    fila = new fila(TAMANHO_FILA);
}

No::~No() {
    delete fila;
}

Fila* No::getFila() {
    return fila;
}

int No::getEndereco() {
    return endereco;
}

void No::receber(Datagrama* d) {
    try {
        this->fila->enqueue(d);
    } catch (overflow_error* e) {
        cout << "\tFila estourou em " << this->endereco << endl;
        delete e;
    }
}

void No::imprimir()
{

}

