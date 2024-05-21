/*
 * Hora.hpp
 *
 *  Created on: May 15, 2024
 *      Author: Mallamaci Pelayes
 */

#ifndef HORA_HPP_
#define HORA_HPP_


#include <iostream>
#include <iomanip>

enum { HORA_INVALIDA };

/**
 * @class Hora
 * @brief
 * Almacena valores de hora y minuto, validando que sean correctos
 */
class Hora
{
private:
	int hora;
	int min;

	/**
	 * @fn void HoraValida()
	 * @brief
	 * Valida que  la hora sea correcta
	 */
	void HoraValida();
public:

	/**
	 * @fn  Hora()
	 * @brief
	 * Constructor de hora por defecto
	 */
	Hora(): hora(0), min(0) {};

	/**
	 * @fn  Hora(const int&, const int&)
	 * @brief
	 * Constructor con hora y minuto elegido por usuario
	 * @param h hora
	 * @param mi minuto
	 */
	Hora(const int& h, const int& mi);

	/**
	 * @fn int GetHora()const
	 * @brief
	 * Interfaz  de salida para hora
	 * @return hora
	 */
	int GetHora () const { return hora; }

	/**
	 * @fn int GetMin()const
	 * @brief
	 * Interfaz  de salida de minutos
	 * @return minuto
	 */
	int GetMin () const { return min; }

	//manejo error
	/**
	 * @fn void SetHora(const int&)
	 * @brief
	 * Interfaz de entrada para hora
	 * @param h hora
	 */
	void SetHora (const int& h);

	/**
	 * @fn void SetMinuto(const int&)
	 * @brief
	 * Interfaz de entrada para minuto
	 * @param m minuto
	 */
	void SetMinuto (const int& m);

	//operadores
	/**
	 * @fn bool operator <(const Hora&)
	 * @brief
	 * Operador de menor
	 * @param f hora
	 * @return
	 */
	bool operator< (const Hora& f);

	/**
	 * @fn bool operator >(const Hora&)
	 * @brief
	 * Operador de mayor
	 * @param f hora
	 * @return
	 */
	bool operator> (const Hora& f);

	/**
	 * @fn bool operator ==(const Hora&)
	 * @brief
	 * Operador de igualdad
	 * @param f hora
	 * @return
	 */
	bool operator== (const Hora& f);

	/**
	 * @fn bool operator !=(const Hora&)
	 * @brief
	 * Operador de desigualdad
	 * @param f hora
	 * @return
	 */
	bool operator!= (const Hora& f);

};
/**
 * @fn std::ostream operator <<&(std::ostream&, const Hora&)
 * @brief
 * Escribe hora con el formato hora-minuto
 * @param os
 * @param f
 * @return
 */
std::ostream& operator<< (std::ostream& os, const Hora& f);

/**
 * @fn std::istream operator >>&(std::istream&, Hora&)
 * @brief
 * Lee hora con formato hora-minuto
 * @param is
 * @param f
 * @return
 */
std::istream& operator>> (std::istream& is, Hora& f);

/**
 * @class HoraException
 * @brief
 * Manejo de exepciones de hora
 */
class HoraException: public std::exception
{
	int nro;
public:
	/**
	 * @fn  HoraException(const int&)
	 * @brief
	 * Constructor asigna la exepcion
	 * @param _nro
	 */
	HoraException(const int& _nro): nro(_nro) {};
	/**
	 * @fn const char what*()const throw ()
	 * @brief
	 * Manejo de exepciones
	 * @return
	 */
	virtual const char* what() const throw();
};



#endif /* HORA_HPP_ */
