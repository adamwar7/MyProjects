#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <regex>
class Interface
{

public:

	sf::Texture white; ///< texture of icon with player with white figures
	sf::Texture black; ///< texture of icon with player with black figures
	sf::Texture logo_tex;  ///< texture of logo

	sf::Sprite whiteIcon; ///< sprite of icon with player with white figures
	sf::Sprite blackIcon; ///< sprite of icon with player with black figures
	sf::Sprite logo; ///< sprite of logo
	 
	sf::Font font; ///< font

	sf::Text nameWhite; ///< name of player with white figures
	sf::Text nameBlack; ///< name of player with black figures
	sf::Text author; ///< name of author
	sf::Text whiteRank; ///< player with white figures ranking
	sf::Text blackRank; ///< player with black figures ranking
	sf::Text resetButtonText; ///< text in reset button
	sf::Text login; ///< welcoming text
	sf::Text loginPlayer; ///< welcoming text
	sf::Text username; ///< player input
	sf::Text loginError; ///< error about login
	sf::Text timerB; ///< converted timer of player with white figures
	sf::Text timerW; ///< converted timer of player with white figures
	sf::Text timeout_text; ///< ending text
	sf::Text mat; ///< ending text

	sf::Time white_time; ///< timer of player with white figures
	sf::Time black_time; ///< timer of player with black figures

	sf::RectangleShape resetButton; ///< reset button
	sf::RectangleShape whiteMove; ///< rectangle, green == player can move
	sf::RectangleShape blackMove; ///< rectangle, green == player can move

	/** no arguments constructor */
	Interface();

private:

	/** method sets sprites for all sf::sprite objects */
	void setSprites();

	/** method sets parameters for all sf::text objects */
	void setTexts();

	/** method sets font */
	void setFont();

	/** method sets parameters for players name */
	void setNames();

	/** method sets parameters for author name */
	void setAuthor();

public:

	//body of function below must be here or compilator detects an error

	/** method checks existing of file
	@param filename filename
	@return exist == true, no == false
	*/
	inline bool fileExist(std::string& filename) {
		struct stat buffer;
		std::string txt = filename + ".txt";
		return (stat(txt.c_str(), &buffer) == 0);
	}

	/** method create new txt file
	@param filename filename
	*/
	void createFile(std::string& filename);

	/** method create new txt file
	@param filename filename
	@param whiteORblack color of player figures
	*/
	void readPlayerNameAndRank(std::string filename, bool whiteORblack);

	/** method sets text parameters
	@param text text to change parameters
	@param size size of characters
	@param color color of characters
	@param position position of text
	*/
	void setTextParameters(sf::Text& text, unsigned int size, sf::Color color, sf::Vector2f position);

	/** method sets parameters for reset button */
	void setResetButton();

	/** method checks that player clicked in reset button
	@param mousePosition mouse position
	@return true == yes, false == no
	*/
	bool containResetButton(sf::Vector2f mousePosition);

	/** method sets parameters from sf::RectangleShape objects */
	void setMoveSqueres();

	/** method sets parameters from sf::Time and sf::Text objects */
	void setTimes();

	/** method changes players ranking
	@param whiteORblackMat true == white mat, false == black mat
	*/
	void changeRanking(bool whiteORblackMat);

	/** method saves new ranking and player name to file */
	void saveDataToFile();

	/** Destructor */
	~Interface() {};
};

