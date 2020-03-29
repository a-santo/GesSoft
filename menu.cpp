/*
 eFolio A
 21093 - Programacao por Objetos - 2018-2019
 Aluno: Andre Santo
 Numero: 1502142
*/

#include "menu.h"

int Menu::mostrarMenu() {

    int opcao;

    std::cout << std::endl;
    std::cout << "#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#" << std::endl;
    std::cout << "#                                                     #" << std::endl;
    std::cout << "#             Arco do Cego - GesSoft 0.1              #" << std::endl;
    std::cout << "#                                                     #" << std::endl;
    std::cout << "#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#" << std::endl;
    std::cout << "#                                                     #" << std::endl;
    std::cout << "#             Por favor, escolha uma opcao            #" << std::endl;
    std::cout << "#                                                     #" << std::endl;
    std::cout << "#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#" << std::endl;
    std::cout << "#                                                     #" << std::endl;
    std::cout << "# 1 - Registar paciente                               #" << std::endl;
    std::cout << "# 2 - Registar internamento                           #" << std::endl;
    std::cout << "# 3 - Registar operacao                               #" << std::endl;
    std::cout << "# 4 - Registar consulta                               #" << std::endl;
    std::cout << "# 5 - Visualizar ficha de paciente                    #" << std::endl;
    std::cout << "# 6 - Visualizar lista mensal de internamentos        #" << std::endl;
    std::cout << "# 7 - Visualizar lista mensal de operacoes            #" << std::endl;
    std::cout << "# 8 - Visualizar lista mensal de consultas            #" << std::endl;
    std::cout << "# --------------------------------------------------- #" << std::endl;
    std::cout << "# 0 - Sair                                            #" << std::endl;
    std::cout << "#                                                     #" << std::endl;
    std::cout << "#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#" << std::endl;
    std::cout << std::endl;
    std::cout << "Digite a sua opcao: ";

    std::cin >> opcao;
    std::cin.ignore(); //ignorar o \n

    return opcao;

}

std::vector<Paciente> Menu::registarPaciente(std::vector<Paciente> Pacientes) {

    Paciente p;
    std::string nome_p, nome_dono, morada, raca, tipo;
    int telefone, idade;

    Validar v; //para validar dados

    Dados d; //para escrever os dados os paciente a registar

    std::cout << std::endl;
    std::cout << "########################################################" << std::endl;
    std::cout << "#                 Registar um paciente                 #" << std::endl;
    std::cout << "########################################################" << std::endl;
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Nome: ";
    getline(std::cin, nome_p);
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Nome do dono: ";
    getline(std::cin, nome_dono);
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Numero de telefone: ";
    std::cin >> telefone;
    std::cin.ignore();
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Morada: ";
    getline(std::cin, morada);
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Raca: ";
    getline(std::cin, raca);
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Idade: ";
    std::cin >> idade;
    std::cin.ignore();
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Tipo de animal (cao ou gato): ";
    getline(std::cin, tipo);
    tipo = v.tipoAnimal(tipo); //verificar se cao ou gato
    std::cout << "--------------------------------------------------------" << std::endl;

    //registar os dados do paciente
    p.setIdPaciente(Pacientes.back().getIdPaciente()+1); //obter o id do ultimo paciente registado e adicionar mais um (auto incrementação)
    p.setNomePaciente(nome_p);
    p.setNomeDonoPaciente(nome_dono);
    p.setTelefone(telefone);
    p.setMorada(morada);
    p.setRaca(raca);
    p.setIdade(idade);
    p.setTipo(tipo);

    //escrever os dados do paciente no ficheiro
    d.guardarDados(p);

    std::cout << "Paciente registado com sucesso!" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    Pacientes = d.lerPacientes();

    return Pacientes;

}

