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
        delete temp;
        atual->processar();
        if (!atual->ativo()) delete atual;
        else {
            if (atual->getDestino() == endereco) delete atual;
            else {
                if (tabela->getDestino(atual->getDestino()) != NULL)
                    tabela->getDestino(atual->getDestino())->receber(atual);
                else delete atual;
            }
        }
    } catch (underflow_error *e) {
        cout << "\tFila vazia em " << this->getEndereco() << endl;
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
