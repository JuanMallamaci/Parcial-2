/*
 * Menu.hpp
 *
 *  Created on: May 8, 2024
 *      Author: pc1
 */

#ifndef MENU_HPP_
#define MENU_HPP_
#include <string>
#include <iostream>
#include <map>

struct Screen
{
	void(*action)();
	std::string text;
};

class Menu
{
private:
	std::map<char,Screen> screens;
public:
	Menu();
};




#endif /* MENU_HPP_ */
