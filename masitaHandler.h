#pragma once
#define MASITAHANLDER

#include "basic_classes.h"
#include "simulator_settings.h"
#include <iostream>

Masita* createMasita(int& nth_masita);
void addForce(Masita* mass, int& count, int& masitaCnt);
