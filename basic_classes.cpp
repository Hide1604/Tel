#include "basic_classes.h"
#include "simulator_settings.h"
#include <cmath>
// ############ Force's methods ###########

// Constructors

Force::Force(float x0, float y0, float xf, float yf)
	:x_0(x0), y_0(y0), x_f(xf), y_f(yf) // this->x_0 = x_0; and so on
{
  this->calc_magnitude();
}

// Destructor
Force::~Force() = default;

// Setters

void Force::set_magnitude(float new_magnitude){
	magnitude = new_magnitude;
}

void Force::set_magnitude_x(float new_magnitude_x){
	magnitude_x = new_magnitude_x;
}
void Force::set_magnitude_y(float new_magnitude_y){
	magnitude_y = new_magnitude_y;
}

// Getters

float Force::get_magnitude(){
	return magnitude;
}
float Force::get_magnitude_x(){
	return magnitude_x;
}
float Force::get_magnitude_y(){
	return magnitude_y;
}

float Force::get_x_0(){
	return x_0;
}
float Force::get_x_f(){
	return x_f;
}

float Force::get_y_0(){
	return y_0;
}
float Force::get_y_f(){
	return y_f;
}

// Methods
void Force::calc_magnitude() {
	set_magnitude_x(x_f - x_0);
	set_magnitude_y(y_f - y_0);
	set_magnitude(std::hypot(magnitude_x, magnitude_y));
}

// ########### Masita's methods ##########

Masita::Masita(){
  TotalForce = new Force(x_0, y_0, 0, 0);
  ay = -EARTH_GRAVITY;
  ax = 0;
}

Masita::~Masita(){
  delete this->TotalForce;
};
// Setters

void Masita::set_mass(float new_mass){
	mass = new_mass;
}

void Masita::set_x(float x){
	x_0 = x;
}
void Masita::set_y(float y){
	y_0 = y;
}

void Masita::set_vel_x(float new_vx){
	vx = new_vx;
}
void Masita::set_vel_y(float new_vy){
	vy = new_vy;
}

void Masita::set_acc_x(float new_ax){
	ax = new_ax;
}
void Masita::set_acc_y(float new_ay){
	ay = new_ay;
}

// Getters

float Masita::get_mass(){
	return mass;
}

float Masita::get_x(){
	return x_0;
}
float Masita::get_y(){
	return y_0;
}


float Masita::get_vel_x(){
	return vx;
}
float Masita::get_vel_y(){
	return vy;
}

float Masita::get_acc_x(){
	return ax;
}
float Masita::get_acc_y(){
	return ay;
}

// Methods
void Masita::update_acceleration() {
  ax += (TotalForce->get_magnitude_x() / mass);
  ay += (TotalForce->get_magnitude_y() / mass);
}

void Masita::update_position(const float& dt) {
	// Update the position using the new acceleration
	if (update_x && update_y)
	{
		// Do not update values if mass exits screen boundaries
		const static float half_dt_square = 0.5f + dt*dt;

    temp_x = x_0 + vx * dt + ax * half_dt_square; // Compute temporal new positions
		temp_y = y_0 + vy * dt + ay * half_dt_square;

		// Keep the Masita in boundaries
		if((temp_x < 0) || (temp_x >=COLUMNS)){
			update_x = false;
			return;
		} else if ((temp_y > ROWS) || (temp_y<=0)){
			update_y = false;
			return;
		} else {
      // Update the real values
      x_0 = temp_x;
      y_0 = temp_y;
		}
	}
}

void Masita::update_velocity(const float& dt) {
	// Update the velocity based on the acceleration
	vx += ax * dt;
	vy += ay * dt;
}

void Masita::update_force(Force& ApplyForce){
  TotalForce->set_magnitude_x(TotalForce->get_magnitude_x() + ApplyForce.get_magnitude_x());
  TotalForce->set_magnitude_y(TotalForce->get_magnitude_y() + ApplyForce.get_magnitude_y());
}


Force* Masita::get_force(){
  return TotalForce;
}

