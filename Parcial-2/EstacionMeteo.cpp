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


EstacionMeteo::EstacionMeteo(float vel, float t, float mm, int a, int m, int d, int h, int mn)
{

	        DatClima nuevoDato;
	        Fecha f;
	        Hora hs;
	        nuevoDato.SetVeloViento(vel);
	        nuevoDato.SetTemp(t);
	        nuevoDato.SetmmH20(mm);
	        f.SetAnio(a);
	        f.SetMes(m);
			f.SetDia(d);
			hs.SetHora(h);
			hs.SetMinuto(mn);
			nuevoDato.SetHora(hs);
			nuevoDato.SetFecha(f);
	        datos.push_back(nuevoDato);
	    }

std::istream& operator>>(std::istream& in, EstacionMeteo& vec)
{
    DatClima dato;
    // Leer números del archivo hasta que se alcance el final del archivo
    while (in >> dato)
    {
    	vec.SetEstacionMeteo(dato);
    }
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
 void EstacionMeteo::LecArch(const std::string& ruta)
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
