/*
 eFolio A
 21093 - Programacao por Objetos - 2018-2019
 Aluno: Andre Santo
 Numero: 1502142
*/

#include "validar.h"

std::string Validar::tipoAnimal(std::string tipo) {

    //converter string em minusculas
    std::transform(tipo.begin(), tipo.end(), tipo.begin(), ::tolower);

    if(tipo != "gato" && tipo != "cao") {

        std::cout << "Apenas é permitido inserir 'cao' ou 'gato'! Por favor tente novamente" << std::endl;
        std::cout << "Tipo de animal (cao ou gato): ";
        getline(std::cin, tipo);
        //validar ate que o utilizador escreva 'cao' ou 'gato'
        tipo = Validar::tipoAnimal(tipo);

    }

    return tipo;

}

std::string Validar::data(std::string data) {

    int dia = std::stoi(data.substr(0, 2)); //XX-xx-xxxx
    int mes = std::stoi(data.substr(3, 2)); //xx-XX-xxxx
    int ano = std::stoi(data.substr(6, 4)); //xx-xx-XXXX

    if(dia < 1 || dia > 31) {

        std::cout << "Data invalida (dia)! Por favor digite uma data valida: " << std::endl;
        getline(std::cin, data);
        data = Validar::data(data);

    } else if(mes < 1 || mes > 12) {

        std::cout << "Data invalida (mes)! Por favor digite uma data valida: " << std::endl;
        getline(std::cin, data);
        data = Validar::data(data);

    } else if (ano < 1 || ano > 9999) {

        std::cout << "Data invalida (ano)! Por favor digite uma data valida: " << std::endl;
        getline(std::cin, data);
        data = Validar::data(data);

    }

    return data;

}

int Validar::validarConverterNumero(std::string numero) {

    int numero_convertido = 0;

    try {

        numero_convertido = std::stoi(numero);

    }

    //se nao for possivel converter a string para inteiro, apanhar e devolver zero...
    //provavelmente o utilizador terá inserido uma string
    catch (const std::invalid_argument &e){

        return 0;

    }

    return numero_convertido;

}