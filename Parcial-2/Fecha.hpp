/*
 * Fecha.hpp
 *
 *  Created on: May 3, 2024
 *      Author: Mallamaci, Pelayes
 */

#ifndef FECHA_HPP_
#define FECHA_HPP_

#include <iostream>
#include <iomanip>
#include <exception>

enum { ANIO_INVALIDO, MES_INVALIDO, DIA_INVALIDO };

/**
 * @class Fecha
 * @brief
 *	Alamacena anio mes dia validando que sea una fecha valida
 */
class Fecha
{
private:
	int anio;
	int mes;
	int dia;
	/**
	 * @fn void FechaValida()
	 * @brief
	 *	Valida si la fecha es valida, ¡En esta version este metodo no contempla anios bisiestos!
	 */
	void FechaValida();
public:

	/**
	 * @fn  Fecha()
	 * @brief
	 *	Constructor por defecto, inizializa con 1/1/1
	 */
	Fecha(): anio(1), mes(1), dia(1){};

	/**
	 * @fn  Fecha(const int&, const int&, const int&)
	 * @brief
	 *	Construye la fecha con los valores en los argumentos
	 * @param a anio
	 * @param m mes
	 * @param d dia
	 */
	Fecha(const int& a, const int& m, const int& d);

	/**
	 * @fn int GetAnio()const
	 * @brief
	 *	Interfaz de salida para anio
	 * @return anio
	 */
	int GetAnio () const { return anio; }

	/**
	 * @fn int GetMes()const
	 * @brief
	 *	Interfaz de salida para mes
	 * @return mes
	 */

	int GetMes () const { return mes; }

	/**
	 * @fn int GetDia()const
	 * @brief
	 *	Interfaz de salida para dia
	 * @return dia
	 */
	int GetDia () const { return dia; }

	/**
	 * @fn void SetFecha(const int&, const int&, const int&)
	 * @brief
	 * Interfaz de entrada para fecha
	 * @param a anio
	 * @param m mes
	 * @param d dia
	 */
	void SetFecha (const int& a, const int& m, const int& d);

	/**
	 * @fn void SetAnio(const int&)
	 * @brief
	 *	Interfaz de entrada para anio
	 * @param a anio
	 */
	void SetAnio (const int& a);

	/**
	 * @fn void SetMes(const int&)
	 * @brief
	 *	Interfaz de entrada para mes
	 * @param m mes
	 */
	void SetMes (const int& m);

	/**
	 * @fn void SetDia(const int&)
	 * @brief
	 *	Interfaz de entrada para dia
	 * @param d dia
	 */
	void SetDia (const int& d);

	//operadores
	/**
	 * @fn bool operator <(const Fecha&)
	 * @brief
	 *	Sobrecarga de operador menor
	 * @param f fecha
	 * @return
	 */
	bool operator< (const Fecha& f);

	/**
	 * @fn bool operator >(const Fecha&)
	 * @brief
	 *	Sobrecarga operador mayor
	 * @param f fecha
	 * @return
	 */
	bool operator> (const Fecha& f);

	/**
	 * @fn bool operator ==(const Fecha&)
	 * @brief
	 *	Sobrecarga de operador de igualidad
	 * @param f fecha
	 * @return
	 */
	bool operator== (const Fecha& f);

	/**
	 * @fn bool operator !=(const Fecha&)
	 * @brief
	 *	Sobrecarga de operador de desigual
	 * @param f fecha
	 * @return
	 */
	bool operator!= (const Fecha& f);

};

/**
 * @brief
 * 	Escribe fecha con el formato anio-mes-dia
 * @param os
 * @param f fecha
 * @return
 */
std::ostream& operator<< (std::ostream& os, const Fecha& f);

/**
 * @brief
 * Lee hora con formato anio-mes-dia
 * @param is
 * @param f fecha
 * @return
 */
std::istream& operator>> (std::istream& is, Fecha& f);


/**
 * @class FechaException
 * @brief
 * Manejo de exepciones
 */
class FechaException: public std::exception
{
	int nro;
public:
	/**
	 * @fn  FechaException(const int&)
	 * @brief
	 * Constructor asigna la exepcion
	 * @param _nro
	 */
	FechaException(const int& _nro): nro(_nro) {};
	/**
	 * @fn const char what*()const throw ()
	 * @brief
	 * Manejo de exepciones
	 * @return
	 */
	virtual const char* what() const throw();
};


#endif /* FECHA_HPP_ */
