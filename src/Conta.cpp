#include "Banco.hpp"

Conta::Conta(string nome){
    this->nome = nome;
    this->numero = geraNumero();
    this->saldo = 0;
}

string Conta::geraNumero(){
    string numero = "";
    for(int i = 0; i < 6; i++){
        numero += to_string(rand() % 10);
    }
    return numero;
}