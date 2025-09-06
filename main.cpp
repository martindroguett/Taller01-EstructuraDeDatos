#include <iostream>
#include "Alumno.h"
#include "Curso.h"
#include "NodoAlumno.h"
#include "NodoCurso.h"
#include "ListaAlumno.h"
#include "ListaCurso.h"

using namespace std;

ListaAlumno listaA = ListaAlumno();
ListaCurso listaC = ListaCurso();

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

    Alumno* alumno = new Alumno(id, nombre, apellido, carrera, fechaIngreso);

    listaA.insertar(*alumno);
         
    cout << "¡Alumno registrado con éxito!" << endl << endl;

}

//Listo - falta control error
void buscarAlumno() {
    string dato;

    cout << "Ingrese dato de búsqueda: " << endl;
    cin >> dato;

    try { 
        Alumno* alumno = listaA.buscar(stoi(dato));

        if (alumno != nullptr) {
            cout << "Id: " << alumno -> getId() << endl;
            cout << "Nombre: " << alumno -> getNombre() << endl;
            cout << "Apellido: " << alumno -> getApellido() << endl;
            cout << "Carrera: " << alumno -> getCarrera() << endl;
            cout << "Fecha de Ingreso: " << alumno -> getIngreso() << endl;
        } else {
            cout << "No hay ningún alumno con la id " << dato << endl;
        }
    } catch (exception& e) {
        listaA.buscar(dato);
    }
    
    cout << endl;
}

//falta control error - eliminar registro de notas e historial de cursos
void eliminarAlumno() {
    string id;

    cout << "Ingrese id de alumno a eliminar: ";
    cin >> id;
    bool valido = false;

    while (!valido) {
        try {
            listaA.eliminar(stoi(id));
            valido = true;

        } catch (exception& e) {
            cout << "La id ingresada no es válida." << endl << endl;
        }
    }

    cout << endl;
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

    cout << "¡Saliendo de la gestión de alumnos!" << endl;

}

//Listo - falta control error
void registrarCurso() {
    int id;
    string nombre;
    int maxEst;
    string carrera;
    string profesor;

    cout << "Ingrese id del curso: ";
    cin >> id; 

    cout << "Ingrese nombre del curso: ";
    cin >> nombre;
     
    cout << "Ingrese capacidad máxima de estudiantes del curso: ";
    cin >> maxEst;

    cout << "Ingrese carrera del curso: ";
    cin >> carrera;

    cout << "Ingrese profesor que dicta el curso: ";
    cin >> profesor;

    Curso* curso = new Curso(id, nombre, maxEst, carrera, profesor);

    listaC.insertar(*curso);
         
    cout << "¡Curso registrado con éxito!" << endl << endl;
}

//Listo - falta control error
void buscarCurso() {
    string dato;

    cout << "Ingrese dato de búsqueda: " << endl;
    cin >> dato;

    try { 
        Curso* curso = listaC.buscar(stoi(dato));

        if (curso != nullptr) {
            cout << "Id: " << curso -> getId() << endl;
            cout << "Nombre: " << curso -> getNombre() << endl;
            cout << "Máximo de estudiantes: " << curso -> getMaxEst() << endl;
            cout << "Carrera: " << curso -> getCarrera() << endl;
            cout << "Profesor: " << curso -> getProfesor() << endl;
        } else {
            cout << "No hay ningún curso con la id " << dato << endl;
        }

    } catch (exception& e) {
        listaC.buscar(dato);
    }

    cout << endl;
}

//falta control error - eliminar registro de notas e historial de cursos
void eliminarCurso() {
    string id;

    cout << "Ingrese id de curso a eliminar: ";
    cin >> id;
    bool valido = false;

    while (!valido) {
        try {
            listaC.eliminar(stoi(id));
            valido = true;

        } catch (exception& e) {
            cout << "La id ingresada no es válida." << endl << endl;
        }
    }
    
    cout << endl;
}

void gestionCurso() {
    int opcion = 0;

    while (opcion != 4) {
        cout << "=== Menú de Gestión de Cursos ===" << endl;
        cout << "¿Qué desea hacer?" << endl;
        cout << "1) Registrar curso" << endl;
        cout << "2) Búsqueda de curso" << endl;
        cout << "3) Eliminar curso" << endl;
        cout << "4) Salir" << endl;
        cout << "> ";

        cin >> opcion;
        cout << endl;

        if (opcion == 1) { registrarCurso(); }
        else if (opcion == 2) { buscarCurso(); }
        else if (opcion == 3) { eliminarCurso(); }
        else if (opcion != 4) { cout << "Ese número no está dentro de las opciones" << endl; }
    }

    cout << "¡Saliendo de la gestión de cursos!" << endl;

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