/*
 eFolio A
 21093 - Programacao por Objetos - 2018-2019
 Aluno: Andre Santo
 Numero: 1502142
*/

#ifndef EFOLIOA_PPO_INTERNACOES_H
#define EFOLIOA_PPO_INTERNACOES_H

#include <string>

class Motivo {

private:

    std::string razao;
    std::string nome_medico;
    std::string data;
    int id_paciente;
    std::string nome_paciente;

public:

    //Constructor
    Motivo();

    //getters
    std::string getRazao();
    std::string getNomeMedico();
    std::string getData();
    int getIdPaciente();
    std::string getNomePaciente();

    //setters
    void setRazao(std::string ra);
    void setNomeMedico(std::string nm);
    void setData(std::string da);
    void setIdPaciente(int id);
    void setNomePaciente(std::string np);

    //Destructor
    ~Motivo();

};

class Internamento : public Motivo {

private:

    int duracao;

public:

    Internamento();

    int getDuracao();

    void setDuracao(int du);

    ~Internamento();

};

class Operacao : public Motivo {

private:

    std::string hora;

public:

    Operacao();

    std::string getHora();

    void setHora(std::string h);

    ~Operacao();


};

class Consulta : public Operacao {

public:

    Consulta();
    ~Consulta();

};


#endif //EFOLIOA_PPO_INTERNACOES_H
