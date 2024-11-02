#include "masitaHandler.h"
#include "basic_classes.h"
#include "matrixTools.h"

Masita* createMasita(int& nth_masita){
	std::cout << "Creando masa " << nth_masita+1 << std::endl;
	Masita* the_mass = new Masita;
	float x = 0, y = 0;
	bool flag = true;
	do {
		std::cout << "Ingrese posición inicial de la masa:\n";
		std::cout << "Coordenada X: ";
		std::cin >> x;
		std::cout << "Coordenada Y: ";
		std::cin >> y;
		if (x < 0 || x >= COLUMNS || y < 0 || y >= ROWS) {
			std::cerr << "Coordenadas fuera de rango. Por favor, ingrese valores válidos." << std::endl;
		} else {
			flag = false;
			the_mass->set_x(x);
			the_mass->set_y(y);
		}
	} while (flag);
	float mass = 0;
	while (mass <= 0) {
		std::cout << "Magnitud de la masa (kg): ";
		std::cin >> mass;
		if (mass <= 0) {
			std::cout << "Masa de magnitud inválida, reintente porfavor.\n";
		} else{
			the_mass->set_mass(mass);
		}
	}

	return the_mass;
}

void addForce(Masita* mass, int& count, int& masitaCnt) {
    float x = 0, y = 0;
    bool loop = true;
    while (loop) {
        std::cout << "Ingrese las coordenadas de la punta del vector " << count+1 << " para la masa " << masitaCnt+1 << ": \n";
        std::cout << "x: ";
        std::cin >> x;
        std::cout << "y: ";
        std::cin >> y;

        // Validate coordinates of the vector's point C:
        if (x < 0 || x >= COLUMNS || y < 0 || y >= ROWS) {
            std::cout << "Coordenadas fuera de rango. Por favor, ingrese valores válidos." << std::endl;
        } else { // Create the new force and update the mass's force given such new force
			      Force new_force(mass->get_x(), mass->get_y(), x, y);
            mass->update_force(new_force);
            addDot((int)new_force.get_x_f(), (int)new_force.get_y_f(), (char)'+'); // Add the tip of the vector on the screen
            loop = false;
        }
    }
}
