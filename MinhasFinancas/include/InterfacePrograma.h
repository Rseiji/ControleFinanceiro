#ifndef INTERFACEPROGRAMA_H
#define INTERFACEPROGRAMA_H

#include <iostream>
#include <cstdlib>
#include <locale>

using namespace std;

class InterfacePrograma {
    public:
        InterfacePrograma();
        virtual ~InterfacePrograma();
        void exibirOpcoes();
        bool continuarOuN();
        //void opcoesAvancadas();

    private:
        bool firstPrint;
};

#endif // INTERFACEPROGRAMA_H
