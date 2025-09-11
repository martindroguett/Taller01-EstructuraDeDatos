#pragma once
#include "NodoNota.h"
#include <string>

class ListaNota {
    private:
        NodoNota* head;

    public:
        ListaNota();
        ~ListaNota();

        NodoNota* getHead();
        void insertar(double nota);
        void ver();
};