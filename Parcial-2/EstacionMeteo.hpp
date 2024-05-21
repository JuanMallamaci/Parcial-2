/*
 * EstacionMeteo.hpp
 *
 *  Created on: May 7, 2024
 *      Author: pc1
 */

#ifndef ESTACIONMETEO_HPP_
#define ESTACIONMETEO_HPP_

#include <vector>
#include <iostream>
#include <fstream>
#include "DatClima.hpp"
#include <string>
#include <algorithm>

/**
 * @class EstacionMeteo
 * @brief
 * Contiente datos climaticos, permite ordenamiento, lecuta y escritura
 */
class EstacionMeteo
{
private:
	std::vector<DatClima> datos;
public:
	EstacionMeteo(){};

	void SetEstacionMeteo (const std::vector<DatClima>& date) {datos = date;}
	void SetEstacionMeteo (const DatClima& date) {datos.push_back(date);}

	std::vector<DatClima> GetEstacion() const {return datos;}
	DatClima GetEstacion(const int& idx) const {return datos[idx];}
  
	int GetCantDatos() {return datos.size() - 1;}

	void SetDatos(float vel, float t, float mm, float hum, int a, int m, int d, int h, int mn);
	void ClearEstacion() { datos.clear();}
	std::vector<DatClima> RmEstacion(const int& idx);
	void LeeArch(const std::string& ruta);
	void WriteFile(const std::string& ruta);

	void OrdenaDatos(){std::sort(datos.begin(),datos.end());}
	static bool ComparaVelViento(const DatClima& a, const DatClima& b){return 	!(a.GetVeloViento() < b.GetVeloViento());}
	void OrdenaDatosViento(){std::sort(datos.begin(),datos.end(),ComparaVelViento);}
};
std::istream& operator>>(std::istream& in,  EstacionMeteo& vec);
std::ostream& operator<< (std::ostream& out, EstacionMeteo& vec);

#endif /* ESTACIONMETEO_HPP_ */
