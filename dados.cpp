/*
 eFolio A
 21093 - Programacao por Objetos - 2018-2019
 Aluno: Andre Santo
 Numero: 1502142
*/

#include "dados.h"

void Dados::guardarDados(Paciente p) {

    std::ofstream ficheiro;

    //abrir o ficheiro em modo append, para nao substituir os dados já existentes no ficheiro
    ficheiro.open ("pacientes.txt", std::ios::app);

    if(!ficheiro)
    {
        std::cerr << "Erro! Não foi possivel aceder ao ficheiro 'pacientes.txt'!" << std::endl;
        exit(EXIT_FAILURE);

    }

    //guardar os dados, separados por ";"
    ficheiro << p.getIdPaciente() << ";" << p.getNomePaciente() << ";" << p.getNomeDonoPaciente() << ";";
    ficheiro << p.getTelefone() << ";" << p.getMorada() << ";" << p.getRaca() << ";" << p.getIdade() << ";";
    ficheiro << p.getTipo() << "\n";

    ficheiro.close();

}

void Dados::guardarDados(Internamento i) {

    std::ofstream ficheiro;

    ficheiro.open ("internamentos.txt", std::ios::app);

    if(!ficheiro)
    {
        std::cerr << "Erro! Não foi possivel aceder ao ficheiro 'internamentos.txt'!" << std::endl;
        exit(EXIT_FAILURE);

    }

    ficheiro << i.getRazao() << ";" << i.getNomeMedico() << ";" << i.getData() << ";";
    ficheiro << i.getDuracao() << ";" << i.getIdPaciente() << ";" << i.getNomePaciente() << "\n";
    ficheiro.close();

}

void Dados::guardarDados(Operacao o) {

    std::ofstream ficheiro;

    ficheiro.open ("operacoes.txt", std::ios::app);

    if(!ficheiro)
    {
        std::cerr << "Erro! Não foi possivel aceder ao ficheiro 'operacoes.txt'!" << std::endl;
        exit(EXIT_FAILURE);

    }

    ficheiro << o.getRazao() << ";" << o.getNomeMedico() << ";" << o.getData() << ";";
    ficheiro << o.getHora() << ";" << o.getIdPaciente() << ";" << o.getNomePaciente() << "\n";
    ficheiro.close();

}

void Dados::guardarDados(Consulta c) {

    std::ofstream ficheiro;

    ficheiro.open ("consultas.txt", std::ios::app);

    if(!ficheiro)
    {
        std::cerr << "Erro! Não foi possivel aceder ao ficheiro 'consultas.txt'!" << std::endl;
        exit(EXIT_FAILURE);

    }

    ficheiro << c.getRazao() << ";" << c.getNomeMedico() << ";" << c.getData() << ";";
    ficheiro << c.getHora() << ";" << c.getIdPaciente() << ";" << c.getNomePaciente() << "\n";
    ficheiro.close();

}

std::vector<Paciente> Dados::lerPacientes() {

    int i; //contador de palavras em cada linha separadas por ;
    std::string linha;
    std::string s;
    std::vector<Paciente> p;

    std::ifstream ficheiro;
    ficheiro.open("pacientes.txt");

    //se falhar, terminar
    if(!ficheiro)
    {
        std::cerr << "Erro! Não foi possivel aceder ao ficheiro 'pacientes.txt'!" << std::endl;
        exit(EXIT_FAILURE);

    }

    //ler o ficheiro, linha a linha
    while(getline(ficheiro, linha)) {
        i = 0;
        std::stringstream ss(linha);

        //Classe "Paciente" temporaria para alojar os dados recolhidos de um paciente
        Paciente temp = {};

        //ler cada frase/palavra separada por ';'
        while(getline(ss, s, ';')) {

            //se for a primeira, é o id de paciente...
            if(i==0) {

                //id
                temp.setIdPaciente(std::stoi(s));

              //o segundo é o nome, e por aí fora...
            } else if(i==1) {

                //nome
                temp.setNomePaciente(s);

            } else if(i==2) {

                //dono
                temp.setNomeDonoPaciente(s);

            } else if(i==3) {

                //telefone
                temp.setTelefone(std::stoi(s));

            } else if(i==4) {

                //morada
                temp.setMorada(s);

            } else if(i==5) {

                //raça
                temp.setRaca(s);

            } else if(i==6) {

                //idade
                temp.setIdade(std::stoi(s));

            } else if(i==7) {

                //tipo
                temp.setTipo(s);

            }

            i++;

        }

        //alojar os dados deste paciente no vetor de pacientes
        p.push_back(temp);

    }

    //fechar o ficheiro
    ficheiro.close();

    //devolver pacientes
    return p;

}

