/*
 * DatClima.cpp
 *
 *  Created on: May 3, 2024
 *      Author: pc1
 */
#include "DatClima.hpp"
#include "string"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

bool DatClima::operator < (const DatClima& date)
{

	if(fecha != date.GetFecha())
	{
		return (fecha < date.GetFecha());
	}else
	{
		return (hora < date.GetHora());
	}
}

std::ostream& operator<< (std::ostream& os , const DatClima& d)
{
	os << d.GetFecha()<< "-" << d.GetHora() << "-" << d.GetVeloViento() << "-" << d.GetTemp() << "-" << d.GetHumedadRela() << "-" << d.GetmmH20();
	return os;
}

std::istream& operator>> (std::istream& is , DatClima& d)
{
	const char delim ('-');
	char aux;

	Fecha f;
	is >> f >> aux;
	if(aux != delim)
	{
		throw std::invalid_argument("Dormato de datos climaticos incorrecto");
	}
	d.SetFecha(f);

	Hora h;
	is >> h >> aux;
	if(aux != delim)
	{
		throw std::invalid_argument("Dormato de datos climaticos incorrecto");
	}
	d.SetHora(h);

	float veloViento;
	is >> veloViento >> aux;
	if(aux != delim)
	{
		throw std::invalid_argument("Dormato de datos climaticos incorrecto");
	}
	d.SetVeloViento(veloViento);


	float temp;
	is >> temp >> aux;
	if(aux != delim)
	{
		throw std::invalid_argument("Dormato de datos climaticos incorrecto");
	}
	d.SetTemp(temp);

	float humedadRela;
	is >> humedadRela >> aux;
	if(aux != delim)
	{
		throw std::invalid_argument("Dormato de datos climaticos incorrecto");
	}
	d.SetHumedadRela(humedadRela);

	float mmH20;
	is >> mmH20;
	d.SetmmH20(mmH20);

	return is;
}
