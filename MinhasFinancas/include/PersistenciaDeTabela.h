#ifndef PERSISTENCIADETABELA_H
#define PERSISTENCIADETABELA_H

#include <stdexcept>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iostream>
#include <locale>
#include <iomanip>

#include "TabelasDeDados.h"

using namespace std;

class PersistenciaDeTabela {
    public:
        PersistenciaDeTabela (TabelasDeDados* td);
        virtual ~PersistenciaDeTabela();
        void inserirValor();
        float getSaldo(); //obtem saldo na conta
       // bool isDivida(); //return false se n deve nada e exibe dividas se for true;
        //bool isDevedores(); //idem divida, mas para devedores;
        void isNovo(string arquivo_caixa); //se a planilha estiver limpa, desenhar um cabecalho para ela
        void printUltimosLancamentos();
        void printUltimosLancamentos(int x);

    private:
        void obterDados();
        TabelasDeDados* td;
        vector<float>* valores;
        vector<string>* datas;
        vector<string>* motivos;
};

#endif // PERSISTENCIADETABELA_H
