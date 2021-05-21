#pragma once
#include "Figure.h"

/** class Rook */
class Rook:virtual public Figure
{
public:
	/** no arguments constructor */
	Rook();

	/** constructor with two arguments
	@param color variable to set rook color
	@param startPosition position where rook will be placed at the start of the game
	*/
	Rook(bool color, sf::Vector2f startPosition);

	/** method loads texture from a file and set sprite texture */
	void loadTexture();


	/** method collect all possible moves
	@param possibleAttacks possible attacks
	@param map map with all board coordinates
	@param pieces vector with all objects type of sf::RectangleShape
	@return vector with all possible moves
	*/
	std::vector<sf::Vector2f> showPossibleMoves(std::vector<sf::Vector2f> possibleAttacks, std::map<std::string, std::pair<sf::Vector2f, bool>>& map, std::vector<sf::RectangleShape>& pieces);

	/** Destructor */
	~Rook() {};
};

