#include "TabelasDeDados.h"

TabelasDeDados::TabelasDeDados() {
    arquivo_caixa = "DadosConta.byseiji";
    dividas_devedores = "DividasEDevedores.xlsl";
}

TabelasDeDados::~TabelasDeDados() {
    //dtor
}

string TabelasDeDados::getArqDividasDevedores() {
    return dividas_devedores;
}

string TabelasDeDados::getArqTransacoes() {
    return arquivo_caixa;
}

bool TabelasDeDados::setArqTransacoes(string arquivo_caixa) {
    this->arquivo_caixa = arquivo_caixa;
    return true; //dps tem q add as condicoes
}

bool TabelasDeDados::setArqDividasDevedores(string dividas_devedores) {
    this->dividas_devedores = dividas_devedores;
    return true;  //qq coisa muda
}
