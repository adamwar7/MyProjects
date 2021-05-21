#include "Player.h"

Player::Player()
{
	points = 0;
	this->color = true;
	setFigures();
}

Player::Player(bool color)
{
	points = 0;
	this->color = color;
	setFigures();
}

void Player::setFigures()
{
	if (this->color == true)
	{
		sf::Vector2f positions(80, 560);
		for (int i = 0; i < 8; i++)
		{
			std::insert_iterator<std::vector<Pawn*>> iter(this->pawns, this->pawns.end());
			*iter = new Pawn(true, true, positions);
			positions.x = positions.x + 80;
		}
		this->ra = new Rook(true, sf::Vector2f(80, 640));
		this->rh = new Rook(true, sf::Vector2f(640, 640));
		this->kb = new Knight(true, sf::Vector2f(160, 640));
		this->kg = new Knight(true, sf::Vector2f(560, 640));
		this->bc = new Bishop(true, sf::Vector2f(240, 640));
		this->bf = new Bishop(true, sf::Vector2f(480, 640));
		this->queen = new Queen(true, sf::Vector2f(320, 640));
		this->king = new King(true, sf::Vector2f(400, 640));
	}
	else
	{
		sf::Vector2f positions(80, 160);
		for (int i = 0; i < 8; i++)
		{
			std::insert_iterator<std::vector<Pawn*>> iter(this->pawns, this->pawns.end());
			*iter = new Pawn(false, true, positions);
			positions.x = positions.x + 80;
		}
		this->ra = new Rook(false, sf::Vector2f(80, 80));
		this->rh = new Rook(false, sf::Vector2f(640, 80));
		this->kb = new Knight(false, sf::Vector2f(160, 80));
		this->kg = new Knight(false, sf::Vector2f(560, 80));
		this->bc = new Bishop(false, sf::Vector2f(240, 80));
		this->bf = new Bishop(false, sf::Vector2f(480, 80));
		this->queen = new Queen(false, sf::Vector2f(320, 80));
		this->king = new King(false, sf::Vector2f(400, 80));
	}



}

std::vector<sf::Vector2f> Player::showWhiteFigureMove(sf::Vector2f figurePosition, std::map<std::string, std::pair<sf::Vector2f, bool>>& map, std::vector<sf::RectangleShape>& pieces, Player& opposite)
{
	std::vector<sf::Vector2f> availableMoves;
	std::vector<Pawn*>::iterator start = this->pawns.begin();
	std::vector<Pawn*>::iterator end = this->pawns.end();
	for (start; start != end; start++)
	{
		if (this->pawns.at(std::distance(this->pawns.begin(), start))->position == figurePosition)
		{
			if (this->pawns.at(std::distance(this->pawns.begin(), start))->whiteORblack == true)
			{
				std::vector<sf::Vector2f> tmp = this->pawns.at(std::distance(this->pawns.begin(), start))->showPossibleMoves(map, pieces);
				for (auto& element : tmp)
				{
					availableMoves.push_back(element);
				}
				std::vector<sf::Vector2f> tmp2 = changeColorIfAttackIsPossible(figurePosition, map, pieces, opposite);
				for (auto& element : tmp2)
				{
					availableMoves.push_back(element);
				}
			}
		}
	}
	if (this->ra->position == figurePosition and ra->whiteORblack == true)
	{
		std::vector<sf::Vector2f> tmp = changeColorIfAttackIsPossible(figurePosition, map, pieces, opposite);
		std::vector<sf::Vector2f> tmp2 = this->ra->showPossibleMoves(tmp, map, pieces);
		for (auto& move : tmp2)
		{
			tmp.push_back(move);
		}
		for (auto& element : tmp)
		{
			availableMoves.push_back(element);
		}
	}
	else if (this->rh->position == figurePosition and rh->whiteORblack == true)
	{
		std::vector<sf::Vector2f> tmp = changeColorIfAttackIsPossible(figurePosition, map, pieces, opposite);
		std::vector<sf::Vector2f> tmp2 = this->rh->showPossibleMoves(tmp, map, pieces);
		for (auto& move : tmp2)
		{
			tmp.push_back(move);
		}
		for (auto& element : tmp)
		{
			availableMoves.push_back(element);
		}
	}
	else if (this->kb->position == figurePosition and kb->whiteORblack == true)
	{
		std::vector<sf::Vector2f> tmp = changeColorIfAttackIsPossible(figurePosition, map, pieces, opposite);
		std::vector<sf::Vector2f> tmp2 = this->kb->showPossibleMoves(map, pieces);
		for (auto& element : tmp2)
		{

			tmp.push_back(element);
		}
		for (auto& element : tmp)
		{
			availableMoves.push_back(element);
		}
	}
	else if (this->kg->position == figurePosition and kg->whiteORblack == true)
	{
		std::vector<sf::Vector2f> tmp = changeColorIfAttackIsPossible(figurePosition, map, pieces, opposite);
		std::vector<sf::Vector2f> tmp2 = this->kg->showPossibleMoves(map, pieces);
		for (auto& element : tmp2)
		{
			tmp.push_back(element);
		}
		for (auto& element : tmp)
		{
			availableMoves.push_back(element);
		}
	}
	else if (this->bc->position == figurePosition and bc->whiteORblack == true)
	{
		std::vector<sf::Vector2f> tmp = changeColorIfAttackIsPossible(figurePosition, map, pieces, opposite);
		std::vector<sf::Vector2f> tmp2 = this->bc->showPossibleMoves(tmp, map, pieces);
		for (auto& element : tmp2)
		{
			tmp.push_back(element);
		}
		for (auto& element : tmp)
		{
			availableMoves.push_back(element);
		}
	}
	else if (this->bf->position == figurePosition and bf->whiteORblack == true)
	{
		std::vector<sf::Vector2f> tmp = changeColorIfAttackIsPossible(figurePosition, map, pieces, opposite);
		std::vector<sf::Vector2f> tmp2 = this->bf->showPossibleMoves(tmp, map, pieces);
		for (auto& element : tmp2)
		{
			tmp.push_back(element);
		}
		for (auto& element : tmp)
		{
			availableMoves.push_back(element);
		}
	}
	else if (this->queen->position == figurePosition and queen->whiteORblack == true)
	{
		std::vector<sf::Vector2f> tmp = changeColorIfAttackIsPossible(figurePosition, map, pieces, opposite);
		std::vector<sf::Vector2f> tmp2 = this->queen->showPossibleMoves(tmp, map, pieces);
		for (auto& element : tmp2)
		{
			tmp.push_back(element);
		}
		for (auto& element : tmp)
		{
			availableMoves.push_back(element);
		}
	}
	else if (this->king->position == figurePosition and king->whiteORblack == true)
	{
		std::vector<sf::Vector2f> tmp = changeColorIfAttackIsPossible(figurePosition, map, pieces, opposite);
		std::vector<sf::Vector2f> tmp2 = this->king->showPossibleMoves(opposite.king->getPosition(), map, pieces);
		for (auto& element : tmp2)
		{
			tmp.push_back(element);
		}
		for (auto& element : tmp)
		{
			availableMoves.push_back(element);
		}
	}
	/*else if (this->ra->position == figurePosition and ra->whiteORblack == true)
	{
		std::vector<sf::Vector2f> tmp = changeColorIfAttackIsPossible(figurePosition, map, pieces, opposite);
		std::vector<sf::Vector2f> tmp2 = this->ra->showPossibleMoves(tmp, map, pieces);
		for (auto& move : tmp2)
		{
			tmp.push_back(move);
		}
		for (auto& element : tmp)
		{
			availableMoves.push_back(element);
		}
	}
	else if (this->rh->position == figurePosition and rh->whiteORblack == true)
	{
		std::vector<sf::Vector2f> tmp = changeColorIfAttackIsPossible(figurePosition, map, pieces, opposite);
		std::vector<sf::Vector2f> tmp2 = this->rh->showPossibleMoves(tmp, map, pieces);
		for (auto& move : tmp2)
		{
			tmp.push_back(move);
		}
		for (auto& element : tmp)
		{
			availableMoves.push_back(element);
		}
	}*/
	availableMoves.push_back(figurePosition);
	return availableMoves;
}


