#pragma once
#include <string>
#include "Alumno.h"

class NodoAlumno {
    private:
        Alumno alumno;
        NodoAlumno* sig;

    public:
        NodoAlumno(Alumno alumno);
        NodoAlumno* insertar();
        NodoAlumno* eliminar();
        ~NodoAlumno();
    
};