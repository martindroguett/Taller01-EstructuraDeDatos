#pragma once
#include <string>
#include "ListaAlumno.h"

class Curso {
    private:
        int id;
        std::string nombre;
        int maxEst;
        std::string carrera;
        std::string profesor;

        int inscritos;

        ListaAlumno listaA;

    public:
        Curso();
        Curso(int id, std::string nombre, int maxEst, std::string carrera,
            std::string profesor);

        int getId();
        std::string getNombre();
        int getMaxEst();
        std::string getCarrera();
        std::string getProfesor();

        void inscribir(Alumno* alumno);
        void eliminar(Alumno* alumno);

        ~Curso();
};