/*
 eFolio A
 21093 - Programacao por Objetos - 2018-2019
 Aluno: Andre Santo
 Numero: 1502142
*/

#ifndef EFOLIOA_MENU_H
#define EFOLIOA_MENU_H


#include <iostream>
#include <iomanip>
#include <vector>
#include "dados.h"
#include "paciente.h"
#include "validar.h"

class Menu {

public:

    int mostrarMenu(); //mostar o menu principal
    std::vector<Paciente> registarPaciente(std::vector<Paciente> Pacientes); //registar um paciente
    void registarInternamento(); //registar um internamento
    void registarOperacao(); //registar uma operacao
    void registarConsulta(); //registar uma consulta
    void procurarFichaPaciente(std::vector<Paciente> Pacientes); //menu de procura de ficha de paciente
    void mostrarFichaPaciente(Paciente p); //menu para mostrar a ficha de paciente
    void menuEscolhaRelatorioMensal(); //menu para escolha de mes, ano e tipo de relatorio mensal que se quer mostrar
    void mostrarRelatorioMensal(std::vector<Internamento> Internamentos); //menu para mostrar o relatorio mensal de internamentos
    void mostrarRelatorioMensal(std::vector<Operacao> Operacoes); //menu para mostrar o relatorio mensal de operacoes
    void mostrarRelatorioMensal(std::vector<Consulta> Consultas); //menu para mostrar o relatorio mensal de consultas
    std::string escolherAno(); //menu escolher ano
    std::string escolherMes(); //menu escolher mes
    Paciente encontrarPaciente(); //menu para encontrar paciente
    void pausa(); //menu pausar e permitar a visualizacao do conteudo ao utilizador

};



#endif //EFOLIOA_MENU_H
