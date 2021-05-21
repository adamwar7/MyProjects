#pragma once
#include <iostream>
#include "player.h"
#include "game.h"
#include "board.h"
#include "Interface.h"
#include <windows.h>

/** class controls whole logic and
* draws objects from interface
*/
class AppLogic
{
public:
	
	Game game;	///< object type of game (board, players,figures)
	
	sf::Vector2f mousePosition = sf::Vector2f(0, 0); ///< mouse position
	
	int counter = 0; ///< counter used in switch
	
	bool player = true; ///< current player, true == white, black == false
	
	bool loginPhase = true; ///< login phase, true == yes, false == no
	
	sf::Text input; ///< input used in login phase
	sf::Font font; ///< font to draw input text
	std::string _input = ""; ///< input container
	
	std::vector<sf::Vector2f> tmp; ///< avaliable moves container
	
	Interface intfc; ///< object type of interface with all drawing objects
	
	sf::Text nameAndRankWhite; ///< converted format to draw name and rank for white player
	sf::Text nameAndRankBlack; ///< converted format to draw name and rank for black player
	
	int checkW = 0; ///< information about check by white figures
	int checkB = 0;	///< information about check by black figures
	int badMove = 0; ///< counter, increase when player click on figure which has 0 possible moves
	
	bool timeout = false; ///< information about time-out, true == yes, flase == no

	/** constructor with one argument
	@param intf container with drawable objects representing interface
	*/
	AppLogic(Interface& intf);

	/** method which allows to start and restart the game by setting all objects to starting positions */
	void startResetGame();

	/** The most important method in the game. Method controls all events in the right order and draws all drawable objects */
	void play();

	/** method sets font */
	void setFont();

	/** method sets text parameters
	@param text text to change parameters
	@param size size of characters
	@param color color of characters
	@param position position of text
	*/
	void setTextParameters(sf::Text& text, unsigned int size, sf::Color color, sf::Vector2f position);

	/** method converts player name and player rank to sf::text format */
	void setRankandNameForPlayer();

	/** Destructor */
	~AppLogic() {};

};

