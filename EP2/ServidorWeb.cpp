#include "ServidorWeb.h"

ServidorWeb::ServidorWeb(int endereco, int porta, Roteador* gateway, string conteudo)
: Processo(endereco, porta, gateway) {
    this->conteudo = conteudo;
}

ServidorWeb::~ServidorWeb() {}

void ServidorWeb::receber(int origem, Segmento* mensagem) {
    Segmento* responseSeg = new Segmento(this->porta, origem, conteudo);
    Datagrama* responseDat = new Datagrama(this->endereco, origem, getTtlPadrao(), responseSeg);
    gateway->receber(responseDat);
}
