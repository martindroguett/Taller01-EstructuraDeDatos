#include "ListaAlumno.h"
#include "Alumno.h"
#include <iostream>
#include <string>

ListaAlumno::ListaAlumno() {
    head = nullptr;
}

ListaAlumno::~ListaAlumno() {
    NodoAlumno* aux = head;
    while (aux != nullptr) {
        NodoAlumno* aux2 = aux;
        aux = aux -> getSig();
        delete aux2;
    }
}

void ListaAlumno::insertar(Alumno& alumno) {
    NodoAlumno* newNodo = new NodoAlumno(alumno);

    if (head == nullptr) {
        head = newNodo;
        return;
    }

    NodoAlumno* aux = head;

    while (aux -> getSig() != nullptr) {
        aux = aux -> getSig();
    }

    aux -> setSig(newNodo);

}

Alumno* ListaAlumno::buscar(int id) {
    NodoAlumno* aux = head;

    while(aux != nullptr) {
        if (aux -> getAlumno() -> getId() == id) {
            Alumno* alumno = aux -> getAlumno();

            return alumno;
        }

        aux = aux -> getSig();
    }

    return nullptr;
}

void ListaAlumno::buscar(std::string nombre) {
     NodoAlumno* aux = head;
     bool encontrado = false;

    while(aux != nullptr) {
        if (aux -> getAlumno() -> getNombre() == nombre) {
            Alumno* alumno = aux -> getAlumno();

            std::cout << "Id: " << alumno -> getId() << std::endl;
            std::cout << "Nombre: " << alumno -> getNombre() << std::endl;
            std::cout << "Apellido: " << alumno -> getApellido() << std::endl;
            std::cout << "Carrera: " << alumno -> getCarrera() << std::endl;
            std::cout << "Fecha de Ingreso: " << alumno -> getIngreso() << std::endl;
            
            std::cout << "=========================================" << std::endl;
            
            encontrado = true;
        }

        aux = aux -> getSig();
    }

    if (!encontrado) {
        std::cout << "No hay ningún alumno con el nombre " << nombre << std::endl;
    }

}

void ListaAlumno::eliminar(int id, bool eliminar) {
    if (head == nullptr) {
        std::cout << "No hay nada que eliminar" << std::endl;
        return;
    }

    NodoAlumno* aux = head;

    if (aux -> getAlumno() -> getId() == id) {

        head = head -> getSig();

        if (eliminar) {
            delete aux -> getAlumno();
        }

        delete aux;

        std::cout << "Alumno eliminado con éxito" << std::endl;

        return;
    }

    NodoAlumno* aux2 = head -> getSig();

    while (aux2 != nullptr && aux2 -> getAlumno() -> getId() != id) {
        aux = aux -> getSig();
        aux2 = aux2 -> getSig();
    }
    
    if (aux2 == nullptr) {
        std::cout << "No existe un alumno con la id " << id << std::endl;
        return;
    }

    aux -> setSig(aux2 -> getSig());

    if (eliminar) {
        delete aux2 -> getAlumno();
    }
    delete aux2;

    std::cout << "Alumno eliminado con éxito" << std::endl;
}

void ListaAlumno::ver() {
    if (head == nullptr) {
        std::cout << "No hay nada que mostrar" << std::endl;
        return;
    }

    NodoAlumno* aux = head;

    while (aux != nullptr) {
        std::cout << aux -> getAlumno() -> getNombre() << " -> ";
        aux = aux -> getSig();
    }

    std::cout << std::endl << std::endl;
}