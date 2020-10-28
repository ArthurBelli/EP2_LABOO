#ifndef PERSISTENCIADEREDE_H
#define PERSISTENCIADEREDE_H
#include "Rede.h"
#include <string>
using namespace std;

class PersistenciaDeRede {
 public:
    PersistenciaDeRede();
    virtual ~PersistenciaDeRede();
    virtual Rede* carregar(string arquivo);


    private:
        Rede* rede;
};

#endif // PERSISTENCIADEREDE_H
