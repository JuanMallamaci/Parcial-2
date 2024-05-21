/*
 * EstacionMeteo.cpp
 *
 *  Created on: May 7, 2024
 *      Author: pc1
 */

#include "EstacionMeteo.hpp"
#include "DatClima.hpp"
#include "Hora.hpp"
#include <fstream>

std::vector<DatClima> EstacionMeteo::RmEstacion(const int& idx)
{
	if(idx < datos.size())
	{
		datos.erase(datos.begin() + idx); //validar rango
	}

	return datos;
}

void EstacionMeteo::LeeArch(const std::string& ruta)
{
	std::ifstream arch(ruta);

	if(!arch.is_open())
	{
		std::cerr << "Error arch" << std::endl;
		throw 9;
	}

	while (!arch.eof())
	{
		DatClima tmp;
		arch >> tmp;
		this->SetEstacionMeteo(tmp);
	}
	arch.close();

}

void EstacionMeteo::EscribeArch(const std::string& ruta)
{
	std::ofstream arch(ruta);
	if(!arch.is_open())
	{
		std::cerr << "Error abriendo archivo \n";
	}
	std::vector<DatClima>:: iterator ite;
	for(ite = datos.begin() ; ite != datos.end() ; ite++)
	{
		arch << *ite ;
		if(ite != datos.end()-1)  arch << std::endl; // valida si es el ultimo para no agregar un \n de mas
	}
	arch.close();
}

std::istream& operator>>(std::istream& in, EstacionMeteo& vec)
{
    DatClima dato;

    in >> dato;
    vec.SetEstacionMeteo(dato);
    return in;
}

std::ostream& operator<< (std::ostream& out, EstacionMeteo& vec)
{
	std::vector<DatClima>:: iterator it;
	std::vector<DatClima> aux = vec.GetEstacion();

	for ( it = aux.begin() ; it != aux.end() ; it++)
	{
		out << *it << std::endl;
	}
	return out;
}
