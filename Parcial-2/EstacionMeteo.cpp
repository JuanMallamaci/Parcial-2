/*
 * EstacionMeteo.cpp
 *
 *  Created on: May 7, 2024
 *      Author: pc1
 */

#include "EstacionMeteo.hpp"
#include "DatClima.hpp"
#include <fstream>


EstacionMeteo::EstacionMeteo(float vel, float t, float mm, int a, int m, int d, int h, int mn)
{

	        DatClima nuevoDato;
	        Fecha nuev;
	        nuevoDato.SetVeloViento(vel);
	        nuevoDato.SetTemp(t);
	        nuevoDato.SetmmH20(mm);
	        nuev.SetAnio(a);
	        nuev.SetMes(m);
			nuev.SetDia(d);
			nuev.SetHora(h);
			nuev.SetMinuto(mn);
			nuevoDato.SetFecha(nuev);
	        datos.push_back(nuevoDato);
	    }

std::istream& operator>>(std::istream& in, EstacionMeteo& vec) {
    DatClima dato;
    // Leer números del archivo hasta que se alcance el final del archivo
    while (in >> dato)
    {
    	vec.SetEstacionMeteo(dato);
    }
    return in;
}
EstacionMeteo LecArch(const std::string& ruta , const EstacionMeteo& e)
{
	EstacionMeteo aux;
	std::ifstream arch(ruta);
	/*if(!arch.is_open())
		{
			std::cerr << "Error arch" << std::endl;
			throw 1;
		}*/
		while (!arch.eof())
		{
			arch >> aux;
		}
		arch.close();

		return aux;
	}




