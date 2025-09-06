#pragma once
#include "NodoAlumno.h"
#include <string>

class ListaAlumno {
    private:
        NodoAlumno* head;

    public:
        ListaAlumno();
        ~ListaAlumno();

        void insertar(Alumno alumno);
        void buscar(int id);
        void buscar(std::string nombre);
        void ver();

};