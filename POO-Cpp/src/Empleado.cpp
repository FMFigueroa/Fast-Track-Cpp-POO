#include "Empleado.h"

using namespace std;

// Constructor Parametrizado
Empleado::Empleado(string nombre, string apellido)
{
    this->nombre = nombre;
    this->apellido = apellido;
}

// Metodos de Acceso Public usados en Copia de Supervisor
float Empleado::calcularSueldoMensual()
{
    return (sueldoAnual / numeroDePagas);
}
float Empleado::calcularSueldoMensual(int numeroDePagas)
{
    return (sueldoAnual / numeroDePagas);
}
string Empleado::nombreCompleto()
{
    return (nombre + " " + apellido);
}

// Metodos Observadores para atributos de acceso privado
const string* Empleado::getNombre() const
{
    return &nombre;
}
string Empleado::getApellido() const
{
    return apellido;
}
const float* Empleado::getSueldoAnual() const
{
    return &sueldoAnual;
}
const int Empleado::getNumeroDePagas() const
{
    return numeroDePagas;
}

const Supervisor* Empleado::getSupervisor() const
{
    return supervisor;
}

// Metodos Modificadores para atributos de acceso privado
void Empleado::setNombre(string nombre)
{
    this->nombre = nombre;
}
void Empleado::setApellido(string apellido)
{
    this->apellido = apellido;
}
void Empleado::setSueldoAnual(float sueldoAnual)
{
    this->sueldoAnual = sueldoAnual;
}

// Metodo de acceso public para atributos de clase amiga.
void Empleado::mostrarSueldoSupervisor(const Supervisor* supervisor)
{
    cout << "El sueldo anual del supervisor " << supervisor->nombre << " " << supervisor->apellido << " es: " << supervisor->sueldoAnual << endl;
}

// Asociacion y Navegavilidad entre clases
void Empleado::esSupervisadoPor(Supervisor& supervisor)
{
    this->supervisor = &supervisor;
}
