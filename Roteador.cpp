#include "Roteador.h"

Roteador::Roteador(int endereco): No(endereco) {
    tabela = new TabelaDeRepasse();
}

Roteador::~Roteador() {
    delete tabela;
}

void Roteador::processar() {
    try {
        Datagrama* atual = new Datagrama(0, 0, 0, "");
        atual = fila->dequeue();
        atual->processar();
        if (!atual->ativo()) delete atual;
        else {
            if (atual->destino == endereco) delete atual;
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
