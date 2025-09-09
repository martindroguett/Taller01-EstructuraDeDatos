#include "ListaCurso.h"
#include "Curso.h" 
#include <iostream>
#include <string>

ListaCurso::ListaCurso() {
    head = nullptr;
}

ListaCurso::~ListaCurso() {
    NodoCurso* aux = head;
    while (aux != nullptr) {
        NodoCurso* aux2 = aux;
        aux = aux -> getSig();
        delete aux2;
    }
}

void ListaCurso::insertar(Curso& curso) {
    NodoCurso* newNodo = new NodoCurso(curso);

    if (head == nullptr) {
        head = newNodo;
        return;
    }

    NodoCurso* aux = head;

    while (aux -> getSig() != nullptr) {
        aux = aux -> getSig();
    }

    aux -> setSig(newNodo);

}

Curso* ListaCurso::buscar(int id) {
    NodoCurso* aux = head;

    while(aux != nullptr) {
        if (aux -> getCurso() -> getId() == id) {
            Curso* curso = aux -> getCurso();
            
            return aux -> getCurso();
        }

        aux = aux -> getSig();
    }
    return nullptr;
}

void ListaCurso::buscar(std::string nombre) {
     NodoCurso* aux = head;
     bool encontrado = false;

    while(aux != nullptr) {
        if (aux -> getCurso() -> getNombre() == nombre) {
            Curso* curso = aux -> getCurso();

            std::cout << "Id: " << curso -> getId() << std::endl;
            std::cout << "Nombre: " << curso -> getNombre() << std::endl;
            std::cout << "Máximo de estudiantes: " << curso -> getMaxEst() << std::endl;
            std::cout << "Carrera: " << curso -> getCarrera() << std::endl;
            std::cout << "Profesor: " << curso -> getProfesor() << std::endl;
            
            std::cout << "=========================================" << std::endl;
            
            encontrado = true;
        }

        aux = aux -> getSig();
    }

    if (!encontrado) {
        std::cout << "No hay ningún curso con el nombre " << nombre << std::endl;
    }

}

void ListaCurso::eliminar(int id, bool eliminar) {
    if (head == nullptr) {
        std::cout << "No hay nada que eliminar" << std::endl;
        return;
    }

    NodoCurso* aux = head;

    if (aux -> getCurso() -> getId() == id) {

        head = head -> getSig();

        if (eliminar) {
            delete aux -> getCurso();
        }
        delete aux;

        std::cout << "Curso eliminado con éxito" << std::endl;

        return;
    }

    NodoCurso* aux2 = head -> getSig();

    while (aux2 != nullptr && aux2 -> getCurso() -> getId() != id) {
        aux = aux -> getSig();
        aux2 = aux2 -> getSig();
    }
    
    if (aux2 == nullptr) {
        std::cout << "No existe un curso con la id " << id << std::endl;
        return;
    }

    aux -> setSig(aux2 -> getSig());

    if (eliminar) {
        delete aux2 -> getCurso();
    }
    delete aux2;

    std::cout << "Curso eliminado con éxito" << std::endl;
}

void ListaCurso::verNotas() {
    if (head == nullptr) {
        std::cout << "No hay nada que mostrar" << std::endl;
        return;
    }

    NodoCurso* aux = head;

    while (aux != nullptr) {
        aux -> getCurso() -> verNotas();
        aux = aux -> getSig();
    }

    std::cout << std::endl << std::endl;
}

void ListaCurso::ver() {
    if (head == nullptr) {
        std::cout << "No hay nada que mostrar" << std::endl;
        return;
    }

    NodoCurso* aux = head;

    while (aux != nullptr) {
        std::cout << aux -> getCurso() -> getNombre() << " -> ";
        aux = aux -> getSig();
    }

    std::cout << std::endl << std::endl;
}