std::vector<sf::Vector2f> Player::showBlackFigureMove(sf::Vector2f figurePosition, std::map<std::string, std::pair<sf::Vector2f, bool>>& map, std::vector<sf::RectangleShape>& pieces, Player& opposite)
{
	std::vector<sf::Vector2f> availableMoves;
	std::vector<Pawn*>::iterator start = this->pawns.begin();
	std::vector<Pawn*>::iterator end = this->pawns.end();
	for (start; start != end; start++)
	{
		if (this->pawns.at(std::distance(this->pawns.begin(), start))->position == figurePosition)
		{
			if (this->pawns.at(std::distance(this->pawns.begin(), start))->whiteORblack == false)
			{
				std::vector<sf::Vector2f> tmp = this->pawns.at(std::distance(this->pawns.begin(), start))->showPossibleMoves(map, pieces);
				for (auto& element : tmp)
				{
					availableMoves.push_back(element);
				}
				std::vector<sf::Vector2f> tmp2 = changeColorIfAttackIsPossible(figurePosition, map, pieces, opposite);
				for (auto& element : tmp2)
				{
					availableMoves.push_back(element);
				}
			}
		}
	}
	if (this->ra->position == figurePosition and ra->whiteORblack == false)
	{
		std::vector<sf::Vector2f> tmp = changeColorIfAttackIsPossible(figurePosition, map, pieces, opposite);
		std::vector<sf::Vector2f> tmp2 = this->ra->showPossibleMoves(tmp, map, pieces);
		for (auto& move : tmp2)
		{
			tmp.push_back(move);
		}
		for (auto& element : tmp)
		{
			availableMoves.push_back(element);
		}
	}
	else if (this->rh->position == figurePosition and rh->whiteORblack == false)
	{
		std::vector<sf::Vector2f> tmp = changeColorIfAttackIsPossible(figurePosition, map, pieces, opposite);
		std::vector<sf::Vector2f> tmp2 = this->rh->showPossibleMoves(tmp, map, pieces);
		for (auto& move : tmp2)
		{
			tmp.push_back(move);
		}
		for (auto& element : tmp)
		{
			availableMoves.push_back(element);
		}
	}
	else if (this->kb->position == figurePosition and kb->whiteORblack == false)
	{
		std::vector<sf::Vector2f> tmp = changeColorIfAttackIsPossible(figurePosition, map, pieces, opposite);
		std::vector<sf::Vector2f> tmp2 = this->kb->showPossibleMoves(map, pieces);
		for (auto& element : tmp2)
		{
			tmp.push_back(element);
		}
		for (auto& element : tmp)
		{
			availableMoves.push_back(element);
		}
	}
	else if (this->kg->position == figurePosition and kg->whiteORblack == false)
	{
		std::vector<sf::Vector2f> tmp = changeColorIfAttackIsPossible(figurePosition, map, pieces, opposite);
		std::vector<sf::Vector2f> tmp2 = this->kg->showPossibleMoves(map, pieces);
		for (auto& element : tmp2)
		{
			tmp.push_back(element);
		}
		for (auto& element : tmp)
		{
			availableMoves.push_back(element);
		}
	}
	else if (this->bc->position == figurePosition and bc->whiteORblack == false)
	{
		std::vector<sf::Vector2f> tmp = changeColorIfAttackIsPossible(figurePosition, map, pieces, opposite);
		std::vector<sf::Vector2f> tmp2 = this->bc->showPossibleMoves(tmp, map, pieces);
		for (auto& element : tmp2)
		{
			tmp.push_back(element);
		}
		for (auto& element : tmp)
		{
			availableMoves.push_back(element);
		}
	}
	else if (this->bf->position == figurePosition and bf->whiteORblack == false)
	{
		std::vector<sf::Vector2f> tmp = changeColorIfAttackIsPossible(figurePosition, map, pieces, opposite);
		std::vector<sf::Vector2f> tmp2 = this->bf->showPossibleMoves(tmp, map, pieces);
		for (auto& element : tmp2)
		{
			tmp.push_back(element);
		}
		for (auto& element : tmp)
		{
			availableMoves.push_back(element);
		}
	}
	else if (this->queen->position == figurePosition and queen->whiteORblack == false)
	{
		std::vector<sf::Vector2f> tmp = changeColorIfAttackIsPossible(figurePosition, map, pieces, opposite);
		std::vector<sf::Vector2f> tmp2 = this->queen->showPossibleMoves(tmp, map, pieces);
		for (auto& element : tmp2)
		{
			tmp.push_back(element);
		}
		for (auto& element : tmp)
		{
			availableMoves.push_back(element);
		}
	}
	else if (this->king->position == figurePosition and king->whiteORblack == false)
	{
		std::vector<sf::Vector2f> tmp = changeColorIfAttackIsPossible(figurePosition, map, pieces, opposite);
		std::vector<sf::Vector2f> tmp2 = this->king->showPossibleMoves(opposite.king->getPosition(), map, pieces);
		for (auto& element : tmp2)
		{
			tmp.push_back(element);
		}
		for (auto& element : tmp)
		{
			availableMoves.push_back(element);
		}
	}
	availableMoves.push_back(figurePosition);
	return availableMoves;
}

