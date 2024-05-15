/*
 * DatClima.cpp
 *
 *  Created on: May 3, 2024
 *      Author: pc1
 */
#include "DatClima.hpp"

std::ostream& operator<< (std::ostream& os , const DatClima& d)
{
	os << d.GetFecha() << d.GetHora() << "-" << "-" << d.GetVeloViento() << "-" << d.GetTemp() << "-" << d.GetHumedadRela() << "-" << d.GetmmH20();
	return os;
}

std::istream& operator>> (std::istream& is , DatClima& d)
{
	char deter('0');
	Fecha aux;
	is >> aux;
	d.SetFecha(aux);

	is >> deter;
	if( deter != '-')
	{
		throw 1;
	}

	Hora aux1;
	is >> aux1;
	d.SetHora(aux1);

	is >> deter;
	if( deter != '-')
	{
		throw 1;
	}

	float tmp;

	is >> tmp;
	d.SetVeloViento(tmp);
	is >> deter;

	if( deter != '-')
	{
		throw 1;
	}

	is >> tmp;
	d.SetTemp(tmp);
	is >> deter;

	if( deter != '-')
	{
		throw 1;
	}

	is >> tmp;
	d.SetHumedadRela(tmp);
	is >> deter;

	if( deter != '-')
	{
		throw 1;
	}

	is >> tmp;
	d.SetmmH20(tmp);

	return is;
}