void Menu::registarInternamento() {

    Internamento i;
    std::string razao, medico, data, nome_paciente;
    int duracao, id_paciente;

    char opcao;
    Paciente p;

    Validar v;

    Dados d;

    std::cout << std::endl;
    std::cout << "########################################################" << std::endl;
    std::cout << "#               Registar um internamento               #" << std::endl;
    std::cout << "########################################################" << std::endl;
    std::cout << std::endl;
    std::cout << "Deseja pesquisar um cliente existente? (s/n) " << std::endl;
    std::cin >> opcao;
    std::cin.ignore();
    if(std::tolower(opcao)=='s') {

        p = encontrarPaciente();

        std::cout << std::endl;
        std::cout << "########################################################" << std::endl;
        std::cout << "#               Registar um internamento               #" << std::endl;
        std::cout << "########################################################" << std::endl;
        std::cout << std::endl;

    }

    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Razao: ";
    getline(std::cin, razao);
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Medico responsavel: " << std::endl;
    getline(std::cin, medico);
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Data (ex.: 08-11-2018): " << std::endl;
    getline(std::cin, data);
    data = v.data(data);
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Duracao: " << std::endl;
    std::cin >> duracao;
    std::cin.ignore();
    std::cout << "--------------------------------------------------------" << std::endl;
    if(p.getIdPaciente() == 0) {

        //se o id for zero ('p' vazio), entao pedir estes dados ao utilizador
        std::cout << "ID do paciente: " << std::endl;
        std::cin >> id_paciente;
        std::cin.ignore();
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << "Nome do paciente: " << std::endl;
        getline(std::cin, nome_paciente);
        std::cout << "--------------------------------------------------------" << std::endl;

    }

    //registar os dados do intermento:
    i.setRazao(razao);
    i.setNomeMedico(medico);
    i.setData(data);
    i.setDuracao(duracao);
    if(p.getIdPaciente() == 0) {

        i.setIdPaciente(id_paciente);
        i.setNomePaciente(nome_paciente);

    } else {

        //se o utilizador escolheu pesquisar o cliente, entao utilizar esse nome e id
        i.setIdPaciente(p.getIdPaciente());
        i.setNomePaciente(p.getNomePaciente());

    }

    //escrever dados no ficheiro de internamentos
    d.guardarDados(i);

    std::cout << "Internamento registado com sucesso!" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

}

void Menu::registarOperacao() {

    Operacao o;
    std::string razao, medico, data, hora, nome_paciente;
    int id_paciente;

    char opcao;
    Paciente p;

    Dados d;

    std::cout << std::endl;
    std::cout << "########################################################" << std::endl;
    std::cout << "#                Registar uma operacao                 #" << std::endl;
    std::cout << "########################################################" << std::endl;
    std::cout << std::endl;
    std::cout << "Deseja pesquisar um cliente existente? (s/n) " << std::endl;
    std::cin >> opcao;
    std::cin.ignore();
    if(std::tolower(opcao)=='s') {

        p = encontrarPaciente(); //procurar o paciente

        std::cout << std::endl;
        std::cout << "########################################################" << std::endl;
        std::cout << "#                Registar uma operacao                 #" << std::endl;
        std::cout << "########################################################" << std::endl;

    }


    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Razao: ";
    getline(std::cin, razao);
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Medico responsavel: " << std::endl;
    getline(std::cin, medico);
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Data (ex.: 08-11-2018): " << std::endl;
    getline(std::cin, data);
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Hora (ex.: 09:00): " << std::endl;
    getline(std::cin, hora);
    std::cout << "--------------------------------------------------------" << std::endl;

    if(p.getIdPaciente() == 0) {

        //se o id for zero ('p' vazio), entao pedir esses dados ao utilizador
        std::cout << "ID do paciente: " << std::endl;
        std::cin >> id_paciente;
        std::cin.ignore();
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << "Nome do paciente: " << std::endl;
        getline(std::cin, nome_paciente);
        std::cout << "--------------------------------------------------------" << std::endl;

    }

    //registar os dados da operacao
    o.setRazao(razao);
    o.setNomeMedico(medico);
    o.setData(data);
    o.setHora(hora);

    if(p.getIdPaciente() == 0) {

        o.setIdPaciente(id_paciente);
        o.setNomePaciente(nome_paciente);

    } else {

        o.setIdPaciente(p.getIdPaciente());
        o.setNomePaciente(p.getNomePaciente());

    }

    d.guardarDados(o);

    std::cout << "Operacao registada com sucesso!" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

}

