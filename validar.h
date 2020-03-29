/*
 eFolio A
 21093 - Programacao por Objetos - 2018-2019
 Aluno: Andre Santo
 Numero: 1502142
*/

#ifndef EFOLIOA_PPO_VALIDAR_H
#define EFOLIOA_PPO_VALIDAR_H

#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>

class Validar {

public:

    std::string tipoAnimal(std::string tipo); //valida se o tipo de animal e um cao ou gato
    std::string data(std::string data); //valida a data
    int validarConverterNumero(std::string numero); //converte e valida a string em inteiro e devolve o inteiro

};


#endif //EFOLIOA_PPO_VALIDAR_H
