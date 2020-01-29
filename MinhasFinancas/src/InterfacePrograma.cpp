#include "InterfacePrograma.h"

InterfacePrograma::InterfacePrograma() {
    firstPrint = true;
}

InterfacePrograma::~InterfacePrograma() {
    //dtor
}

void InterfacePrograma::exibirOpcoes() {
    if(firstPrint == true)
        cout << "O que deseja fazer?" << endl;
    else
        cout << "O que deseja fazer agora?" << endl;

    cout << "1) Inserir valor" << endl;
    cout << "2) Consultar saldo" << endl;
    cout << "3) Últimos 10 lançamentos" << endl;
    cout << "4) Últimos x lançamentos" << endl;
    cout << "5) Opções avançadas" << endl;
    cout << "6) Sair" << endl;
    cout << "Tecle 1, 2, 3, 4 ou 5 de acordo com as opções acima: ";
    firstPrint = false;
}

bool InterfacePrograma::continuarOuN() {
    cout << "O que deseja fazer agora?" << endl;
    cout << "1) Sair" << endl;
    cout << "2) Continuar utilizando o serviço" << endl;
    cout << "Tecle 1 ou 2 de acordo com as opções acima: ";
    int simOuNao;
    cin >> simOuNao;
    cout << endl;
    if(simOuNao == 1) {
        system("CLS");
        cout << "Operação encerrada. Obrigado por utilizar o serviço!" << endl;
        return false;
    }
    else {
        //cout << string(50, '\n');
        system("CLS");  //apaga o que ja foi escrito ate entao na tela. Precisa de #include <cstdlib>
        return true;    //Usar essa funcao eh ma pratica, seila pq. O ideal eh usar cout \n varias vezes.
    }                   //porem para encaixar o texto no console de forma mais bonita eu estou usando system msm!
}

