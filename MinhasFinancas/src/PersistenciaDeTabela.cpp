#include "PersistenciaDeTabela.h"

PersistenciaDeTabela::PersistenciaDeTabela(TabelasDeDados* td) {
    this->td = td;
}

PersistenciaDeTabela::~PersistenciaDeTabela() {
    //dtor
}

void PersistenciaDeTabela::inserirValor() {
    ofstream output;
    output.open(td->getArqTransacoes(), ios_base::app);

        isNovo(td->getArqTransacoes());

        cout << "Informe a data: ";
            string data;
            cin >> data;
            output << data << "\t";

        cout << "Informe o motivo: ";
            string reason;
            cin.ignore();
            getline(cin, reason);
            output << reason << "\t";

        cout << "Agora, o valor: ";
            float valor;
            cin >> valor;
            output << valor << "\n";

    output.close();

    cout << endl << "Processo concluído!" << endl << endl;
}

float PersistenciaDeTabela::getSaldo() {
    obterDados();

    cout << endl;

    float saldo = 0;
    for(int i = 0; i < valores->size(); i++) {
        saldo += valores->at(i);
    }
    return saldo;
}

void PersistenciaDeTabela::isNovo (string arquivo_caixa) {
    ifstream input;
    input.open(arquivo_caixa);

        string primeiraCelula;
        input >> primeiraCelula;

        if(input.fail()) {
            input.close();

            ofstream output;
            output.open(arquivo_caixa, ios_base::app);
                output << "Movimentações financeiras\n";
                output << "Data" << "\t" << "Descrição" << "\t" << "Valor" << "\n";
            output.close();
        } else input.close();
}

void PersistenciaDeTabela::obterDados() {
    valores = new vector<float>;
    datas = new vector<string>;
    motivos = new vector<string>;

    ifstream input;
    input.open(td->getArqTransacoes());
        string cabecalho;

        input >> cabecalho;
        input >> cabecalho;
        input >> cabecalho;
        input >> cabecalho;
        input >> cabecalho;

        string data;
        string motivo;
        float valor;

        while(!input.eof()) {
            input >> data;
            if(input.eof())
                break;
            datas->push_back(data);
            input.ignore();
            getline(input, motivo,'\t');
            motivos->push_back(motivo);

            input >> valor;
            valores->push_back(valor);
        }
    input.close();
}

void PersistenciaDeTabela::printUltimosLancamentos() {  //falta alinhar colunas
    obterDados();
    cout << endl;
    cout << "Os 10 últimos lançamentos: " << endl;
    cout << setw(10) << left << "DATA";
    cout << setw(30) << left << "MOTIVO";
    cout << setw(10) << left << "VALOR" << endl;

    if(valores->size() <= 10) {
        for(int i = 0; i < valores->size(); i++) {
            cout << setw(10) << left << datas->at(i);
            cout << setw(30) << left << motivos->at(i);
            cout << setw(10) << left << valores->at(i) << endl;
        }
        if(valores->size() < 10)
            cout << "OBS: há menos que dez valores pois não há dez lancamentos." << endl;
        cout << endl;
    } else { //if valores->size > 10
        for(int i = valores->size() - 10; i < valores->size(); i++) {
            cout << setw(10) << left << datas->at(i);
            cout << setw(30) << left << motivos->at(i);
            cout << setw(10) << left << valores->at(i) << endl;
        }
        cout << endl;
    }
}

void PersistenciaDeTabela::printUltimosLancamentos(int x) {
    obterDados();
    cout << endl;
    cout << "Os últimos " << x << " lançamentos: " << endl << endl;
    cout << "DATA" << "\t" << "MOTIVO" << "\t" << "VALOR" << endl;

    for(int i = valores->size() - x; i < valores->size(); i++)
        cout << datas->at(i) << "\t" << motivos->at(i) << "\t" <<valores->at(i) << endl;
    cout << endl;
}
