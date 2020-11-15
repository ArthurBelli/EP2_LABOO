#include <iostream>
#include <string>
#include <stdexcept>
#include "Datagrama.h"
#include "Fila.h"
#include "Hospedeiro.h"
#include "Navegador.h"
#include "No.h"
#include "PersistenciaDeRede.h"
#include "Processo.h"
#include "Rede.h"
#include "Roteador.h"
#include "Segmento.h"
#include "ServidorWeb.h"
#include "TabelaDeRepasse.h"


using namespace std;

void Menu0(int &opcao);
void Menu1(Rede* rede, int &opcao);
void Menu2(Rede* rede, int &tempo, int &opcao);
void Menu3(Rede* rede, int &opcao);

int main() {
    int opcao = 0;
    int tempo = 0;
    string arquivo;
    PersistenciaDeRede* persistencia = new PersistenciaDeRede();
    Rede* rede = new Rede();
    cout << "Digite o nome do arquivo: ";
    cin >> arquivo;
    try {
        rede = persistencia->carregar(arquivo);
    } catch (invalid_argument* e) {
        cout << "Nome de arquivo invalido." << endl;
        opcao = 4;
        delete e;
    }

    while (opcao != 4) {
        if (opcao == 0) Menu0(opcao);
        else if (opcao == 1) Menu1(rede, opcao);
        else if (opcao == 2) Menu2(rede, tempo, opcao);
        else if (opcao == 3) Menu3(rede, opcao);
    }
    //no final tem q excluir tudo as parada que foi declarada com new (lists, vectors, etc)
    return 0;
}

void Menu0(int &opcao) {
    cout << endl << "Simulador de Rede" << endl << "---" << endl << "1) Usar um navegador" << endl
    << "2) Passar tempo" << endl << "3) Alterar TTL" << endl << "4) Sair" << endl << "Esolha uma opcao: ";
    cin >> opcao;
    cout << endl;
}

void Menu1(Rede* rede, int &opcao) {
    int endHosp, portaNav, endWeb, portaWeb;
    bool temEndereco = false, temPorta = false;
    list<Hospedeiro*>* hospedeiros = new list<Hospedeiro*>();
    vector<Processo*>* processos = new vector<Processo*>();
    hospedeiros = rede->getHospedeiros();
    list<Hospedeiro*>::iterator i = hospedeiros->begin();
    vector<Processo*>::iterator j;
    Hospedeiro* hospEscolhido;
    Navegador* n;
    ServidorWeb* s;
    while (i != hospedeiros->end()) {
        cout << "Hospedeiro " << (*i)->getEndereco() << endl;
        processos = (*i)->getProcessos();
        j = processos->begin();
        while (j != processos->end()) {
            n = dynamic_cast<Navegador*>(*j);
            if (n != NULL) {
                cout << "\tNavegador " << n->getPorta() << endl;
            }
            else {
                s = dynamic_cast<ServidorWeb*>(*j);
                cout << "\tServidor Web " << s->getPorta() << endl;
            }
            j++;
        }
        i++;
    }
    cout << endl;
    while(!temEndereco) {
        cout << "Digite o endereco do hospedeiro: ";
        cin >> endHosp;
        i = hospedeiros->begin();
        while (i != hospedeiros->end()) { //verificar se tem esse endereco de hospedeiro
            if ((*i)->getEndereco() == endHosp) { //o pdf n especifica se deveria verificar se existe um navegador nesse hospedeiro mas como isso daria trabalho eu n pus. Depois a gente poe qualquer coisa
                temEndereco = true;
                hospEscolhido = (*i);
            }
            i++;
        }
        if (!temEndereco) cout << "Endereco invalido" << endl;
    }
    processos = hospEscolhido->getProcessos();
    while(!temPorta) {
        cout << "Digite a porta do navegador: ";
        cin >> portaNav;
        j = processos->begin();
        while (j != processos->end()) { //verificar se tem essa porta nos processos
            if ((*j)->getPorta() == portaNav && dynamic_cast<Navegador*>((*j)) != NULL) temPorta = true;
            j++;
        }
        if (!temPorta) cout << "Porta invalida" << endl;
    }
    cout << "Abrir pagina no endereco: ";
    cin >> endWeb; //pode ser que endWeb nao seja o melhor nome, muda se precisar
    cout << "Porta do Servidor Web: ";
    cin >> portaWeb;
    //se todos os valores estiverem ok, vamos mandar um request do navegador para o servidor
    Navegador* nav = dynamic_cast<Navegador*>(hospEscolhido->getProcesso(portaNav));
    nav->abrir(endWeb, portaWeb);
    opcao = 0;
}

void Menu2(Rede* rede, int &tempo, int &opcao) {
    cout << "Quantidade de tempo: ";
    cin >> tempo;
    cout << endl;
    for (int i = 1; i <= tempo; i++) {
        cout << "Instante " << i << endl;
        cout << "---" << endl;
        rede->passarTempo();
    }
    opcao = 0;
}

void Menu3(Rede* rede, int &opcao) {
    int novoPadrao;
    list<Hospedeiro*>* hospedeiros = new list<Hospedeiro*>();
    vector<Processo*>* processos = new vector<Processo*>();
    hospedeiros = rede->getHospedeiros();
    list<Hospedeiro*>::iterator i = hospedeiros->begin();
    vector<Processo*>::iterator j;
    cout << "TTL atual: " << hospedeiros->front()->getProcessos()->front()->getTtlPadrao() << endl; //lol
    cout << "Novo TTL: ";
    cin >> novoPadrao;
    while (i != hospedeiros->end()) {
        processos = (*i)->getProcessos();
        j = processos->begin();
        while (j != processos->end()) {
            (*j)->setTtlPadrao(novoPadrao);
            j++;
        }
        i++;
    }
    opcao = 0;
}
