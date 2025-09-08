#include "NodoCurso.h"
#include "Curso.h"
#include <string>

NodoCurso::~NodoCurso() {
    
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
