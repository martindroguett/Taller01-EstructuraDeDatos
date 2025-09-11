#include "Curso.h"
#include "Alumno.h"
#include <string>
#include <iostream>

Curso::~Curso() {
}

Curso::Curso() {

}

Curso::Curso(int id, std::string nombre, int maxEst, std::string carrera,
            std::string profesor) {
    
    this -> id = id;
    this -> nombre = nombre;
    this -> maxEst = maxEst;
    this -> carrera = carrera;
    this -> profesor = profesor;

    this -> inscritos = 0;
    this -> listaA = ListaAlumno();
    
    this -> listaN = ListaNota();
}

int Curso::getId(){ return id; }
std::string Curso::getNombre(){ return nombre; }
int Curso::getMaxEst(){ return maxEst; }
std::string Curso::getCarrera(){ return carrera; }
std::string Curso::getProfesor(){ return profesor; }

void Curso::inscribir(Alumno* alumno) {
    
    if (this -> inscritos >= this -> maxEst) {
        std::cout << "No se pueden agregar más alumnos a este curso" << std::endl;
        return;
    }

    Alumno* copia = new Alumno(*alumno); 

    this -> listaA.insertar(*copia);
    alumno -> inscribir(this);
    inscritos++;

    std::cout << alumno -> getNombre() << " " << alumno -> getApellido() 
    << " " << "fue agregado con éxito!" << std::endl;
}

void Curso::eliminar(Alumno* alumno) {
    this -> listaA.eliminar(alumno -> getId(), true);
    alumno -> eliminar(this);
    inscritos--;
}

void Curso::subirNota(double nota) {
    listaN.insertar(nota);

}

void Curso::verNotas() {
    listaN.ver();
}

double Curso::getPromedio() {
    NodoNota* aux = listaN.getHead();
    if (aux == nullptr) {
        std::cout << "No hay notas en este curso aún" << std::endl;
        return 0;
    }

    int count = 0;
    double sum = 0;

    while (aux != nullptr) {
        sum += aux -> getNota();
        count++;

        aux = aux -> getSig();
    }

    return (sum / count);

}