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

#include "DatClima.hpp"
#include "Fecha.hpp"
#include "Menu.hpp"
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

void UnaCosaLoca(std::string& texto, int& n)
{
	std::cout << texto << " -AAAAAAAAAAAAAAAAAA- " << n << std::endl;
}

int main()
{
	Menu test;
	test.AddScreen('a', "Este es el menu de prueba", UnaCosaLoca);
}

int main2()
{
	/*
	int number=7878;
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
	ofArch.close();
	*/
	return 0;
}
