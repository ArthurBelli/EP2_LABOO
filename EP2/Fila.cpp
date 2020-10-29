#include "Fila.h"

Fila::Fila(int tamanho) {
    this->tamanho = tamanho;
    inicio = fim = 0;
    vetFila = new Datagrama*[tamanho + 1]; //vamos adotar a fila circular com uma posicao sempre vazia
    quantidade = 0;
}

Fila::~Fila() {
    delete[] vetFila;
}

void Fila::enqueue(Datagrama* d) {
    if ((inicio == fim + 1) || (inicio == 0 && fim == tamanho)) throw new overflow_error("Overflow");
    else {
        vetFila[fim] = d;
        quantidade++;
        if(fim == tamanho) fim = 0;
        else fim++;
    }
}

Datagrama* Fila::dequeue() {
    if (this->isEmpty()) throw new underflow_error("Underflow");
    Datagrama* retirado = vetFila[inicio];
    quantidade--;
    if (inicio == tamanho) inicio = 0;
    else inicio++;
    return retirado;
}

bool Fila::isEmpty() {
    return (inicio == fim); //condicao de fila cheia para a solucao adotada
}

void Fila::imprimir() {
    cout << "Fila: " << endl;
    cout << "Comeco: " << inicio << endl;
    cout << "Fim: " << fim << endl;
    for (int i=inicio; i!=fim; i++) {
        cout << vetFila[i]->getDado()->getDado();
        cout << " ";
    }
}