void Menu::registarConsulta() {

    Consulta c;
    std::string razao, medico, data, hora, nome_paciente;
    int id_paciente;

    char opcao;
    Paciente p;

    Dados d;

    std::cout << std::endl;
    std::cout << "########################################################" << std::endl;
    std::cout << "#                Registar uma consulta                 #" << std::endl;
    std::cout << "########################################################" << std::endl;
    std::cout << std::endl;
    std::cout << "Deseja pesquisar um cliente existente? (s/n) " << std::endl;
    std::cin >> opcao;
    std::cin.ignore();
    if(std::tolower(opcao)=='s') {

        p = encontrarPaciente(); //procurar o paciente

        std::cout << std::endl;
        std::cout << "########################################################" << std::endl;
        std::cout << "#                Registar uma consulta                 #" << std::endl;
        std::cout << "########################################################" << std::endl;

    }


    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Razao: ";
    getline(std::cin, razao);
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Medico responsavel: " << std::endl;
    getline(std::cin, medico);
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Data (ex.: 08-11-2018): " << std::endl;
    getline(std::cin, data);
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Hora (ex.: 09:00): " << std::endl;
    getline(std::cin, hora);
    std::cout << "--------------------------------------------------------" << std::endl;

    if(p.getIdPaciente() == 0) {

        //se o id for zero ('p' vazio), entao pedir esses dados ao utilizador
        std::cout << "ID do paciente: " << std::endl;
        std::cin >> id_paciente;
        std::cin.ignore();
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << "Nome do paciente: " << std::endl;
        getline(std::cin, nome_paciente);
        std::cout << "--------------------------------------------------------" << std::endl;

    }

    //registar os dados da operacao
    c.setRazao(razao);
    c.setNomeMedico(medico);
    c.setData(data);
    c.setHora(hora);

    if(p.getIdPaciente() == 0) {

        c.setIdPaciente(id_paciente);
        c.setNomePaciente(nome_paciente);

    } else {

        c.setIdPaciente(p.getIdPaciente());
        c.setNomePaciente(p.getNomePaciente());

    }

    d.guardarDados(c);

    std::cout << "Consulta registada com sucesso!" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

}

void Menu::procurarFichaPaciente(std::vector<Paciente> const Pacientes) {

    int opcao, id_paciente_inteiro;
    std::string nome_paciente, id_paciente;
    Paciente p;
    Dados d;
    Validar v;

    std::cout << "Deseja procurar por nome ou id de paciente?" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "1. Por nome" << std::endl;
    std::cout << "2. Por id" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "0. Voltar ao menu inicial" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Digite a sua opcao seguida pela tecla 'ENTER': ";
    std::cin >> opcao;
    std::cin.ignore();

    if(opcao==1) {

        std::cout << std::endl;
        std::cout << "Digite o nome do paciente seguido pela tecla 'ENTER': ";
        getline(std::cin, nome_paciente);
        p = d.procurarPaciente(Pacientes, nome_paciente);
        if(p.getIdPaciente() == 0) {

            std::cout << "Paciente nao encontrado!" << std::endl;
            return;

        }

        Menu::mostrarFichaPaciente(p); //mostrar a ficha do paciente

        return;

    } else if(opcao==2) {

        std::cout << std::endl;
        std::cout << "Digite o id do paciente seguido pela tecla 'ENTER': ";
        getline(std::cin, id_paciente);
        id_paciente_inteiro = v.validarConverterNumero(id_paciente); //converter string em int, devolve 0 se falhar
        p = d.procurarPaciente(Pacientes, id_paciente_inteiro);
        if(p.getIdPaciente() == 0) {

            std::cout << "Paciente nao encontrado!" << std::endl;
            return;

        }

        Menu::mostrarFichaPaciente(p); //mostrar a ficha do paciente


    } else if(opcao==0) {

        return;

    } else
        return;


}

Paciente Menu::encontrarPaciente() {

    int opcao, id_paciente_inteiro;
    std::string nome_paciente, id_paciente;
    std::vector<Paciente> Pacientes;
    Paciente p;
    Dados d;
    Validar v;

    Pacientes = d.lerPacientes();

    std::cout << "Deseja procurar por nome ou id de paciente?" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "1. Por nome" << std::endl;
    std::cout << "2. Por id" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "0. Voltar ao menu anterior" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Digite a sua opção seguida pela tecla 'ENTER': ";
    std::cin >> opcao;
    std::cin.ignore();

    if (opcao == 1) {

        std::cout << std::endl;
        std::cout << "Digite o nome do paciente seguido pela tecla 'ENTER': ";
        getline(std::cin, nome_paciente);
        p = d.procurarPaciente(Pacientes, nome_paciente);
        if (p.getIdPaciente() == 0) {

            std::cout << std::endl;
            std::cout << "Paciente nao encontrado! " << std::endl;
            std::cout << std::endl;
            p = encontrarPaciente();

        }

        return p;

    } else if (opcao == 2) {

        std::cout << std::endl;
        std::cout << "Digite o id do paciente seguido pela tecla 'ENTER': ";
        getline(std::cin, id_paciente);
        id_paciente_inteiro = v.validarConverterNumero(id_paciente); //converter string em int, devolve 0 se falhar
        p = d.procurarPaciente(Pacientes, id_paciente_inteiro);
        if (p.getIdPaciente() == 0) {

            std::cout << "Paciente nao encontrado!" << std::endl;
            p = encontrarPaciente();

        }

        return p;

    } else {

        return p;

    }
}

