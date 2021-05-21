#include "King.h"

King::King()
{
	whiteORblack = true;
	position = sf::Vector2f(0, 0);
	loadTexture();
}

King::King(bool color, sf::Vector2f startPosition)
{
	whiteORblack = color;
	position = startPosition;
	loadTexture();
}

void King::loadTexture()
{
	if (whiteORblack)
	{
		if (!texture.loadFromFile("textures/wking.png"))
		{
			std::cout << "Load texture from file textures/wking.png failed" << std::endl;
		}
	}
	else
	{
		if (!texture.loadFromFile("textures/bking.png"))
		{
			std::cout << "Load texture from file textures/bking.png failed" << std::endl;
		}
	}
	sprite.setTexture(texture);
	sprite.setPosition(position);
}

std::vector<sf::Vector2f> King::showPossibleMoves(sf::Vector2f enemyKing, std::map<std::string, std::pair<sf::Vector2f, bool>>& map, std::vector<sf::RectangleShape>& pieces)
{
	std::vector<sf::Vector2f> possibleMoves;
	sf::Vector2f tmp(0, 0);
	float x = this->position.x - 80;
	float y = this->position.y + 80;
	std::vector < sf::Vector2f> avoidEnemyKing;
	avoidEnemyKing.push_back(sf::Vector2f(x - 80, y - 80));
	avoidEnemyKing.push_back(sf::Vector2f(x - 80, y));
	avoidEnemyKing.push_back(sf::Vector2f(x - 80, y + 80));
	avoidEnemyKing.push_back(sf::Vector2f(x, y + 80));
	avoidEnemyKing.push_back(sf::Vector2f(x + 80, y + 80));

	for (int i = 0; i < 8; i++)
	{
		if (enemyKing != avoidEnemyKing.at(0) and enemyKing != avoidEnemyKing.at(1) and enemyKing != avoidEnemyKing.at(2)
			and enemyKing != avoidEnemyKing.at(3) and enemyKing != avoidEnemyKing.at(4))
		{
				tmp = changeColorIfMoveIsPossible(sf::Vector2f(x,y), map, pieces);
		}
		if (tmp.x != 0)
		{
			possibleMoves.push_back(tmp);
			tmp = sf::Vector2f(0, 0);
		}
		switch (i)
		{
		case 0:
			y -= 80;
			avoidEnemyKing.at(0) = sf::Vector2f(x - 80, y - 80);
			avoidEnemyKing.at(1) = sf::Vector2f(x - 80, y);
			avoidEnemyKing.at(2) = sf::Vector2f(x - 80, y + 80);
			avoidEnemyKing.at(3) = sf::Vector2f(0, 0);
			avoidEnemyKing.at(4) = sf::Vector2f(0, 0);
			break;
		case 1:
			y -= 80;
			avoidEnemyKing.at(0) = sf::Vector2f(x - 80, y - 80);
			avoidEnemyKing.at(1) = sf::Vector2f(x - 80, y);
			avoidEnemyKing.at(2) = sf::Vector2f(x - 80, y + 80);
			avoidEnemyKing.at(3) = sf::Vector2f(x, y - 80);
			avoidEnemyKing.at(4) = sf::Vector2f(x + 80, y - 80);
			break;
		case 2:
			x += 80;
			avoidEnemyKing.at(0) = sf::Vector2f(x - 80, y - 80);
			avoidEnemyKing.at(1) = sf::Vector2f(x, y - 80);
			avoidEnemyKing.at(2) = sf::Vector2f(x + 80, y - 80);
			avoidEnemyKing.at(3) = sf::Vector2f(0, 0);
			avoidEnemyKing.at(4) = sf::Vector2f(0, 0);
			break;
		case 3:
			y += 160;
			avoidEnemyKing.at(0) = sf::Vector2f(x - 80, y + 80);
			avoidEnemyKing.at(1) = sf::Vector2f(x, y + 80);
			avoidEnemyKing.at(2) = sf::Vector2f(x + 80, y + 80);
			avoidEnemyKing.at(3) = sf::Vector2f(0, 0);
			avoidEnemyKing.at(4) = sf::Vector2f(0, 0);
			break;
		case 4:
			x += 80;
			avoidEnemyKing.at(0) = sf::Vector2f(x - 80, y + 80);
			avoidEnemyKing.at(1) = sf::Vector2f(x, y + 80);
			avoidEnemyKing.at(2) = sf::Vector2f(x + 80, y + 80);
			avoidEnemyKing.at(3) = sf::Vector2f(x + 80, y);
			avoidEnemyKing.at(4) = sf::Vector2f(x + 80, y - 80);
			break;
		case 5:
			y -= 80;
			avoidEnemyKing.at(0) = sf::Vector2f(x + 80, y + 80);
			avoidEnemyKing.at(1) = sf::Vector2f(x + 80, y);
			avoidEnemyKing.at(2) = sf::Vector2f(x + 80, y - 80);
			avoidEnemyKing.at(3) = sf::Vector2f(0, 0);
			avoidEnemyKing.at(4) = sf::Vector2f(0, 0);
			break;
		case 6:
			y -= 80;
			avoidEnemyKing.at(0) = sf::Vector2f(x + 80, y + 80);
			avoidEnemyKing.at(1) = sf::Vector2f(x + 80, y);
			avoidEnemyKing.at(2) = sf::Vector2f(x + 80, y - 80);
			avoidEnemyKing.at(3) = sf::Vector2f(x, y - 80);
			avoidEnemyKing.at(4) = sf::Vector2f(x - 80, y - 80);
			break;
		default:
			break;
		}
	}
	return possibleMoves;
}
