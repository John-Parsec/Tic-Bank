#ifndef BANCO.HPP
#define BANCO.HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Data{
    private:
        tm* data;

    public:
        Data();
        Data(int dia, int mes, int ano);
        tm* getData();
        void setData(int dia, int mes, int ano);
        string toString();

        bool operator<(Data* data);
        bool operator<=(Data* data);
        bool operator>(Data* data);
        bool operator>=(Data* data);
        bool operator==(Data* data);
        void operator=(Data* data);

        static Data dataAtual();
};

class Transacao{
    private:
        static int id;
        Data data;
        string descricao;
        double valor;

    public:
        Transacao(int id, Data data, string descricao, double valor);
        int getId();
        Data getData();
        string getDescricao();
        double getValor();

        void setData(Data data);
        void setDescricao(string descricao);
        void setValor(double valor);
};

int Transacao::id = 0;

class Conta{
    private:

    protected:
        string nome;
        string numero;
        double saldo;
        vector<Transacao> transacoes;

        string geraNumero();

    public:
        Conta(string nome, double saldo); //saldo default = 0
        
        virtual string getNome();
        virtual string getNumero();
        virtual double getSaldo();
        virtual vector<Transacao> getTransacoes();
        virtual Transacao getTransacaoById();   //retorna uma transacao pelo id

        virtual void setNome(string nome);
        virtual void setNumero(string numero);
        virtual void setSaldo(double saldo);

        virtual void addTransacao(Transacao transacao);
        virtual void deposito(double valor); //todo deposito add uma transacao
        virtual void saque(double valor);  //todo saque add uma transacao
        virtual void extrato();

        //Metodos estaticos
        static void deposito(string numeroConta, double valor); //todo deposito add uma transacao
        static void saque(string numeroConta, double valor);  //todo saque add uma transacao
        static void extrato(string numeroConta);
};

class ContaCorrente : public Conta{
    private:

    public:
        ContaCorrente(string nome, double saldo);
};

class ContaCorrenteL : public Conta{
    private:
        double limite;

    public:
        ContaCorrenteL(string nome, double saldo, double limite);
        double getLimite();
        void setLimite(double limite);
};

class ContaPoupanca : public Conta{
    private:
        Data aniversario;

    public:
        ContaPoupanca(string nome, double saldo, Data aniversario);
        Data getAniversario();
        void setAniversario(Data aniversario);
};

#endif