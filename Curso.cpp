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
    Alumno copia = *alumno; 
    this -> listaA.eliminar(copia.getId(), true);
    alumno -> eliminar(this);
    inscritos--;
}
