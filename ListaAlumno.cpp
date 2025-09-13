#include "ListaAlumno.h"
#include "Alumno.h"
#include <iostream>
#include <string>

//Listo
ListaAlumno::ListaAlumno() {
    head = nullptr;
}

//Listo
ListaAlumno::~ListaAlumno() {
    NodoAlumno* aux = head;
    while (aux != nullptr) {
        NodoAlumno* aux2 = aux;
        aux = aux -> getSig();
        delete aux2;
    }
}

//Listo
void ListaAlumno::insertar(Alumno& alumno) {
    NodoAlumno* newNodo = new NodoAlumno(alumno);

    if (head == nullptr) {
        head = newNodo;
        std::cout << "Student registered successfully!" << std::endl << std::endl;
        return;
    }

    NodoAlumno* aux = head;

    while (aux != nullptr) {
        if (aux -> getAlumno() -> getId() == newNodo -> getAlumno() -> getId()) {
            std::cout << "This ID already exists in students!" << std::endl << std::endl;
            delete newNodo;
            return;
        }

        if (aux -> getSig() == nullptr) break;
        aux = aux -> getSig();
    }

    aux -> setSig(newNodo);
    std::cout << "Student registered successfully!" << std::endl << std::endl;

}

//Listo
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

//Listo
void ListaAlumno::buscar(std::string nombre) {
     NodoAlumno* aux = head;
     bool encontrado = false;

    while(aux != nullptr) {
        if (aux -> getAlumno() -> getNombre() == nombre) {
            Alumno* alumno = aux -> getAlumno();

            std::cout << "ID: " << alumno -> getId() << std::endl;
            std::cout << "Name: " << alumno -> getNombre() << std::endl;
            std::cout << "Last name: " << alumno -> getApellido() << std::endl;
            std::cout << "Major: " << alumno -> getCarrera() << std::endl;
            std::cout << "Enrollment date: " << alumno -> getIngreso() << std::endl;
            
            std::cout << "=========================================" << std::endl;
            
            encontrado = true;
        }

        aux = aux -> getSig();
    }

    if (!encontrado) {
        std::cout << "There's no student named " << nombre << std::endl;
    }

}

//Listo
void ListaAlumno::buscarPorCarrera(std::string nombre) {
     NodoAlumno* aux = head;
     bool encontrado = false;

    while(aux != nullptr) {
        if (aux -> getAlumno() -> getCarrera() == nombre) {
            Alumno* alumno = aux -> getAlumno();

            std::cout << "ID: " << alumno -> getId() << std::endl;
            std::cout << "Name: " << alumno -> getNombre() << std::endl;
            std::cout << "Last name: " << alumno -> getApellido() << std::endl;
            std::cout << "Major: " << alumno -> getCarrera() << std::endl;
            std::cout << "Enrollment date: " << alumno -> getIngreso() << std::endl;
            
            std::cout << "=========================================" << std::endl;
            
            encontrado = true;
        }

        aux = aux -> getSig();
    }

    if (!encontrado) {
        std::cout << "There's no student in the major " << nombre << std::endl;
    }

}

//Listo
void ListaAlumno::eliminar(int id, bool eliminar) {
    if (head == nullptr) {
        std::cout << "There's no student to delete" << std::endl;
        return;
    }

    NodoAlumno* aux = head;

    if (aux -> getAlumno() -> getId() == id) {

        head = head -> getSig();

        delete aux;

        if (eliminar) {
            std::cout << "The student deleted was succesfully!" << std::endl;
        }

        return;
    }

    NodoAlumno* aux2 = head -> getSig();

    while (aux2 != nullptr && aux2 -> getAlumno() -> getId() != id) {
        aux = aux -> getSig();
        aux2 = aux2 -> getSig();
    }
    
    if (aux2 == nullptr) {
        std::cout << "There's no student with the ID " << id << std::endl;
        return;
    }

    aux -> setSig(aux2 -> getSig());

    delete aux2;

    if (eliminar) {
        std::cout << "The student deleted was succesfully!" << std::endl;
    }
}

//Listo
void ListaAlumno::ver() {
    if (head == nullptr) {
        std::cout << "There's nothing to see here!" << std::endl;
        return;
    }

    NodoAlumno* aux = head;

    while (aux != nullptr) {
        std::cout << aux -> getAlumno() -> getNombre() << " -> ";
        aux = aux -> getSig();
    }

    std::cout << std::endl << std::endl;
}