#pragma once

class NodoNota {
    private:
        double nota;
        NodoNota* sig;

    public:
        NodoNota(double nota);

        NodoNota* getSig();
        double getNota();
        void setSig(NodoNota* nuevo);
        ~NodoNota();
};