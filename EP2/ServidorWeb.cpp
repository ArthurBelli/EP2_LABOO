#include "ServidorWeb.h"

ServidorWeb::ServidorWeb(int endereco, int porta, Roteador* gateway, string conteudo)
: Processo(endereco, porta, gateway) {
    this->endereco = endereco;
    this->porta = porta;
    this->gateway = gateway;
    this->conteudo = conteudo;
}

ServidorWeb::~ServidorWeb() {}

void ServidorWeb::receber(int origem, Segmento* mensagem) {
    if (mensagem->getDado() == "GET") {
        Segmento* responseSeg = new Segmento(this->porta, mensagem->getPortaDeOrigem(), conteudo);
        Datagrama* responseDat = new Datagrama(this->endereco, origem, getTtlPadrao(), responseSeg);
        gateway->receber(responseDat);
        cout << "ServidorWeb " << getEndereco() << endl;
        cout << "\tDevolvendo mensagem para " << origem << ":" << mensagem->getPortaDeOrigem() << endl;
    }
}
