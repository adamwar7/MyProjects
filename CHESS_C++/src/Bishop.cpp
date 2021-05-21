#include "Bishop.h"
Bishop::Bishop()
{
	whiteORblack = true;
	position.x = 0.f;
	position.y = 0.f;
}

Bishop::Bishop(bool color, sf::Vector2f startPosition)
{
	whiteORblack = color;
	position = startPosition;
	loadTexture();
}

void Bishop::loadTexture()
{
	if (whiteORblack)
	{
		if (!texture.loadFromFile("textures/wbishop.png"))
		{
			std::cout << "Load texture from file textures/wbishop.png failed" << std::endl;
		}
	}
	else
	{
		if (!texture.loadFromFile("textures/bbishop.png"))
		{
			std::cout << "Load texture from file textures/bbishop.png failed" << std::endl;
		}
	}
	sprite.setTexture(texture);
	sprite.setPosition(position);
}

std::vector<sf::Vector2f> Bishop::showPossibleMoves(std::vector<sf::Vector2f> possibleAttacks, std::map<std::string, std::pair<sf::Vector2f, bool>>& map, std::vector<sf::RectangleShape>& pieces)
{
	std::vector<sf::Vector2f> possibleMoves;
	sf::Vector2f tmp;
	changeFigurePiecesToGrey(pieces);
	if (possibleAttacks.at(0).x != 0)
	{
		float x = possibleAttacks.at(0).x + 80;
		float y = possibleAttacks.at(0).y + 80;
		for (x; x < this->position.x; x += 80)
		{
			if (y < this->position.y)
			{
				possibleMoves.push_back(changeColorIfMoveIsPossible(sf::Vector2f(x, y), map, pieces));
			}
			y += 80;
		}
	}
	else
	{
		float y = this->position.y - 80;
		for (float x = this->position.x - 80; x >= 80; x -= 80)
		{
			sf::Vector2f tmp = changeColorIfMoveIsPossible(sf::Vector2f(x, y), map, pieces);

			y -= 80;
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
		float x = possibleAttacks.at(1).x + 80;
		float y = possibleAttacks.at(1).y - 80;
		for (x; x < this->position.x; x += 80)
		{
			if (y > this->position.y)
			{
				possibleMoves.push_back(changeColorIfMoveIsPossible(sf::Vector2f(x, y), map, pieces));
			}
			y -= 80;
		}
	}
	else
	{
		float y = this->position.y + 80;
		for (float x = this->position.x - 80; x >= 80; x -= 80)
		{

			sf::Vector2f tmp = changeColorIfMoveIsPossible(sf::Vector2f(x, y), map, pieces);
			y += 80;
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
		float x = possibleAttacks.at(2).x - 80;
		float y = possibleAttacks.at(2).y + 80;
		for (x; x > this->position.x; x -= 80)
		{
			if (y < this->position.y)
			{
				possibleMoves.push_back(changeColorIfMoveIsPossible(sf::Vector2f(x, y), map, pieces));
			}
			y += 80;
		}
	}
	else
	{
		float y = this->position.y - 80;
		for (float x = this->position.x + 80; x <= 640; x += 80)
		{

			sf::Vector2f tmp = changeColorIfMoveIsPossible(sf::Vector2f(x, y), map, pieces);

			y -= 80;
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
		float x = possibleAttacks.at(3).x - 80;
		float y = possibleAttacks.at(3).y - 80;
		for (x; x > this->position.x; x -= 80)
		{
			if (y > this->position.y)
			{
				possibleMoves.push_back(changeColorIfMoveIsPossible(sf::Vector2f(x, y), map, pieces));
			}
			y -= 80;
		}
	}
	else
	{
		float y = this->position.y + 80;
		for (float x = this->position.x + 80; x <= 640; x += 80)
		{

			sf::Vector2f tmp = changeColorIfMoveIsPossible(sf::Vector2f(x, y), map, pieces);

			y += 80;
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