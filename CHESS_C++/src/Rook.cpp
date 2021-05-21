#include "Rook.h"
Rook::Rook()
{
	whiteORblack = true;
	position.x = 0.f;
	position.y = 0.f;
}

Rook::Rook(bool color, sf::Vector2f startPosition)
{
	whiteORblack = color;
	position =  startPosition;
	loadTexture();
}

void Rook::loadTexture()
{
	if (whiteORblack)
	{
		if (!texture.loadFromFile("textures/wrock.png"))
		{
			std::cout << "Load texture from file textures/wrock.png failed" << std::endl;
		}
	}
	else
	{
		if (!texture.loadFromFile("textures/brock.png"))
		{
			std::cout << "Load texture from file textures/brock.png failed" << std::endl;
		}
	}
	sprite.setTexture(texture);
	sprite.setPosition(position);
}

std::vector<sf::Vector2f> Rook::showPossibleMoves(std::vector<sf::Vector2f> possibleAttacks, std::map<std::string, std::pair<sf::Vector2f, bool>>& map, std::vector<sf::RectangleShape>& pieces)
{
	std::vector<sf::Vector2f> possibleMoves;
	changeFigurePiecesToGrey(pieces);
	if (possibleAttacks.at(0).x != 0)
	{
		for (float i = possibleAttacks.at(0).y + 80; i < position.y; i += 80)
		{
			possibleMoves.push_back(changeColorIfMoveIsPossible(sf::Vector2f(this->position.x, i), map, pieces));
		}
	}
	else
	{
		for (float i = position.y - 80; i >= 80; i -= 80)
		{
			sf::Vector2f tmp = changeColorIfMoveIsPossible(sf::Vector2f(this->position.x, i), map, pieces);
			if (tmp.x == 0)
			{
				break;
			}
			else
			{
				possibleMoves.push_back(tmp);
				tmp.x = 0;
				tmp.y = 0;
			}
		}
	}

	if (possibleAttacks.at(1).x != 0)
	{
		for (float i = possibleAttacks.at(1).y - 80; i > position.y; i -= 80)
		{
			possibleMoves.push_back(changeColorIfMoveIsPossible(sf::Vector2f(this->position.x, i), map, pieces));
		}
	}
	else
	{
		for (float i = position.y + 80; i <= 640; i += 80)
		{

			sf::Vector2f tmp = changeColorIfMoveIsPossible(sf::Vector2f(this->position.x, i), map, pieces);
			if (tmp.x == 0)
			{
				break;
			}
			else
			{
				possibleMoves.push_back(tmp);
				tmp.x = 0;
				tmp.y = 0;
			}
		}
	}

	if (possibleAttacks.at(2).x != 0)
	{
		for (float i = possibleAttacks.at(2).x + 80; i < position.x; i += 80)
		{
			possibleMoves.push_back(changeColorIfMoveIsPossible(sf::Vector2f(i, this->position.y), map, pieces));
		}
	}
	else
	{
		for (float i = position.x - 80; i >= 80; i -= 80)
		{
			sf::Vector2f tmp = changeColorIfMoveIsPossible(sf::Vector2f(i, this->position.y), map, pieces);
			if (tmp.x == 0)
			{
				break;
			}
			else
			{
				possibleMoves.push_back(tmp);
				tmp.x = 0;
				tmp.y = 0;
			}
		}
	}

	if (possibleAttacks.at(3).x != 0)
	{
		for (float i = possibleAttacks.at(3).x - 80; i > position.x; i -= 80)
		{
			possibleMoves.push_back(changeColorIfMoveIsPossible(sf::Vector2f(i, this->position.y), map, pieces));
		}
	}
	else
	{
		for (float i = position.x + 80; i <= 640; i += 80)
		{
			sf::Vector2f tmp = changeColorIfMoveIsPossible(sf::Vector2f(i, this->position.y), map, pieces);
			if (tmp.x == 0)
			{
				break;
			}
			else
			{
				possibleMoves.push_back(tmp);
				tmp.x = 0;
				tmp.y = 0;
			}
		}
	}
	return possibleMoves;
}