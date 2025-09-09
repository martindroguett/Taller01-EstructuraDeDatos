#include "NodoNota.h"
#include <string>

NodoNota::~NodoNota() {
    
}

NodoNota::NodoNota(double nota) {
    this -> nota = nota;
    this -> sig = nullptr; 
}

NodoNota* NodoNota::getSig() {
    return this -> sig;
}

void NodoNota::setSig(NodoNota* nuevo) {
    this -> sig = nuevo;
}

double NodoNota::getNota() {
    return nota;
}