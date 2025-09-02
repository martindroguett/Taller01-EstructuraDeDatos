#include "Curso.h"
#include <string>

Curso::Curso(int id, std::string nombre, int maxEst, std::string carrera,
            std::string profesor) {
    
    this -> id = id;
    this -> nombre = nombre;
    this -> maxEst = maxEst;
    this -> carrera = carrera;
    this -> profesor = profesor;
}

int Curso::getId(){ return id; }
std::string Curso::getNombre(){ return nombre; }
int Curso::getMaxEst(){ return maxEst; }
std::string Curso::getCarrera(){ return carrera; }
std::string Curso::getProfesor(){ return profesor; }