std::vector<Internamento> Dados::lerInternamentos() {

    int i;

    std::string linha;
    std::string s;
    std::vector<Internamento> Intern;

    std::ifstream ficheiro;
    ficheiro.open("internamentos.txt");

    if(!ficheiro)
    {
        std::cerr << "Erro! Não foi possivel aceder ao ficheiro 'internamentos.txt'!" << std::endl;
        exit(EXIT_FAILURE);

    }

    while(getline(ficheiro, linha)) {
        i = 0;
        std::stringstream ss(linha);

        Internamento temp;

        while(getline(ss, s, ';')) {

            if(i==0) {

                //razao
                temp.setRazao(s);

            } else if(i==1) {

                //nome medico
                temp.setNomeMedico(s);

            } else if(i==2) {

                //data
                temp.setData(s);

            } else if(i==3) {

                //duração
                temp.setDuracao(std::stoi(s));

            } else if(i==4) {

                //id do paciente
                temp.setIdPaciente(std::stoi(s));

            } else if(i==5) {

                //nome do paciente
                temp.setNomePaciente(s);

            }

            i++;

        }

        Intern.push_back(temp);

    }

    ficheiro.close();

    return Intern;

}

std::vector<Operacao> Dados::lerOperacoes() {

    int i;

    std::string linha;
    std::string s;
    std::vector<Operacao> Operacoes;

    std::ifstream ficheiro;
    ficheiro.open("operacoes.txt");

    if(!ficheiro)
    {
        std::cerr << "Erro! Não foi possivel aceder ao ficheiro 'operacoes.txt'!" << std::endl;
        exit(EXIT_FAILURE);

    }

    while(getline(ficheiro, linha)) {
        i = 0;
        std::stringstream ss(linha);

        Operacao temp;

        while(getline(ss, s, ';')) {

            if(i==0) {

                //razao
                temp.setRazao(s);

            } else if(i==1) {

                //nome medico
                temp.setNomeMedico(s);

            } else if(i==2) {

                //data
                temp.setData(s);

            } else if(i==3) {

                //hora
                temp.setHora(s);

            } else if(i==4) {

                //id do paciente
                temp.setIdPaciente(std::stoi(s));

            } else if(i==5) {

                //nome do paciente
                temp.setNomePaciente(s);

            }

            i++;

        }

        Operacoes.push_back(temp);

    }

    ficheiro.close();

    return Operacoes;

}

std::vector<Consulta> Dados::lerConsultas() {

    int i;

    std::string linha;
    std::string s;
    std::vector<Consulta> Consultas;

    std::ifstream ficheiro;
    ficheiro.open("consultas.txt");

    if(!ficheiro)
    {
        std::cerr << "Erro! Não foi possivel aceder ao ficheiro 'consultas.txt'!" << std::endl;
        exit(EXIT_FAILURE);

    }

    while(getline(ficheiro, linha)) {
        i = 0;
        std::stringstream ss(linha);

        Consulta temp;

        while(getline(ss, s, ';')) {

            if(i==0) {

                //razao
                temp.setRazao(s);

            } else if(i==1) {

                //nome medico
                temp.setNomeMedico(s);

            } else if(i==2) {

                //data
                temp.setData(s);

            } else if(i==3) {

                //hora
                temp.setHora(s);

            } else if(i==4) {

                //id do paciente
                temp.setIdPaciente(std::stoi(s));

            } else if(i==5) {

                //nome do paciente
                temp.setNomePaciente(s);

            }

            i++;

        }

        Consultas.push_back(temp);

    }

    ficheiro.close();

    return Consultas;

}

Paciente Dados::procurarPaciente(std::vector<Paciente> Pacientes, std::string nome) {

    //ler cada paciente da lista de pacientes ate encontrar o paciente que se pretende (nome)
    for(auto &i : Pacientes) {

        if(i.getNomePaciente() == nome)
            return i;

    }

    Paciente p;

    return p;

}

