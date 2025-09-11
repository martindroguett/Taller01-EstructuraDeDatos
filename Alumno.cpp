#include "Alumno.h"
#include "Curso.h" 
#include <string>
#include <iostream> 

Alumno::~Alumno() {
    
}

Alumno::Alumno() {

}

Alumno::Alumno(int id, std::string nombre, std::string apellido, 
            std::string carrera, std::string fechaIngreso){
    
    this -> id = id;
    this -> nombre = nombre;
    this -> apellido = apellido;
    this -> carrera = carrera;
    this -> fechaIngreso = fechaIngreso;
}

int Alumno::getId() { return id; }
std::string Alumno::getNombre() { return nombre; } 
std::string Alumno::getApellido() { return apellido; } 
std::string Alumno::getCarrera() { return carrera; } 
std::string Alumno::getIngreso() { return fechaIngreso; } 

//Listo
void Alumno::inscribir(Curso* curso) {
    Curso* copia = new Curso(*curso); 
    this -> listaC.insertar(*copia);
}

//Listo
bool Alumno::cursando(Curso* curso) {
    if (listaC.buscar(curso -> getId()) != nullptr) {
        return true;
    } 
    
    std::cout << this -> getNombre() << this -> getApellido() << " is not enrolled in the course " 
    << curso -> getNombre() << std::endl;

    return false;
}

//Listo
void Alumno::eliminar(Curso* curso) {

    this -> listaC.eliminar(curso -> getId(), true);
}

//Listo
void Alumno::subirNota(int id, double nota) {
    Curso* curso = listaC.buscar(id);
    curso -> subirNota(nota);
}

//Listo
void Alumno::verNotas() {
    listaC.verNotas();
}

//Listo
void Alumno::getCursos() {
    listaC.ver();
}

//Listo
void Alumno::getPromedio(int id) {
    if (id == 0) {
        NodoCurso* aux = listaC.getHead();

        int count = 0;
        double sum = 0;

        while (aux != nullptr) {
            Curso* curso = aux -> getCurso();
            count++;
            sum += curso -> getPromedio();

            aux = aux -> getSig();
        }

        std::cout << "The overall average of " << this -> getNombre() << " is: " << 
        (sum / count) << std::endl;

        return;
    }
    
    Curso* curso = listaC.buscar(id);

    std::cout << "The average of " << this -> getNombre() << " in " << curso -> getNombre() 
    << " is: " << curso -> getPromedio() << std::endl;

    return;
}