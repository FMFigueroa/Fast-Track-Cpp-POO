#pragma once
#include <iostream>
#include <string>
#include "Supervisor.h"

using namespace std;
class Supervisor;

class Empleado
{
public:
	Empleado() {};
	Empleado(string nombre, string apellido);

	float calcularSueldoMensual();
	float calcularSueldoMensual(int numeroDePagas);
	string nombreCompleto();

	friend class Supervisor;

	void mostrarSueldoSupervisor(const Supervisor* supervisor);
	friend float calcularSueldoMedioAnualPorDepartamento(Supervisor* supervisor, Empleado* empleado1, Empleado* empleado2);

	// Relaciones entre clase:
	void esSupervisadoPor(Supervisor& supervisor);

	// Getter - Metodos Observadores
	const string* getNombre() const;     // return const string*
	string getApellido() const;          // return string
	const float* getSueldoAnual() const; // return const float*
	const int getNumeroDePagas() const;
	const Supervisor* getSupervisor() const;

	// setter - Metodos Modificadores
	void setNombre(string nombre);
	void setApellido(string apellido);
	void setSueldoAnual(float sueldoAnual);

private:
	string nombre, apellido;
	float sueldoAnual;
	static const int numeroDePagas = 12;
	Supervisor* supervisor;
};


