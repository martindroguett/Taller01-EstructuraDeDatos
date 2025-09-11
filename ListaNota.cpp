#include "ListaNota.h"
#include <iostream>

ListaNota::ListaNota() {
    head = nullptr;
}

ListaNota::~ListaNota() {
    NodoNota* aux = head;
    while (aux != nullptr) {
        NodoNota* aux2 = aux;
        aux = aux -> getSig();
        delete aux2;
    }
}

void ListaNota::insertar(double nota) {
    NodoNota* newNodo = new NodoNota(nota);

    if (head == nullptr) {
        head = newNodo;
        return;
    }

    NodoNota* aux = head;

    while (aux -> getSig() != nullptr) {
        aux = aux -> getSig();
    }

    aux -> setSig(newNodo);

}

void ListaNota::ver() {
    if (head == nullptr) {
        std::cout << "No hay nada que mostrar" << std::endl;
        return;
    }

    NodoNota* aux = head;

    while (aux != nullptr) {
        std::cout << aux -> getNota() << " -> ";
        aux = aux -> getSig();
    }

    std::cout << std::endl << std::endl;
}

NodoNota* ListaNota::getHead() {
    return this -> head;
}