#ifndef TABELASDEDADOS_H
#define TABELASDEDADOS_H

#include <string>
#include <stdexcept>

using namespace std;

class TabelasDeDados {
    public:
        TabelasDeDados();
        virtual ~TabelasDeDados();
        string getArqDividasDevedores();
        string getArqTransacoes();
        bool setArqTransacoes(string arquivo_caixa);
        bool setArqDividasDevedores(string dividas_devedores);

    private:
        string arquivo_caixa;
        string dividas_devedores;
};

#endif // TABELASDEDADOS_H
