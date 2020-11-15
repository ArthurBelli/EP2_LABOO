#include "TabelaDeRepasse.h"

const int TabelaDeRepasse::MAXIMO_TABELA = 5;

TabelaDeRepasse::TabelaDeRepasse() {
    vetNo = new No*[TabelaDeRepasse::MAXIMO_TABELA];
    vetEnd = new int[TabelaDeRepasse::MAXIMO_TABELA];
    noPadrao = NULL;
    for (int i = 0; i < TabelaDeRepasse::MAXIMO_TABELA; i++) {
        vetNo[i] = NULL;
        vetEnd[i] = 0;
    }
}

TabelaDeRepasse::~TabelaDeRepasse() {
    delete[] vetNo;
    delete[] vetEnd;
}

void TabelaDeRepasse::mapear(int endereco, No* adjacente) {
    int i = 0;
    while (vetNo[i] != NULL && vetEnd[i] != 0) {
        i++;
        if (vetNo[i] == adjacente) { //substitui vetor que ja esta na tabela
            vetEnd[i] = endereco;
            return;
        }
        if (i == TabelaDeRepasse::MAXIMO_TABELA) throw overflow_error("Erro: Tabela cheia");
    }
    if ((vetNo[i] == NULL && vetEnd[i] != 0) || (vetNo[i] != NULL && vetEnd[i] == 0))
        throw logic_error("Erro no mapeamento: vetores desalinhados"); //talvez out_of_range, talvez apagar
    vetNo[i] = adjacente;
    vetEnd[i] = endereco;
}

No** TabelaDeRepasse::getAdjacentes() {
    No** adjacentes;
    int quantAdj = this->getQuantidadeDeAdjacentes();
    adjacentes = new No*[quantAdj];
    for (int i = 0; i < quantAdj; i++) adjacentes[i] = vetNo[i];
    return adjacentes;
}

int TabelaDeRepasse::getQuantidadeDeAdjacentes() {
    int contOcupado = 0; //contador de quantas casas ocupadas tem no vetor
    for (int i = 0; i < TabelaDeRepasse::MAXIMO_TABELA; i++) {
        if (vetNo[i] != NULL) contOcupado++;
    }
    return contOcupado;
}

void TabelaDeRepasse::setPadrao(No* padrao) {
    noPadrao = padrao;
}

No* TabelaDeRepasse::getDestino(int endereco) {
    int i;
    int k = -1;
    for (i = 0; i < TabelaDeRepasse::MAXIMO_TABELA; i++) {
        if (endereco == vetEnd[i]) k = i;
    }
    if (k != -1) return vetNo[k];
    else return noPadrao;
}

void TabelaDeRepasse::imprimir() {
    cout << "Os adjascentes sao: " << endl;
    for (int i=0; i<this->getQuantidadeDeAdjacentes(); i++) {
        cout << this->getAdjacentes()[i]->getEndereco() << endl;
    }
    cout << "O padrao e: " << endl;
    cout << noPadrao->getEndereco() << endl;
}
