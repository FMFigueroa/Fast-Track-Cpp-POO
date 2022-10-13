#pragma once
#include <iostream>
#include <string>
#include "Empleado.h"

using namespace std;

class Empleado;
class Supervisor
{
public:

    Supervisor() {};
    Supervisor(string _nombre, string _apellido) : nombre(_nombre), apellido(_apellido) { sueldoAnual = 20000; };
    Supervisor(const Supervisor& supervisorOriginal);
    explicit Supervisor(const Empleado empleado);

    ~Supervisor();

    float calcularSueldoMensual(int numeroDePagas);
    string nombreCompleto();

    friend class Empleado;

    void mostrarSueldoEmpleado(const Empleado* empleado);
    friend float calcularSueldoMedioAnualPorDepartamento(Supervisor* supervisor, Empleado* empleado1, Empleado* empleado2);

    // Relaciones entre clase:
    void supervisaA(Empleado& empleado);

    // setter - Metodos Modificadores
    void setNombre(string nombre);
    void setApellido(string apellido);
    void setSueldoAnual(float sueldoAnual);

    // Getter - Metodos Observadores
    const string* getNombre() const; // return const string*
    string getApellido() const;      // return string
    const float* getSueldoAnual() const; // return const float*
    const int getNumeroDePagas() const;
    const Empleado* getEmpleado() const;

protected:
    // Los miebros privados No se heredan, pero los protegidos Si.

private:
    string nombre, apellido;
    float sueldoAnual;
    static const int numeroDePagas = 12;
    Empleado* empleadoSupervisado;
};




