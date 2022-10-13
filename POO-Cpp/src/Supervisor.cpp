#include "Supervisor.h"

using namespace std;


// Constructor de Copia:
Supervisor::Supervisor(const Supervisor& supervisorOriginal)
{
    nombre = supervisorOriginal.nombre;
    apellido = supervisorOriginal.apellido;
    sueldoAnual = supervisorOriginal.sueldoAnual;
}

// Constructor de conversion
Supervisor::Supervisor(const Empleado empleado)
{
    apellido = empleado.getApellido(); // return string
}

// Destructor Parametrizado
Supervisor::~Supervisor()
{
}

//  Metodos Observadores para atributos de acceso privado
const string* Supervisor::getNombre() const
{
    return &nombre;
}
string Supervisor::getApellido() const
{
    return apellido;
}
const float* Supervisor::getSueldoAnual() const
{
    return &sueldoAnual;
}
const int Supervisor::getNumeroDePagas() const
{
    return numeroDePagas;
}
const Empleado* Supervisor::getEmpleado() const
{
    return empleadoSupervisado;
}

// Metodos de Acceso Public
float Supervisor::calcularSueldoMensual(int numeroDePagas)
{
    float sueldoMensual;
    string tipoDeError;
    try
    {
        if (numeroDePagas == 0)
        {
            tipoDeError = "El numero de pagas es cero.";
            throw tipoDeError;
        }
    }
    catch (const string& tipoDeError)
    {
        cout << "Error: " << tipoDeError << endl;
    }
    sueldoMensual = (sueldoAnual / numeroDePagas);
    return sueldoMensual;
}
string Supervisor::nombreCompleto()
{
    return (nombre + " " + apellido);
}

// Metodos Modificadores para atributos de acceso privado
void Supervisor::setNombre(string nombre)
{
    this->nombre = nombre;
}
void Supervisor::setApellido(string apellido)
{
    this->apellido = apellido;
}
void Supervisor::setSueldoAnual(float sueldoAnual)
{
    this->sueldoAnual = sueldoAnual;
}

// Metodo de acceso public para atributos de clase amiga.
void Supervisor::mostrarSueldoEmpleado(const Empleado* empleado)
{
    cout << "El sueldo anual del empleado " << empleado->nombre << " " << empleado->getApellido() << " es: " << empleado->sueldoAnual << endl;
}

// Asociacion y Navegavilidad entre clases
void Supervisor::supervisaA(Empleado& empleado)
{
    this->empleadoSupervisado = &empleado;
}

