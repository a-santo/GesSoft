/*
 eFolio A
 21093 - Programacao por Objetos - 2018-2019
 Aluno: Andre Santo
 Numero: 1502142
*/

#include "paciente.h"

Paciente::Paciente() {

    id = 0;
    nome = "Indefinido";
    nome_dono = "Indefinido";
    telefone = 0;
    morada = "Indefinida";
    raca = "Indefinida";
    tipo = "Indefinido";

}

void Paciente::setIdPaciente(int i) {

    id = i;

}
void Paciente::setNomePaciente(std::string n) {

    nome = n;

}

void Paciente::setNomeDonoPaciente(std::string n) {

    nome_dono = n;

}

void Paciente::setTelefone(int t) {

    telefone = t;

}

void Paciente::setMorada(std::string m) {

    morada = m;

}

void Paciente::setRaca(std::string r) {

    raca = r;

}

void Paciente::setIdade(int i) {

    idade = i;

}

void Paciente::setTipo(std::string t) {

    tipo = t;

}

int Paciente::getIdPaciente() {

    return id;

}

std::string Paciente::getNomePaciente() {

    return nome;

}

std::string Paciente::getNomeDonoPaciente() {

    return nome_dono;

}

int Paciente::getTelefone() {

    return telefone;

}

std::string Paciente::getMorada() {

    return morada;

}


std::string Paciente::getRaca() {

    return raca;

}

int Paciente::getIdade() {

    return idade;

}

std::string Paciente::getTipo() {

    return tipo;

}

Paciente::~Paciente() = default;
