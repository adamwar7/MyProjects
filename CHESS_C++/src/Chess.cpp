#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Game.h"
#include "Interface.h"
#include "AppLogic.h"
#include <regex>

int main()
{
	Interface intfc;
	AppLogic logic(intfc);
	logic.play();

	
	return 0;
}
