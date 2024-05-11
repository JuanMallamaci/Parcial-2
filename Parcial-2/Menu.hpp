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

/*
 *
 */


typedef char(*FuncPtr)();
char DefScreen();

class Menu
{
private:
	std::map<char, FuncPtr> screen;

public:
	Menu(const char& key = 'd', FuncPtr action = DefScreen) { screen[key] = action; };

	void AddScreen(const char& key, FuncPtr action) { screen[key] = action; };
	void LoopScreen(const char& exitKey);
};




#endif /* MENU_HPP_ */
