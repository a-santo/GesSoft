/*
 eFolio A
 21093 - Programacao por Objetos - 2018-2019
 Aluno: Andre Santo
 Numero: 1502142
*/

#ifndef EFOLIOA_GUARDARDADOS_H
#define EFOLIOA_GUARDARDADOS_H


#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "paciente.h"
#include "motivo.h"

class Dados {

public:

    std::vector<Paciente> lerPacientes(); //lê os dados do ficheiro "paciente.txt"
    std::vector<Internamento> lerInternamentos(); //lê os dados do ficheiro "internamentos.txt"
    std::vector<Operacao> lerOperacoes(); //lê os dados do ficheiro "operacoes.txt"
    std::vector<Consulta> lerConsultas(); //lê os dados do ficheiro "consultas.txt"

    std::vector<Internamento> obterInternamentos(int id_paciente); //devolve os internamentos por id de paciente
    std::vector<Operacao> obterOperacoes(int id_paciente); //devolve as operacoes por id de paciente
    std::vector<Consulta> obterConsultas(int id_paciente); //devolve as consultas por id de paciente

    void guardarDados(Paciente p); //guardar um paciente
    void guardarDados(Internamento i); //guardar um internamento
    void guardarDados(Operacao o); //guardar uma operação
    void guardarDados(Consulta c); //salva os dados das consultas

    Paciente procurarPaciente(std::vector<Paciente> Pacientes, std::string nome); //procurar paciente por nome
    Paciente procurarPaciente(std::vector<Paciente> Pacientes, int id); //procurar paciente por id

    std::vector<Internamento> filtrarInternamentos(std::string ano, std::string mes); //filtrar internamentos por ano/mes
    std::vector<Operacao> filtrarOperacoes(std::string ano, std::string mes); //filtrar operacoes por ano/mes
    std::vector<Consulta> filtrarConsultas(std::string ano, std::string mes); //filtrar consultas por ano/mes

};


#endif //EFOLIOA_GUARDARDADOS_H