Paciente Dados::procurarPaciente(std::vector<Paciente> Pacientes, int id) {

    //ler cada paciente da lista de pacientes ate encontrar o paciente que se pretende (id)
    for(auto &i : Pacientes) {

        if(i.getIdPaciente() == id)
            return i;

    }

    Paciente p;

    return p;


}

std::vector<Internamento> Dados::obterInternamentos(int id_paciente) {

    std::vector<Internamento> InternamentosTodos; //a lista de todos os internamentos
    std::vector<Internamento> InternamentosPaciente; //a lista de todos os internamentos deste paciente
    Dados d;

    InternamentosTodos = d.lerInternamentos(); //ler todos os internamentos

    //ciclo de todos os internamentos para encontrar os internamentos referentes a este paciente
    for(auto &i : InternamentosTodos) {

        if(i.getIdPaciente() == id_paciente)
            InternamentosPaciente.push_back(i); //se for deste paciente, colocar no vetor

    }

    return InternamentosPaciente;


}

std::vector<Operacao> Dados::obterOperacoes(int id_paciente) {

    std::vector<Operacao> OperacoesTodos; //a lista de todos as operacoes
    std::vector<Operacao> OperacoesPaciente; //a lista de todas as operacoes deste paciente
    Dados d;

    OperacoesTodos = d.lerOperacoes(); //ler todas as operações

    for(auto &i : OperacoesTodos) {

        if(i.getIdPaciente() == id_paciente) //encontrar as operacoes deste paciente
            OperacoesPaciente.push_back(i);

    }

    return OperacoesPaciente;

}

std::vector<Consulta> Dados::obterConsultas(int id_paciente) {

    std::vector<Consulta> ConsultasTodos; //a lista de todas as consultas
    std::vector<Consulta> ConsultasPaciente; //a lista de consultas deste paciente
    Dados d;

    ConsultasTodos = d.lerConsultas(); //ler todas as consultas

    for(auto &i : ConsultasTodos) {

        if(i.getIdPaciente() == id_paciente) //encontrar as constulas deste paciente
            ConsultasPaciente.push_back(i);

    }

    return ConsultasPaciente;

}

std::vector<Internamento> Dados::filtrarInternamentos(std::string ano, std::string mes) {

    Dados d;

    std::vector<Internamento> todosInternamentos; //todos os internamentos
    std::vector<Internamento> filtradosInternamentos; //para alojar os internamentos do mes e ano dados

    std::string a; //ano
    std::string m; //mes

    todosInternamentos = d.lerInternamentos();

    for(auto &i : todosInternamentos) {

        m = i.getData().substr(3, 2); //extrair o mês da data
        a = i.getData().substr(6, 4); //extrair o ano da data

        if(m == mes && a == ano) {

            //é do ano e mês que procuramos, adicionar ao vetor...
            filtradosInternamentos.push_back(i);

        }

    }

    return filtradosInternamentos;

}

std::vector<Operacao> Dados::filtrarOperacoes(std::string ano, std::string mes) {

    Dados d;

    std::vector<Operacao> todasOperacoes; //todas as operações
    std::vector<Operacao> filtradasOperacoes; //para alojar as operações do mes e ano providenciado

    std::string a; //ano
    std::string m; //mes

    todasOperacoes = d.lerOperacoes();

    for(auto &i : todasOperacoes) {

        m = i.getData().substr(3, 2);
        a = i.getData().substr(6, 4);

        if(m == mes && a == ano) {

            filtradasOperacoes.push_back(i);

        }

    }

    return filtradasOperacoes;

}

std::vector<Consulta> Dados::filtrarConsultas(std::string ano, std::string mes) {

    Dados d;

    std::vector<Consulta> todasConsultas;
    std::vector<Consulta> filtradasConsultas;

    std::string a; //ano
    std::string m; //mes

    todasConsultas = d.lerConsultas();

    for(auto &i : todasConsultas) {

        m = i.getData().substr(3, 2);
        a = i.getData().substr(6, 4);

        if(m == mes && a == ano) {

            filtradasConsultas.push_back(i);

        }

    }

    return filtradasConsultas;

}