std::vector<sf::Vector2f>  Player::changeColorIfAttackIsPossible(sf::Vector2f figurePosition, std::map<std::string, std::pair<sf::Vector2f, bool >>& map, std::vector<sf::RectangleShape>& pieces, Player& opposite)
{
	std::vector<sf::Vector2f> availableAttacks;
	std::vector<Pawn*>::iterator start = this->pawns.begin();
	std::vector<Pawn*>::iterator end = this->pawns.end();
	for (start; start != end; start++)
	{
		if (this->pawns.at(std::distance(this->pawns.begin(), start))->position == figurePosition)
		{
			sf::Vector2f tmp;
			if (this->pawns.at(std::distance(this->pawns.begin(), start))->whiteORblack)
			{
				tmp = (compareAttackFiled(sf::Vector2f(this->pawns.at(std::distance(this->pawns.begin(), start))->position.x - 80, this->pawns.at(std::distance(this->pawns.begin(), start))->position.y - 80), map, pieces, opposite));
				if (tmp.x > 0)
				{
					availableAttacks.push_back(tmp);
					tmp.x = 0;
					tmp.y = 0;
				}
				tmp = (compareAttackFiled(sf::Vector2f(this->pawns.at(std::distance(this->pawns.begin(), start))->position.x + 80, this->pawns.at(std::distance(this->pawns.begin(), start))->position.y - 80), map, pieces, opposite));
				if (tmp.x > 0)
				{
					availableAttacks.push_back(tmp);
					tmp.x = 0;
					tmp.y = 0;
				}
			}
			else
			{
				tmp = (compareAttackFiled(sf::Vector2f(this->pawns.at(std::distance(this->pawns.begin(), start))->position.x - 80, this->pawns.at(std::distance(this->pawns.begin(), start))->position.y + 80), map, pieces, opposite));
				if (tmp.x > 0)
				{
					availableAttacks.push_back(tmp);
					tmp.x = 0;
					tmp.y = 0;
				}
				tmp = (compareAttackFiled(sf::Vector2f(this->pawns.at(std::distance(this->pawns.begin(), start))->position.x + 80, this->pawns.at(std::distance(this->pawns.begin(), start))->position.y + 80), map, pieces, opposite));
				if (tmp.x > 0)
				{
					availableAttacks.push_back(tmp);
					tmp.x = 0;
					tmp.y = 0;
				}
			}
		}
		else if (this->ra->position == figurePosition)
		{
			availableAttacks = RookPossibleAttacks(figurePosition, map, pieces, opposite);
		}
		else if (this->rh->position == figurePosition)
		{
			availableAttacks = RookPossibleAttacks(figurePosition, map, pieces, opposite);
		}
		else if (this->kb->position == figurePosition)
		{
			availableAttacks = KnightPossibleAttacks(figurePosition, map, pieces, opposite);
		}
		else if (this->kg->position == figurePosition)
		{
			availableAttacks = KnightPossibleAttacks(figurePosition, map, pieces, opposite);
		}
		else if (this->bc->position == figurePosition)
		{
			availableAttacks = BishopPossibleAttacks(figurePosition, map, pieces, opposite);
		}
		else if (this->bf->position == figurePosition)
		{
			availableAttacks = BishopPossibleAttacks(figurePosition, map, pieces, opposite);
		}
		else if (this->queen->position == figurePosition)
		{
			availableAttacks = QueenPossibleAttacks(figurePosition, map, pieces, opposite);
		}
		else if (this->king->position == figurePosition)
		{
			availableAttacks = KingPossibleAttacks(figurePosition, map, pieces, opposite);
		}
	}
	return availableAttacks;
}

