#pragma once

#include <cmath>
#define MERCURY_GRAVITY 3.7f // Use 'f' character to assure it is float, not double(by default)
#define EARTH_GRAVITY 9.81f

class Force{
	public:
		Force(float x0, float y0, float xf, float yf);
		~Force();	 
		// Setters
		void set_magnitude(float new_magnitude);

		void set_magnitude_x(float new_magnitude_x);
		void set_magnitude_y(float new_magnitude_y);

		// Getters
		float get_magnitude();		
		float get_magnitude_x();
		float get_magnitude_y();

		float get_x_0();
		float get_x_f();
		
		float get_y_0();
		float get_y_f();
		
		// Methods
		void calc_magnitude();
	private:
		float x_0 = 0;
		float y_0 = 0;
		
		float x_f = 0;
		float y_f = 0;
	
		float magnitude = 0;
		float magnitude_x = 0;
		float magnitude_y = 0;
};

class Masita{
	public:
		Masita();
		~Masita();

		//Setters
		void set_mass(float new_mass);

		void set_x(float x);
		void set_y(float y);

		void set_vel_x(float new_vx);
		void set_vel_y(float new_vy);

		void set_acc_x(float new_ax);
		void set_acc_y(float new_ay);

		//Getters
		float get_mass();

		float get_x();
		float get_y();

		float get_vel_x();
		float get_vel_y();

		float get_acc_x();
		float get_acc_y();

		Force* get_force();


		//Methods
		void update_acceleration();
		void update_force(Force& ApplyForce);
		void update_position(const float& dt);   
		void update_velocity(const float& dt);

	private:
		float x_0 = 0;
		float y_0 = 0;
		float temp_x = 0;
		float temp_y = 0;

		float vy = 0;
		float vx = 0;

		float ay = 1;
		float ax = 1;
	
		float mass = 0;
		
		Force* TotalForce;

		bool update_x = true;
		bool update_y = true;
};