void Menu::mostrarFichaPaciente(Paciente p) {

    Dados d;
    std::vector<Internamento> Internamentos;
    std::vector<Operacao> Operacoes;
    std::vector<Consulta> Consultas;
    int contador; //contador de entradas para cada tipo de motivo de visita

    //procurar internamentos, operacoes e consultas para este paciente via id interno
    Internamentos = d.obterInternamentos(p.getIdPaciente());
    Operacoes = d.obterOperacoes(p.getIdPaciente());
    Consultas = d.obterConsultas(p.getIdPaciente());

    std::cout << "############################################################################" << std::endl;
    std::cout << "#                             FICHA DE PACIENTE                            #" << std::endl;
    std::cout << "############################################################################" << std::endl;
    std::cout << "# Nome          -> " << std::left << std::setw(55) << p.getNomePaciente() << " #" << std::endl;
    std::cout << "# Nome do dono  -> " << std::left << std::setw(55) << p.getNomeDonoPaciente() << " #" << std::endl;
    std::cout << "# Telefone      -> " << std::left << std::setw(55) << p.getTelefone() << " #" << std::endl;
    std::cout << "# Morada        -> " << std::left << std::setw(55) << p.getMorada() << " #" << std::endl;
    std::cout << "# Raca          -> " << std::left << std::setw(55) << p.getRaca() << " #" << std::endl;
    std::cout << "# Idade         -> " << std::left << std::setw(55) << p.getIdade() << " #" << std::endl;
    std::cout << "# Tipo de animal-> " << std::left << std::setw(55) << p.getTipo() << " #" << std::endl;
    std::cout << "############################################################################" << std::endl;
    std::cout << std::endl;
    std::cout << "############################################################################" << std::endl;
    std::cout << "#                               INTERNAMENTOS                              #" << std::endl;
    std::cout << "############################################################################" << std::endl;
    std::cout << "# Num. # Razao                 # " << "Medico responsavel #" << " Data       #" << " Duracao #" << std::endl;
    std::cout << "############################################################################" << std::endl;
    //ciclo para listar internamentos
    contador = 1;

    if(Internamentos.empty()) { //se não existrem internamentos, saltar os internamentos e mostrar isso ao utilizador

        std::cout << "# Este paciente nao tem internamentos registados!                          #" << std::endl;
        std::cout << "############################################################################" << std::endl;

    } else {

        for(auto &i : Internamentos) { //ciclo para listar todos os internamentos deste paciente

            std::cout << "# " << std::left << std::setw(4) << contador << " # ";
            std::cout << std::left << std::setw(21) << i.getRazao() << " # ";
            std::cout << std::left << std::setw(18) << i.getNomeMedico() << " # ";
            std::cout << std::left << std::setw(10) << i.getData() << " # ";
            std::cout << std::left << std::setw(7) << std::to_string(i.getDuracao()) + 'd' << " #" << std::endl;
            contador++;

        }

        std::cout << "############################################################################" << std::endl;

    }

    //ciclo para listar Operações
    contador = 1;

    std::cout << std::endl;
    std::cout << "############################################################################" << std::endl;
    std::cout << "#                               OPERACOES                                  #" << std::endl;
    std::cout << "############################################################################" << std::endl;
    std::cout << "# Num. # Razao                 # " << "Medico responsavel #" << " Data       #" << " Hora    #" << std::endl;
    std::cout << "############################################################################" << std::endl;

    if(Operacoes.empty()) { //se não existirem operações, saltar as operações e mostrar isso ao utilizador

        std::cout << "# Este paciente nao tem operacoes registadas!                              #" << std::endl;
        std::cout << "############################################################################" << std::endl;

    } else {

        for(auto &i : Operacoes) { //iterador C++11. Mais info em: https://en.cppreference.com/w/cpp/language/range-for

            std::cout << "# " << std::left << std::setw(4) << contador << " # ";
            std::cout << std::left << std::setw(21) << i.getRazao() << " # ";
            std::cout << std::left << std::setw(18) << i.getNomeMedico() << " # ";
            std::cout << std::left << std::setw(10) << i.getData() << " # ";
            std::cout << std::left << std::setw(7) << i.getHora() << " #" << std::endl;
            contador++;

        }

        std::cout << "############################################################################" << std::endl;

    }

    //ciclo para listar Consultas
    contador = 1;
    std::cout << std::endl;
    std::cout << "############################################################################" << std::endl;
    std::cout << "#                               CONSULTAS                                  #" << std::endl;
    std::cout << "############################################################################" << std::endl;
    std::cout << "# Num. # Razao                 # " << "Medico responsavel #" << " Data       #" << " Hora    #" << std::endl;
    std::cout << "############################################################################" << std::endl;


    if(Consultas.empty()) { //se não existirem consultas, saltar as consultas e mostrar isso ao utilizador

        std::cout << "# Este paciente nao tem consultas registadas!                              #" << std::endl;
        std::cout << "############################################################################" << std::endl;

    } else {

        for(auto &i : Consultas) { //iterador C++11. Mais info em: https://en.cppreference.com/w/cpp/language/range-for

            std::cout << "# " << std::left << std::setw(4) << contador << " # ";
            std::cout << std::left << std::setw(21) << i.getRazao() << " # ";
            std::cout << std::left << std::setw(18) << i.getNomeMedico() << " # ";
            std::cout << std::left << std::setw(10) << i.getData() << " # ";
            std::cout << std::left << std::setw(7) << i.getHora() << " #" << std::endl;
            contador++;

        }

        std::cout << "############################################################################" << std::endl;

    }

    Menu::pausa();

}

