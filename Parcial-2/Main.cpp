/*
 * Main.cpp
 *
 *  Created on: May 20, 2024
 *      Author: pc1
 */
#include "Main.hpp"
void LecturaTeclado();
void LecturaArch();
void FileFin();
std::string Name(std::vector<DatClima>& date);

Main::Main()
{
	char key('0');

	while(key != '9')
	{
		switch(key)
		{
		case '0':
			std::cout << "Eliga una opcion:" << std::endl << "1 - Leer por teclado." << std::endl
						<< "2 - Ingresar por teclado la ruta" << std::endl << "9 - Salir" << std::endl;
			std::cin >> key;
			break;
		case '1':
			LecturaTeclado();
			key = '9';
			break;
		case  '2':
			LecturaArch();
			key = '9';
			break;
		}
	}

	FileFin();
}

void LecturaTeclado()
{
	std::ofstream arch("lecturaDatos");

	if(!arch.is_open())
	{
		std::cerr << "Error abiendo archivo \n";
	}

	const std::string strExit("SALIR");
	std::string strTmp;

	std::cout  << "Para filanizar la lectura ingrese SALIR \n" << "Ingrese los datos del dia con la forma: " <<
				"anio-mes-dia-hora-minuto-velocidad viento-temperatura-humedad-mmH20" << std::endl;
	std::cin >> strTmp;

	while(strExit != strTmp)
	{
		arch << strTmp << std::endl;
		std::cout  << "Para filanizar la lectura ingrese SALIR \n" << "Ingrese los datos del dia con la forma: " <<
						"anio-mes-dia-hora-minuto-velocidad viento-temperatura-humedad-mmH20" << std::endl;
		std::cin >> strTmp;
	}
	arch.close();
}

void LecturaArch()
{
	std::string direc;
	//std::string direc ("datosTest");

	std::cout << "Ingrese la ruta al archivo completa: ";
	std::cin >> direc;
	std::ifstream arch(direc);

	if(!arch.is_open())
	{
		std::cerr << "Error abriendo archivo \n";
	}

	std::ofstream archWrite("lecturaDatos");

	std::string strTmp;
	std::getline(arch, strTmp);
	archWrite << strTmp;
	while (std::getline(arch, strTmp))
	{
		archWrite << std::endl <<strTmp;
	}
	archWrite.close();
	arch.close();
}
void FileFin()
{
	EstacionMeteo estacion;

	estacion.LeeArch("lecturaDatos");
	estacion.OrdenaDatos();

	std::vector<DatClima> datoTmp;
	datoTmp = estacion.GetEstacion();
	std::string nombre = Name (datoTmp);

	estacion.OrdenaDatosV();
	estacion.WriteFile(nombre);
}
std::string Name(std::vector<DatClima>& date)
{
	int aux = date.size() - 1;
	std::string nombreFile;
	std::stringstream ss;
	ss << "VelViento" << date[0].GetFecha() << "inicio" << date[aux].GetFecha() << "fin.dat" << std::endl;
	nombreFile = ss.str();
	return nombreFile;
}
