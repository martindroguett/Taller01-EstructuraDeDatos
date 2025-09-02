#include "NodoAlumno.h"
#include <string>

NodoAlumno::NodoAlumno(Alumno alumno) {
    this -> alumno = alumno;
    this -> sig = nullptr; 
};

NodoAlumno* NodoAlumno::getSig() {
    return this -> sig;
}

void NodoAlumno::setSig(NodoAlumno* nuevo) {
    this -> sig = nuevo;
}

NodoAlumno* insertar(Alumno alumno, NodoAlumno* head) {
    NodoAlumno* newNodo = new NodoAlumno(alumno);

    if (head == nullptr) {
        return newNodo;
    }

    NodoAlumno* aux = head;
    
    while (aux -> getSig() != nullptr) {
        aux = aux -> getSig();
    }

    aux -> setSig(newNodo);

    return head;
}