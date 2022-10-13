/**
* @file main.cpp
* @author fmfigueroa (felixmanuelfigueroa@gmail.com)
* @brief Programacion Orientada a Objetos en C++
* @version 0.1
* @date 2022-09-16
*
* @copyright Copyright (c) 2022
*
*/

#include <iostream>
#include <string>
#include "Empleado.h"
#include "Supervisor.h"

using namespace std;

// Funciones amigas
float calcularSueldoMedioAnualPorDepartamento(Supervisor* supervisor, Empleado* empleado1, Empleado* empleado2)
{
	return (supervisor->sueldoAnual + empleado1->sueldoAnual + empleado2->sueldoAnual) / 3;
}

int main()
{
	Empleado* empleado1 = new Empleado();
	empleado1->setNombre("Alex");
	empleado1->setApellido("Sarmiento");
	empleado1->setSueldoAnual(8000.50);

	Empleado* empleado2 = new Empleado("Pedro", "Perez");
	empleado2->setSueldoAnual(5000);

	Supervisor* supervisor1 = new Supervisor();
	supervisor1->setNombre("Carlos");
	supervisor1->setApellido("Rodriguez");
	supervisor1->setSueldoAnual(15000.50);

	Supervisor* supervisor2 = new Supervisor("Ramon", "Lopez");

	Supervisor* p_copia = new Supervisor(*supervisor1);

	Supervisor supervisor = Supervisor(*empleado1);

	// Compartiendo Clases
	supervisor1->mostrarSueldoEmpleado(empleado1);
	empleado1->mostrarSueldoSupervisor(supervisor1);

	// Relaciones entre calses:
	empleado1->esSupervisadoPor(*supervisor1);
	supervisor1->supervisaA(*empleado1);

	cout << "\nEl sueldo mensual de " << empleado2->nombreCompleto() << " es " << empleado2->calcularSueldoMensual() << endl;

	cout << "El sueldo mensual de " << supervisor2->getNombre() << " " << supervisor2->getApellido() << " es " << supervisor2->calcularSueldoMensual(14) << endl;

	cout << "El sueldo anual del Dpto_1 es: " << calcularSueldoMedioAnualPorDepartamento(supervisor1, empleado1, empleado2) << endl;

	cout << "El sueldo mensual de " << p_copia->nombreCompleto() << " es " << p_copia->calcularSueldoMensual(12) << endl;

	cout << supervisor.getApellido() << " ahora es un Supervisor" << endl;

	cout << empleado1->getSupervisor()->getApellido() << " es el supervisor de " << supervisor1->getEmpleado()->getApellido() << endl;


	cin.get();
	return 0;
}