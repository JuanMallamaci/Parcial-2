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
 *	Almacena datos climaticos en un contenedor tipo vector
 */
class EstacionMeteo
{
private:
	std::vector<DatClima> datos;
	/**
	 * @fn bool ComparaVelViento(const DatClima&, const DatClima&)
	 * @brief
	 *	Define criterio de ordenamiento de los datos climaticos
	 * @param a
	 * @param b
	 * @return
	 */
	static bool ComparaVelViento(const DatClima& a, const DatClima& b){return 	!(a.GetVeloViento() < b.GetVeloViento());}
public:
	/**
	 * @fn  EstacionMeteo()
	 * @brief
	 * 	Constructor por defecto sin inicializar miembros
	 */
	EstacionMeteo(){};
	/**
	 * @fn void SetEstacionMeteo(const std::vector<DatClima>&)
	 * @brief
	 *	interfaz de entrada para un vector de datos climaticos
	 * @param date
	 */
	void SetEstacionMeteo (const std::vector<DatClima>& date) {datos = date;}
	/**
	 * @fn void SetEstacionMeteo(const DatClima&)
	 * @brief
	 * 	interfaz de entrada para un dato climatico
	 * @param date
	 */
	void SetEstacionMeteo (const DatClima& date) {datos.push_back(date);}
	/**
	 * @fn std::vector<DatClima> GetEstacion()const
	 * @brief
	 * 	interfaz de salida para un vector de datos climaticos
	 * @return
	 */
	std::vector<DatClima> GetEstacion() const {return datos;}
	/**
	 * @fn DatClima GetEstacion(const int&)const
	 * @brief
	 *	interfaz de salida para un dato climatico especifico
	 * @param idx
	 * @return
	 */
	DatClima GetEstacion(const int& idx) const {return datos[idx];}
	/**
	 * @fn int GetCantDatos()
	 * @brief
	 * 	interfaz de salida para el tamaño del contenedor
	 * @return
	 */
	int GetCantDatos() {return datos.size() - 1;}
	/**
	 * @fn void ClearEstacion()
	 * @brief
	 * Vacia el contenedor
	 */
	void ClearEstacion() { datos.clear();}
	/**
	 * @fn std::vector<DatClima> RmEstacion(const int&)
	 * @brief
	 * Elimina un dato clima especificado
	 * @param idx
	 * @return
	 */
	std::vector<DatClima> RmEstacion(const int& idx);
	/**
	 * @fn void LeeArch(const std::string&)
	 * @brief
	 *	Lee una Estacion Metereologica desde un Archivo especificado
	 * @param ruta
	 */
	void LeeArch(const std::string& ruta);
	/**
	 * @fn void EscribeArch(const std::string&)
	 * @brief
	 *	Escribe una Estacion Metereologica hacia un Archivo especificado
	 * @param ruta
	 */
	void EscribeArch(const std::string& ruta);
	/**
	 * @fn void OrdenaDatos()
	 * @brief
	 * Ordena los elementos del vector de forma ascendente
	 */
	void OrdenaDatos(){std::sort(datos.begin(),datos.end());}
	/**
	 * @fn void OrdenaDatosViento()
	 * @brief
	 * Ordena los elementos del vector segun critrerio personalizado
	 */
	void OrdenaPorViento(){std::sort(datos.begin(),datos.end(),ComparaVelViento);}
};
/**
 * @fn std::istream operator >>&(std::istream&, EstacionMeteo&)
 * @brief
 *	Lee una Estacion Metereologica
 * @param in
 * @param vec
 * @return
 */
std::istream& operator>>(std::istream& in,  EstacionMeteo& vec);
/**
 * @fn std::ostream operator <<&(std::ostream&, EstacionMeteo&)
 * @brief
 *	Escribe una Estacion Metereologica
 * @param out
 * @param vec
 * @return
 */
std::ostream& operator<< (std::ostream& out, EstacionMeteo& vec);

#endif /* ESTACIONMETEO_HPP_ */
