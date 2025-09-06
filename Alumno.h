#pragma once
#include <string>

class Alumno {
    private: 
        int id;
        std::string nombre;
        std::string apellido;
        std::string carrera;
        std::string fechaIngreso;

    public:
        Alumno();
        Alumno(int id, std::string nombre, std::string apellido, 
            std::string carrera, std::string fechaIngreso);
        
        int getId();
        std::string getNombre();
        std::string getApellido();
        std::string getCarrera();
        std::string getIngreso();

        ~Alumno();
};