#pragma once
#include <iostream>
#include"Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"
#include <vector>

/** class represents player */
class Player
{

public:
	int points = 0; ///< player points
	bool color; ///< color of player figures
	std::vector<Pawn*> pawns; ///< vector of pointer to 8 pawns
	Rook* ra; ///< pointer to rook nr 1
	Rook* rh; ///< pointer to rook nr 2
	Knight* kb; ///< pointer to knight nr 1
	Knight* kg; ///< pointer to knight nr 2
	Bishop* bc; ///< pointer to bishop nr 1
	Bishop* bf; ///< pointer to bishop nr 2
	Queen* queen; ///< pointer to queen
	King* king; ///< pointer to king

public:

	/** method allocates memory for each figure and sets pointer to right figure */
	void setFigures();

	/** no arguments constructor */
	Player();

	/** constructor with one argument
	@param color color of player figures
	*/
	Player(bool color);

	/** method return all possible moves and attacks for white figure
	@param figurePosition selected figure
	@param map map which represent all fields
	@param pieces vector of all fields
	@param opposite player with black figures
	@return vector with all possible moves and attacks
	*/
	std::vector<sf::Vector2f> showWhiteFigureMove(sf::Vector2f figurePosition, std::map<std::string, std::pair<sf::Vector2f, bool>>& map, std::vector<sf::RectangleShape>& pieces, Player& opposite);


	/** method return all possible moves and attacks for black figure
	@param figurePosition selected figure
	@param map map which represent all fields
	@param pieces vector of all fields
	@param opposite player with white figures
	@return vector with all possible moves and attacks
	*/
	std::vector<sf::Vector2f> showBlackFigureMove(sf::Vector2f figurePosition, std::map<std::string, std::pair<sf::Vector2f, bool>>& map, std::vector<sf::RectangleShape>& pieces, Player& opposite);

	/** method changes field color if selected figure can attack this field
	@param figurePosition selected figure
	@param map map which represent all fields
	@param pieces vector of all fields
	@param opposite player with black figures
	@return vector with all possible moves and attacks
	*/
	std::vector<sf::Vector2f> changeColorIfAttackIsPossible(sf::Vector2f figurePosition, std::map<std::string, std::pair<sf::Vector2f, bool >>& map, std::vector<sf::RectangleShape>& pieces, Player& opposite);


	/** method compares fields and returns fields where rook can attack
	@param figurePosition selected figure
	@param map map which represent all fields
	@param pieces vector of all fields
	@param opposite player with opposite figures
	@return vector with all possible attacks
	*/
	std::vector<sf::Vector2f> RookPossibleAttacks(sf::Vector2f figurePosition, std::map<std::string, std::pair<sf::Vector2f, bool >>& map, std::vector<sf::RectangleShape>& pieces, Player& opposite);

	/** method compares fields and returns fields where knight can attack
	@param figurePosition selected figure
	@param map map which represent all fields
	@param pieces vector of all fields
	@param opposite player with opposite figures
	@return vector with all possible attacks
	*/
	std::vector<sf::Vector2f> KnightPossibleAttacks(sf::Vector2f figurePosition, std::map<std::string, std::pair<sf::Vector2f, bool >>& map, std::vector<sf::RectangleShape>& pieces, Player& opposite);

	/** method compares fields and returns fields where bishop can attack
	@param figurePosition selected figure
	@param map map which represent all fields
	@param pieces vector of all fields
	@param opposite player with opposite figures
	@return vector with all possible attacks
	*/
	std::vector<sf::Vector2f> BishopPossibleAttacks(sf::Vector2f figurePosition, std::map<std::string, std::pair<sf::Vector2f, bool >>& map, std::vector<sf::RectangleShape>& pieces, Player& opposite);

	/** method compares fields and returns fields where queen can attack
	@param figurePosition selected figure
	@param map map which represent all fields
	@param pieces vector of all fields
	@param opposite player with opposite figures
	@return vector with all possible attacks
	*/
	std::vector<sf::Vector2f> QueenPossibleAttacks(sf::Vector2f figurePosition, std::map<std::string, std::pair<sf::Vector2f, bool >>& map, std::vector<sf::RectangleShape>& pieces, Player& opposite);

	/** method compares fields and returns fields where king can attack
	@param figurePosition selected figure
	@param map map which represent all fields
	@param pieces vector of all fields
	@param opposite player with opposite figures
	@return vector with all possible attacks
	*/
	std::vector<sf::Vector2f>  KingPossibleAttacks(sf::Vector2f figurePosition, std::map<std::string, std::pair<sf::Vector2f, bool >>& map, std::vector<sf::RectangleShape>& pieces, Player& opposite);

	/** method compares fields and returns field where figure can attack
	@param positionToChange selected field
	@param map map which represent all fields
	@param pieces vector of all fields
	@param opposite player with opposite figures
	@return vector with possible attack
	*/
	sf::Vector2f compareAttackFiled(sf::Vector2f positionToChange, std::map<std::string, std::pair<sf::Vector2f, bool >>& map, std::vector<sf::RectangleShape>& pieces, Player& opposite);

	/** method compares fields and changes field color if position is correct
	@param positionToChange selected field
	@param map map which represent all fields
	@param pieces vector of all fields
	@param color color to change
	@return vector with all changed fields
	*/
	std::vector<sf::Vector2f> changeFieldColorIfPositonIsCorrect(sf::Vector2f positionToChange, std::vector<sf::RectangleShape>& pieces, sf::Color color);

	/** method responsibles for select suitable figure to move
	@param availableMoves vector with all moves and attacks
	@param map map which represent all fields
	@param pieces vector of all fields
	@param window object of type RenderWindow
	@return correct mousePosition
	*/
	sf::Vector2f Move(std::vector<sf::Vector2f> availableMoves, std::map<std::string, std::pair<sf::Vector2f, bool>>& map, std::vector<sf::RectangleShape>& pieces, sf::RenderWindow& window, Player& opposite);


	/** method responsibles for move of figure
	@param piecePosition piece Position
	@param map map which represent all fields
	@param pieces vector of all fields
	*/
	void moveFigure(sf::Vector2f piecePosition, sf::Vector2f positionToMove, std::map<std::string, std::pair<sf::Vector2f, bool>>& map, std::vector<sf::RectangleShape>& pieces, Player& opposite);

	/** method changes enemy figure position when is killed
	@param positionToMove position to move
	@param opposite opposite player
	@return value of figure
	*/
	int takeTheFigure(sf::Vector2f positionToMove, Player& opposite);


	/** method checks position of all figures,
	returns true if position to change is not equal any position of player figures,
	else returns false
	@param positionToChange position to change
	@return not equal your figures == true, equal your figures == false
	*/
	bool isNotEqualYourFigures(sf::Vector2f positionToChange);


	/** method resets position of all figures */
	void ResetFigures();


	/** method checks check
	@return true == check, false == no
	*/
	bool checkCheck(std::map<std::string, std::pair<sf::Vector2f, bool>>& map, std::vector<sf::RectangleShape>& pieces, Player& opposite);

	/** Destructor */
	~Player() {};
};


