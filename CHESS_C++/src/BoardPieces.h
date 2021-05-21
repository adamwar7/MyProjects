#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

/** virtual base class represent every single pieces in chess board */
class BoardPieces
{
public:

	/* method loads position of all pieces to map
	@return map with correct positions and information about figures occupying fields and suitable key value 
	*/
	std::map<std::string, std::pair<sf::Vector2f, bool>> loadPositions();

	/** method creates 64 object of type RactangleShape, than sets color,size and position of each one
	@param positions map with all positions
	@return vector with 64 objects type of RectangleShape symbolizing all field on the chess board
	*/
	std::vector<sf::RectangleShape> setArray(std::map<std::string, std::pair<sf::Vector2f, bool>>);

protected:

	/** no argument constructor */
	BoardPieces();

	/** method returns map with position of all pieces
	@return map with position of all pieces
	*/
	std::map<std::string, std::pair<sf::Vector2f, bool>> getMapWithPositionOfPieces();

	/** methods returns vector with all object of type reactangleShape
	@return vector with all object of type reactangleShape
	*/
	std::vector<sf::RectangleShape> getVectorOfBoardPieces();

public:

	std::vector<sf::RectangleShape> pieces; ///<array for all pieces of board

	std::map<std::string, std::pair<sf::Vector2f, bool>> piecePosition; ///<position of all pieces
	
	/** method to draw board
	@param window object of type RenderWindow
	*/
	void drawBoard(sf::RenderWindow& window);

	/** method reset all colors on the board */
	void resetColors();

	/** Destructor */
	~BoardPieces() {};
};