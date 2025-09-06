#include "Alumno.h"
#include <string>

Alumno::~Alumno() {
    
}

Alumno::Alumno() {

}

Alumno::Alumno(int id, std::string nombre, std::string apellido, 
            std::string carrera, std::string fechaIngreso){
    
    this -> id = id;
    this -> nombre = nombre;
    this -> apellido = apellido;
    this -> carrera = carrera;
    this -> fechaIngreso = fechaIngreso;
}

int Alumno::getId() { return id; }
std::string Alumno::getNombre() { return nombre; } 
std::string Alumno::getApellido() { return apellido; } 
std::string Alumno::getCarrera() { return carrera; } 
std::string Alumno::getIngreso() { return fechaIngreso; } 
