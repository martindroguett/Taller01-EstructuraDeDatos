#pragma once
#include "NodoAlumno.h"
#include <string>

class ListaAlumno {
    private:
        NodoAlumno* head;

    public:
        ListaAlumno();
        ~ListaAlumno();

        void insertar(Alumno& alumno);
        Alumno* buscar(int id);
        void buscar(std::string nombre);
        void eliminar(int id, bool eliminar);
        void ver();
        void buscarPorCarrera(std::string nombre);

};