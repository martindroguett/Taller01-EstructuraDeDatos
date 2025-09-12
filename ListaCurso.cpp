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

//Listo
void ListaCurso::insertar(Curso& curso) {
    NodoCurso* newNodo = new NodoCurso(curso);

    if (head == nullptr) {
        head = newNodo;
        std::cout << "Course registered successfully!" << std::endl << std::endl;
        return;
    }

    NodoCurso* aux = head;

    while (aux != nullptr) {
        if (aux -> getCurso() -> getId() == newNodo -> getCurso() -> getId()) {
            std::cout << "This ID already exists in courses!" << std::endl << std::endl;
            delete newNodo;
            return;
        }

        if (aux->getSig() == nullptr) break;

        aux = aux->getSig();

    }

    aux -> setSig(newNodo);
    std::cout << "Course registered successfully!" << std::endl << std::endl;
}

//Listo
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

//Listo
void ListaCurso::buscar(std::string nombre) {
     NodoCurso* aux = head;
     bool encontrado = false;

    while(aux != nullptr) {
        if (aux -> getCurso() -> getNombre() == nombre) {
            Curso* curso = aux -> getCurso();

            std::cout << "ID: " << curso -> getId() << std::endl;
            std::cout << "Name: " << curso -> getNombre() << std::endl;
            std::cout << "Maximum capacity: " << curso -> getMaxEst() << std::endl;
            std::cout << "Major: " << curso -> getCarrera() << std::endl;
            std::cout << "Professor: " << curso -> getProfesor() << std::endl;
            
            std::cout << "=========================================" << std::endl;
            
            encontrado = true;
        }

        aux = aux -> getSig();
    }

    if (!encontrado) {
        std::cout << "There's no course named " << nombre << std::endl;
    }

}

//Listo
void ListaCurso::eliminar(int id, bool eliminar) {
    if (head == nullptr) {
        std::cout << "There's no course to delete" << std::endl;
        return;
    }

    NodoCurso* aux = head;

    if (aux -> getCurso() -> getId() == id) {

        head = head -> getSig();

        if (eliminar) {
            delete aux -> getCurso();
        }
        delete aux;

        std::cout << "Course deleted successfully" << std::endl;

        return;
    }

    NodoCurso* aux2 = head -> getSig();

    while (aux2 != nullptr && aux2 -> getCurso() -> getId() != id) {
        aux = aux -> getSig();
        aux2 = aux2 -> getSig();
    }
    
    if (aux2 == nullptr) {
        std::cout << "There's no course with the ID " << id << std::endl;
        return;
    }

    aux -> setSig(aux2 -> getSig());

    if (eliminar) {
        delete aux2 -> getCurso();
    }
    delete aux2;

    std::cout << "Course deleted successfully" << std::endl;
}

//Listo
void ListaCurso::verNotas() {
    if (head == nullptr) {
        std::cout << "There's nothing to see here!" << std::endl << std::endl;
        return;
    }

    NodoCurso* aux = head;

    while (aux != nullptr) {
        aux -> getCurso() -> verNotas();
        aux = aux -> getSig();
    }

    std::cout << std::endl;
}

//Listo
void ListaCurso::ver() {
    if (head == nullptr) {
        std::cout << "There's nothing to see here!" << std::endl << std::endl;
        return;
    }

    NodoCurso* aux = head;

    while (aux != nullptr) {
        std::cout << aux -> getCurso() -> getNombre() << " -> ";
        aux = aux -> getSig();
    }

    std::cout << std::endl << std::endl;
}

//Listo
NodoCurso* ListaCurso::getHead() {
    return this -> head;
}