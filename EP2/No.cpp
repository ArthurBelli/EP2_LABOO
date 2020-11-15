#include "No.h"

const int No::TAMANHO_FILA = 5;

No::No(int endereco) {
    this->endereco = endereco;
    fila = new Fila(No::TAMANHO_FILA);
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
    cout << "Sou no " << getEndereco() << endl;
    fila->imprimir();

}
