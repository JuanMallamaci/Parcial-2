/*
 * DatClima.hpp
 *
 *  Created on: May 3, 2024
 *      Author: pc1
 */

#ifndef DATCLIMA_HPP_
#define DATCLIMA_HPP_
#include <iostream>
#include <fstream>
#include <vector>
#include "Fecha.hpp"
#include "Hora.hpp"

/**
 * @class DatClima
 * @brief
 * Almacena datos climaticos (velocidad de viento , temperatura , humedad relativa , milimetros de agua)
 * junto con datos tipo Fecha y Hora
 */
class DatClima
{
private:
	Fecha fecha;
	Hora hora;
	float veloViento;
	float temp;
	float humedadRela ;
	float mmH20;
public:
	/**
	 * @fn DatClima()
	 * @brief
	 * Constructor por defecto inicializa los datos en 0
	 */
	DatClima ():fecha(), veloViento(0),temp(0), humedadRela(0), mmH20(0) {};
	/**
	 * @fn  DatClima(const Fecha&, const Hora&, const float&, const float&, const float&, const float&)
	 * @brief
	 * 	Cronstruye los datos climaticos con los valores de los argumentos
	 * @param f
	 * @param hs
	 * @param v
	 * @param t
	 * @param h
	 * @param mm
	 */
	DatClima(const Fecha& f, const Hora& hs, const float& v, const float& t, const float& h, const float& mm):fecha(f), hora (hs), veloViento(v), temp(t), humedadRela(h), mmH20(mm) {};
	/**
	 * @fn Fecha GetFecha()const
	 * @brief
	 * 	interfaz de salida para fecha
	 * @return fecha
	 */
	Fecha GetFecha() const { return fecha; }
	/**
	 *@fn Hora GetHora()const
	 *@brief
	 *	interfaz de salida para hora
	 *@return hora
	 */
	Hora GetHora() const { return hora; }
	/**
	 * @fn float GetTemp()const
	 * @brief
	 *	interfaz de salida para temperatura
	 * @return temp
	 */
	float GetTemp() const { return temp; }
	/**
	 * @fn float GetVeloViento()const
	 * @brief
	 * 	interfaz de salida de velocidad de viento
	 * @return veloViento
	 */
	float GetVeloViento() const { return veloViento; }
	/**
	 * @fn float GetHumedadRela()const
	 * @brief
	 * 	interfaz de salida para humedad relativa
	 * @return humedadRela
	 */
	float GetHumedadRela() const { return humedadRela; }
	/**
	 * @fn float GetmmH20()const
	 * @brief
	 * 	interfaz de salida para milimetros de agua
	 * @return mmH20
	 */
	float GetmmH20() const { return mmH20; }
	/**
	 * @fn void SetFecha(const Fecha&)
	 * @brief
	 * 	interfaz de entrada para fecha
	 * @param f
	 */
	void SetFecha(const Fecha& f) { fecha = f; }
	/**
	 * @fn void SetHora(const Hora&)
	 * @brief
	 * 	interfaz de entrada para hora
	 * @param h
	 */
	void SetHora(const Hora& h) { hora = h; }
	/**
	 * @fn void SetTemp(const float&)
	 * @brief
	 * 	interfaz de entrada para temperatura
	 * @param t
	 */
	void SetTemp(const float& t) { temp = t; }
	/**
	 * @fn void SetVeloViento(const float&)
	 * @brief
	 * 	interfaz de entrada para velocidad de viento
	 * @param v
	 */
	void SetVeloViento(const float& v) { veloViento = v; }
	/**
	 * @fn void SetHumedadRela(const float&)
	 * @brief
	 * 	interfaz de entrada para humedad relativa
	 * @param h
	 */
	void SetHumedadRela(const float& h) { humedadRela = h; }
	/**
	 * @fn void SetmmH20(const float&)
	 * @brief
	 *	interfaz de entrada para milimetros de agua
	 * @param h
	 */
	void SetmmH20(const float& h) { mmH20 = h; }
	/**
	 * @fn bool operator <(const DatClima&)
	 * @brief
	 *	Sobrecarga de operador menor
	 * @param date
	 * @return
	 */
	bool operator< (const DatClima& date);
	//bool operator> (const DatClima& date) {return !(this < date);}

};
/**
 * @fn std::ostream operator <<&(std::ostream&, const DatClima&)
 * @brief
 * 	Escribe un dato climatico con el formato
 * 	anio-mes-dia-hora-minutos-velocidad de viento-temperatura-humedad relativa-milimetros de agua
 * @param os
 * @param d
 * @return
 */
std::ostream& operator<< (std::ostream& os , const DatClima& d);
/**
 * @fn std::istream operator >>&(std::istream&, DatClima&)
 * @brief
 * 	Lee un dato climatico con el formato
 * 	anio-mes-dia-hora-minutos-velocidad de viento-temperatura-humedad relativa-milimetros de agua
 * @param is
 * @param d
 * @return
 */
std::istream& operator>> (std::istream& is , DatClima& d);

#endif /* DATCLIMA_HPP_ */
