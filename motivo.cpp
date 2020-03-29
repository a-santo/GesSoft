/*
 eFolio A
 21093 - Programação por Objetos - 2018-2019
 Aluno: Andre Santo
 Numero: 1502142
*/

#include "motivo.h"

Motivo::Motivo() {

    razao = "Não preenchido";
    nome_medico = "Não preenchido";
    data = "00-00-0000";
    id_paciente = 0;
    nome_paciente = "Não preenchido";

}

std::string Motivo::getRazao() {

    return razao;

}

std::string Motivo::getNomeMedico() {

    return nome_medico;

}

std::string Motivo::getData() {

    return data;

}

int Motivo::getIdPaciente() {

    return id_paciente;

}

std::string Motivo::getNomePaciente() {

    return nome_paciente;

}

void Motivo::setRazao(std::string ra) {

    razao = ra;

}

void Motivo::setNomeMedico(std::string nm) {

    nome_medico = nm;

}

void Motivo::setData(std::string da) {

    data = da;

}

void Motivo::setIdPaciente(int id) {

    id_paciente = id;

}

void Motivo::setNomePaciente(std::string np) {

    nome_paciente = np;

}

Motivo::~Motivo() {}

/*
 *
 * Sub-classe Internamento
 *
 */

Internamento::Internamento() {

    duracao = 0;

}

int Internamento::getDuracao() {

    return duracao;

}

void Internamento::setDuracao(int du) {

    duracao = du;

}

Internamento::~Internamento() = default;

/*
 *
 * Sub-classe Operação
 *
 */

Operacao::Operacao() {

    hora = "00:00";

}

std::string Operacao::getHora() {

    return hora;

}

void Operacao::setHora(std::string h) {

    hora = h;

}

Operacao::~Operacao() {}

/*
 *
 * Sub-classe Consulta
 *
 */

Consulta::Consulta() = default;
Consulta::~Consulta() = default;