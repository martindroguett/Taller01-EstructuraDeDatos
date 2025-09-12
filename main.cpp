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

//Listo
int controlErrorInt() {
    string s;
    cout << "> ";
    cin >> s;
    try {
        return stoi(s);
    } catch (exception e) {
        cout << "ERROR" << endl;
        return 0;
    }
}

//Listo
string controlErrorString() {
    string s;
    cout << "> ";
    cin >> s;
    for (char c: s) {
        if (!isalpha(c)) {
            cout << "- Only english alphabet letters are allowed!" << endl;
            return "";
        }
    }

    return s;
}

//Listo
double controlErrorDouble() {
    string s;
    cout << "> ";
    cin >> s;
    try {
        return stod(s);
    } catch (exception e) {
        cout << "ERROR" << endl;
        return 0;
    }
}

//Listo
void registrarAlumno() {
    int id = 0;
    string nombre = "";
    string apellido = "";
    string carrera = "";
    string fechaIngreso = "";

    while (id <= 0) {
        cout << "Enter student's ID (int > 0)" << endl;
        id = controlErrorInt();

        if (id <= 0) {
            cout << "- The id must be a positive integer" << endl;
        }
    }

    while (nombre == "") {
        cout << "Enter student's name" << endl;
        nombre = controlErrorString();
    }

    while (apellido == "") {
        cout << "Enter student's last name" << endl;
        apellido = controlErrorString();
    }

    while (carrera == "") { 
        cout << "Enter student's major" << endl;
        carrera = controlErrorString();
    }

    cout << "Enter student's enrollment date" << endl;
    cin >> fechaIngreso;

    Alumno* alumno = new Alumno(id, nombre, apellido, carrera, fechaIngreso);

    listaA.insertar(*alumno);

}

//Listo 
void buscarAlumno() {
    string dato;

    cout << "Enter search query" << endl;
    cout << "> ";
    cin >> dato;

    try { 
        Alumno* alumno = listaA.buscar(stoi(dato));

        if (alumno != nullptr) {
            cout << "ID: " << alumno -> getId() << endl;
            cout << "Name: " << alumno -> getNombre() << endl;
            cout << "Last name: " << alumno -> getApellido() << endl;
            cout << "Major: " << alumno -> getCarrera() << endl;
            cout << "Enrollment date: " << alumno -> getIngreso() << endl;
        } else {
            cout << "There's no student with the ID " << dato << endl;
        }
    } catch (exception& e) {
        listaA.buscar(dato);
    }
    
    cout << endl;
}

//Listo
void eliminarAlumno() {
    int id = 0;

    while (id <= 0) {
        cout << "Enter the ID of the student to delete" << endl;
        id = controlErrorInt();

        if (id <= 0) {
            cout << "- The id must be a positive integer" << endl;
        }
    }

    listaA.eliminar(id, true);
    cout << endl;
}

//Listo
void gestionAlumno() {
    int opcion = 0;

    while (opcion != 4) {
        cout << "=== Student Management Menu ===" << endl;
        cout << "Pick an option" << endl;
        cout << "1) Register a student" << endl;
        cout << "2) Search students" << endl;
        cout << "3) Delete a student" << endl;
        cout << "4) Return" << endl;

        opcion = controlErrorInt();
        cout << endl;

        if (opcion == 1) { registrarAlumno(); }
        else if (opcion == 2) { buscarAlumno(); }
        else if (opcion == 3) { eliminarAlumno(); }
        else if (opcion != 4) { cout << "- Enter a valid option" << endl; }
    }

    cout << "Exiting student management!" << endl << endl;

}

//Listo
void registrarCurso() {
    int id = 0;
    string nombre = "";
    int maxEst = 0;
    string carrera = "";
    string profesor = "";

    while (id <= 0) {
        cout << "Enter course's ID (int > 0)" << endl;
        id = controlErrorInt();

        if (id <= 0) {
            cout << "- The id must be a positive integer" << endl;
        }
    }

    while (nombre == "") {
        cout << "Enter course's name" << endl;
        nombre = controlErrorString();
    }
     
    while (maxEst <= 0) {
        cout << "Enter course's maximum capacity" << endl;
        maxEst = controlErrorInt();

        if (maxEst <= 0) {
            cout << "- The maximum capacity must be a positive integer" << endl;
        }
    }

    while (carrera == "") { 
        cout << "Enter course's major" << endl;
        carrera = controlErrorString();
    }

    while (profesor == "") {
        cout << "Enter course's professor" << endl;
        profesor = controlErrorString();
    }

    Curso* curso = new Curso(id, nombre, maxEst, carrera, profesor);

    listaC.insertar(*curso);

}

