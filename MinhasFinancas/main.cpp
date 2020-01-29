#include <iostream>
#include <string>
#include <stdexcept> //exceções - que inclusive preciso colocar
#include <fstream>   // persistencia
#include <cmath>     // calculos matematicos
#include <vector>
#include <cstdlib>   // para usar a funcao system(), que permite apagar texto da tela do console
#include <iomanip>   //para aceitar setw(x) - ou seja, alinhar as strings q foram imprimidas pelos cout
#include "PersistenciaDeTabela.h"
#include "TabelasDeDados.h"
#include "InterfacePrograma.h"
#include <locale>    //para setar o teclado em português e aceitar acentos, ç, etc

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    TabelasDeDados* td = new TabelasDeDados(); // arquivos de default
    PersistenciaDeTabela* pTabela = new PersistenciaDeTabela(td);
    InterfacePrograma* ip = new InterfacePrograma();

    cout << "Finanças do Seiji" << endl;

    bool iterar = true;

    while(iterar) {

        ip->exibirOpcoes();

        int number;
        cin >> number;

        if(number == 1) {
            char simNao = 's';

            if(simNao == 's') {
                cout << endl << "Informe os dados do saque/depósito: " << endl;

                while(simNao == 's') {
                    pTabela->inserirValor();
                    cout << "inserir mais valores? (s/n) ";
                    cin >> simNao;
                    cout << endl;
                    if(simNao == 'n') {
                        cout <<"inserção de valores encerrada." << endl << endl;
                    }
                    system("CLS");
                }
            }
        } else if (number == 2) {
            cout << "Total: R$ " << pTabela->getSaldo() << endl << endl;
            iterar = ip->continuarOuN();
        } else if(number == 3) {
            pTabela->printUltimosLancamentos();
            iterar = ip->continuarOuN();
        } else if(number == 4) {
            int x;
            cout << endl << "Quantos últimos lançamentos você quer ver? ";
            cin >> x;
            pTabela->printUltimosLancamentos(x);

            iterar = ip->continuarOuN();
        } else if (number == 5) {
            cout << "Em construção" << endl;  //pensar dps o q colocar aqui

            iterar = ip->continuarOuN();
        } else {
            iterar = false;
            system("CLS");
            cout << "Operação encerrada. Obrigado por utilizar o serviço!" << endl;
        }
    }
    return 0;
}
