#pragma once
#include <string>

class Curso {
    private:
        int id;
        std::string nombre;
        int maxEst;
        std::string carrera;
        std::string profesor;

    public:
        Curso();
        Curso(int id, std::string nombre, int maxEst, std::string carrera,
            std::string profesor);

        int getId();
        std::string getNombre();
        int getMaxEst();
        std::string getCarrera();
        std::string getProfesor();

        ~Curso();
};