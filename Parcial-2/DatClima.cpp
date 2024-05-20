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
	if(fecha < date.GetFecha())
	{
		return true;
	}else if (this->fecha == date.GetFecha()){
		if (this->hora < date.GetHora()) return true;
}
	return false;
}

std::ostream& operator<< (std::ostream& os , const DatClima& d)
{
	os << d.GetFecha()<< "-" << d.GetHora() << "-" << d.GetVeloViento() << "-" << d.GetTemp() << "-" << d.GetHumedadRela() << "-" << d.GetmmH20();
	return os;
}

std::istream& operator>> (std::istream& is , DatClima& d)
{
	const char delim ('-');
	char a;
	std::string aux;
	std::getline(is,aux);
	float veloViento,temp,humedadRela,mmH20;
	int cont (0);


/*	Fecha f;
	Hora h;
	float veloViento, temp, humedadRela, mmH20;

	is >> f >> a >> h >> a >> veloViento >> a >> temp >> a >> humedadRela >> a >> mmH20;
	d.SetFecha(f);
	d.SetHora(h);
	d.SetTemp(temp);
	d.SetVeloViento(veloViento);
	d.SetHumedadRela(humedadRela);
	d.SetmmH20(mmH20); */

	Fecha f;
	Hora h;
	is >> f;
	d.SetFecha(f);
	is >> h;
	d.SetHora(h);
	is >> veloViento >> a;
	d.SetVeloViento(veloViento);
	if(a != delim) throw std::invalid_argument("Error en datos climaticos");
	is >> temp >> a;
	d.SetTemp(temp);
	if(a != delim) throw std::invalid_argument("Error en datos climaticos");
	is >> humedadRela >> a;
	d.SetHumedadRela(humedadRela);
	if(a != delim) throw std::invalid_argument("Error en datos climaticos");
	is >> mmH20;
	d.SetmmH20(mmH20);

	return is;
}
