#pragma once
#include "Figure.h"

/** class represents pawn */
class Pawn :virtual public Figure
{

private:
	bool firstMove; ///< infromation about availability of first move: available == true, no == false

public:
	/** no arguments constructor */
	Pawn();

	/** constructor with three arguments
	@param color variable to set pawn color
	@param move variable to set availability of first move
	@param startPosition position where pawn will be placed at the start of the game
	*/
	Pawn(bool color, bool move, sf::Vector2f startPosition);

	/** method loads texture from a file and set sprite texture */
	void loadTexture();

	/** method checks all possbile moves and returns them if exist
	@param map map which represent all fields
	@param pieces vector of all fields
	@return vector with all possible moves
	*/
	std::vector<sf::Vector2f> showPossibleMoves(std::map<std::string, std::pair<sf::Vector2f, bool>>& map, std::vector<sf::RectangleShape>& pieces);

	/** method returns true if first move is possible, else false
	@return information about first move
	*/
	bool getFirstMove();
	
	/** method set first move to new value
	@param over first move is over
	*/
	void setFirstMove(bool over);
	
	/** Destructor */
	~Pawn() {};
};
