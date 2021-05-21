#pragma once
#include "BoardPieces.h"
#include "Player.h"

/** class represents chess board */
class Board :virtual public BoardPieces
{
public:
	Player white; ///< object of type Player for white figures
	Player black; ///< object of type Player for black figures

	/** no argument constructor */
	Board();

	/** constructor with two arguments
	@param white object of type Plyer for white figures
	@param black object of type Plyer for black figures
	*/
	Board(Player white, Player black);

	/** method draws all figures
	@param window object of type sf::RenderWindow
	*/
	void drawFigures(sf::RenderWindow& window);

	/** Destructor */
	~Board() {};
};

