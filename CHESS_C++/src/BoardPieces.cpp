#include "BoardPieces.h"

BoardPieces::BoardPieces()
{
	piecePosition = loadPositions();
	pieces = setArray(piecePosition);
	/*printmap(piecePosition);*/
}

std::map<std::string, std::pair<sf::Vector2f, bool>> BoardPieces::loadPositions()
{
	std::map<std::string, std::pair<sf::Vector2f, bool>> positions;
	char column = 'A';
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			std::string col="";
			col.push_back(column);
			std::string buff = std::to_string(8 - y);
			col += buff;
			positions.insert({ col,{sf::Vector2f((x + 1.f) * 80.f, (y + 1.f) * 80.f),
				(((y + 1.f) * 80.f)>= 80 and ((y + 1.f) * 80.f) <= 160) or (((y + 1.f) * 80.f) >= 560 and ((y + 1.f) * 80.f) <= 640) ? true : false} });
		}
		column++;
	}
	return positions;
}

std::vector<sf::RectangleShape> BoardPieces::setArray(std::map<std::string, std::pair<sf::Vector2f, bool>> positions)
{
	std::vector<sf::RectangleShape> pieces;
	sf::RectangleShape piece;
	bool color = true;
	char columnCount = 'A';
	int rowCount = 8;
	for (int i=0;i<64;i++)
	{
		if (rowCount == 0)
		{
			columnCount++;
			rowCount=8;
			color = !color;
		}
		std::string key="";
		key.push_back(columnCount);
		std::string row = std::to_string(rowCount);
		key += row;
		piece.setSize(sf::Vector2f(80.f, 80.f));
		std::pair<sf::Vector2f, bool > getPair = positions.at(key);
		piece.setPosition(getPair.first);
		piece.setFillColor(color == true ? sf::Color(242, 242, 242) : sf::Color(0, 102, 0));
		piece.setOutlineThickness(-1.f);
		piece.setOutlineColor(sf::Color::Black);
		pieces.push_back(piece);
		color = !color;
		rowCount--;
	}
	return pieces;
}

std::map<std::string, std::pair<sf::Vector2f, bool>> BoardPieces::getMapWithPositionOfPieces()
{
	return this->piecePosition;
}

std::vector<sf::RectangleShape> BoardPieces::getVectorOfBoardPieces()
{
	return this->pieces;
}

void BoardPieces::drawBoard(sf::RenderWindow& window)
{
	for (auto &i : this->pieces)
	{
		window.draw(i);
	}
}

void BoardPieces::resetColors()
{
	bool color = true;
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			this->pieces.at(j + (8 * i)).setFillColor((color == true ? sf::Color(242, 242, 242) : sf::Color(0, 102, 0)));
			color = !color;
		}
		color = !color;
	}
}

//void BoardPieces::printmap(std::map<std::string, sf::Vector2f> piecePosition)
//{
//	for (auto a : piecePosition)
//	{
//		std::cout << a.first << " " << a.second.x << " " << a.second.y << std::endl;
//	}
//}