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
	float ult4[4];
	int cont (0);

//	Fecha f;
//	Hora h;
//	float veloViento, temp, humedadRela, mmH20;
//
//	is >> f >> a >> h >> a >> veloViento >> a >> temp >> a >> humedadRela >> a >> mmH20;
//	d.SetFecha(f);
//	d.SetHora(h);
//	d.SetTemp(temp);
//	d.SetVeloViento(veloViento);
//	d.SetHumedadRela(humedadRela);
//	d.SetmmH20(mmH20);

	Fecha f;
	Hora h;
	is >> f >> a >> h;
	is >> a >> ult4[0] >> a >> ult4[1] >> a >> ult4[2] >> a >> ult4[3];
	d.SetTemp(ult4[0]);
	d.SetVeloViento(ult4[1]);
	d.SetHumedadRela(ult4[2]);
	d.SetmmH20(ult4[3]);
	for(auto itr = aux.rbegin() ; itr != aux.rend() ; itr++)
	{

		if(*itr != delim)
		{
			if( cont < 4)
			{
				ult4[cont++] = static_cast<float>(*itr);//convertir a float
			}
		}
	}
	d.SetTemp(ult4[0]);
	d.SetVeloViento(ult4[1]);
	d.SetHumedadRela(ult4[2]);
	d.SetmmH20(ult4[3]);
//	//Lectura de hora y fecha
	return is;
}

