#pragma once
#include <string>
#include "ListaCurso.h"

class Alumno {
    private: 
        int id;
        std::string nombre;
        std::string apellido;
        std::string carrera;
        std::string fechaIngreso;

        ListaCurso listaC;

    public:
        Alumno();
        Alumno(int id, std::string nombre, std::string apellido, 
            std::string carrera, std::string fechaIngreso);
        
        int getId();
        std::string getNombre();
        std::string getApellido();
        std::string getCarrera();
        std::string getIngreso();

        void inscribir(Curso* curso);
        bool cursando(Curso* curso);
        void eliminar(Curso* curso);

        void subirNota(int id, double nota);
        void verNotas();

        void getCursos();
        void getPromedio(int id);

        ~Alumno();
};