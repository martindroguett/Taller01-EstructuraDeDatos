#pragma once
#include <string>

class Alumno;

class NodoAlumno {
    private:
        Alumno* alumno;
        NodoAlumno* sig;

    public:
        NodoAlumno(Alumno& alumno);

        NodoAlumno* getSig();
        Alumno* getAlumno();
        void setSig(NodoAlumno* nuevo);
        ~NodoAlumno();
    
};