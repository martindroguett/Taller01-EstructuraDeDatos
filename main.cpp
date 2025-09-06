#include <iostream>
#include "Alumno.h"
#include "NodoAlumno.h"
#include "ListaAlumno.h"

using namespace std;

ListaAlumno lista = ListaAlumno();

//Listo - falta control error
void registrarAlumno() {
    int id;
    string nombre;
    string apellido;
    string carrera;
    string fechaIngreso;

    cout << "Ingrese id del alumno: ";
    cin >> id; 

    cout << "Ingrese nombre del alumno: ";
    cin >> nombre;
     
    cout << "Ingrese apellido del alumno: ";
    cin >> apellido;

    cout << "Ingrese carrera del alumno: ";
    cin >> carrera;

    cout << "Ingrese fecha de ingreso del alumno: ";
    cin >> fechaIngreso;

    Alumno alumno = Alumno(id, nombre, apellido, carrera, fechaIngreso);

    lista.insertar(alumno);
         
    cout << "¡Alumno registrado con éxito!" << endl;

}

//Listo - falta control error
void buscarAlumno() {
    string opcion;

    cout << "Ingrese dato de búsqueda: " << endl;
    cin >> opcion;

    try { 
        lista.buscar(stoi(opcion));

    } catch (exception& e) {
        lista.buscar(opcion);
    }
    
}

//falta control error - eliminar registro de notas e historial de cursos
void eliminarAlumno() {
    string id;

    cout << "Ingrese id de alumno a eliminar: ";
    cin >> id;
    bool valido = false;

    while (!valido) {
        try {
            lista.eliminar(stoi(id));
            valido = true;

        } catch (exception& e) {
            cout << "La id ingresada no es válida." << endl << endl;
        }
    }
}

void gestionAlumno() {
    int opcion = 0;

    while (opcion != 4) {
        cout << "=== Menú de Gestión de Alumnos ===" << endl;
        cout << "¿Qué desea hacer?" << endl;
        cout << "1) Registrar alumno" << endl;
        cout << "2) Búsqueda de alumno" << endl;
        cout << "3) Eliminar alumno" << endl;
        cout << "4) Salir" << endl;
        cout << "> ";

        cin >> opcion;
        cout << endl;

        if (opcion == 1) { registrarAlumno(); }
        else if (opcion == 2) { buscarAlumno(); }
        else if (opcion == 3) { eliminarAlumno(); }
        else if (opcion != 4) { cout << "Ese número no está dentro de las opciones" << endl; }
    }

    cout << "¡Saliendo del registro de alumnos!" << endl;

}

void gestionCurso() {

}

void inscripcion() {

}  

void gestionNotas() {

}

void reportes() {

}

int main() {
    int opcion = 0;

    while (opcion != 6) {
        cout << "¡Bienvenido al sistema de gestión académica!" << endl;
        cout << "¿Qué desea hacer?" << endl;
        cout << "1) Gestión de alumnos" << endl;
        cout << "2) Gestión de cursos" << endl;
        cout << "3) Inscripción de cursos" << endl;
        cout << "4) Gestión de notas" << endl;
        cout << "5) Reportes" << endl;
        cout << "6) Salir" << endl;
        cout << "> ";

        cin >> opcion;
        cout << endl;

        if (opcion == 1) { gestionAlumno(); }
        else if (opcion == 2) { gestionCurso(); }
        else if (opcion == 3) { inscripcion(); }
        else if (opcion == 4) { gestionNotas(); }
        else if (opcion == 5) { reportes(); }
        else if (opcion != 6) { cout << "Ese número no está dentro de las opciones" << endl; }
    }

    cout << "¡Gracias por preferirnos!" << endl;

    return 0;
}