#pragma once
#include <string>

class Curso;

class NodoCurso {
    private:
        Curso* curso;
        NodoCurso* sig;

    public:
        NodoCurso(Curso& curso);

        NodoCurso* getSig();
        Curso* getCurso();
        void setSig(NodoCurso* nuevo);
        ~NodoCurso();
    
};