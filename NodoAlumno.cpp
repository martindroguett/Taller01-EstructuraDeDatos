#include "NodoAlumno.h"
#include <string>

NodoAlumno::NodoAlumno(Alumno alumno) {
    this -> alumno = alumno;
    this -> sig = nullptr; 
};

NodoAlumno* insertar(Alumno alumno, NodoAlumno* head) {
    NodoAlumno* newNodo = new NodoAlumno(alumno);

    if (head == nullptr) {
        return newNodo; //Pendiente
    }



}