void Menu::menuEscolhaRelatorioMensal() {

    int opcao = 0;

    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << " Relatorios Mensais (por ano)" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "1. Internamentos" << std::endl;
    std::cout << "2. Operacoes" << std::endl;
    std::cout << "3. Consultas" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "0. Sair " << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "Por favor escolha o tipo de relatorio que deseja consultar: ";
    std::cin >> opcao;
    std::cin.ignore();


    if(opcao==1) {

        std::vector<Internamento> Internamentos;
        Menu::mostrarRelatorioMensal(Internamentos);

    }

    else if(opcao==2) {

        std::vector<Operacao> Operacoes;
        Menu::mostrarRelatorioMensal(Operacoes);

    }

    else if(opcao==3) {

        std::vector<Consulta> Consultas;
        Menu::mostrarRelatorioMensal(Consultas);

    }

    else if(opcao==0) {

        return;

    }

    else
        Menu::menuEscolhaRelatorioMensal();

}
void Menu::mostrarRelatorioMensal(std::vector<Internamento> Internamentos) {

    Dados d;
    std::string ano, mes;
    int contador = 1;

    ano = escolherAno();
    mes = escolherMes();

    Internamentos = d.filtrarInternamentos(ano, mes);

    std::cout << "########################################################################################################" << std::endl;
    std::cout << "#                                             INTERNAMENTOS                                            #" << std::endl;
    std::cout << "#                                                " << ano << "/" << mes << "                                               #" << std::endl;
    std::cout << "########################################################################################################" << std::endl;
    std::cout << "# Num. # Razao                 # " << "Medico responsavel #" << " Data       #" << " Duracao #" << " Paciente           #" << " Id   #" << std::endl;
    std::cout << "########################################################################################################" << std::endl;

    if(Internamentos.empty()) {

        std::cout << "# Nao existem internamentos registados para este mes!                                                  #" << std::endl;

    } else {

        for(auto &i : Internamentos) {

            std::cout << "# " << std::left << std::setw(4) << contador << " # ";
            std::cout << std::left << std::setw(21) << i.getRazao() << " # ";
            std::cout << std::left << std::setw(18) << i.getNomeMedico() << " # ";
            std::cout << std::left << std::setw(10) << i.getData() << " # ";
            std::cout << std::left << std::setw(7) << std::to_string(i.getDuracao()) + 'd' << " # ";
            std::cout << std::left << std::setw(18) << i.getNomePaciente() << " # ";
            std::cout << std::left << std::setw(4) << i.getIdPaciente() << " #" << std::endl;
            contador++;

        }

    }

    std::cout << "########################################################################################################" << std::endl;
    std::cout << "# Numero total de internamentos: " << std::left << std::setw(4) << contador-1 << "                                                                  #" << std::endl;
    std::cout << "########################################################################################################" << std::endl;

    Menu::pausa();

}

