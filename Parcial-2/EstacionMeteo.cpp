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


void EstacionMeteo::SetDatos(float vel, float t, float mm, float hum, int a, int m, int d, int h, int mn)
{
	DatClima nuevoDato;
	Fecha f;
	Hora hs;

	nuevoDato.SetVeloViento(vel);
	nuevoDato.SetTemp(t);
	nuevoDato.SetmmH20(mm);
	nuevoDato.SetHumedadRela(hum);

	f.SetFecha(a, m, d);
	nuevoDato.SetFecha(f);

	hs.SetHora(h);
	hs.SetMinuto(mn);
	nuevoDato.SetHora(hs);

	datos.push_back(nuevoDato);
}

std::vector<DatClima> EstacionMeteo::RmEstacion(const int& idx)
{
	if(idx < datos.size())
	{
		datos.erase(datos.begin() + idx);
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

std::istream& operator>>(std::istream& in, EstacionMeteo& vec)
{
    DatClima dato;

    in >> dato;
    vec.SetEstacionMeteo(dato);

//    while (in >> dato)
//    {
//    	vec.SetEstacionMeteo(dato);
//    }
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
