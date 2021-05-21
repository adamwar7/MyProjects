#pragma once
#include "Board.h"

/** class holds all objects which are used within chess board */
class Game
{

public:

	Board board; ///< chess board

	/** no agruments constructor, not used but required */
	Game() { };

	/** constructor with two arguments
	@param white symbolizing player with white figures
	@param black symbolizing player with black figures
	*/
	Game(Player white, Player black);

	/** method which returns mouse position after click in occupied field
	@param main window
	@return mouse position
	*/
	sf::Vector2f selectField(sf::RenderWindow& window);

	/** Destructor */
	~Game() {};
	
};

