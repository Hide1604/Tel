#include "energia_potencial.h"

EnergiaPotencialGravitatoria::EnergiaPotencialGravitatoria(float masa, float altura)
    : masa(masa), altura(altura) {}

float EnergiaPotencialGravitatoria::calcularPotencialTierra() const {
    return masa * g * altura;
}

void EnergiaPotencialGravitatoria::set_masa(float nueva_masa) {
    masa = nueva_masa;
}

void EnergiaPotencialGravitatoria::set_altura(float nueva_altura) {
    altura = nueva_altura;
}

float EnergiaPotencialGravitatoria::get_masa() const {
    return masa;
}

float EnergiaPotencialGravitatoria::get_altura() const {
    return altura;
}