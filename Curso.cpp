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

//Listo
void Curso::inscribir(Alumno* alumno) {
    
    if (this -> inscritos >= this -> maxEst) {
        std::cout << "This course is full!" << std::endl;
        return;
    }

    Alumno* copia = new Alumno(*alumno); 

    this -> listaA.insertar(*copia);
    alumno -> inscribir(this);
    inscritos++;

    std::cout << alumno -> getNombre() << " " << alumno -> getApellido() 
    << " was enrolled successfully in " << this -> nombre << "!" << std::endl;
}

//Listo
void Curso::eliminar(Alumno* alumno) {
    this -> listaA.eliminar(alumno -> getId(), false);
    alumno -> eliminar(this);
    inscritos--;
}

//Listo
void Curso::subirNota(double nota) {
    listaN.insertar(nota);

}

//Listo
void Curso::verNotas() {
    listaN.ver();
}

//Listo
double Curso::getPromedio() {
    NodoNota* aux = listaN.getHead();
    if (aux == nullptr) {
        std::cout << "There's no grades in this course yet!" << std::endl;
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