#include "Figure.h"

sf::Sprite& Figure::getSprite()
{
	return this->sprite;
}

sf::Vector2f Figure::getPosition()
{
	return this->position;
}

bool Figure::checkField(sf::Vector2f field, std::map <std::string, std::pair<sf::Vector2f, bool>>& map)
{
	for (auto& i : map)
	{
		if (field.x == i.second.first.x and field.y == i.second.first.y)
		{
			return i.second.second;
		}
	}
	return true;
}

void Figure::changeFigurePiecesToGrey(std::vector<sf::RectangleShape>& pieces)
{
	for (auto& a : pieces)
	{
		if (this->position == a.getPosition())
			a.setFillColor(sf::Color(130, 129, 124));
	}
}

sf::Vector2f Figure::changeColorIfMoveIsPossible(sf::Vector2f positionToChange, std::map <std::string, std::pair<sf::Vector2f, bool>>& map, std::vector<sf::RectangleShape>& pieces)
{
	sf::Vector2f moveIsPossible;
	for (auto& sign : map)
	{
		if (sign.second.first.x == positionToChange.x and sign.second.first.y == positionToChange.y and sign.second.second == false)
		{
			for (auto& piece : pieces)
			{
				if (piece.getPosition() == positionToChange)
				{
					piece.setFillColor(sf::Color(255, 221, 153));
					moveIsPossible = positionToChange;
				}
			}
		}
	}
	return moveIsPossible;
}

sf::Vector2f Figure::changeFieldColorIfPositonIsCorrect(sf::Vector2f positionToChange, std::vector<sf::RectangleShape>& pieces, sf::Color color)
{
	sf::Vector2f moveIsPossible;
	for (auto& piece : pieces)
	{
		if (piece.getPosition() == positionToChange)
		{
			piece.setFillColor(color);
			moveIsPossible = positionToChange;
		}
	}
	return moveIsPossible;
}