//Listo
void buscarCurso() {
    string dato;

    cout << "Enter search query" << endl;
    cout << "> ";
    cin >> dato;

    try { 
        Curso* curso = listaC.buscar(stoi(dato));

        if (curso != nullptr) {
            cout << "ID: " << curso -> getId() << endl;
            cout << "Course's name: " << curso -> getNombre() << endl;
            cout << "Maximum capacity: " << curso -> getMaxEst() << endl;
            cout << "Major: " << curso -> getCarrera() << endl;
            cout << "Professor: " << curso -> getProfesor() << endl;
        } else {
            cout << "There's no courses with the ID " << dato << endl;
        }

    } catch (exception& e) {
        listaC.buscar(dato);
    }

    cout << endl;
}

//Listo
void eliminarCurso() {
    int id = 0;

    while (id <= 0) {
        cout << "Enter the ID of the course to delete" << endl;
        id = controlErrorInt();

        if (id <= 0) {
            cout << "- The id must be a positive integer" << endl;
        }
    }

    listaC.eliminar(id, true);
    cout << endl;
}

//Listo
void gestionCurso() {
    int opcion = 0;

    while (opcion != 4) {
        cout << "=== Course Management Menu ===" << endl;
        cout << "Pick an option" << endl;
        cout << "1) Register a course" << endl;
        cout << "2) Search courses" << endl;
        cout << "3) Delete a course" << endl;
        cout << "4) Return" << endl;
        
        opcion = controlErrorInt();
        cout << endl;

        if (opcion == 1) { registrarCurso(); }
        else if (opcion == 2) { buscarCurso(); }
        else if (opcion == 3) { eliminarCurso(); }
        else if (opcion != 4) { cout << "- Enter a valid option!" << endl; }
    }

    cout << "Exiting course management menu!" << endl << endl;

}

//Listo
void inscribir() {
    int idA = 0;

    while (idA <= 0) { 
        cout << "Enter student's ID" << endl;
        idA = controlErrorInt();

        if (idA <= 0) {
            cout << "- The ID must be a positive integer" << endl;
        }
    }

    Alumno* alumno = listaA.buscar(idA);

    if (alumno == nullptr) {
        cout << "There's no student with the ID " << idA << endl;
        return; 
    }

    int idC = 0;

    while (idC <= 0) {
        cout << "Enter course's ID" << endl;
        idC = controlErrorInt();

        if (idC <= 0) {
            cout << "- The ID must be a positive integer" << endl;
        }
    }

    Curso* curso = listaC.buscar(idC);

    if (curso == nullptr) {
        cout << "There's no student with the ID " << idC << endl;
        return; 
    }

    if (alumno -> getCarrera() != curso -> getCarrera()) {
        cout << alumno -> getNombre() << " cannot be enrolled in " << 
        curso -> getNombre() << " because they are not in the same mayor" << endl;

        return;
    }

    curso -> inscribir(alumno); 
    cout << endl;

}

//Listo
void desinscribir() {
    int idA = 0;

    while (idA <= 0) { 
        cout << "Enter student's ID" << endl;
        idA = controlErrorInt();

        if (idA <= 0) {
            cout << "- The ID must be a positive integer" << endl;
        }
    }

    Alumno* alumno = listaA.buscar(idA);

    if (alumno == nullptr) {
        cout << "There's no student with the ID " << idA << endl;
        return; 
    }

    int idC = 0;

    while (idC <= 0) {
        cout << "Enter course's ID" << endl;
        idC = controlErrorInt();

        if (idC <= 0) {
            cout << "- The ID must be a positive integer" << endl;
        }
    }

    Curso* curso = listaC.buscar(idC);

    if (curso == nullptr) {
        cout << "There's no student with the ID " << idC << endl;
        return; 
    }

    if (alumno -> cursando(curso)) {
        curso -> eliminar(alumno);
    }

    cout << endl;

}

//Listo
void gestionInscripcion() {
    int opcion = 0;

    while (opcion != 3) {
        cout << "=== Inscriptions menu ===" << endl;
        cout << "Pick an option" << endl;
        cout << "1) Enroll a student to a course" << endl;
        cout << "2) Remove a student from a course" << endl;
        cout << "3) Return" << endl;

        opcion = controlErrorInt();

        if (opcion == 1) { inscribir(); }
        else if (opcion == 2) { desinscribir(); }
        else if (opcion != 3) { cout << "- Enter a valid option" << endl; }
    }
}

