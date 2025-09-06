#include "NodoCurso.h"
#include <string>

NodoCurso::~NodoCurso() {
    delete this -> getCurso();
}

NodoCurso::NodoCurso(Curso& curso) {
    this -> curso = &curso;
    this -> sig = nullptr; 
}

NodoCurso* NodoCurso::getSig() {
    return this -> sig;
}

void NodoCurso::setSig(NodoCurso* nuevo) {
    this -> sig = nuevo;
}

Curso* NodoCurso::getCurso() {
    return curso;
}
