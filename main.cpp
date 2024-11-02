#include <cstdio>
#include <iostream>
#include <cmath>
#include <unistd.h> // Unix systems control library
#include <vector>

#include "basic_classes.h" // Include the basic Masita and Force classes 
#include "Banner_Simulatel.h" // Print banner 
#include "basic_structs.h"
#include "matrixTools.h"
#include "menus.h"

// Bob se fue de sabático
static std::vector<Masita*> masita_arr;
extern int sim_ms; // Access the simulator_settings's simulation time variable


int main() {
  // Show Banner and intro C:
  printBanner();

  std::cout << "\n\n\nPresione ENTER para continuar...\n";
  std::getchar();

  std::cout << "\033[2J\033[H";

  // Main App menu   
  std::cout << "\n\n\n"; 
  
  Menus::menu(masita_arr);

  // Calculate initial acceleration
  for (int i = 0; i < (int)masita_arr.size(); ++i) {
    masita_arr[i]->update_acceleration();
  }

  // Show information of masitas
  for(int i=0; i<(int)masita_arr.size(); ++i){
    Masita* m = masita_arr[i];
    std::cout << "\n##############\n\n";
    std::cout << "Masita Nro " << i+1 << "\n";
    std::cout << "Masa: " << m->get_mass() << "(kg) \n";
    std::cout << "Aceleraciones (x,y): " << m->get_acc_x() << ", " << m->get_acc_y() << "(m/s2) \n";
    std::cout << "Fuerzas (x, y): " << m->get_force()->get_magnitude_x() << ", " << m->get_force()->get_magnitude_x() << "(N)\n";
    std::cout << "Posición inicial (x, y): " << m->get_x() << ", " << m->get_y() << "\n\n";
  }

  std::cout << "!! Presione ENTER para iniciar la simulación !!";
  std::cin.ignore();
  std::getchar();

  const static float dt = (1.0f/FPS); // Time step in seconds
  
  // Run the simulation
  while (true) {
    clearMatrix();
    for (int i = 0; i < (int)masita_arr.size(); ++i) {
      Masita* m = masita_arr[i];
      m->update_velocity(dt); // Update velocity based on acceleration
      m->update_position(dt); // Update position based on velocity and acceleration
      addDot((int)m->get_x(), (int)m->get_y(), (char)'o'); // Draw the mass
    }
    drawFrame(); // Draw the updated frame
  }

  for(int i=0; i<masita_arr.size(); ++i){
    delete masita_arr[i];;
  }

  return 0;
}