std::vector<sf::Vector2f> Player::KnightPossibleAttacks(sf::Vector2f figurePosition, std::map<std::string, std::pair<sf::Vector2f, bool >>& map, std::vector<sf::RectangleShape>& pieces, Player& opposite)
{
	std::vector<sf::Vector2f> possibleMoves;
	sf::Vector2f tmp;
	for (auto& element : map)
	{
		int j = 1;
		for (int i = 0; i < 2; i++)
		{
			if (sf::Vector2f((figurePosition.x + (80 * j)), figurePosition.y - 160) == element.second.first and element.second.second == true)
			{
				tmp = compareAttackFiled(sf::Vector2f((figurePosition.x + (80 * j)), figurePosition.y - 160), map, pieces, opposite);
				if (tmp.x != 0)
				{
					possibleMoves.push_back(tmp);
				}
			}
			if (sf::Vector2f((figurePosition.x + (160 * j)), figurePosition.y - 80) == element.second.first and element.second.second == true)
			{
				tmp = compareAttackFiled(sf::Vector2f((figurePosition.x + (160 * j)), figurePosition.y - 80), map, pieces, opposite);
				if (tmp.x != 0)
				{
					possibleMoves.push_back(tmp);
				}
			}
			if (sf::Vector2f((figurePosition.x + (160 * j)), figurePosition.y + 80) == element.second.first and element.second.second == true)
			{
				tmp = compareAttackFiled(sf::Vector2f((figurePosition.x + (160 * j)), figurePosition.y + 80), map, pieces, opposite);
				if (tmp.x != 0)
				{
					possibleMoves.push_back(tmp);
				}
			}
			if (sf::Vector2f((figurePosition.x + (80 * j)), figurePosition.y + 160) == element.second.first and element.second.second == true)
			{
				tmp = compareAttackFiled(sf::Vector2f((figurePosition.x + (80 * j)), figurePosition.y + 160), map, pieces, opposite);
				if (tmp.x != 0)
				{
					possibleMoves.push_back(tmp);
				}
			}
			j = -j;
		}

	}
	return possibleMoves;
}

std::vector<sf::Vector2f>  Player::RookPossibleAttacks(sf::Vector2f figurePosition, std::map<std::string, std::pair<sf::Vector2f, bool >>& map, std::vector<sf::RectangleShape>& pieces, Player& opposite)
{
	std::vector<sf::Vector2f> availableAttacks;
	sf::Vector2f tmpField(0, 0);
	for (float tmpTop = figurePosition.y - 80; tmpTop >= 80; tmpTop -= 80)
	{
		if (not isNotEqualYourFigures(sf::Vector2f(figurePosition.x, tmpTop)))
		{
			break;
		}
		tmpField = (compareAttackFiled(sf::Vector2f(figurePosition.x, tmpTop), map, pieces, opposite));
		if (tmpField.x > 0)
		{
			availableAttacks.push_back(tmpField);
			tmpField.x = 0;
			tmpField.y = 0;
			break;
		}
	}
	if (availableAttacks.size() == 0)
	{
		availableAttacks.push_back(tmpField);
	}
	for (float tmpBottom = figurePosition.y + 80; tmpBottom <= 640; tmpBottom += 80)
	{
		if (not isNotEqualYourFigures(sf::Vector2f(figurePosition.x, tmpBottom)))
		{
			break;
		}
		tmpField = (compareAttackFiled(sf::Vector2f(figurePosition.x, tmpBottom), map, pieces, opposite));
		if (tmpField.x > 0)
		{
			availableAttacks.push_back(tmpField);
			tmpField.x = 0;
			tmpField.y = 0;
			break;
		}
	}
	if (availableAttacks.size() == 1)
	{
		availableAttacks.push_back(tmpField);
	}
	for (float tmpLeft = figurePosition.x - 80; tmpLeft >= 80; tmpLeft -= 80)
	{
		if (not isNotEqualYourFigures(sf::Vector2f(tmpLeft, figurePosition.y)))
		{
			break;
		}
		tmpField = (compareAttackFiled(sf::Vector2f(tmpLeft, figurePosition.y), map, pieces, opposite));
		if (tmpField.x > 0)
		{
			availableAttacks.push_back(tmpField);
			tmpField.x = 0;
			tmpField.y = 0;
			break;
		}
	}
	if (availableAttacks.size() == 2)
	{
		availableAttacks.push_back(tmpField);
	}
	for (float tmpRight = figurePosition.x + 80; tmpRight <= 640; tmpRight += 80)
	{
		if (not isNotEqualYourFigures(sf::Vector2f(tmpRight, figurePosition.y)))
		{
			break;
		}
		tmpField = (compareAttackFiled(sf::Vector2f(tmpRight, figurePosition.y), map, pieces, opposite));
		if (tmpField.x > 0)
		{
			availableAttacks.push_back(tmpField);
			tmpField.x = 0;
			tmpField.y = 0;
			break;
		}
	}
	if (availableAttacks.size() == 3)
	{
		availableAttacks.push_back(tmpField);
	}
	if (availableAttacks.size() == 4)
	{
		return availableAttacks;
	}
	return availableAttacks;
}

