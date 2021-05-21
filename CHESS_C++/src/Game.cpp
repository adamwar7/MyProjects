#include "Game.h"


Game::Game(Player white, Player black)
{
	Board board(white, black);
	this->board = board;
}

sf::Vector2f Game::selectField(sf::RenderWindow& window)
{
	sf::Vector2f mousePosition(0, 0);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		std::vector<sf::RectangleShape>::iterator start = this->board.pieces.begin();
		std::vector<sf::RectangleShape>::iterator end = this->board.pieces.end();
		char column = 'A';
		char row = '8';
		for (start; start != end; start++)
		{
			std::string buffer = "";
			buffer.push_back(column);
			buffer.push_back(row);
			if (this->board.pieces.at(std::distance(this->board.pieces.begin(), start)).getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				if (this->board.piecePosition.at(buffer).second == true)
				{
					return this->board.pieces.at(std::distance(this->board.pieces.begin(), start)).getPosition();
				}
			}
			else if (sf::Mouse::getPosition(window).x >= 740 and sf::Mouse::getPosition(window).x <= 900
				and sf::Mouse::getPosition(window).y >= 360 and sf::Mouse::getPosition(window).y <= 440)
			{
				mousePosition.x = (float)sf::Mouse::getPosition(window).x;
				mousePosition.y = (float)sf::Mouse::getPosition(window).y;
			}
			row--;
			if (row == '0')
			{
				column++;
				row = '8';
			}
		}
	}
	return mousePosition;
}
