#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


/** virtual base class with common features for figures */
class Figure
{

protected:

	sf::Texture texture; ///< figure texture
	sf::Sprite sprite; ///< figure sprite

	/** clean virtual method, used for downloading a specific texture from a file and loading into field of type sf::Texture */
	virtual void loadTexture() = 0;

public:

	bool whiteORblack = true; ///< figure color: white == true, black == false
	sf::Vector2f position; ///< figure position on the board

	/** method which returns sprite of figure
	@return sprite
	*/
	sf::Sprite& getSprite();

	/** method which returns position of figure
	@return postion
	*/
	sf::Vector2f getPosition();

	/** method returns true is selected field is empty, else false
	@param field selected field
	@param map map which represent all fields
	@return true or false
	*/
	bool checkField(sf::Vector2f field, std::map <std::string, std::pair<sf::Vector2f, bool>>& map);

	/** method change background of selected figure to gray
	@param pieces vector of all fields
	@return true or false
	*/
	void changeFigurePiecesToGrey(std::vector<sf::RectangleShape>& pieces);

	/** method comapare selected field with map, if field is empty returns this position
	@param map map which represent all fields
	@param pieces vector of all fields
	@return possible move
	*/
	sf::Vector2f changeColorIfMoveIsPossible(sf::Vector2f positionToChange, std::map <std::string, std::pair<sf::Vector2f, bool>>& map, std::vector<sf::RectangleShape>& pieces);

	/** method comapare selected field with map, if field is empty returns this position
	@param map map which represent all fields
	@param pieces vector of all fields
	@param color selected color
	@return possible move
	*/
	sf::Vector2f changeFieldColorIfPositonIsCorrect(sf::Vector2f positionToChange, std::vector<sf::RectangleShape>& pieces, sf::Color color);

};
