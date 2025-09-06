#include "NodoAlumno.h"
#include <string>

NodoAlumno::~NodoAlumno() {
    delete this -> getAlumno();
}

NodoAlumno::NodoAlumno(Alumno& alumno) {
    this -> alumno = &alumno;
    this -> sig = nullptr; 
}

NodoAlumno* NodoAlumno::getSig() {
    return this -> sig;
}

void NodoAlumno::setSig(NodoAlumno* nuevo) {
    this -> sig = nuevo;
}

Alumno* NodoAlumno::getAlumno() {
    return alumno;
}
