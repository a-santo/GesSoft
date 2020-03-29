/*
 eFolio A
 21093 - Programacao por Objetos - 2018-2019
 Aluno: Andre Santo
 Numero: 1502142
*/

#ifndef EFOLIOA_PACIENTE_H
#define EFOLIOA_PACIENTE_H


#include <string>
#include <vector>

class Paciente {

private:

    int id;
    std::string nome;
    std::string nome_dono;
    int telefone;
    std::string morada;
    std::string raca;
    int idade;
    std::string tipo;

public:

    //Constructor
    Paciente();

    //os setters
    void setIdPaciente(int i);
    void setNomePaciente(std::string n);
    void setNomeDonoPaciente(std::string n);
    void setTelefone(int t);
    void setMorada(std::string m);
    void setRaca(std::string r);
    void setIdade(int i);
    void setTipo(std::string t);

    //os getters
    int getIdPaciente();
    std::string getNomePaciente();
    std::string getNomeDonoPaciente();
    int getTelefone();
    std::string getMorada();
    std::string getRaca();
    int getIdade();
    std::string getTipo();

    //Destructor
    ~Paciente();


};

#endif //EFOLIOA_PACIENTE_H