std::vector<sf::Vector2f> Player::BishopPossibleAttacks(sf::Vector2f figurePosition, std::map<std::string, std::pair<sf::Vector2f, bool >>& map, std::vector<sf::RectangleShape>& pieces, Player& opposite)
{
	std::vector<sf::Vector2f> possibleMoves;
	sf::Vector2f tmp;

	float x = figurePosition.x - 80;
	float y = figurePosition.y - 80;
	for (x, y; x >= 80 or y >= 80; x -= 80, y -= 80)
	{

		tmp = compareAttackFiled(sf::Vector2f(x, y), map, pieces, opposite);
		if (isNotEqualYourFigures(sf::Vector2f(x, y)))
		{
			if (tmp.x != 0)
			{
				possibleMoves.push_back(tmp);
				break;
			}
		}
		else
		{
			break;
		}
	}
	if (possibleMoves.size() == 0)
	{
		possibleMoves.push_back(sf::Vector2f(0, 0));
	}
	x = figurePosition.x - 80;
	y = figurePosition.y + 80;
	for (x, y; x >= 80 or y <= 640; x -= 80, y += 80)
	{

		tmp = compareAttackFiled(sf::Vector2f(x, y), map, pieces, opposite);
		if (isNotEqualYourFigures(sf::Vector2f(x, y)))
		{
			if (tmp.x != 0)
			{
				possibleMoves.push_back(tmp);
				break;
			}
		}
		else
		{
			break;
		}
	}
	if (possibleMoves.size() == 1)
	{
		possibleMoves.push_back(sf::Vector2f(0, 0));
	}
	x = figurePosition.x + 80;
	y = figurePosition.y - 80;
	for (x, y; x <= 640 or y >= 80; x += 80, y -= 80)
	{

		tmp = compareAttackFiled(sf::Vector2f(x, y), map, pieces, opposite);
		if (isNotEqualYourFigures(sf::Vector2f(x, y)))
		{
			if (tmp.x != 0)
			{
				possibleMoves.push_back(tmp);
				break;
			}
		}
		else
		{
			break;
		}
	}
	if (possibleMoves.size() == 2)
	{
		possibleMoves.push_back(sf::Vector2f(0, 0));
	}
	x = figurePosition.x + 80;
	y = figurePosition.y + 80;
	for (x, y; x <= 640 or y <= 640; x += 80, y += 80)
	{

		tmp = compareAttackFiled(sf::Vector2f(x, y), map, pieces, opposite);
		if (isNotEqualYourFigures(sf::Vector2f(x, y)))
		{
			if (tmp.x != 0)
			{
				possibleMoves.push_back(tmp);
				break;
			}
		}
		else
		{
			break;
		}
	}
	if (possibleMoves.size() == 3)
	{
		possibleMoves.push_back(sf::Vector2f(0, 0));
	}
	return possibleMoves;
}

std::vector<sf::Vector2f> Player::QueenPossibleAttacks(sf::Vector2f figurePosition, std::map<std::string, std::pair<sf::Vector2f, bool >>& map, std::vector<sf::RectangleShape>& pieces, Player& opposite)
{
	auto t1 = RookPossibleAttacks(figurePosition, map, pieces, opposite);
	auto t2 = BishopPossibleAttacks(figurePosition, map, pieces, opposite);
	for (auto& el : t2)
	{
		t1.push_back(el);
	}
	return t1;
}

