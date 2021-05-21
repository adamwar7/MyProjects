#pragma once
#include "Figure.h"

/** class represents the figure of knight */
class Knight : public Figure
{

public:
	/** no arguments constructor */
	Knight();

	/** constructor with two arguments
	@param color variable to set knight color
	@param startPosition position where knight will be placed at the start of the game
	*/
	Knight(bool color, sf::Vector2f startPosition);

	/** method loads texture from a file and set sprite texture */
	void loadTexture();


	/** function checks all possbile moves and returns them if exist
	@param map map which represent all fields
	@param pieces vector of all fields
	@return vector with all possible moves
	*/
	std::vector<sf::Vector2f> showPossibleMoves(std::map<std::string, std::pair<sf::Vector2f, bool>>& map, std::vector<sf::RectangleShape>& pieces);

	/** Destructor */
	~Knight() {};
	
};

