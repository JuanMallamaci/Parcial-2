/*
 * Main.cpp
 *
 *  Created on: May 20, 2024
 *      Author: pc1
 */
#include "Main.hpp"
void LecturaTeclado();
void LecturaArch();

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

	EstacionMeteo estacion;

	estacion.LeeArch("RawDatosEstacionMeteo");
	estacion.OrdenaDatos();

	std::vector<DatClima> datoTmp;
	datoTmp = estacion.GetEstacion();
	int aux = estacion.GetCantDatos();
	std::cout << aux << "\n\n";

	std::string nombreFile;
	std::stringstream ss;
	ss << "VelViento" << datoTmp[0].GetVeloViento() << datoTmp[0].GetFecha().GetAnio() << "fin" << datoTmp[aux].GetVeloViento() << std::endl;
	nombreFile = ss.str();
	std::cout << nombreFile;

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

	std::cout  << "Para filanizar la lectura ingrese SALIR \n" << std::endl;
	std::cin >> strTmp;

	while(strExit != strTmp)
	{
		arch << strTmp << std::endl;
		std::cout  << "Para filanizar la lectura ingrese SALIR \n" << "Ingrese los datos del dia con la forma: " << std::endl
				<< "anio-mes-dia-hora-minuto-velocidad viento-temperatura-humedad-mmH20" << std::endl;
		std::cin >> strTmp;
	}
	arch.close();
}

void LecturaArch()
{
	//std::string direc;
	std::string direc ("RawDatosEstacionMeteo");

	std::cout << "Ingrese la ruta al archivo completa: ";
//	std::cin >> direc;
	std::ifstream arch(direc);

	if(!arch.is_open())
	{
		std::cerr << "Error abiendo archivo \n";
	}

	std::ofstream archWrite("lecturaDatos");
	while (!arch.eof())
	{
		std::string strTmp;

		arch >> strTmp;
		archWrite << strTmp << std::endl;
	}
	archWrite.close();
	arch.close();

}

