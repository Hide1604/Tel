#include "menus.h" 
#include "masitaHandler.h"
#include "matrixTools.h"
#include "simulator_settings.h"
#include <cstdio>

// !! THIS FUNCTION GETS EXECUTED FIRST !!
void Menus::menu(std::vector<Masita*> &masita_arr){
  Menus::tutorial();
  Menus::setup_environment(masita_arr);
}

// Give basic instructions to the user C:
void Menus::tutorial(){
  std::cout << "En un plano como este podrás agregar distintas masas puntuales, ubicarlas y crear fuerzas ejercidas sobre ellas.\n";
  std::cout << "Por ahora, las simulaciones se ejecutan utilizando la gravedad de la tierra (app. 9.82 m/s^2)\n\n";
  std::cout << "\n\nNota: Actualmente el plano tiene un tamaño de (" << ROWS << " x " << COLUMNS <<").\n\n";
  std::cout << "Presione ENTER para ver el plano... \n";
  std::getchar();

  clearMatrix();
  drawFrame();

  std::cout << "Presione ENTER para continuar... \n";
  std::getchar();

  std::cout << "\033[2J\033[H"; // Clear screen 
}


void Menus::setup_environment(std::vector<Masita*>& masita_arr){
  int num_masitas = 0;
  bool masitas_flag = true;
  do {
    std::cout << "Ingrese el número de masas que serán sometidas a fuerzas,\n (máximo " << MAXMASITAS << "): ";
    std::cin >> num_masitas;

    // validate masitas
    if(num_masitas <= 0 || num_masitas > MAXMASITAS){
      std::cout << "Número de masas inválido.\n";
      masitas_flag = true;
    } else { // Setup masitas
      masitas_flag = false;
      Menus::setup_masitas(masita_arr, num_masitas);
    }

  }while(masitas_flag);
}

void Menus::setup_masitas(std::vector<Masita*> &masita_arr, int& num_masitas){
  for(int i=0; i<num_masitas; ++i){
    drawFrame();

    Masita* new_mass = createMasita(i);
    addDot((int)new_mass->get_x(), (int)new_mass->get_y(), (char)'m');

    std::cout << "\033[2J\033[H";

    drawFrame();
    
    Menus::setup_mass_forces(masita_arr, new_mass, i);
   
    std::cout << "\033[2J\033[H";
    drawFrame();
  }
}


void Menus::setup_mass_forces(std::vector<Masita*> &masita_arr, Masita* the_mass, int& nth_mass){
  int force_amnt = -1;
  int created_forces = 0;

  std::cout << "Ahora debe añadir las fuerzas que actúan en la masa\n";
  
  // Ask for amount of forces
  //TODO: Simplify this logic
  while(force_amnt < 0 || force_amnt > MAXFORCES){
    std::cout << "Máximo " << MAXFORCES << " fuerzas por masa.\n";
    std::cout << "Cuántas fuerzas desea añadir?: ";
    std::cin >> force_amnt;
    
    // Validate amount of forces
    if(force_amnt < 0 || force_amnt > MAXFORCES){
      std::cout << "Cantidad de fuerzas inválida, intente nuevamente.\n";
    }
  }

  // Create the forces for the mass
  while (created_forces < force_amnt){
    addForce(the_mass, created_forces, nth_mass);
    ++created_forces; 
  }
  masita_arr.push_back(the_mass);
}



