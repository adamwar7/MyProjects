#include "Knight.h"

Knight::Knight()
{
	whiteORblack = true;
	position.x = 0.f;
	position.y = 0.f;
}

Knight::Knight(bool color, sf::Vector2f startPosition)
{
	whiteORblack = color;
	position = startPosition;
	loadTexture();
}

void Knight::loadTexture()
{
	if (whiteORblack)
	{
		if (!texture.loadFromFile("textures/swhite.png"))
		{
			std::cout << "Load texture from file textures/swhite.png failed" << std::endl;
		}
	}
	else
	{
		if (!texture.loadFromFile("textures/sblack.png"))
		{
			std::cout << "Load texture from file textures/sblack.png failed" << std::endl;
		}
	}
	sprite.setTexture(texture);
	sprite.setPosition(position);
}

std::vector<sf::Vector2f> Knight::showPossibleMoves(std::map<std::string, std::pair<sf::Vector2f, bool>>& map, std::vector<sf::RectangleShape>& pieces)
{
	std::vector<sf::Vector2f> possibleMoves;
	sf::Vector2f tmp;
	changeFigurePiecesToGrey(pieces);
	int j = 1;
	for (int i = 0; i < 2; i++)
	{
		tmp = changeColorIfMoveIsPossible(sf::Vector2f((this->position.x + (80 * j)), this->position.y - 160), map, pieces);
		if (tmp.x != 0)
		{
			possibleMoves.push_back(tmp);
		}
		tmp = changeColorIfMoveIsPossible(sf::Vector2f((this->position.x + (160 * j)), this->position.y - 80), map, pieces);
		if (tmp.x != 0)
		{
			possibleMoves.push_back(tmp);
		}
		tmp = changeColorIfMoveIsPossible(sf::Vector2f((this->position.x + (160 * j)), this->position.y + 80), map, pieces);
		if (tmp.x != 0)
		{
			possibleMoves.push_back(tmp);
		}
		tmp = changeColorIfMoveIsPossible(sf::Vector2f((this->position.x + (80 * j)), this->position.y + 160), map, pieces);
		if (tmp.x != 0)
		{
			possibleMoves.push_back(tmp);
		}
		j = -j;
	}
	return possibleMoves;
}