//Listo
void gestionNotas() {
    cout << "=== Grades Management ===" << endl;
    int idA = 0;

    while (idA <= 0) { 
        cout << "Enter student's ID" << endl;
        idA = controlErrorInt();

        if (idA <= 0) {
            cout << "- The ID must be a positive integer" << endl;
        }
    }

    Alumno* alumno = listaA.buscar(idA);

    if (alumno == nullptr) {
        cout << "There's no student with the ID " << idA << endl;
        return; 
    }

    int idC = 0;

    while (idC <= 0) {
        cout << "Enter course's ID" << endl;
        idC = controlErrorInt();

        if (idC <= 0) {
            cout << "- The ID must be a positive integer" << endl;
        }
    }

    Curso* curso = listaC.buscar(idC);

    if (curso == nullptr) {
        cout << "There's no course with the ID " << idC << endl;
        return; 
    }

    if (alumno -> cursando(curso)) {
        
        double nota = 0;

        while (nota < 1 || nota > 7) {
            cout << "Enter grade" << endl;
            nota = controlErrorDouble();

            if (nota < 1 || nota > 7) {
                cout << "- Enter a valid grade between (1.0 and 7.0)" << endl;
            }
        }

        alumno -> subirNota(curso -> getId(), nota);

        cout << "GRADES: " << endl;
        alumno -> verNotas();
    }

}

//Listo
void todosCarrera() {
    string carrera = "";

    while (carrera == "") {
        cout << "Enter major" << endl;
        carrera = controlErrorString();
    }

    cout << endl;
    listaA.buscarPorCarrera(carrera);

    cout << endl;
}

//Listo
void todosCurso() {
    int idA = 0;

    cout << "Enter student's ID" << endl;
    idA = controlErrorInt();

    Alumno* alumno = listaA.buscar(idA);

    if (alumno == nullptr) {
        cout << "There's no student with the ID " << idA << endl;
        return; 
    }

    alumno -> getCursos();
}

//Listo
void promedioNotas() {
    cout << "=== Grades Average ===" << endl;
    int idA = 0;

    while (idA <= 0) { 
        cout << "Enter student's ID" << endl;
        idA = controlErrorInt();

        if (idA == 0) {
            cout << "- The id must be a positive integer" << endl;
        }
    }
    

    Alumno* alumno = listaA.buscar(idA);

    if (alumno == nullptr) {
        cout << "There's no student with the ID " << idA << endl;
        return; 
    }

    int idC = 0;

    while (idC <= 0) {
        cout << "Enter course's ID" << endl;
        idC = controlErrorInt();

        if (idC <= 0) {
            cout << "- The ID must be a positive integer" << endl;
        }
    }

    Curso* curso = listaC.buscar(idC);

    if (curso == nullptr) {
        cout << "There's no course with the ID " << idC << endl;
        return; 
    }

    if (alumno -> cursando(curso)) {
        alumno -> getPromedio(curso -> getId());
    }

    cout << endl;
}

//Listo
void promedioGeneral() {
    cout << "=== Overall Grades Average ===" << endl;
    int idA = 0;

    while (idA <= 0) {
        cout << "Enter student's ID" << endl;
        idA = controlErrorInt();

        if (idA <= 0) {
            cout << "- The ID must be a positive integer" << endl;
        }
    }

    Alumno* alumno = listaA.buscar(idA);

    if (alumno == nullptr) {
        cout << "There's no student with the ID " << idA << endl;
        return; 
    }

    alumno -> getPromedio(0);
    cout << endl;
}

//Listo
void reportes() {
    int opcion = 0;

    while (opcion != 7) {
        cout << "=== Reports ===" << endl;
        cout << "Pick an option" << endl;
        cout << "1) See all students enrolled in a major" << endl;
        cout << "2) See all courses enrolled by a student" << endl;
        cout << "3) Calculate the grades average of a student" << endl;
        cout << "4) Calculate the overall grade average of a student" << endl;
        cout << "5) View all students" << endl;
        cout << "6) View all courses" << endl;
        cout << "7) Return" << endl;
        opcion = controlErrorInt();
        cout << endl;

        if (opcion == 1) { todosCarrera();}
        else if (opcion == 2) { todosCurso(); }
        else if (opcion == 3) { promedioNotas(); }
        else if (opcion == 4) { promedioGeneral(); }
        else if (opcion == 5) { listaA.ver(); }
        else if (opcion == 6) { listaC.ver(); }
        else if (opcion != 7) { cout << "- Enter a valid option!" << endl; }
    }
}

//Listo
int main() {
    int opcion = 0;

    while (opcion != 6) {
        cout << "Welcolme to the Academic Management System!" << endl;
        cout << "Pick an option" << endl;
        cout << "1) Students management" << endl;
        cout << "2) Courses management" << endl;
        cout << "3) Courses registrations" << endl;
        cout << "4) Grades management" << endl;
        cout << "5) Reports" << endl;
        cout << "6) Exit" << endl;

        opcion = controlErrorInt();
        cout << endl;

        if (opcion == 1) { gestionAlumno(); }
        else if (opcion == 2) { gestionCurso(); }
        else if (opcion == 3) { gestionInscripcion(); }
        else if (opcion == 4) { gestionNotas(); }
        else if (opcion == 5) { reportes(); }
        else if (opcion != 6) { cout << "- Enter a valid option!" << endl; }
    }

    cout << "Thanks!! Goodbye" << endl;

    return 0;
}