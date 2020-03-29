/*
 eFolio A
 21093 - Programacao por Objetos - 2018-2019
 Aluno: Andre Santo
 Numero: 1502142
*/

#include "dados.h"
#include "paciente.h"
#include "menu.h"

int main() {

    Dados d; // Classe Dados
    Menu m; // Classe Menu
    int opcao;

    //'std::vector' para alojar os dados dos pacientes
    std::vector<Paciente> Pacientes = d.lerPacientes();;
    //'std::vector' para alojar os dados dos internamentos, operacoes e consultas
    std::vector<Internamento> Internamentos = d.lerInternamentos();
    std::vector<Operacao> Operacoes = d.lerOperacoes();
    std::vector<Consulta> Consultas = d.lerConsultas();

    //mostrar o menu principal ao utilizador ate que escolha 0
    do {

        opcao = m.mostrarMenu();

        if(opcao == 1)
            Pacientes = m.registarPaciente(Pacientes);
        if(opcao == 2)
            m.registarInternamento();
        if(opcao == 3)
            m.registarOperacao();
        if(opcao == 4)
            m.registarConsulta();
        if(opcao == 5)
            m.procurarFichaPaciente(Pacientes);
        if(opcao == 6) {
            Internamentos = d.lerInternamentos(); //ler todos os internamentos
            m.mostrarRelatorioMensal(Internamentos);
        }
        if(opcao == 7) {
            Operacoes = d.lerOperacoes(); //ler todas as operacoes
            m.mostrarRelatorioMensal(Operacoes);
        }
        if(opcao == 8){
            Consultas = d.lerConsultas(); //ler todas as consultas
            m.mostrarRelatorioMensal(Consultas);
        }


    }
    while(opcao != 0);

    std::cout << std::endl;
    std::cout << "Votos de um excelente dia! Ate a proxima!" << std::endl;

    return 0;

}