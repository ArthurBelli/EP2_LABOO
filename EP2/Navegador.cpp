#include "Navegador.h"

Navegador::Navegador(int endereco, int porta, Roteador* gateway): Processo(endereco, porta, gateway) {
    conteudo = ""; //inicializacao das variaveis com valores neutros
    requestEnd = -1;
}

Navegador::~Navegador() {}

void Navegador::receber(int origem, Segmento* mensagem) {
    cout << "Navegador " << this->getPorta() << endl;
    if (origem == requestEnd) {
        conteudo = mensagem->getDado();
        cout << "\tRecebido de " << origem << ":" << mensagem->getPortaDeOrigem()
        << ": " << mensagem->getDado() << endl;
        requestEnd = -1; //deixa de esperar um segmento
    }else {
        cout << "\tMensagem ignorada " << origem << ":" << mensagem->getPortaDeOrigem()
        << ": " << mensagem->getDado() << endl;
    }
}

void Navegador::abrir(int endereco, int porta) {
    requestEnd = endereco; //agora o navegador sabe de que endereco ele esta esperando a resposta
    Segmento* requestSeg = new Segmento(this->porta, porta, "GET");
    Datagrama* requestDat = new Datagrama(this->endereco, endereco, this->getTtlPadrao(), requestSeg);
    conteudo = "";
    gateway->receber(requestDat);
}

void Navegador::abrir(int endereco) {
    requestEnd = endereco;
    Segmento* requestSeg = new Segmento(this->porta, 80, "GET");
    Datagrama* requestDat = new Datagrama(this->endereco, endereco, this->getTtlPadrao(), requestSeg);
    conteudo = "";
    gateway->receber(requestDat);
}

string Navegador::getConteudo() {
    return conteudo;
}
