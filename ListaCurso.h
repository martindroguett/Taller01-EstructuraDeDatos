#pragma once
#include "NodoCurso.h"
#include <string>

class ListaCurso {
    private:
        NodoCurso* head;

    public:
        ListaCurso();
        ~ListaCurso();

        void insertar(Curso& curso);
        void buscar(int id);
        void buscar(std::string nombre);
        void eliminar(int id);
        void ver();

};