std::vector<sf::Vector2f> Player::KingPossibleAttacks(sf::Vector2f figurePosition, std::map<std::string, std::pair<sf::Vector2f, bool >>& map, std::vector<sf::RectangleShape>& pieces, Player& opposite)
{
	std::vector<sf::Vector2f> possibleMoves;
	sf::Vector2f tmp(0, 0);
	float x = this->king->position.x - 80;
	float y = this->king->position.y + 80;
	std::vector < sf::Vector2f> avoidEnemyKing;
	avoidEnemyKing.push_back(sf::Vector2f(x - 80, y - 80));
	avoidEnemyKing.push_back(sf::Vector2f(x - 80, y));
	avoidEnemyKing.push_back(sf::Vector2f(x - 80, y + 80));
	avoidEnemyKing.push_back(sf::Vector2f(x, y + 80));
	avoidEnemyKing.push_back(sf::Vector2f(x + 80, y + 80));
	for (int i = 0; i < 8; i++)
	{
		if (opposite.king->getPosition() != avoidEnemyKing.at(0) and opposite.king->getPosition() != avoidEnemyKing.at(1) and opposite.king->getPosition() != avoidEnemyKing.at(2)
			and opposite.king->getPosition() != avoidEnemyKing.at(3) and opposite.king->getPosition() != avoidEnemyKing.at(4))
		{
			tmp = compareAttackFiled(sf::Vector2f(x, y), map, pieces, opposite);
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

sf::Vector2f Player::compareAttackFiled(sf::Vector2f positionToChange, std::map<std::string, std::pair<sf::Vector2f, bool >>& map, std::vector<sf::RectangleShape>& pieces, Player& opposite)
{
	sf::Vector2f availableField;
	sf::Color color = sf::Color(255, 204, 102);
	for (auto& sign : map)
	{
		if (sign.second.first.x == positionToChange.x and sign.second.first.y == positionToChange.y and sign.second.second == true)
		{
			for (Pawn*& pawn : opposite.pawns)
			{
				if (pawn->getPosition() == positionToChange)
				{
					changeFieldColorIfPositonIsCorrect(positionToChange, pieces, color);
					availableField = positionToChange;
				}
			}

			if (opposite.ra->getPosition() == positionToChange)
			{
				changeFieldColorIfPositonIsCorrect(positionToChange, pieces, color);
				availableField = positionToChange;
			}
			else if (opposite.rh->getPosition() == positionToChange)
			{
				changeFieldColorIfPositonIsCorrect(positionToChange, pieces, color);
				availableField = positionToChange;
			}
			else if (opposite.kb->getPosition() == positionToChange)
			{
				changeFieldColorIfPositonIsCorrect(positionToChange, pieces, color);
				availableField = positionToChange;
			}
			else if (opposite.kg->getPosition() == positionToChange)
			{
				changeFieldColorIfPositonIsCorrect(positionToChange, pieces, color);
				availableField = positionToChange;
			}
			else if (opposite.bc->getPosition() == positionToChange)
			{
				changeFieldColorIfPositonIsCorrect(positionToChange, pieces, color);
				availableField = positionToChange;
			}
			else if (opposite.bf->getPosition() == positionToChange)
			{
				changeFieldColorIfPositonIsCorrect(positionToChange, pieces, color);
				availableField = positionToChange;
			}
			else if (opposite.queen->getPosition() == positionToChange)
			{
				changeFieldColorIfPositonIsCorrect(positionToChange, pieces, color);
				availableField = positionToChange;
			}
			else if (opposite.king->getPosition() == positionToChange)
			{
				availableField = positionToChange;
			}
		}
	}
	return availableField;
}

std::vector<sf::Vector2f> Player::changeFieldColorIfPositonIsCorrect(sf::Vector2f positionToChange, std::vector<sf::RectangleShape>& pieces, sf::Color color)
{
	std::vector<sf::Vector2f> availableMoves;
	for (auto& piece : pieces)
	{
		if (piece.getPosition() == positionToChange)
		{
			piece.setFillColor(color);
			availableMoves.push_back(positionToChange);
		}
	}
	return availableMoves;
}

sf::Vector2f Player::Move(std::vector<sf::Vector2f> availableMoves, std::map<std::string, std::pair<sf::Vector2f, bool>>& map, std::vector<sf::RectangleShape>& pieces, sf::RenderWindow& window, Player& opposite)
{
	sf::Vector2f mousePosition(0, 0);
	std::vector<sf::Vector2f> tmp = availableMoves;
	tmp.pop_back();
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		std::vector<sf::RectangleShape>::iterator start = pieces.begin();
		std::vector<sf::RectangleShape>::iterator end = pieces.end();
		for (start; start != end; start++)
		{
			if (pieces.at(std::distance(pieces.begin(), start)).getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				for (auto& move : tmp)
				{
					if (move == pieces.at(std::distance(pieces.begin(), start)).getPosition() and pieces.at(std::distance(pieces.begin(), start)).getPosition() != opposite.king->getPosition())
					{
						sf::Vector2f piecePosition = availableMoves.back();
						moveFigure(piecePosition, pieces.at(std::distance(pieces.begin(), start)).getPosition(), map, pieces, opposite);
						mousePosition = pieces.at(std::distance(pieces.begin(), start)).getPosition();
					}
				}
			}
		}
	}
	return mousePosition;
}

void Player::moveFigure(sf::Vector2f piecePosition, sf::Vector2f positionToMove, std::map<std::string, std::pair<sf::Vector2f, bool>>& map, std::vector<sf::RectangleShape>& pieces, Player& opposite)
{
	char columnCount = 'A';
	int rowCount = 8;
	for (auto& piece : pieces)
	{
		if (piece.getPosition() == piecePosition)
		{
			for (auto& el : map)
			{
				if (el.second.first == piecePosition)
				{
					el.second.second = false;
				}
				if (el.second.first == positionToMove)
				{
					el.second.second = true;
				}
			}
		}
	}
	for (Pawn*& pawn : this->pawns)
	{
		if (pawn->getPosition() == piecePosition)
		{

			pawn->position = positionToMove;
			pawn->getSprite().setPosition(pawn->position);
			if (pawn->getFirstMove() == true)
			{
				pawn->setFirstMove(false);
			}

		}
	}
	if (this->ra->getPosition() == piecePosition)
	{
		this->ra->position = positionToMove;
		this->ra->getSprite().setPosition(this->ra->position);
	}
	else if (this->rh->getPosition() == piecePosition)
	{
		this->rh->position = positionToMove;
		this->rh->getSprite().setPosition(this->rh->position);
	}
	else if (this->kb->getPosition() == piecePosition)
	{
		this->kb->position = positionToMove;
		this->kb->getSprite().setPosition(this->kb->position);
	}
	else if (this->kg->getPosition() == piecePosition)
	{
		this->kg->position = positionToMove;
		this->kg->getSprite().setPosition(this->kg->position);
	}
	else if (this->bc->getPosition() == piecePosition)
	{
		this->bc->position = positionToMove;
		this->bc->getSprite().setPosition(this->bc->position);
	}
	else if (this->bf->getPosition() == piecePosition)
	{
		this->bf->position = positionToMove;
		this->bf->getSprite().setPosition(this->bf->position);
	}
	else if (this->queen->getPosition() == piecePosition)
	{
		this->queen->position = positionToMove;
		this->queen->getSprite().setPosition(this->queen->position);
	}
	else if (this->king->getPosition() == piecePosition)
	{
		this->king->position = positionToMove;
		this->king->getSprite().setPosition(this->king->position);
	}
	this->points += takeTheFigure(positionToMove, opposite);

}

int Player::takeTheFigure(sf::Vector2f positionToMove, Player& opposite)
{
	int figureValue = 0;
	sf::Vector2f whiteTakenfigures(0, 0);
	sf::Vector2f blackTakenfigures(0, 720);
	for (Pawn*& pawn : opposite.pawns)
	{
		if (pawn->whiteORblack == true)
		{
			if (pawn->getPosition() == positionToMove)
			{

				pawn->position = whiteTakenfigures;
				pawn->getSprite().setPosition(pawn->position);
				if (pawn->getFirstMove() == true)
				{
					pawn->setFirstMove(false);
				}
				figureValue = 1;

			}
		}
		else
		{
			if (pawn->getPosition() == positionToMove)
			{

				pawn->position = blackTakenfigures;
				pawn->getSprite().setPosition(pawn->position);
				if (pawn->getFirstMove() == true)
				{
					pawn->setFirstMove(false);
				}
				figureValue = 1;

			}
		}
		whiteTakenfigures.x += 80;
		blackTakenfigures.x += 80;
	}
	if (opposite.ra->whiteORblack == true)
	{
		if (opposite.ra->getPosition() == positionToMove)
		{
			opposite.ra->position = sf::Vector2f(640, 0);
			opposite.ra->getSprite().setPosition(opposite.ra->position);
			figureValue = 5;
		}
	}
	else
	{
		if (opposite.ra->getPosition() == positionToMove)
		{
			opposite.ra->position = sf::Vector2f(640, 720);
			opposite.ra->getSprite().setPosition(opposite.ra->position);
			figureValue = 5;
		}
	}

	if (opposite.rh->whiteORblack == true)
	{
		if (opposite.rh->getPosition() == positionToMove)
		{
			opposite.rh->position = sf::Vector2f(720, 0);
			opposite.rh->getSprite().setPosition(opposite.rh->position);
			figureValue = 5;
		}
	}
	else
	{
		if (opposite.rh->getPosition() == positionToMove)
		{
			opposite.rh->position = sf::Vector2f(720, 720);
			opposite.rh->getSprite().setPosition(opposite.rh->position);
			figureValue = 5;
		}

	}


	if (opposite.kb->whiteORblack == true)
	{
		if (opposite.kb->getPosition() == positionToMove)
		{
			opposite.kb->position = sf::Vector2f(800, 0);
			opposite.kb->getSprite().setPosition(opposite.kb->position);
			figureValue = 3;
		}
	}
	else
	{
		if (opposite.kb->getPosition() == positionToMove)
		{
			opposite.kb->position = sf::Vector2f(800, 720);
			opposite.kb->getSprite().setPosition(opposite.kb->position);
			figureValue = 3;
		}
	}

	if (opposite.kg->whiteORblack == true)
	{
		if (opposite.kg->getPosition() == positionToMove)
		{
			opposite.kg->position = sf::Vector2f(880, 720);
			opposite.kg->getSprite().setPosition(opposite.kg->position);
			figureValue = 3;
		}
	}
	else
	{
		if (opposite.kg->getPosition() == positionToMove)
		{
			opposite.kg->position = sf::Vector2f(880, 720);
			opposite.kg->getSprite().setPosition(opposite.kg->position);
			figureValue = 3;
		}
	}

	if (opposite.bc->whiteORblack == true)
	{
		if (opposite.bc->getPosition() == positionToMove)
		{
			opposite.bc->position = sf::Vector2f(960, 0);
			opposite.bc->getSprite().setPosition(opposite.bc->position);
			figureValue = 3;
		}
	}
	else
	{
		if (opposite.bc->getPosition() == positionToMove)
		{
			opposite.bc->position = sf::Vector2f(960, 720);
			opposite.bc->getSprite().setPosition(opposite.bc->position);
			figureValue = 3;
		}
	}

	if (opposite.bc->whiteORblack == true)
	{
		if (opposite.bf->getPosition() == positionToMove)
		{
			opposite.bf->position = sf::Vector2f(1040, 0);
			opposite.bf->getSprite().setPosition(opposite.bf->position);
			figureValue = 3;
		}
	}
	else
	{
		if (opposite.bf->getPosition() == positionToMove)
		{
			opposite.bf->position = sf::Vector2f(1040, 720);
			opposite.bf->getSprite().setPosition(opposite.bf->position);
			figureValue = 3;
		}
	}
	if (opposite.bc->whiteORblack == true)
	{
		if (opposite.queen->getPosition() == positionToMove)
		{
			opposite.queen->position = sf::Vector2f(1120, 0);
			opposite.queen->getSprite().setPosition(opposite.queen->position);
			figureValue = 9;
		}
	}
	else
	{
		if (opposite.queen->getPosition() == positionToMove)
		{
			opposite.queen->position = sf::Vector2f(1120, 720);
			opposite.queen->getSprite().setPosition(opposite.queen->position);
			figureValue = 9;
		}
	}
	return figureValue;
}

bool Player::isNotEqualYourFigures(sf::Vector2f positionToChange)
{
	bool notEqual = true;
	for (Pawn*& pawn : pawns)
	{
		if (pawn->getPosition() == positionToChange)
		{
			notEqual = false;
		}
	}
	if (this->ra->getPosition() == positionToChange)
	{
		notEqual = false;
	}
	else if (this->rh->getPosition() == positionToChange)
	{
		notEqual = false;
	}
	else if (this->kb->getPosition() == positionToChange)
	{

		notEqual = false;
	}
	else if (this->kg->getPosition() == positionToChange)
	{
		notEqual = false;
	}
	else if (this->bc->getPosition() == positionToChange)
	{
		notEqual = false;
	}
	else if (this->bf->getPosition() == positionToChange)
	{
		notEqual = false;
	}
	else if (this->queen->getPosition() == positionToChange)
	{
		notEqual = false;
	}
	else if (this->king->getPosition() == positionToChange)
	{
		notEqual = false;
	}
	return notEqual;

}

void Player::ResetFigures()
{
	if (this->color == true)
	{
		sf::Vector2f positions(80, 560);
		for (Pawn*& pawn : pawns)
		{
			pawn->position = positions;
			positions.x = positions.x + 80;
			pawn->getSprite().setPosition(pawn->position);
			pawn->setFirstMove(true);
		}
		this->ra->position = sf::Vector2f(80, 640);
		this->ra->getSprite().setPosition(this->ra->position);
		this->rh->position = sf::Vector2f(640, 640);
		this->rh->getSprite().setPosition(this->rh->position);
		this->kb->position = sf::Vector2f(160, 640);
		this->kb->getSprite().setPosition(this->kb->position);
		this->kg->position = sf::Vector2f(560, 640);
		this->kg->getSprite().setPosition(this->kg->position);
		this->bc->position = sf::Vector2f(240, 640);
		this->bc->getSprite().setPosition(this->bc->position);
		this->bf->position = sf::Vector2f(480, 640);
		this->bf->getSprite().setPosition(this->bf->position);
		this->queen->position = sf::Vector2f(320, 640);
		this->queen->getSprite().setPosition(this->queen->position);
		this->king->position = sf::Vector2f(400, 640);
		this->king->getSprite().setPosition(this->king->position);
	}
	else
	{
		sf::Vector2f positions(80, 160);
		for (Pawn*& pawn : pawns)
		{
			pawn->position = positions;
			positions.x = positions.x + 80;
			pawn->getSprite().setPosition(pawn->position);
			pawn->setFirstMove(true);
		}
		this->ra->position = sf::Vector2f(80, 80);
		this->ra->getSprite().setPosition(this->ra->position);
		this->rh->position = sf::Vector2f(640, 80);
		this->rh->getSprite().setPosition(this->rh->position);
		this->kb->position = sf::Vector2f(160, 80);
		this->kb->getSprite().setPosition(this->kb->position);
		this->kg->position = sf::Vector2f(560, 80);
		this->kg->getSprite().setPosition(this->kg->position);
		this->bc->position = sf::Vector2f(240, 80);
		this->bc->getSprite().setPosition(this->bc->position);
		this->bf->position = sf::Vector2f(480, 80);
		this->bf->getSprite().setPosition(this->bf->position);
		this->queen->position = sf::Vector2f(320, 80);
		this->queen->getSprite().setPosition(this->queen->position);
		this->king->position = sf::Vector2f(400, 80);
		this->king->getSprite().setPosition(this->king->position);
	}
}

bool Player::checkCheck(std::map<std::string, std::pair<sf::Vector2f, bool>>& map, std::vector<sf::RectangleShape>& pieces, Player& opposite)
{
	std::vector<sf::Vector2f> allAttacks;
	std::vector<sf::Vector2f> tmp;
	tmp = changeColorIfAttackIsPossible(this->pawns.at(0)->getPosition(), map, pieces, opposite);
	for (auto& attack : tmp)
	{
		allAttacks.push_back(attack);
	}
	tmp = changeColorIfAttackIsPossible(this->pawns.at(1)->getPosition(), map, pieces, opposite);
	for (auto& attack : tmp)
	{
		allAttacks.push_back(attack);
	}
	tmp = changeColorIfAttackIsPossible(this->pawns.at(2)->getPosition(), map, pieces, opposite);
	for (auto& attack : tmp)
	{
		allAttacks.push_back(attack);
	}
	tmp = changeColorIfAttackIsPossible(this->pawns.at(3)->getPosition(), map, pieces, opposite);
	for (auto& attack : tmp)
	{
		allAttacks.push_back(attack);
	}
	tmp = changeColorIfAttackIsPossible(this->pawns.at(4)->getPosition(), map, pieces, opposite);
	for (auto& attack : tmp)
	{
		allAttacks.push_back(attack);
	}
	tmp = changeColorIfAttackIsPossible(this->pawns.at(5)->getPosition(), map, pieces, opposite);
	for (auto& attack : tmp)
	{
		allAttacks.push_back(attack);
	}
	tmp = changeColorIfAttackIsPossible(this->pawns.at(6)->getPosition(), map, pieces, opposite);
	for (auto& attack : tmp)
	{
		allAttacks.push_back(attack);
	}
	tmp = changeColorIfAttackIsPossible(this->pawns.at(7)->getPosition(), map, pieces, opposite);
	for (auto& attack : tmp)
	{
		allAttacks.push_back(attack);
	}
	tmp = changeColorIfAttackIsPossible(this->ra->getPosition(), map, pieces, opposite);
	for (auto& attack : tmp)
	{
		allAttacks.push_back(attack);
	}
	tmp = changeColorIfAttackIsPossible(this->rh->getPosition(), map, pieces, opposite);
	for (auto& attack : tmp)
	{
		allAttacks.push_back(attack);
	}
	tmp = changeColorIfAttackIsPossible(this->kb->getPosition(), map, pieces, opposite);
	for (auto& attack : tmp)
	{
		allAttacks.push_back(attack);
	}
	tmp = changeColorIfAttackIsPossible(this->kg->getPosition(), map, pieces, opposite);
	for (auto& attack : tmp)
	{
		allAttacks.push_back(attack);
	}
	tmp = changeColorIfAttackIsPossible(this->bc->getPosition(), map, pieces, opposite);
	for (auto& attack : tmp)
	{
		allAttacks.push_back(attack);
	}
	tmp = changeColorIfAttackIsPossible(this->bf->getPosition(), map, pieces, opposite);
	for (auto& attack : tmp)
	{
		allAttacks.push_back(attack);
	}
	tmp = changeColorIfAttackIsPossible(this->queen->getPosition(), map, pieces, opposite);
	for (auto& attack : tmp)
	{
		allAttacks.push_back(attack);
	}
	for (auto& attack : allAttacks)
	{
		if (attack == opposite.king->getPosition())
		{
			return true;
		}
	}
	return false;
}