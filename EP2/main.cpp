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

int main()
{
    Rede* rede = new Rede();
    PersistenciaDeRede* p1 = new PersistenciaDeRede();
    try {
        rede = p1->carregar("rede1.txt");
        rede->imprimir();
        Hospedeiro* h5 = dynamic_cast<Hospedeiro*>(rede->getNo(5));
        ServidorWeb* w1 = dynamic_cast<ServidorWeb*>(h5->getProcesso(1005));
        w1->imprimir();
    } catch (invalid_argument* e) {
        cout << e->what() << endl;
        delete e;
    }
    /*Rede* rede = new Rede();
    Segmento* s1 = new Segmento(1,1000,"s1");
    Segmento* s2 = new Segmento(2,2000,"s2");
    Segmento* s3 = new Segmento(3,3000,"s3");
    Segmento* s4 = new Segmento(4,4000,"s4");
    Datagrama* d1 = new Datagrama(1,5,5,s1);
    Datagrama* d2 = new Datagrama(1,4,5,s2);
    Datagrama* d3 = new Datagrama(2,3,5,s3);
    Datagrama* d4 = new Datagrama(2,3,5,s4);
    Roteador* r1 = new Roteador(1);
    Roteador* r2 = new Roteador(2);
    Hospedeiro* h3 = new Hospedeiro(3, r1);
    Roteador* r4 = new Roteador(4);
    Hospedeiro* h5 = new Hospedeiro(5, r2);
    TabelaDeRepasse* t1 = r1->getTabela();
    Fila* f = r1->getFila();
    f->enqueue(d1);
    f->imprimir();
    cout << endl;
    f->enqueue(d2);
    f->imprimir();
    cout << endl;
    f->enqueue(d3);
    f->imprimir();
    cout << endl;
    f->imprimir();
    cout << endl;
    f->dequeue();
    f->imprimir();
    cout << endl;
    f->enqueue(d4);
    f->imprimir();*/
    return 0;
}
