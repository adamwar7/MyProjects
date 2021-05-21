#include "Pawn.h"

Pawn::Pawn()
{
	this->whiteORblack = true;
	this->firstMove = true;
	this->position.x = 0.f;
	this->position.y = 0.f;
}

Pawn::Pawn(bool color, bool move, sf::Vector2f startPosition)
{
	this->whiteORblack = color;
	this->firstMove = move;
	this->position = startPosition;
	loadTexture();
}

void Pawn::loadTexture()
{
	if (this->whiteORblack)
	{
		if (!texture.loadFromFile("textures/pwhite.png"))
		{
			std::cout << "Load texture from file textures/pwhite.png failed" << std::endl;
		}
	}
	else
	{
		if (!texture.loadFromFile("textures/pblack.png"))
		{
			std::cout << "Load texture from file textures/pblack.png failed" << std::endl;
		}
	}
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(this->position);
}

std::vector<sf::Vector2f> Pawn::showPossibleMoves(std::map<std::string, std::pair<sf::Vector2f, bool>>& map, std::vector<sf::RectangleShape>& pieces)
{
	std::vector<sf::Vector2f> possibleMoves;
	changeFigurePiecesToGrey(pieces);
	if (this->whiteORblack == true)
	{
		possibleMoves.push_back(changeColorIfMoveIsPossible(sf::Vector2f(this->position.x, this->position.y - 80), map, pieces));
		if (this->firstMove == true and possibleMoves.at(0).x != 0)
		{
			possibleMoves.push_back(changeColorIfMoveIsPossible(sf::Vector2f(this->position.x, this->position.y - 160), map, pieces));
		}
		

	}
	else
	{
		possibleMoves.push_back(changeColorIfMoveIsPossible(sf::Vector2f(this->position.x, this->position.y + 80), map, pieces));
		if (this->firstMove == true and possibleMoves.at(0).x != 0)
		{
			possibleMoves.push_back(changeColorIfMoveIsPossible(sf::Vector2f(this->position.x, this->position.y + 160), map, pieces));
		}
	}
	return possibleMoves;
}

bool Pawn::getFirstMove()
{
	return this->firstMove;
}

void Pawn::setFirstMove(bool over)
{
	this->firstMove = over;
}