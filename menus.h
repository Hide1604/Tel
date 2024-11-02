#include <vector>
#include "basic_classes.h"
#include "simulator_settings.h"
#include <iostream>
#include "matrixTools.h"

namespace Menus{



void menu(std::vector<Masita*> &masita_arr); 

void tutorial();

void setup_mass_forces(std::vector<Masita*>& masita_arr, Masita* the_mass, int& nth_mass);

void setup_masitas(std::vector<Masita*>& masita_arr, int& num_masitas);

void setup_environment(std::vector<Masita*>& masita_arr);

}
