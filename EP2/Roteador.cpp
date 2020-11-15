#include "Roteador.h"

Roteador::Roteador(int endereco): No(endereco) {
    tabela = new TabelaDeRepasse();
}

Roteador::~Roteador() {
    delete tabela;
}

void Roteador::processar() {
    try {
        Segmento* temp = new Segmento(0, 0, "");
        Datagrama* atual = new Datagrama(0, 0, 0, temp);
        atual = fila->dequeue();
        atual->processar();
        cout << "Roteador " << this->getEndereco() << endl;
        if (!atual->ativo()) {
            cout << "\tDestruido por TTL: ";
            atual->imprimir();
            delete atual;
        } else {
            if (atual->getDestino() == endereco) {
                cout << "\tRecebido ";
                atual->imprimir();
                delete atual;
            }else {
                if (tabela->getDestino(atual->getDestino()) != NULL) {
                    cout << "\tEnviado para " << tabela->getDestino(atual->getDestino())->getEndereco() << " ";
                    atual->imprimir();
                    tabela->getDestino(atual->getDestino())->receber(atual);
                }else {
                    cout << "\tSemProximo: ";
                    atual->imprimir();
                    delete atual;
                }
            }
        }
    } catch (underflow_error *e) {
        //cout << "\tFila vazia em " << this->getEndereco() << endl;
        delete e;
    }
}

TabelaDeRepasse* Roteador::getTabela() {
    return tabela;
}

void Roteador::imprimir() {
    cout << "Sou o roteador" << this->getEndereco() <<  endl;
    cout << "minha fila:" << endl;
    fila->imprimir();
    cout << "minha tabela:" << endl;
    tabela->imprimir();
}
