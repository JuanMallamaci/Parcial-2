/*
 * stringTest.cc
 *
 *  Created on: 26/08/2017
 *      Author: adrian
 */
#include <iostream>
#include <sstream>
#include <string>
#include <fstream> //para manejo de archivos
#include <exception>

#include "DatClima.hpp"
#include "Fecha.hpp"
#include "Main.hpp"
#include "EstacionMeteo.hpp"
//Estructura para auxiliar en la lectura de un archivo especializado
struct Experimento
{
	std::string descriptor;
	int ind;
	double tension, corriente;
	Experimento(){};
};

std::string int2string(const int& number)
{
	std::ostringstream oss;
	oss << number;
	return oss.str();
}



char Screen0()
{
	std::cout << "Eliga una opcion:" << std::endl << "1 - Leer por teclado." << std::endl
			<< "2 - Ingresar por teclado la ruta" << std::endl << "0 - Salir" << std::endl;

	char key;
	std::cin >> key;
	return key;
}

char Screen1()
{
	std::cout << "Ingrese los datos del dia con la forma: " << std::endl
			<< "anio-mes-dia-hora-minuto-velocidad viento-temperatura-humedad-mmH20" << std::endl;
	std::string s;
	std::cin >> s;

	return 'd';
}

char Screen2()
{
	std::cout << "Ingrese la ruta al archivo completa: ";

	std::string direc;
	std::cin >> direc;

	return 'd';
}

int main() {

	try {
		/*Fecha f1;
		Hora h1;
		std::ifstream arch("RawDatosEstacionMeteo");
		arch >> f1;
		std::cout << f1;
		arch >> h1;
		std::cout << h1;

		EstacionMeteo e;
		e.LeeArch("datosTest");
		e.OrdenaDatos();
		std::cout << e;*/
		Main();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
	catch ( int e)
	{
		std::cout << "\n" << e;
	}
		return 0;
}

int main2()
{

	/*int number=7878;
	std::string test="SSSSS";
	test += int2string(number);
	std::cout << test << std::endl;


	std::string test2="AAA 123 SSSSS 3.141592654";
	std::istringstream totalSString( test2 );
	std::string string1, string2;
	int    integer1;
	double pi;

	totalSString >> string1 >> integer1 >> string2 >> pi;

	std::cout << "Variables \"parseadas\" individualmente:" << std::endl;
	std::cout << "Primer string:  " << string1   << std::endl;
	std::cout << "Segundo string:  " << string2   << std::endl;
	std::cout << "Primer integer: " << integer1  << std::endl;
	std::cout << "Valor de pi:   " << pi        << std::endl;

	std::string str3( string1 + string2 );
	std::cout << "Concatenacion del primer y segundo string:" << std::endl;
	std::cout << str3 << std::endl;

	//Ejemplo leyendo de un archivo formateado con:
	// palabra descriptora, entero de indice, valor de tension, valor de corriente
	// y debe almacenarse en otro archivo de salida sin descriptor en el mismo orden:
	std::ifstream ifArch( "archivo.txt" );
	if( ifArch.fail() )
	{
		std::cout << "No pudo abrir \"archivo.txt\" para lectura\n";
		return -1;
	}
	std::ofstream ofArch( "archModif.txt" );
	if( ofArch.fail() )
	{
		ifArch.close(); //cierra porque ya estaba abierto
		std::cout << "No pudo abrir \"archModif.txt\" para escritura\n";
		return -1;
	}
	std::string strLinea;

	while( getline(ifArch,strLinea) )
	{
		if( !strLinea.empty() )// Ignora lineas vacias
		{
			Experimento exp;
			std::istringstream issLinea( strLinea );
			issLinea >> exp.descriptor;
			issLinea >> exp.ind;
			issLinea >> exp.tension;
			issLinea >> exp.corriente;
			//
			ofArch << exp.ind << "  ";
			ofArch << exp.tension << "  ";
			ofArch << exp.corriente << "\n";
			//
		}
	}
	//
	ifArch.close();
	ofArch.close();*/

	return 0;
}