void Menu::mostrarRelatorioMensal(std::vector<Operacao> Operacoes) {

    Dados d;
    std::string ano, mes;
    int contador = 1;

    ano = escolherAno();
    mes = escolherMes();

    Operacoes = d.filtrarOperacoes(ano, mes);

    std::cout << "#######################################################################################################" << std::endl;
    std::cout << "#                                            OPERACOES                                                #" << std::endl;
    std::cout << "#                                             " << ano << "/" << mes << "                                                 #" << std::endl;
    std::cout << "#######################################################################################################" << std::endl;
    std::cout << "# Num. # Razao                 # " << "Medico responsavel #" << " Data       #" << " Hora    #" << " Paciente           #" << " Id  #" << std::endl;
    std::cout << "#######################################################################################################" << std::endl;

    if(Operacoes.empty()) {

        std::cout << "# Nao existem operacoes registadas para este mes!                                                     #" << std::endl;

    } else {

        for(auto &i : Operacoes) {

            std::cout << "# " << std::left << std::setw(4) << contador << " # ";
            std::cout << std::left << std::setw(21) << i.getRazao() << " # ";
            std::cout << std::left << std::setw(18) << i.getNomeMedico() << " # ";
            std::cout << std::left << std::setw(10) << i.getData() << " # ";
            std::cout << std::left << std::setw(7) << i.getHora() << " # ";
            std::cout << std::left << std::setw(18) << i.getNomePaciente() << " # ";
            std::cout << std::left << std::setw(4) << i.getIdPaciente() << "#" << std::endl;
            contador++;

        }

    }


    std::cout << "#######################################################################################################" << std::endl;
    std::cout << "# Numero total de operacoes: " << std::left << std::setw(4) << contador-1 << "                                                                     #" << std::endl;
    std::cout << "#######################################################################################################" << std::endl;

    Menu::pausa();

}

void Menu::mostrarRelatorioMensal(std::vector<Consulta> Consultas) {

    Dados d;
    std::string ano, mes;
    int contador = 1;

    ano = escolherAno();
    mes = escolherMes();

    Consultas = d.filtrarConsultas(ano, mes);

    std::cout << "#######################################################################################################" << std::endl;
    std::cout << "#                                            CONSULTAS                                                #" << std::endl;
    std::cout << "#                                             " << ano << "/" << mes << "                                                 #" << std::endl;
    std::cout << "#######################################################################################################" << std::endl;
    std::cout << "# Num. # Razao                 # " << "Medico responsavel #" << " Data       #" << " Hora    #" << " Paciente           #" << " Id  #" << std::endl;
    std::cout << "#######################################################################################################" << std::endl;

    if(Consultas.empty()) {

        std::cout << "# Nao existem consultas registadas para este mes!                                                     #" << std::endl;

    } else {

        for(auto &i : Consultas) {

            std::cout << "# " << std::left << std::setw(4) << contador << " # ";
            std::cout << std::left << std::setw(21) << i.getRazao() << " # ";
            std::cout << std::left << std::setw(18) << i.getNomeMedico() << " # ";
            std::cout << std::left << std::setw(10) << i.getData() << " # ";
            std::cout << std::left << std::setw(7) << i.getHora() << " # ";
            std::cout << std::left << std::setw(18) << i.getNomePaciente() << " # ";
            std::cout << std::left << std::setw(4) << i.getIdPaciente() << "#" << std::endl;
            contador++;

        }

    }

    std::cout << "#######################################################################################################" << std::endl;
    std::cout << "# Numero total de consultas: " << std::left << std::setw(4) << contador-1 << "                                                                     #" << std::endl;
    std::cout << "#######################################################################################################" << std::endl;

    Menu::pausa();

}

std::string Menu::escolherAno() {

    std::string ano;

    std::cout << "Por favor, digite o ano (ex.: 2018): ";
    getline(std::cin, ano);

    return ano;


}

std::string Menu::escolherMes() {

    std::string mes;

    std::cout << "Por favor, digite o mes (ex.: 11): ";
    getline(std::cin, mes);

    return mes;

}

void Menu::pausa() {

    std::string temp;

    std::cout << "Prima ENTER para continuar..." << std::endl;

    getline(std::cin, temp);


}