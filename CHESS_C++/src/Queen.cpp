#include "Queen.h"

Queen::Queen()
{
	whiteORblack = true;
	position.x = 0.f;
	position.y = 0.f;
}

Queen::Queen(bool color, sf::Vector2f startPosition)
{
	whiteORblack = color;
	position = startPosition;

	loadTexture();
}

void Queen::loadTexture()
{
	if (whiteORblack)
	{
		if (!texture.loadFromFile("textures/hwhite.png"))
		{
			std::cout << "Load texture from file textures/hwhite.png failed" << std::endl;
		}
	}
	else
	{
		if (!texture.loadFromFile("textures/hblack.png"))
		{
			std::cout << "Load texture from file textures/hblack.png failed" << std::endl;
		}
	}
	sprite.setTexture(texture);
	sprite.setPosition(position);
}

std::vector<sf::Vector2f> Queen::showPossibleMoves(std::vector<sf::Vector2f> possibleAttacks, std::map<std::string, std::pair<sf::Vector2f, bool>>& map, std::vector<sf::RectangleShape>& pieces)
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

	if (possibleAttacks.at(4).x != 0)
	{
		float x = possibleAttacks.at(4).x + 80;
		float y = possibleAttacks.at(4).y + 80;
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

	if (possibleAttacks.at(5).x != 0)
	{
		float x = possibleAttacks.at(5).x + 80;
		float y = possibleAttacks.at(5).y - 80;
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

	if (possibleAttacks.at(6).x != 0)
	{
		float x = possibleAttacks.at(6).x - 80;
		float y = possibleAttacks.at(6).y + 80;
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

	if (possibleAttacks.at(7).x != 0)
	{
		float x = possibleAttacks.at(7).x - 80;
		float y = possibleAttacks.at(7).y - 80;
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