#include "Alumno.h"
#include "Curso.h" 
#include <string>
#include <iostream> 

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

void Alumno::inscribir(Curso* curso) {
    Curso* copia = new Curso(*curso); 
    this -> listaC.insertar(*copia);
}

bool Alumno::cursando(Curso* curso) {
    if (listaC.buscar(curso -> getId()) != nullptr) {
        return true;
    } 
    
    std::cout << this -> getNombre() << this -> getApellido() << " no está cursando " 
    << curso -> getNombre() << std::endl;

    return false;
}

void Alumno::eliminar(Curso* curso) {
    Curso copia = *curso; 

    this -> listaC.eliminar(copia.getId(), true);
}

void Alumno::getCursos() {
    listaC.ver();
}